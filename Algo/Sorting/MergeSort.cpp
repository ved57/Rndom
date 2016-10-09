#include<iostream>
#include <vector>
using namespace std;


void merge(int a[],vector<int>&temp, int low, int mid, int high)
{
	int left_low = low;
	int left_high = mid;
	int right_low = mid+1;
	int right_high = high;

	int i = left_low;
	int j = right_low;
	int k = 0;
	while (i<=left_high && j<=right_high)
	{
		if (a[i]<a[j]){
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{
			temp[k]= (a[j]);
			j++;
			k++;
		}
	}
	while(i<=left_high)
	{
		temp[k]= (a[i]);
		i++;
		k++;
	}
	while (j<=right_high)
	{
		temp[k] = (a[j]);
		j++;
		k++;
	}

	/*
	 * Note: Modify the original array only in the current range only
	 */
	for (int m=0 ;m<k;m++)
	{
		a[m+low]=temp[m];
	}
}


/*
 * Make the high as also inclusive. This resolves many troubles.
 * Add a temp array as part of parameter to avoid
 */
void mergeSort(int a[],vector<int>& temp, int low, int high)
{
	if (low<high)
	{
		int mid = low+ (high-low)/2;
		mergeSort(a,temp,low,mid);
		mergeSort(a,temp,mid+1,high);
		merge(a,temp,low,mid,high);
	}
}


int main()
{
	int a[]={6,4,1,2,8,3,9,0,5,7};
	int N = sizeof a/ sizeof a[0];
	vector<int> temp(N);
	mergeSort(a,temp,0,N-1);
	for (int i=0;i<N;i++)
		cout<<"\t "<<a[i];
	cout<<endl;
	for (int i=0;i<N;i++)
		cout<<"\t "<<temp[i];
	return 0;
}
