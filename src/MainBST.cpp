/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

int main(){
	struct node *root = NULL;
	int nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int elements = 3;
	for (int i = 0; i < 10; i++){
		root = add_node_spec(root, nums[i]);
	}
	int height = get_height(root);
	printf("height %d\n", height);
	int sum1 = get_left_subtree_sum(root);
	printf("sum %d\n", sum1);
	int sum = get_right_subtree_sum(root);
	printf("sum %d\n", sum);
	//int result[3];
	/*postorder(root, result);
	for (int i = 0; i < 3; i++)
		printf("%d->\n", result[i]);
	preorder(root, result);
	for (int i = 0; i < 3; i++)
		printf("%d->\n", result[i]);
	postorder(root, result);
	for (int i = 0; i < 3; i++)
		printf("%d->\n", result[i]);*/
	//Use it for testing ,Creating BST etc
}
