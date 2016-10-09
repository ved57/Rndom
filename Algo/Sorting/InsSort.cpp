
#include <iostream>
#include <fstream>
#include<algorithm>
#include <set>
using namespace std;


void printResult(int arr[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t ";
	}
}

void insertion_sort(int arr[],int n)
{

	for (size_t i =1;i<n;i++)
	{
		for (size_t j=i;j>0;j--)
		{
			if (arr[j]<arr[j-1])
			{
				swap(arr[j-1],arr[j]);
			}
			else
				break;
		}
	}
	cout<<"\n\n Insertion sort done: \n";
	printResult(arr,n);
}



void reinitialize_array(int arr[], int n)
{
	random_shuffle(&arr[0],&arr[n-1]);
	cout<<"\n\n Re-initialized array: \n";
	printResult(arr,n);
}

int main()
{
	int a[] = {6,5,3,1,8,4};

	int N = sizeof a /sizeof a[0];
	int test_count = 10; //do the test 10 times

	for (int i=0;i<test_count;i++)
	{
		reinitialize_array(a,N);
		insertion_sort (a,N);
	}

	return 0;
}
