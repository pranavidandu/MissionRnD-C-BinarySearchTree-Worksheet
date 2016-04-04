/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void left_height_tree(struct node *root, int *height){
	if (root->left != NULL){
		*height = *height + 1;
		left_height_tree(root->left, height);
	}
	if (root->right != NULL){
		left_height_tree(root->right, height);
	}
	return;
}
void right_height_tree(struct node *root, int *height){
	if (root->right != NULL){
		*height = *height + 1;
		right_height_tree(root->right, height);
	}
	if (root->left != NULL){
		right_height_tree(root->left, height);
	}
	return;
}
int get_height(struct node *root){
	if (root == NULL)
		return -1;
	int height1 = 1;
	left_height_tree(root, &height1);//height of left sub tree
	int height2 = 1;
	right_height_tree(root, &height2);//height of right sub tree
	if (height1 > height2)
		return height1;
	else return height2;
}
//recursive function to get the sum of the left sub tree
int left_subtree_sum(struct node *root, int sum){
	if (root->left != NULL){
		sum += root->data;
		return(left_subtree_sum(root->left, sum));
	}
	sum += root->data;
	if (root->right != NULL){
		return(left_subtree_sum(root->right, sum));
	}
	return sum;
}
int get_left_subtree_sum(struct node *root){
	if (root == NULL)
		return -1;
	else if (root->left == NULL){
		return 0;
	}
	return left_subtree_sum(root->left, 0);
}
//recursive function to get the sum of the right sub tree
int right_subtree_sum(struct node *root, int sum){
	if (root->right != NULL){
		sum += root->data;
		return(right_subtree_sum(root->right, sum));
	}
	sum += root->data;
	if (root->left != NULL){
		return(right_subtree_sum(root->left, sum));
	}
	return sum;
}
int get_right_subtree_sum(struct node *root){
	if (root == NULL){
		return -1;
	}
	else if (root->right == NULL)
		return 0;
	return right_subtree_sum(root->right, 0);
}

