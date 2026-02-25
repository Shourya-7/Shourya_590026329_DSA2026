#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next,*prev;
};

int main(){
    struct Node *head=NULL,*tail=NULL,*newNode,*temp;
    int n,i,count=0;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);

        if(head==NULL){
            head=tail=newNode;
            head->next=head->prev=head;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            newNode->next=head;
            head->prev=newNode;
            tail=newNode;
        }
    }

    temp=head;
    if(temp){
        do{
            printf("%d ",temp->data);
            count++;
            temp=temp->next;
        }while(temp!=head);
    }

    printf("\nNodes=%d\n",count);

    // free memory
    if(head){
        tail->next=NULL;
        temp=head;
        while(temp){
            struct Node* next=temp->next;
            free(temp);
            temp=next;
        }
    }
    return 0;
}
