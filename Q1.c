#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
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

        if(head==NULL) head=temp=newNode;
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    temp=head;
    printf("List: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        count++;
        temp=temp->next;
    }

    printf("\nTotal nodes = %d\n",count);

    // free memory
    temp=head;
    while(temp){
        struct Node* next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}
