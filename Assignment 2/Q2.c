#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    struct Node *head=NULL,*temp,*newNode;
    int n,i,key,pos=1,found=0;

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

    printf("Enter element to search: ");
    scanf("%d",&key);

    temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            printf("Element found at position %d\n",pos);
            found=1;
            break;
        }
        temp=temp->next;
        pos++;
    }

    if(!found) printf("Element does not exist\n");

    // free memory
    temp=head;
    while(temp){
        struct Node* next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}
