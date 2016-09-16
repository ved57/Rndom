#include <iostream>
using namespace std;
void print_array(int a[],int n)
{
	cout<<"\n";
	for (int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
}

void insertion_sort(int a[],int n)
{
   int value;
   for (int i=1;i<n;++i)
   {
   	value = a[i];
   	cout<<"Value taken is "<<value<<"\n";
   	for (int j=i-1;j>=0;j--)
   	{   		
   		if (value < a[j])
   		{
   			a[j+1]=a[j];    			
   			if (j==0)
   			a[j]=value;
   		}
   		else 
   		{
   			a[j+1] = value;
   			break;
   		}

   	}
   	print_array(a,n);
   }
}

void insertion_sort2(int a[],int n)
{
	int value;
	int j;
	for (int i=1;i<n;i++)
	{
		value = a[i];
		j = i;
		while (j>0 && a[j-1]>value)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = value;
	}
}

void merge(int l[],int l_max,int r[],int r_max)
{
	int i=0;
	int j=0;
	int b[l_max+r_max];
	int temp;
	while(i<l_max && j<j_max)
	{
		if (r[j]<l[i])
		{
			temp = r[j];
			r[j] = l[i];
			l[i] = temp;
			++i;
		}
		else j++;
	}
}


void merge_sort(int a[],int n)
{

}


int main(int argc, char const *argv[])
{
	int a[]= {2,9,5,6,3,7,1,8,0,4};	
	print_array(a,10);
	insertion_sort2(a,10);
	print_array(a,10);
	return 0;
}