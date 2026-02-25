#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    struct Node *head=NULL,*temp,*newNode;
    int arr[1000],n,i=0,j;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int k=0;k<n;k++){
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
    while(temp){
        arr[i++]=temp->data;
        temp=temp->next;
    }

    temp=head;
    j=i-1;
    while(temp){
        temp->data=arr[j--];
        temp=temp->next;
    }

    temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

    // free memory
    temp=head;
    while(temp){
        struct Node* next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}
