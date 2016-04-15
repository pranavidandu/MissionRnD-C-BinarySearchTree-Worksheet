/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder_recursive(struct node *root, int *arr, int index){
	if (root->left != NULL){
		inorder_recursive(root->left, arr, index);
		index++;
	}
	arr[index] = root->data;
	index++;
	if (root->right != NULL){
		inorder_recursive(root->right, arr, index);
	}
	
	return;
}
void preorder_recursive(struct node *root, int *arr, int index){
	arr[index] = root->data;
	index++;
	if (root->left != NULL){
		preorder_recursive(root->left, arr, index);
	}
	index++;
	if (root->right != NULL){
		preorder_recursive(root->right, arr, index);
	}
	return;
}
void postorder_recursive(struct node *root, int *arr, int index){
	if (root->left != NULL){
		postorder_recursive(root->left, arr, index);
		index++;
	}
	if (root->right != NULL){
		postorder_recursive(root->right, arr, index);
		index++;
	}
	arr[index] = root->data;
	index++;
	return;
}
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	//int index = 0;
	inorder_recursive(root, arr, 0);
	return;
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	//int index = 0;
	preorder_recursive(root, arr, 0);
	return;
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	//int index = 0;
	postorder_recursive(root, arr, 0);
	return;
}

