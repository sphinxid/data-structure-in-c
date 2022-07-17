#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void preorder(struct node* root)
{
    if(root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

void postorder(struct node* root)
{
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int search(struct node* root, int num)
{
    if(root != NULL) {
        if (num == root->key) {
            return 1;
        }
        if (num < root->key) {
            return search(root->left, num);
        }
        if (num > root->key) {
            return search(root->right, num);
        }
    }

    return 0;
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
	struct node* root = NULL;
    int i, len, num;
    int data[] = {13, 27, 83, 67, 1, 90, 37, 40, 62, 102, 53, 72, 34, 21, 20};
    
    num = 40;

    len = sizeof(data)/sizeof(data[0]);
    for(i=0;i<len;i++) {
        if(i==0) {
            root = insert(root, data[i]);
        }
        else {
            insert(root, data[i]);
        }
    }
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
	inorder(root);
    printf("\n");

    printf("Postorder: ");
	postorder(root);
    printf("\n");

    if (search(root, num) != 0 ) {
        printf("%d is found on the binary search tree\n", num);
    } else {
        printf("%d is NOT found on the binary search tree\n", num);
    }

	return 0;
}
