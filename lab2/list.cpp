#include "list.h"
#include <stdio.h>
#include<stdlib.h>
bool IsEmpty(Node* head){
    if(head){//check the whether the list is empty
        return false;
    }
    else return true;
}
Node *InsertNode(Node** phead, int index, double x){//insert a element into an array list
    if (index < 0) return 0;
    int currIndex = 1;
    Node* currNode = *phead;
    while (currNode && index > currIndex) {//find the relation of index and current node
        currNode = currNode->next;
        currIndex ++;
    }
    if (index > 0 && currNode == 0) return 0;//if the index greater than zero and the list isn't exist
    Node* newNode = (Node*)malloc(sizeof(Node));//create a memory space to store data
    newNode->data = x;
    if (index == 0) {
        newNode->next = *phead;
        *phead = newNode;
    }
    else {
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return newNode;
}
int FindNode(Node* head, double x){//find a element in the the index which value is x
    if(IsEmpty(head)) {
        return 0;
    }
    else{
        int index = 1;
        Node* currentNode = head;
        while(currentNode){
            if(currentNode->data == x){
                return index;
            }
            currentNode = currentNode -> next;
            index++;
        }
        return 0;
    }
}
int DeleteNode(Node** phead, double x){//delete a element in the list
    if(IsEmpty(*phead)){//check if the list is exist
        return 0;
    }
    Node* currentNode = *phead;
    int index = 1;
    while(currentNode){
            if(currentNode -> data == x && currentNode == *phead){//if the delete element is allocated in the head of the array list
                *phead = currentNode -> next;
                free(currentNode);
                return index;
            }
            else if(currentNode ->next -> data == x ){
                Node* free_space;//the space to store the element that needs to be deleted
                free_space = currentNode -> next;
                currentNode -> next = currentNode -> next -> next;
                free(free_space);
                return (index+1);
            }
            currentNode = currentNode -> next;
            index++;
        }

}
void DisplayList(Node* head){//display the list
    if(IsEmpty(head)){
        printf("The list isn't exist");
    }
    Node* currentNode = head;
    int index = 1;
    while(currentNode){// if current node exist
        printf("index = %d--data = %lf \n",index,currentNode->data);
        currentNode = currentNode -> next;
        index++;
    }
}
void DestroyList(Node* head){//destroy the whole the list
    if(IsEmpty(head)){
        printf("The list isn't exist");
    }
    Node* currentNode = head;
    Node* free_space;
    while(currentNode){// if the list still has element delete one by one
        free_space = currentNode;
        currentNode = currentNode->next;
        free(free_space);
    }
}
int main()
{
    Node *head = 0;
    for(int i=0; i<5; i++)
        InsertNode(&head, i, i);
    DisplayList(head);
    for(int i=0; i<5; i++)
        InsertNode(&head, 0, i);
    DisplayList(head);
    for(int i=0; i<7; i+=2){
        int idx = FindNode(head, i);
        if(idx>0)
            printf("%d is at position %d.\n", i, idx);
        else
            printf("%d is not in the list.\n", i);
    }
    DeleteNode(&head, 0);
    DisplayList(head);
    DestroyList(head);
}  