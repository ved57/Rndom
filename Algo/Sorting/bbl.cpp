#include<iostream>
using namespace std;

void bubbleSort(int a[],int low, int high)
{
	for (int i=low;i<=high;i++)
	{
		for (int j=low;j<high-low;j++)
		{
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}

int main()
{
	int a[]={6,4,1,2,8,3,9,0,5,7};
	int N = sizeof a/ sizeof a[0];

	bubbleSort(a,0,N-1);

	for (int i=0;i<N;i++)
		cout<<"\t "<<a[i];
	cout<<endl;

	return 0;
}
