#include "BST.h"
#include "stdlib.h"

Node *insertNode(Node **proot, int x) {// insert a node into the tree
    Node *currentNode = *proot;
    if (currentNode == NULL) {//if current node does not exist ,create a space
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        *proot = newNode;
    } else if (currentNode->key == x) {//if the input number is equal to the current node value, insert fail
        return NULL;
    } else {
        if (currentNode->key > x) {
            currentNode->left = insertNode(&currentNode->left, x);

        } else {
            currentNode->right = insertNode(&currentNode->right, x);
        }
    }
    return *proot;
}

Node *deleteNode(Node **proot, int x) {//delete a node from the BST
    if (!*proot || !findNode(*proot, x)) {//if the tree doesn't exist or the number not found
        return NULL;
    } else {
        Node *currentNode = *proot;
        Node *previousNode;
        Node *findNode;
        while (true) {//find the delete node position and the previous node of the delete one
            if (x > currentNode->key) {//if the number greater than the current node value go to its right child
                previousNode = currentNode;
                currentNode = currentNode->right;
            } else if (x < currentNode->key) {//if the number smaller than the current node value go to its left child
                previousNode = currentNode;
                currentNode = currentNode->left;
            } else {//if find the node
                findNode = currentNode;
                break;
            }
        }
        if (findNode->right == NULL) {//if the delete node don't have right child
            if (!previousNode) {//if the delete node doesn't have previous one
                *proot = findNode->left;
            } else {
                if (findNode->left == NULL) {//if the delete node don't have any child
                    if (findNode->key > previousNode->key) {
                        previousNode->right = NULL;
                    } else
                        previousNode->left = NULL;
                } else {
                    if (findNode->left->key > previousNode->key) {
                        previousNode->right = findNode->left;
                    } else {
                        previousNode->left = findNode->left;
                    }
                }
            }
            return findNode;
        } else if (findNode->left == NULL) {//if the delete node don't have left child
                if (!previousNode) {//if the delete node doesn't have previous one
                    *proot = findNode->right;
                } else {
                    if (findNode->right->key > previousNode->key) {
                        previousNode->right = findNode->right;
                    } else {
                        previousNode->left = findNode->right;
                    }
                }
            return findNode;
        } else {//if delete node have two children
            Node *tempNode = findNode;
            Node *tempPrevious = findNode;
            tempNode = tempNode->right;
            while (true) {//find the smallest one in the delete node's right subtree
                if (tempNode->left) {
                    tempPrevious = tempNode;
                    tempNode = tempNode->left;
                } else {
                    break;
                }
            }
            findNode->key = tempNode->key;//exchange the value
            tempPrevious->left = tempNode->right;
            return tempNode;
        }
    }
}

Node *findNode(Node *root, int x) {//find the position of a number
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

void destroyTree(Node *root) {//destroy the hole BST
    // insert your code here
    if (root == NULL) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}