#include <stdio.h>
#include <stdlib.h>

struct Record{
    int data;
};

int main(){
    struct Record *r=NULL;
    int n=0,ch,i;

    while(1){
        printf("\n1.Add 2.Display 3.Delete Last 4.Exit\n");
        scanf("%d",&ch);

        if(ch==1){
            n++;
            r=realloc(r,n*sizeof(struct Record));
            scanf("%d",&r[n-1].data);
        }
        else if(ch==2){
            for(i=0;i<n;i++)
                printf("%d ",r[i].data);
        }
        else if(ch==3){
            if(n>0) n--;
            r=realloc(r,n*sizeof(struct Record));
        }
        else{
            free(r);
            break;
        }
    }
}
