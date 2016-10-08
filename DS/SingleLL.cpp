#include<iostream>
using namespace std;
//Program for implementing linked list and related functions
//Implementing closer to C functions

typedef struct Node{
	int data;
	Node* next;
	Node(int d):data(d),next(NULL){}
};

void print(Node* head)
{
	cout<<endl;
	while (head!=NULL)
	{
		cout<<"\t "<<head->data;
		head = head->next;
	}
	cout<<endl;
}

typedef enum POS{
	START,
	END,
	MIDDLE
};


void insert(Node** head_ref, int data, int pos, Node* prev=NULL)
{
	Node* newNode = new Node(data);
	if (*head_ref == NULL)
	{
		*head_ref = newNode;
	}

	if (pos==START) //insert at the front
	{
		newNode->next = *head_ref;
		*head_ref = newNode;
	}
	else if (pos==END){
		//traverse until the last and insert at the end
		Node* curr = *head_ref;
		while (curr && curr->next!=NULL)
			curr = curr->next;
		curr->next = newNode;
	}
	else if (pos==MIDDLE)
	{
		Node* curr = *head_ref;
		while(curr && curr!=prev)
		{
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

//creates linked list from array
Node* create()
{
	//creating {5,4,2,1,8,7,6,3}
	int a[] = {5,4,2,1,8,7,6,3};
	Node* head = new Node (a[0]);
	Node* curr = head;
	for (int i=1; i< (sizeof a/ sizeof a[0]);i++)
	{
		curr->next = new Node(a[i]);
		curr=curr->next;
	}
	return head;
}

int main()
{
	Node* head = create();
	print(head);
	insert(&head,18,END);
	insert(&head,20,MIDDLE,head->next->next);
	print(head);
	return 0;
}
