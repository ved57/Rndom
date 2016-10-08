
#include <iostream>
#include <fstream>
#include<algorithm>
#include <set>
using namespace std;

int knapsack(int wt[],int val[],int count, int max_weight)
{
	//Note: we can include the item only if the weight is within allowed limit
	if (count<=0 || max_weight<wt[count-1])
	{
		return 0;
	}
	if (count == 1)
	{
		return val[0];
	}
	//either include the item or leave the item
	return max( val[count-1]+ knapsack(wt,val,count-1,max_weight-wt[count-1]),
			knapsack(wt,val,count-1,max_weight)
			);

}


int main()
{
	int wt[]={1,3,4,5};
	int val[]={1,4,5,7};
	int total_weight = 7;
	int max_value = knapsack(wt,val,sizeof wt/sizeof wt[0], total_weight);
	std::cout<<"\n Max value obtained is "<<max_value<<endl;
	return 0;
}
