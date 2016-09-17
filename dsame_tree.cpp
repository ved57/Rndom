#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
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
	BTNode (int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

//creates Full binary tree
BTNode* createTree(int a[], int n)
{
	if (n<=0)
		return NULL;
}

BTNode* createStdTree()
{
	BTNode *root = new BTNode(1);
	root->left = new BTNode(2);
	root->right = new BTNode(3);
	root->left->left = new BTNode(4);
	root->left->right = new BTNode(5);
	root->right->left = new BTNode(6);
	root->right->right = new BTNode(7);


	root->left->left->left = new BTNode(8);
	root->left->left->right = new BTNode(9);	
	root->left->right->left = new BTNode(10);
	root->left->right->right = new BTNode(11);
	root->right->left->left = new BTNode(12);
	root->right->left->right = new BTNode(13);
	root->right->right->left = new BTNode(14);
	root->right->right->right = new BTNode(15);


	return root;
}


void inOrderTraversal_r(BTNode* root)
{
	if (!root)
	{
		return;
	}
	cout<<"\t "<<root->data;
	inOrderTraversal_r(root->left);
	inOrderTraversal_r(root->right);
}

void inOrderTraversal_i(BTNode* root)
{
	cout<<"\n";
	stack<BTNode*> s;
	BTNode *current = root;
	while(1)
	{		
		while(root)
		{
			s.push(root);			
			root=root->left;	
		}
		if(!s.empty()&& root==NULL)
		{
			BTNode* curr = s.top();
			s.pop();
			cout<<"\t"<<curr->data;
			root = curr->right;
		}
		else if (s.empty()&&root==NULL)
			return;		
	}
}

void preOrderTraversal_r(BTNode* root)
{
	if (!root)
		return;
	cout<<"\t"<<root->data;
	preOrderTraversal_r(root->left);
	preOrderTraversal_r(root->right);
}

void preOrderTraversal_i(BTNode* root)
{
	cout<<"\n";
	stack<BTNode*> s;
	BTNode *current = root;
	while(1)
	{		
		while(root)
		{
			s.push(root);
			cout<<"\t"<<root->data;
			root=root->left;	
		}
		if(!s.empty()&& root==NULL)
		{
			BTNode* curr = s.top();
			s.pop();
			
			root = curr->right;
		}
		else if (s.empty()&&root==NULL)
			return;		
	}
}

void postOrderTraversal_r(BTNode *root)
{
	if (!root)
		return;
	postOrderTraversal_r(root->left);
	postOrderTraversal_r(root->right);
	cout<<"\t"<<root->data;
}


void postOrderTraversal_i(BTNode *root)
{
	cout<<"\n postOrderTraversal_i entered \n";
	stack<BTNode*> s;
	stack<int> s2;
	s.push(root);
	while(!s.empty())
	{		
		BTNode* current = s.top();
		s.pop();
		if (current)
		{			
			s.push(current->left);
			s2.push(current->data);
			s.push(current->right);			

		}
	}
	while(!s2.empty())
	{
		int curr = s2.top();
		s2.pop();
		cout<<"\t "<<curr;
	}
	cout<<"\n";
}


void levelOrderTraversal_r(BTNode *root)
{
	queue<BTNode*> q;
	q.push(root);
	while(!q.empty())
	{
		BTNode *current = q.front();
		q.pop();
		if (current)
		{
			cout<<"\t "<<current->data;
			q.push(current->left);
			q.push(current->right);
		}
	}				
}


int findMax_r(BTNode* root)
{
	if (!root)
		return INT_MIN;
	return max(root->data,max(findMax_r(root->left),findMax_r(root->right)));

}



int main(int argc, char const *argv[])
{	
	BTNode * root = createStdTree();	
	cout<<"\n";
	cout<<findMax_r(root)<<endl;

	return 0;
}