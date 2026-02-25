#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[30];
    float marks;
};

int main() {
    int n,i;
    scanf("%d",&n);

    struct Student *s = malloc(n*sizeof(struct Student));

    for(i=0;i<n;i++)
        scanf("%d %s %f",&s[i].roll,s[i].name,&s[i].marks);

    for(i=0;i<n;i++)
        printf("%d %s %.2f\n",s[i].roll,s[i].name,s[i].marks);

    free(s);
}
