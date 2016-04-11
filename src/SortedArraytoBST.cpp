/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include<stdio.h>
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node* convert_bbst(int *arr, int start, int end){
	if (start > end){
		return NULL;
	}
		struct node* ptr = (struct node *)malloc(sizeof(struct node));
		int mid = (start + end) / 2;
		ptr->data = arr[mid];
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->left = convert_bbst(arr, start, mid - 1);
		ptr->right = convert_bbst(arr, mid + 1, end);
		return ptr;
}
struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL)
		return NULL;
	return convert_bbst(arr, 0, len - 1);
}

