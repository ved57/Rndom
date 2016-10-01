//Find LowestCommonAncestor of binary tree

/*
 * Note:
 * Distance between two nodes is:
 *  The distance from n1 to n2 = distance from the root to n1
 *  				+ distance from the root to n2 -
 *  				2 x distance from the root to their lowest common ancestor
 *
 */

#include<iostream>
#include <stdio.h>

using namespace std;

struct Node{
	int data;
	Node *right,*left;
	Node(int d):data(d),right(NULL),left(NULL){
	}
};

/* O(h) complexity
 * LCA is root when its value is in between n1 and n2
 * else if root is greater than both n2 and n1 then traverse left
 * else if root is lesser than both n2 and n1 then traverse right
 * For simplicity assumes that n1 < n2
 */

Node* LowestCommonAncestor_BST(Node*root, Node* n1, Node* n2)
{

	if (root == NULL || n1==NULL || n2 == NULL) return NULL;
	if (n2->data < n1->data) {
		Node * temp =  n1;
		n1 = n2;
		n2 = temp;
	}
	if (root->data>=n1->data && root->data<=n2->data)
	{
		return root;
	}
	else if (root->data >= n1->data && root->data >= n2->data)
	{
		return LowestCommonAncestor_BST(root->left,n1,n2);
	}
	else if (root->data <= n1->data && root->data <= n2->data)
	{
		return	LowestCommonAncestor_BST(root->right,n1,n2);
	}
	else return NULL;
}


/* Driver program to test lca() */
int main()
{
    // Let us construct the BST shown in the above figure
    Node *root        = new Node(20);
    root->left               = new Node(8);
    root->right              = new Node(22);
    root->left->left         = new Node(4);
    root->left->right        = new Node(12);
    root->left->right->left  = new Node(10);
    root->left->right->right = new Node(14);

    int n1 = 10, n2 = 14;
    Node *t = LowestCommonAncestor_BST(root, root->left->right->left,  root->left->right->right);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = LowestCommonAncestor_BST(root, root->left->right->right, root->left);
    printf("LCA of %d and %d is %d \n",  root->left->right->right, root->left , t->data);

    n1 = 10, n2 = 22;
    t = LowestCommonAncestor_BST(root, root->left->right->left, root->right);
    printf("LCA of %d and %d is %d \n", root->left->right->left, root->right , t->data);


    return 0;
}
