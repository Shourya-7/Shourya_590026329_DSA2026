#include <stdio.h>
#include <stdlib.h>

struct Employee{
    int id;
    char name[30];
    float salary;
};

int main(){
    int n,i,max=0;
    scanf("%d",&n);

    struct Employee *e = malloc(n*sizeof(struct Employee));

    for(i=0;i<n;i++)
        scanf("%d %s %f",&e[i].id,e[i].name,&e[i].salary);

    for(i=1;i<n;i++)
        if(e[i].salary > e[max].salary)
            max=i;

    printf("Highest Salary: %s %.2f",e[max].name,e[max].salary);

    free(e);
}
