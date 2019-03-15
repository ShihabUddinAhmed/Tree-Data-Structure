// first.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
struct bstNode
{
	int data;
	bstNode* left;
	bstNode* right;
};
bstNode* getNewNode(int x)
{
	bstNode* root = new bstNode;
	root->data = x;
	root->left = NULL;
	root->right = NULL;
	return root;
}
bstNode* Insert(bstNode* root, int x)
{
	if (root == NULL)
	{
		root = getNewNode(x);
	}
	else if (x <= root->data)
	{
		root->left = Insert(root->left, x);
	}
	else
	{
		root->right = Insert(root->right, x);
	}
	return root;
}
bool Search(bstNode* root, int x)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == x)
	{
		return true;
	}
	else if (x < root->data)
	{
		return Search(root->left, x);
	}
	else
	{
		return Search(root->right, x);
	}
}
int FindHigh(bstNode* root)
{
	if (root->right == NULL)
	{
		return root->data;
	}
	else
	{
		return FindHigh(root->right);
	}
}
int Height(bstNode* root)
{
	if (root == NULL)
	{
		return -1;
	}
	else
	{
		return __max(Height(root->left), Height(root->right)) + 1;
	}
}
int main()
{
	bstNode* root = NULL;
	int n, g;
	cout << "Hello Binary Search Tree!\n";
	cout << "Enter the number of ur input: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the number: ";
		cin >> g;
		root = Insert(root, g);
	}
	ZOO:cout << "Enter the number you wanna search: ";
	cin >> n;
	bool t = Search(root, n);
	if (!t)
	{
		cout << "SORRY DATA NOT FOUND!" << endl;
	}
	else
	{
		cout << "Eureka!!! Found in tree XD" << endl;
		goto ZOO;
	}
	cout << "Highest number is: " << FindHigh(root) << endl;
	cout << "Height of the tree: " << Height(root) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
