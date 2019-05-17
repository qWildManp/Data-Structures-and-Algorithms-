#include "AVL.h"
#include "stdlib.h"
#include "stdio.h"

Node* pareantNode;

int height(Node ** proot){
    if((*proot)==NULL){
        return 0;
    }
    else
        return (*proot)->height;
}
void updateHeight(Node ** proot){
    if(*proot !=  NULL){
        if(!(*proot)->left&&!(*proot)->right)
            (*proot)->height = 0;
        else
            (*proot)->height = height(&(*proot)->left) > height(&(*proot)->right) ?(*proot)->height=height(&(*proot)->left)+1:(*proot)->height = height(&(*proot)->right)+1;
    }
}
void leftRotation(Node* root){
    Node* k2 = root;
    Node* k1 = k2->right;
    Node* temp = k1->left;
    root = k1;
    root->left = k2;
    k2->right = temp;
    updateHeight(&root->left);
    updateHeight(&root);
}
void rightRotation(Node* root){
    Node* k2 = root;
    Node* k1 = k2->left;
    Node* temp = k1->right;
    root = k1;
    root->right = k2;
    k2->left = temp;
    updateHeight(&root->right);
    updateHeight(&root);
}

int isBalanced(Node ** proot){
    if((*proot)!=NULL){
    if((*proot)->left == NULL && height(proot)==2){
        if((*proot)->right->right != NULL)
            return 2;
        else
            return 4;
    }
    if((*proot)->right == NULL && height(proot)==2){
        if((*proot)->left->left!=NULL)
            return 1;
        else
            return 3;
    }
    if(height(&(*proot)->left)-height(&(*proot)->right) > 1){
        if((*proot)->left->left!=NULL){
            return 1;
        }
        else
            return 3;
    }
    else if(height(&(*proot)->right)-height(&(*proot)->left) > 1){
        if((*proot)->right->right!=NULL){
            return 2;
        }
        else
            return 4;
    }
    return 0;
    }
}
void rebalanced(Node ** proot){
    switch(isBalanced(proot)){
        case  1://left left heavy
            rightRotation(*(proot));
        case  2://right right heavy
            rightRotation(*(proot));
        case  3://left right heavy
             leftRotation((*proot)->left);
             rightRotation(*proot);
        case  4://right left heavy
            rightRotation((*proot)->right);
            leftRotation(*proot);
        default:
            return ;
    }
}
Node* insertNode(Node **proot, int x){
        Node* newNode;
        if((*proot)==NULL){
            newNode = (Node*)malloc(sizeof(Node));
            newNode->key = x;
            newNode->height = 0;
            newNode->left = NULL;
            newNode->right = NULL;
            *proot = newNode;
            return *proot;
        }
        else if((*proot)->key == x){
            return NULL;
        }
        else {
            if ((*proot)->key > x) {
                newNode = insertNode(&(*proot)->left, x);
            } else {
                newNode = insertNode(&(*proot)->right, x);
            }
        }
        updateHeight(proot);
        rebalanced(proot);
        return newNode;
}
Node* deleteMin(Node** proot){
    Node * minNode;
    if((*proot)->left==NULL) {
        minNode = (*proot);
        *proot = (*proot)->right;
        return minNode;
    }
    minNode = deleteMin(&(*proot)->left);
    updateHeight(proot);
    rebalanced(proot);
    return minNode;
}
Node* deleteRoot(Node** proot){
    Node* temp = (*proot);
    Node* currNode = temp;
    if(currNode->left == NULL){
        *proot = (*proot)->right;
        return currNode;
    }
    if(currNode->right == NULL){
        *proot = (*proot)->left;
        return currNode;
    }

    Node * minNode = deleteMin(&(*proot)->right);
    minNode->left = (*proot)->left;
    minNode->right = (*proot)->right;
    *proot = minNode;
    return currNode;
}
Node* deleteNode(Node **proot, int x){
    Node* matchNode;
    if((*proot)==NULL){
        return NULL;
    }
    if((*proot)->key > x){
        pareantNode = (*proot);
        matchNode = deleteNode(&(*proot)->left,x);
    }
    else if((*proot)->key < x){
        pareantNode = (*proot);
        matchNode = deleteNode(&(*proot)->right,x);
    }
    else
        matchNode = deleteRoot(proot);
    updateHeight(proot);
     rebalanced(proot);
    return matchNode;
}

Node* findNode(Node *root, int x){
    Node *currentNode = root;
    if (currentNode == NULL) {
        return NULL;
    } else if (currentNode->key == x) {
        return currentNode;
    } else {
        if (currentNode->key > x) {
            return findNode(currentNode->left, x);
        } else {
            return findNode(currentNode->right, x);
        }
    }
}

void destroyTree(Node *root){
    if (root == NULL) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}