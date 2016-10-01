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
#include <climits>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node *right,*left;
	Node(int d):data(d),right(NULL),left(NULL){
	}
};

//Do DFS on the tree
bool findPath(Node *root, vector<Node*>& path, int des)
{
	if (root == NULL)
		return false;

	path.push_back(root);
	if (root->data == des)
	{
		return true; //Path is found
	}
	else if (findPath(root->left,path,des) ||
			findPath(root->right,path,des)
	)
	{
		return true;
	}
	else{
		//path is not found. so pop the root
		path.pop_back();
		return false;
	}
}

/* O(n) solution. 3 traversals. 2 path vectors
 * Find the path between root to n1
 * Find the path between root to n2
 * Last common node between path is the LCA
 */
Node* LowestCommonAncestor_1(Node*root, Node* n1, Node* n2){
	if (n1 ==NULL || n2 == NULL)
	{
		cerr<<"Error the nodes are NULL";
		return NULL;
	}

	vector<Node*> path1;
	vector<Node*> path2;

	if (findPath(root,path1,n1->data) &&
			findPath(root,path2,n2->data) )
	{
		unsigned int i;
		for (i=0;i<path1.size()&&i<path2.size();i++)
			if (path1[i]->data!=path2[i]->data)
				break;
		return path1[i-1];
	}
	return NULL;
}

/* O(n) This solution does not require any additional space.
 * But ASSUMES THAT BOTH THE NODES ARE PRESENT IN THE TREE.
 *  If one key is present and other is absent, then it returns the present key as LCA.
 */

Node* LowestCommonAncestor_2(Node* root, Node* n1, Node* n2)
{
	if (root==NULL || n1 == NULL || n2 == NULL)
	{
		return NULL;
	}

	if (root->data == n1->data || root->data== n2->data)
	{
		return root;
	}

	//Search right and left nodes
	Node* left_only = LowestCommonAncestor_2(root->left,n1,n2);
	Node* right_only = LowestCommonAncestor_2(root->right,n1,n2);

	//Means n1 and n2 are found one at each branch
	if (left_only && right_only) return root;

	//Means that both n1 and n2 are found in left
	if (left_only) return left_only;

	//Means that both n2 and n1 are found at right
	if (right_only) return right_only;

	return NULL;
}


/* O(n) This solution does not require any additional space.
 * Does not assume that both nodes are present in the tree
 */

Node* LowestCommonAncestor_3(Node* root, Node* n1, Node* n2, bool& n1_present, bool& n2_present)
{
	if (root==NULL || n1 == NULL || n2 == NULL)
	{
		return NULL;
	}

	if (root->data == n1->data)
	{
		n1_present = true;
		return root;
	}
	else if (root->data== n2->data)
	{
		n2_present = true;
		return root;
	}

	//Search right and left nodes
	Node* left_only = LowestCommonAncestor_3(root->left,n1,n2,n1_present,n2_present);
	Node* right_only = LowestCommonAncestor_3(root->right,n1,n2,n1_present,n2_present);

	if (n1_present && n2_present)
	{
		//Means n1 and n2 are found one at each branch
		if (left_only && right_only) return root;

		//Means that both n1 and n2 are found in left
		if (left_only) return left_only;

		//Means that both n2 and n1 are found at right
		else return right_only;
	}

	else return NULL;
}





// Driver program to test above functions
int main()
{
	// Let us create the Binary Tree shown in above diagram.
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout << "LCA(4, 5) = " << LowestCommonAncestor_2(root, root->left->left, root->left->right)->data;
	cout << "\nLCA(4, 6) = " << LowestCommonAncestor_2(root, root->left->left, root->right->left)->data;
	cout << "\nLCA(3, 4) = " << LowestCommonAncestor_2(root, root->right, root->left->left)->data;
	cout << "\nLCA(2, 4) = " << LowestCommonAncestor_1(root, root->left, root->left->left)->data;


	bool n1_present = false;
	bool n2_present = false;
	cout << "\nLCA(4, 5) = " << LowestCommonAncestor_3(root, root->left->left, root->left->right,n1_present,n2_present)->data;
	cout << "\nLCA(4, 6) = " << LowestCommonAncestor_3(root, root->left->left, root->right->left,n1_present,n2_present)->data;
	cout << "\nLCA(3, 4) = " << LowestCommonAncestor_3(root, root->right, root->left->left,n1_present,n2_present)->data;
	cout << "\nLCA(2, 4) = " << LowestCommonAncestor_3(root, root->left, root->left->left,n1_present,n2_present)->data;


	return 0;
}
