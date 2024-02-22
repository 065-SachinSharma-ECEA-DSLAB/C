#include <stdio.h>
#include <stdlib.h>

void linear_search(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            printf("Element %d found at index %d.\n", element, i);
            return;
        }
    }
    printf("Element %d not found.\n", element);
}

void insert_element(int arr[], int *n, int index, int element) {
    if (index < 0 || index > *n) {
        printf("Invalid index for insertion.\n");
        return;
    }
    for (int i = *n - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    (*n)++;
}

void delete_element(int arr[], int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Invalid index for deletion.\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void reverse_array(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void update_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            arr[i] += 5;
        } else {
            arr[i] *= 2;
        }
    }
}

void print_array(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice,element,index ,n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Reverse Array\n");
        printf("5. Update Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                linear_search(arr, n, element);
                break;
            case 2:
                printf("Enter the index of array to insert element: ");
                scanf("%d", &index);
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                insert_element(arr, &n, index, element);
                break;
            case 3:
                printf("Enter the index of element to be deleted: ");
                scanf("%d", &index);
                delete_element(arr, &n, index);
                break;
            case 4:
                reverse_array(arr, n);
                break;
            case 5:
                update_array(arr, n);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
        
        if (choice >= 2 && choice <= 5) {
            printf("Array after operation: ");
            print_array(arr, n);
        }
    } while (choice != 6);

    free(arr);
    return 0;
}