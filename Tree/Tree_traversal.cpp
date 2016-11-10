#include<iostream>
#include<deque>
using namespace std;

/*
Learnings:
Dequeue:
Dequeue is spelled as deque
It does not have separate push and pop operation.
It only has push,pop,front,back combination.
Also pop_front() and pop_back() does not return the value. They just delete.
So use front() and back() to access the corresponding elements.


Traversals:
Traversals are not hard as they seem to be when thought about implementing for
binary tree. Just extend the concept for graph.
If going deeper use Stack (or recursion internally).
If going across use Queue.
*/


typedef struct Node {
	int data;
	Node *right, *left;
}Node;

void preOrder(Node* curr)
{
	if (curr == NULL)
		return;
	preOrder(curr->left);
	cout<<"\n Data is "<<curr->data;
	preOrder(curr->right);
}


void postOrder(Node* curr)
{
	if (curr == NULL)
		return;
	cout<<"\n Data is "<<curr->data;
	postOrder(curr->left);
	postOrder(curr->right);
}

void inOrder(Node* curr)
{	
	if (curr == NULL)
		return;
	inOrder(curr->left);
	inOrder(curr->right);
	cout<<"\n Data is "<<curr->data;
}

void BFS_ReversalHelper(deque<Node*> q)
{
	while(!q.empty())
	{
		Node* curr = q.front();
		q.pop_front();
		if (curr != NULL)
		{
			cout<<"\n Data is "<<curr->data;
			q.push_back(curr->right);
			q.push_back(curr->left);			
		}		
	}
}

void BFS_helper(deque<Node*> q)
{	
	while(!q.empty())
	{
		Node* curr = q.front(); //hope it is deleted as well	
		q.pop_front();
		if (curr==NULL) continue;
		cout<<"\n Data is "<<curr->data;
		q.push_back(curr->left);
		q.push_back(curr->right);
	}
}


void BFS(Node* curr)
{		
	deque<Node*>q;
	q.push_back(curr);
	BFS_ReversalHelper(q);
}

Node* newtNode(int data)
{
  Node* tNode = new Node();
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
  return(tNode);
}


int main(int argc, char const *argv[])
{
	cout<<"\n Hello";
/*	Node root = {
		.data = 5,
		.right = NULL,
		.left = NULL
};*/
	  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
	Node *root = newtNode(1);
    root->left        = newtNode(2);
    root->right       = newtNode(3);
    root->left->left  = newtNode(4);
    root->left->right = newtNode(5); 
	//Depth first search
  	cout<<"\n Doing preOrder";
	preOrder(root);
	cout<<endl;
	cout<<"\n Doing postOrder";
	postOrder(root);
	cout<<endl;
	cout<<"\n Doing inOrder";
	inOrder(root);
	cout<<"\n Doing BFS";
	cout<<endl;
	BFS(root);
	return 0;
}

