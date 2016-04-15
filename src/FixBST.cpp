/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
int inorder_recursive1(struct node* root, int arr[], int index){
	if (root == NULL)
		return index;
	if (root->left != NULL){
		index = inorder_recursive1(root->left, arr, index);
	}
		arr[index] = root->data;
		index++;
	if (root->right != NULL)
		index = inorder_recursive1(root->right, arr, index);
		return index;
}

int count_nodes(struct node* root, int count){
	count = 1;
	if (root == NULL)
		return 0;
	else{
		count += count_nodes(root->left, count);
		count += count_nodes(root->right, count);
		return count;
	}
}
void  preorder_recursive2(struct node* root, int temp1, struct node **ptr1){
	if (root == NULL)
		return;
	if (root->data == temp1){
		printf("%d datais\n", root->data);
		//printf("temp2 %d\n", temp2);
		printf("yahoo\n");
		*ptr1 = root;
		return;
	}
	preorder_recursive2(root->left, temp1, ptr1);
	preorder_recursive2(root->right, temp1, ptr1);
}	
void fix_bst(struct node *root){
	if (root == NULL)
		return;
	int count = count_nodes(root, 1);//function to find number of nodes in bst
	printf("coutn %d\n", count);
	int *arr = (int*)malloc(sizeof(int) * count);
	int index = inorder_recursive1(root, arr, 0);
	int temp1, temp2;
	//finds the first element whose position is exchanged
	for (int i = 0; i < count; i++){
		if (arr[i] < arr[i + 1]){
			continue;
		}
		else{
			temp1 = arr[i];
			index = i;
			break;
		}
	}
	// finds the second element position
	for (int i = count - 1; i > index; i--){
		if (arr[i] > arr[i - 1])
			continue;
		else{
			temp2 = arr[i];
			break;
		}
	}
	struct node* ptr1 = NULL;
	preorder_recursive2(root, temp1, &ptr1);//function to find the position of the first swapped element
	struct node* ptr2 = NULL;
	preorder_recursive2(root, temp2, &ptr2);////function to find the position of the second swapped element
	ptr1->data = temp2;
	ptr2->data = temp1;
}
