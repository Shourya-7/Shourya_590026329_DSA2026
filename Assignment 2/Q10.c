#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int roll;
    char name[30];
    float marks;
    struct Student* next;
};

void display(struct Student* head){
    while(head){
        printf("%d %s %.2f\n",head->roll,head->name,head->marks);
        head=head->next;
    }
}

int main(){
    struct Student *head=NULL,*temp,*newNode,*prev;
    int n,i,searchRoll,delRoll;

    printf("Enter number of students: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        newNode=(struct Student*)malloc(sizeof(struct Student));
        scanf("%d %s %f",&newNode->roll,newNode->name,&newNode->marks);
        newNode->next=NULL;

        if(head==NULL) head=temp=newNode;
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    printf("\nRecords:\n");
    display(head);

    printf("Enter roll to search: ");
    scanf("%d",&searchRoll);

    temp=head;
    while(temp){
        if(temp->roll==searchRoll){
            printf("Found: %s %.2f\n",temp->name,temp->marks);
            break;
        }
        temp=temp->next;
    }
    if(!temp) printf("Record not found\n");

    printf("Enter roll to delete: ");
    scanf("%d",&delRoll);

    temp=head; prev=NULL;
    while(temp && temp->roll!=delRoll){
        prev=temp;
        temp=temp->next;
    }
    if(temp){
        if(prev==NULL) head=temp->next;
        else prev->next=temp->next;
        free(temp);
        printf("Record deleted\n");
    } else {
        printf("Record not found\n");
    }

    printf("\nUpdated Records:\n");
    display(head);

    // free memory
    temp=head;
    while(temp){
        struct Student* next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}
