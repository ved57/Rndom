#include<iostream>
#include<typeinfo>

using namespace std;



struct Node
{
	int data;
	Node* left;
	Node* right;
public:
	Node(int val):data(val),left(NULL),right(NULL)
	{

	}
};

class BST
{
	Node* root;
public:
	BST():root(NULL){}

	void insert(int data)
	{
		cout<<"\n Root is "<<root;
		insert(&root,data);
	}

/*
Note there is an additional level of indirection needed whenever 
the value stored by the pointer has to be varies in the same location.
In this case the content of the root pointer should be modified to
the newly created pointer. Hence pass the address of the pointer.
Tip: Use * to modify the value of a variable at the same location.
Use ** to modify the value of a pointer at the same location. 
*/

	void insert(Node** curr, int data)
	{
		if(*curr == NULL)
		{			
			*curr =  new Node(data);			
			
		}
		else
		{

			Node *curr2;
			curr2 = *curr;

			if(data < (curr2)->data)
			{
				insert(&curr2->left,data);
			}
			else
			{
				insert(&curr2->right,data);
			}
		}
	}

	void print()
	{
		cout<<"\n Printing all the nodes";
		print(root);
	}

	void print(Node* curr)
	{	

		if (curr==NULL)
		{			
			return;
		}
		else
		{			
			print(curr->left);
			cout<<"\t"<<curr->data;
			print(curr->right);
		}
	}
};

int main(int argc, char const *argv[])
{
	BST bst;	
	bst.insert(6);	
	bst.print();
	bst.insert(3);	
	bst.insert(4);
	bst.insert(9);
	bst.insert(5);	
	bst.insert(1);
	bst.print();
	return 0;
}
