#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* head){
    if(head==NULL){
        printf("List empty\n");
        return;
    }
    struct Node* temp=head;
    int count=0;
    do{
        printf("%d ",temp->data);
        count++;
        temp=temp->next;
    }while(temp!=head);
    printf("\nNodes=%d\n",count);
}

int main(){
    struct Node *head=NULL,*tail=NULL,*newNode,*temp;
    int n,i;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);

        if(head==NULL){
            head=tail=newNode;
            newNode->next=head;
        }else{
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
    }

    display(head);

    // free memory (break circle first)
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
