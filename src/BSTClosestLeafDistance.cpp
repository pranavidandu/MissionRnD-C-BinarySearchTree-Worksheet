/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int height2(struct node* root){
	if (root == NULL)
		return 0;
	else{
		printf("%d\n", root->data);
		int h1 = height2(root->left);
		int h2 = height2(root->right);
		printf("h1 %d h2 %d\n", h1, h2);
		if (h1 < h2){
			return h2 + 1;
		}
		else return h1 + 1;
	}
}
int distance_root_to_node(struct node *root, int data, int res){
	if (root == NULL){
		return res;
	}
	if (root->data == data)
		return res;
	else if (root->data > data){
		res++;
		return distance_root_to_node(root->left, data, res);
	}
	else{
		res++;
		return distance_root_to_node(root->right, data, res);
	}
}
int minimum_distance_left_sub_tree(struct node *root){
	if (root == NULL)
		return 0;
	/*printf("%d\n", root->data);
	int h1 = height2(root->left);
	int h2 = height2(root->right);
	printf("h1 %d h2 %d\n", h1, h2);
	if (h1 < h2){
	return h2 + 1;
	}
	else return h1 + 1;*/
	else{
		int h1 = minimum_distance_left_sub_tree(root->right) + 1;
		int h2 = minimum_distance_left_sub_tree(root->left) + 1;
		if (h1 < h2)
			return h1 + 1;
		else
			return h2 + 1;
	}
}
int min(int d1, int d2){
	if (d1 > d2)
		return d2;
	else return d1;
}
int min_dept(struct node *root){
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	if (!root->left)
		return min_dept(root->right) + 1;
	if (!root->right)
		return min_dept(root->left) + 1;
	return min(min_dept(root->left), min_dept(root->right)) + 1;
}
struct node* find_parent_of_temp(struct node* root, struct node* temp){
	if (root == NULL || temp == NULL){
		return NULL;
	}
	else{
		if (root->left == temp || root->right == temp)
			return root;
		else {
			if (root->data < temp->data) {
				return find_parent_of_temp(root->right, temp);
			}
			else {
				return find_parent_of_temp(root->left, temp);
			}
		}
	}
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{ 
	if (root == NULL || temp == NULL)
	return -1;
	if (temp->left == NULL && temp->right == NULL)//if temp node is a leaf
	return 0;
	int dis = min_dept(temp);//closest leaf from temp node
	printf("dis before %d\n", dis);
	dis--;
	int dis1 = 0;
	if (temp->data > root->data){
		dis1 = min_dept(root->left);
	}
	else
		dis1 = min_dept(root->right);
	printf("dis1 %d\n", dis1);
	struct node* ptr = NULL;
	if (dis1 >= dis){
		ptr = find_parent_of_temp(root, temp);
		printf("temp-> data %d\n", ptr->data);
		int dis2 = min_dept(ptr);
		if (dis2 > dis)
			return dis;
		return dis2;
	}
	ptr = find_parent_of_temp(root, temp);
	printf("temp-> data %d\n", ptr->data);
	int dis2 = min_dept(ptr);
	if (dis1 >= dis2)
	return dis2;
	else return dis1 + 1;
}