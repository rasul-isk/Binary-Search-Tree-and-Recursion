// C++ program for different tree traversals
#include <iostream>
#include <string.h>

using namespace std;

string path = "";
bool firstTime = true;
bool found = false;
int indexNode = 0;
int countTree = 0;

// A binary tree node has data, pointer to left child and a pointer to right child
struct Node {
	int data;
	struct Node* left, * right;
};

//Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node* TEMP = newNode('a');

void lowestLeaf(struct Node* node)
{
	if (node == NULL)
		return;

	if (node->left == NULL && node->right == NULL)
	{
		if (firstTime)
		{
			firstTime = false;
			TEMP = node;
		}
		else if (node->data < TEMP->data)
		{
			TEMP = node;
		}
		return;
	}
	lowestLeaf(node->left);
	lowestLeaf(node->right);
}


void printInorder(struct Node* node)
{
	if (node == NULL)
		return;


	printInorder(node->left);
	cout << node->data << "\n";
	printInorder(node->right);
}


void counter(struct Node* node)
{
	if (node == NULL)
		return;

	countTree++;
	counter(node->left);
	counter(node->right);
}

void medianFind(struct Node* node)
{
	if (node == NULL)
		return;

	medianFind(node->left);
	if (countTree / 2 == indexNode)
	{
		TEMP = node;
	}
	indexNode++;
	medianFind(node->right);
}

void findNode(struct Node* node, char search) //STRING STRING STRING STRING
{
	if (node == NULL)
		return;

	if (node->data == search)
	{
		found = true;
		return;
	}

	if (search < node->data && !found)
	{
		path += "left ";
		findNode(node->left, search);
	}

	if (search > node->data && !found)
	{
		path += "right ";
		findNode(node->right, search);
	}

	return;
}


int main()
{
	struct Node* root = newNode('F');
	root->left = newNode('D');
	root->right = newNode('R');
	root->left->left = newNode('A');
	root->left->left->right = newNode('C');
	root->left->right = newNode('E');
	root->right->left = newNode('K');
	root->right->left->right = newNode('N');
	root->right->right = newNode('S');

	lowestLeaf(root);

	cout << "Lowest Leaf" << TEMP->data << endl << endl;

	printInorder(root);

	cout << endl << endl;

	medianFind(root);

	cout << endl << endl;

	findNode(root, 'E');

	if (found && path != "")
		cout << "Name is found. Path: " << path;
	else if (found)
		cout << "Name is found. It is root node.";
	else
		cout << "Not found :(";

	cout << endl << endl;

	return 0;
}
