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
    struct Node *head=NULL,*temp,*newNode;
    int choice,val,after;

    while(1){
        printf("\n1.Insert Beginning 2.Insert End 3.Insert After Node 4.Display 5.Exit\n");
        scanf("%d",&choice);

        if(choice==5) break;

        if(choice==4){
            display(head);
            continue;
        }

        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&val);
        newNode->data=val;
        newNode->next=NULL;

        if(choice==1){
            newNode->next=head;
            head=newNode;
        }
        else if(choice==2){
            if(head==NULL) head=newNode;
            else{
                temp=head;
                while(temp->next) temp=temp->next;
                temp->next=newNode;
            }
        }
        else if(choice==3){
            printf("Insert after value: ");
            scanf("%d",&after);
            temp=head;
            while(temp && temp->data!=after)
                temp=temp->next;
            if(temp){
                newNode->next=temp->next;
                temp->next=newNode;
            } else {
                printf("Given node not found\n");
                free(newNode);
            }
        }
        else{
            printf("Invalid choice\n");
            free(newNode);
        }
    }

    // free memory
    temp=head;
    while(temp){
        struct Node* next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}
