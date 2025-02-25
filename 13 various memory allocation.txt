#include <stdio.h>
#include <stdlib.h>

void useMalloc() {
    int *ptr, n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &ptr[i]);

    printf("Stored elements are: ");
    for (i = 0; i < n; i++)
        printf("%d ", ptr[i]);

    free(ptr);
    printf("\nMemory freed successfully\n");
}

void useCalloc() {
    int *ptr, n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Allocated memory initialized to zero: ");
    for (i = 0; i < n; i++)
        printf("%d ", ptr[i]);

    free(ptr);
    printf("\nMemory freed successfully\n");
}

void useRealloc() {
    int *ptr, n, new_n, i;
    printf("Enter initial number of elements: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &ptr[i]);

    printf("Enter new size for memory reallocation: ");
    scanf("%d", &new_n);

    ptr = (int *)realloc(ptr, new_n * sizeof(int));
    if (ptr == NULL) {
        printf("Reallocation failed\n");
        return;
    }

    printf("Updated memory block: ");
    for (i = 0; i < new_n; i++)
        printf("%d ", ptr[i]);

    free(ptr);
    printf("\nMemory freed successfully\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMemory Allocation Strategies:\n");
        printf("1. malloc()\n2. calloc()\n3. realloc()\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: useMalloc(); break;
            case 2: useCalloc(); break;
            case 3: useRealloc(); break;
            case 4: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
