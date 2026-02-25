#include <stdio.h>
#include <stdlib.h>

struct Poly{
    int coeff,exp;
    struct Poly* next;
};

int main(){
    struct Poly *head=NULL,*temp,*newNode;
    int n,i,x,sum=0;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        newNode=(struct Poly*)malloc(sizeof(struct Poly));
        scanf("%d%d",&newNode->coeff,&newNode->exp);
        newNode->next=NULL;

        if(head==NULL) head=temp=newNode;
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    printf("Enter x: ");
    scanf("%d",&x);

    temp=head;
    while(temp){
        int p=1;
        for(i=0;i<temp->exp;i++) p*=x;
        sum+=temp->coeff*p;
        temp=temp->next;
    }

    printf("Value = %d\n",sum);

    // free memory
    temp=head;
    while(temp){
        struct Poly* next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}
