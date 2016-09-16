#include <iostream>
using namespace std;

template<typename N> 
void somefunction(N n1)
{
	cout<<std::endl<<n1;
	return;
}


struct BTNode{
	BTNode *left;
	BTNode *right;
	int data;
};

//creates Full binary tree
BTNode* createTree(int a[], int n)
{
	if (n<=0)
		return NULL;
	BTNode *root = new BTNode();
	

}


int main(int argc, char const *argv[])
{
	BTNode *root = new Node();
	root->data = 5;
	cout<<root->data<<endl;
	
	return 0;
}