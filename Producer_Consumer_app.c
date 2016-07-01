#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

# define BUFFER_SIZE 2
# define MESSAGE_SIZE 20

void *Enqueuer();
void *Dequeuer();

unsigned int readIndex = 0;
unsigned int writeIndex = 0;
char dataBuffer[BUFFER_SIZE][MESSAGE_SIZE];

pthread_cond_t bufferNotFull=PTHREAD_COND_INITIALIZER;
pthread_cond_t bufferNotEmpty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutexLock=PTHREAD_MUTEX_INITIALIZER;

int sockfd; /* socket */
int portno; /* port to listen on */
int clientlen; /* byte size of client's address */
struct sockaddr_in serveraddr; /* server's addr */
struct sockaddr_in clientaddr; /* client addr */
struct hostent *hostp; /* client host info */	
char *hostaddrp; /* dotted decimal host addr string */
int optval; /* flag value for setsockopt */
int n; /* message byte size */


/*
 * error - wrapper for perror
 */
 void error(char *msg) {
 	perror(msg);
 	exit(1);
 }


 void *Enqueuer()
 {    
 	while(1)
 	{
 		printf("Enqueuer entered \n");
 		pthread_mutex_lock(&mutexLock);
 		printf("Enqueuer acquired lock\n");
 		if(abs(writeIndex - readIndex) == BUFFER_SIZE)
 		{
 			printf("Waiting for buffer not to be full\n");
 			writeIndex %= BUFFER_SIZE;
 			pthread_cond_wait(&bufferNotFull,&mutexLock);
 		}

        /*
		 * recvfrom: receive a UDP datagram from a client
		 */
		 memset(dataBuffer[writeIndex],0,MESSAGE_SIZE);
		 n = recvfrom(sockfd, dataBuffer[writeIndex], MESSAGE_SIZE, 0,
		 	(struct sockaddr *) &clientaddr, &clientlen);
		 if (n < 0)
		 	error("ERROR in recvfrom");

		 printf("Received datagram \t %s \n", dataBuffer[writeIndex]);
		 
		 printf("Written index : %u \n",writeIndex);        
		 writeIndex = (writeIndex + 1);
		 pthread_mutex_unlock(&mutexLock);
		 printf("Enqueuer released teh lock \n");
		 pthread_cond_signal(&bufferNotEmpty);        
		}        
	}

	void *Dequeuer()
	{
		while(1)
		{
			printf("\n Dequeuer entered");
			pthread_mutex_lock(&mutexLock);
			printf("\n Dequeuer acquired lock");
			if(readIndex == writeIndex)
			{            
				pthread_cond_wait(&bufferNotEmpty,&mutexLock);
			}

	 /*
	 * sendto: echo the input back to the client
	 */
	 printf("Dequeuer::Sendto is going to be called. \n");
	 n = sendto(sockfd, dataBuffer, strlen(dataBuffer[readIndex]), 0,
	 	(struct sockaddr *) &clientaddr, clientlen);
	 printf("\n Send to result is %d ", n);

	 if (n < 0)
	 	error("ERROR in sendto");

	 printf("Consume : %d \n",readIndex);        
	 readIndex = (readIndex + 1) % BUFFER_SIZE;
	 pthread_mutex_unlock(&mutexLock);        
	 pthread_cond_signal(&bufferNotFull);                
	}
}

	
int main(int argc, char **argv) {
	/*
	 * check command line arguments
	 */
	 if (argc != 2) {
	 	fprintf(stderr, "usage: %s <port>\n", argv[0]);
	 	exit(1);
	 }
	 portno = atoi(argv[1]);

	/*
	 * socket: create the parent socket
	 */
	 sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	 if (sockfd < 0)
	 	error("ERROR opening socket");

	 optval = 1;
	 setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
	 	(const void *)&optval , sizeof(int));

	/*
	 * build the server's Internet address
	 */
	 bzero((char *) &serveraddr, sizeof(serveraddr));
	 serveraddr.sin_family = AF_INET;
	 serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	 serveraddr.sin_port = htons((unsigned short)portno);

	/*
	 * bind: associate the parent socket with a port
	 */
	 if (bind(sockfd, (struct sockaddr *) &serveraddr,
	 	sizeof(serveraddr)) < 0)
	 	error("ERROR on binding");

	/*
	 * main loop: wait for a datagram, then echo it
	 */
	 clientlen = sizeof(clientaddr);	


	 pthread_t ptid,ctid;    

	 pthread_create(&ptid,NULL,Enqueuer,NULL);
	 pthread_create(&ctid,NULL,Dequeuer,NULL);

	 pthread_join(ptid,NULL);
	 pthread_join(ctid,NULL);

	 return 0;
	}