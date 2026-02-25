#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct Node *head=NULL,*temp,*prev,*newNode;
    int n,i,ch,val;

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

    printf("1.Delete Beginning 2.Delete End 3.Delete After Value\n");
    scanf("%d",&ch);

    if(head==NULL){
        printf("List is empty\n");
        return 0;
    }

    if(ch==1){
        temp=head;
        head=head->next;
        free(temp);
    }
    else if(ch==2){
        if(head->next==NULL){
            free(head);
            head=NULL;
        } else {
            temp=head;
            while(temp->next){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            free(temp);
        }
    }
    else if(ch==3){
        printf("Enter value: ");
        scanf("%d",&val);
        temp=head;
        while(temp && temp->data!=val)
            temp=temp->next;
        if(temp && temp->next){
            struct Node* del=temp->next;
            temp->next=del->next;
            free(del);
        } else {
            printf("Deletion not possible\n");
        }
    }

    display(head);

    // free memory
    temp=head;
    while(temp){
        struct Node* next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}
