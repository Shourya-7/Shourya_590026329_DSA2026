#include <stdio.h>

int main() {
    long sap;
    int family;

    printf("Enter SAP ID: ");
    scanf("%ld", &sap);

    int last3 = sap % 1000;
    family = last3 % 10;

    printf("SAP ID %ld belongs to family %d\n", sap, family);

    return 0;
}
