/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int count_nodes1(struct node* root, int count){
	count = 1;
	if (root == NULL)
		return 0;
	else{
		count += count_nodes1(root->left, count);
		count += count_nodes1(root->right, count);
		return count;
	}
}
int height1(struct node* root){
	if (root == NULL)
		return 0;
	else{
		int h1 = height1(root->left);
		int h2 = height1(root->right);
		if (h1 > h2)
			return h1 + 1;
		else return h2 + 1;
	}
}
int level_order(struct node* root, int *arr, int index, int level){
	if (root == NULL)
		return index;
	if (level == 1){
		arr[index] = root->data;
		index = index + 1;
		return index;
	}
	else if (level > 1)
	{
		index = level_order(root->right, arr, index,  level - 1);
		index = level_order(root->left, arr, index, level - 1);
		return index;
	}

}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int count = count_nodes1(root, 1);//function to find number of nodes in bst
	int *arr = NULL;
	arr = (int*)malloc(sizeof(int) * count);
	int height = height1(root);//functionto find the height og sub tree

	int index = 0;
	for (int i = 1; i <= height; i++){
		index = level_order(root,arr, index, i);//level order traversal using dfs
	}
	return arr;
}
