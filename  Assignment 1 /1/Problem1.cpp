#include "list.h"
#include <stdio.h>
#include<stdlib.h>

bool IsEmpty(Node *head) {
    if (head) {//check the whether the list is empty
        return false;
    } else return true;
}

Node *InsertNode(Node **phead, int index, double x) {//insert a element into an array list
    if (index < 0) return 0;
    int currIndex = 1;
    Node *currNode = *phead;
    while (currNode && index > currIndex) {//find the relation of index and current node
        currNode = currNode->next;
        currIndex++;
    }
    if (index > 0 && currNode == 0) return 0;//if the index greater than zero and the list isn't exist
    Node *newNode = (Node *) malloc(sizeof(Node));//create a memory space to store data
    newNode->data = x;
    if (index == 0) {
        newNode->next = *phead;
        *phead = newNode;
    } else {
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return newNode;
}

int FindNode(Node *head, double x) {//find a element in the the index which value is x
    if (IsEmpty(head)) {
        return 0;
    } else {
        int index = 1;
        Node *currentNode = head;
        while (currentNode) {
            if (currentNode->data == x) {
                return index;
            }
            currentNode = currentNode->next;
            index++;
        }
        return 0;
    }
}

int DeleteNode(Node **phead, double x) {//delete a element in the list
    if (IsEmpty(*phead)) {//check if the list is exist
        return 0;
    } else {
        Node *currentNode = *phead;
        int index = 1;
        while (currentNode) {
            if (currentNode->data == x &&
                currentNode == *phead) {//if the delete element is allocated in the head of the array list
                *phead = currentNode->next;
                free(currentNode);
                return index;
            } else if (currentNode->next->data == x) {
                Node *free_space;//the space to store the element that needs to be deleted
                free_space = currentNode->next;
                currentNode->next = currentNode->next->next;
                free(free_space);
                return (index + 1);
            }
            currentNode = currentNode->next;
            index++;
        }
    }

}

void DisplayList(Node *head) {//display the list
    if (IsEmpty(head)) {
        printf("The list isn't exist\n");
    } else {
        Node *currentNode = head;
        int index = 1;
        while (currentNode) {// if current node exist
            printf("index = %d--data = %lf \n", index, currentNode->data);
            currentNode = currentNode->next;
            index++;
        }
    }
}

void DestroyList(Node *head) {//destroy the whole the list
    if (IsEmpty(head)) {
        printf("The list isn't exist\n");
    } else {
        Node *free_space;
        while (head != NULL) {// if the list still has element delete one by one
            free_space = head;
            head = head->next;
            free(free_space);
        }
        free(head);
    }
}
void InverseNodes(Node** phead){//function to reverse a array list
    if(IsEmpty(*phead)){//if the list is empty do nothing
    }
    else{
        Node *node_front = *phead;
        Node *node_tail;
        int len = 0;
        while(node_front){//get the length of the list
            node_front = node_front -> next;
            len++;
        }
        node_front = *phead;//current front node point to the front of the list and move towards the tail
        for(int i = 1;i<=len;i++){
            node_tail = node_front;//current tail point to the tail of the list and move towards the front
            if(i > len/2)//if i is greater than the half length of the list it means inverse is done
                break;
            for(int j = i;j <= len - i;j++){//loop to find the tail
                node_tail = node_tail->next;
            }
            //to exchange the values between node_front and node_tail
            double temp = node_front->data;
            node_front->data = node_tail->data;
            node_tail->data = temp;
            node_front = node_front->next;

        }
    }
}

void RemoveDuplicates(Node** phead){//remove duplicates in the list
    if(IsEmpty(*phead)){//if the list is empty do nothing
    }
    else{
        Node *current_node = *phead;//the current node
        Node *moving_point;// the point moving from the next node of the current node to the end
        Node *previous_point = NULL;//the previous current node

        while(current_node){//loop to remove duplicates
            int range = 0;//range between duplicates and distinct values
            moving_point = current_node -> next;
            while(true){//find if the current node is duplicate
                range++;
                if( moving_point == NULL||moving_point->data != current_node->data)
                    break;
                moving_point = moving_point->next;
            }
            if(range <= 1){//if the range is smaller than 1 it means the next node is different form the current node
                previous_point = current_node;
                current_node = current_node->next;

            }
            else{//if the range is greater than 1 it means there are duplicates
                if(current_node == *phead){//if the duplicates are start at the head of the list, it need to change the *phead
                    current_node  = moving_point;
                    *phead = current_node;
                }
                else{//if the duplicates is in the list
                    previous_point -> next = moving_point;
                    current_node = moving_point;
                }
            }

        }
    }

}
int main() {
    Node *head = 0;
    for (int i = 0; i < 5; i++)
        InsertNode(&head, i, i);
    DisplayList(head);
    printf("\nreverse the list\n");
    InverseNodes(&head);//inverse the array list
    DisplayList(head);


    //insert two 0 at tail of the list
    printf("\n\ninsert two 0 at tail of the list\n");
    InsertNode(&head,5,0);
    InsertNode(&head,6,0);
    DisplayList(head);
    RemoveDuplicates(&head);//remove duplicates
    printf("remove duplicates\n");
    DisplayList(head);


    //insert four 4 at the front of the list
    printf("\n\ninsert four 4 at the front of the list\n");
    for(int i = 0;i<4;i++){
        InsertNode(&head,0,4);
    }
    DisplayList(head);
    RemoveDuplicates(&head);//remove duplicates
    printf("remove duplicates\n");
    DisplayList(head);

    //insert three 7 in the list
    printf("\n\ninsert three 7 in the list\n");
    for(int i =1;i<4;i++){
        InsertNode(&head,i,7);
    }
    DisplayList(head);
    RemoveDuplicates(&head);//remove duplicates
    printf("remove duplicates\n");
    DisplayList(head);
    printf("\nrepeat each value in the list once\n");
    InsertNode(&head,1,3);
    InsertNode(&head,3,2);
    InsertNode(&head,4,1);
    DisplayList(head);
    RemoveDuplicates(&head);
    printf("remove duplicates\n");
    DisplayList(head);
    printf("\n");
    for (int i = 0; i < 5; i++)
        InsertNode(&head, 0, i);
    DisplayList(head);
    for (int i = 0; i < 7; i += 2) {
        int idx = FindNode(head, i);
        if (idx > 0)
            printf("%d is at position %d.\n", i, idx);
        else
            printf("%d is not in the list.\n", i);
    }
    DeleteNode(&head, 0);
    DisplayList(head);
    DestroyList(head);
}  