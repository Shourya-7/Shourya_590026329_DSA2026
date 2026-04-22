#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

int hashFunction(long sap) {
    return (sap % 1000) % SIZE;
}

void insert(long sap) {
    int index = hashFunction(sap);

    if (hashTable[index] != -1) {
        printf("Collision occurred at index %d\n", index);
        return;
    }

    hashTable[index] = sap;
    printf("Inserted at index %d\n", index);
}

void search(long sap) {
    int index = hashFunction(sap);

    if (hashTable[index] == sap)
        printf("Found at index %d\n", index);
    else
        printf("Not found\n");
}

void deleteKey(long sap) {
    int index = hashFunction(sap);

    if (hashTable[index] == sap) {
        hashTable[index] = -1;
        printf("Deleted\n");
    } else {
        printf("Not found\n");
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice;
    long sap;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter SAP ID: ");
                scanf("%ld", &sap);
                insert(sap);
                break;
            case 2:
                printf("Enter SAP ID: ");
                scanf("%ld", &sap);
                deleteKey(sap);
                break;
            case 3:
                printf("Enter SAP ID: ");
                scanf("%ld", &sap);
                search(sap);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}
