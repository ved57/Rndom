#include<iostream>
#include <vector>
using namespace std;


/*
 * Think in terms of wall and swapping.
 * Preferably move the pivot element only at the last
 *
 */
int partition(int a[],int low, int high)
{
	//Selecting the last element for convenience
	int pivot = a[high];
	int wall = high -1;
	int i = high-1;
	while(i>=low)
	{
		if (a[i]>pivot)
		{
			swap(a[wall],a[i]);
			--wall;
		}
		--i;
	}
	++wall;
	swap(a[wall],a[high]);
	return wall;
}

void quickSort(int a[], int low, int high)
{
	int p;
	if (low<high)
	{
		p = partition(a,low,high);
		quickSort(a,low,p-1);
		quickSort(a,p+1,high);
	}
}


int main()
{
	int a[]={6,4,1,2,8,3,9,0,5,7};
	int N = sizeof a/ sizeof a[0];

	quickSort(a,0,N-1);

	for (int i=0;i<N;i++)
		cout<<"\t "<<a[i];
	cout<<endl;

	return 0;
}
