#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev,*next;
};

int main(){
    struct Node *head=NULL,*temp,*newNode;
    int n,i,count=0;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        newNode->prev=NULL;

        if(head==NULL) head=temp=newNode;
        else{
            temp->next=newNode;
            newNode->prev=temp;
            temp=newNode;
        }
    }

    temp=head;
    printf("Forward: ");
    while(temp){
        printf("%d ",temp->data);
        count++;
        if(temp->next==NULL) break;
        temp=temp->next;
    }

    printf("\nBackward: ");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->prev;
    }

    printf("\nCount=%d\n",count);

    // free memory
    temp=head;
    while(temp){
        struct Node* next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}
