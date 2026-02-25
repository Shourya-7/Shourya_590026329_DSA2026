#include <stdio.h>

struct S{
    int i;
    float f;
    char c;
};

union U{
    int i;
    float f;
    char c;
};

int main(){
    printf("Structure size = %lu\n",sizeof(struct S));
    printf("Union size = %lu\n",sizeof(union U));
}
