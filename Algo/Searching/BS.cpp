
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

int binary_search_rec (int a[],int start, int end, int x)
{
	int mid = (start-end)/2 + end;
	if (start>=end)
		return -1;
	if (a[mid]==x)
		return mid;
	if (x<a[mid])
		return binary_search_rec(a,start,mid-1,x);
	if (x>a[mid])
		return binary_search_rec(a,mid+1,end,x);
	return -1;
}

int binary_search_rec_first (int a[],int start, int end, int x)
{
	int mid = (start-end)/2 + end;
	if (start>=end)
		return -1;
	if (a[mid]==x){
		while(mid-1>=0)
		{
			if (a[mid-1]!=x)
			{
				break;
			}
			--mid;
		}
		return mid;
	}
	if (x<a[mid])
		return binary_search_rec(a,start,mid-1,x);
	if (x>a[mid])
		return binary_search_rec(a,mid+1,end,x);
	return -1;
}


int binary_search_last(int a[], int N, int x)
{
	int start = 0;
	int end = N;
	int result = -1;
	while (start <= end)
	{
		int mid = (start - end)/2 + end;
		if (a[mid]==x)
		{
			result = mid;
			//to find last occur, search in the right again
			 start = mid+1 ;
			 //Note: to find first occur, search in the left again
			 //end = mid-1;
		}
		else if (x<a[mid])
		{
			end = mid-1;
		}
		else if (x>a[mid])
		{
			start = mid +1;
		}
	}
	return result;
}

int binary_search(int a[], int N, int x)
{
	int start = 0;
	int end = N;
	while (start <= end)
	{
		int mid = (start - end)/2 + end;
		if (a[mid]==x)
		{
			return mid;
		}
		else if (x<a[mid])
		{
			end = mid-1;
		}
		else if (x>a[mid])
		{
			start = mid +1;
		}
	}
	return -1;
}


//this method is quite different. just takes O(logN) time.
//Don't do a linear search after locating atleast one instance. 
//This does not scale well.
int count(int a[],int N,int x)
{
	return (binary_search_last(a,N,x)-binary_search_rec_first(a,0,N,x)+1);
}



int main()
{
	int a[] = {2,4,10,10,10,18,20};
	int N = sizeof a / sizeof a[0];
	cout<<find (a,a+N,3) - a<<endl;
	cout<<binary_search(a,N-1,202)<<endl;
	cout<<binary_search_rec(a,0,N-1,10)<<endl;
	cout<<binary_search_rec_first(a,0,N-1,10)<<endl;
	cout<<count(a,N,10);
	return 0;
}
