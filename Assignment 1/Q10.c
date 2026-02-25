#include <stdio.h>
#include <stdlib.h>

struct Student{
    int roll;
    char name[30];
    float marks;
};

int main(){
    int n,i,j;
    scanf("%d",&n);

    struct Student *s = malloc(n*sizeof(struct Student));
    struct Student temp;

    for(i=0;i<n;i++)
        scanf("%d %s %f",&s[i].roll,s[i].name,&s[i].marks);

    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(s[j].marks > s[j+1].marks){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }

    for(i=0;i<n;i++)
        printf("%d %s %.2f\n",s[i].roll,s[i].name,s[i].marks);

    free(s);
}
