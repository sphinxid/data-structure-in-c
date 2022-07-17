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

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minValueNode(root->right);

        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
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

    if (search(root, num) != 0 ) {
        printf("%d is found on the binary search tree\n", num);
    } else {
        printf("%d is NOT found on the binary search tree\n", num);
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

    deleteNode(root, num);

    if (search(root, num) != 0 ) {
        printf("%d is found on the binary search tree\n", num);
    } else {
        printf("%d is NOT found on the binary search tree\n", num);
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
    
	return 0;
}
