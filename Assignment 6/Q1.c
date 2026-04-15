#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int data) {
    if(root == NULL) return create(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate not allowed\n");

    return root;
}

struct Node* findMin(struct Node* root) {
    while(root->left) root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if(root == NULL) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL && root->right == NULL)
            return NULL;
        else if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void search(struct Node* root, int key) {
    if(root == NULL) {
        printf("Not Found\n");
        return;
    }
    if(root->data == key)
        printf("Found\n");
    else if(key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

void inorder(struct Node* root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    printf("Name: Shourya Singh\n\n");

    struct Node* root = NULL;
    int n, val, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder: ");
    inorder(root);

    printf("\nEnter value to search: ");
    scanf("%d", &key);
    search(root, key);

    printf("Enter value to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("Inorder after deletion: ");
    inorder(root);

    return 0;
}
