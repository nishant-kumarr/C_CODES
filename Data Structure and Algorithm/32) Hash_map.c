/*

Hello, Visitor! Below is my code that facilitates the four functionalities < Insert, remove, search, getrandom > 
on some data using hashing in constant time complexity.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

// Hash Map to store element-index pairs
int hashMap[MAX_SIZE];
int arr[MAX_SIZE];
int size = 0;

// Function to insert an element into the array and hash map
void insert(int x) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    // Check if x is already present
    if (hashMap[x] != 0) {
        printf("%d is already present in the array.\n", x);
        return;
    }

    // Insert x at the end of the array
    arr[size] = x;

    // Add x to the hash map
    hashMap[x] = size;

    size++;
    printf("%d has been inserted.\n", x);
}

// Function to remove an element from the array and hash map
void removeElement(int x) {
    if (size <= 0) {
        printf("Array is empty. Cannot remove.\n");
        return;
    }

    // Check if x is present
    if (hashMap[x] == 0) {
        printf("%d is not present in the array.\n", x);
        return;
    }

    // Find the index of x
    int index = hashMap[x];

    // Swap x with the last element in the array
    arr[index] = arr[size - 1];
    hashMap[arr[index]] = index;

    // Remove the last element
    size--;

    // Remove x from the hash map
    hashMap[x] = 0;

    printf("%d has been removed.\n", x);
}

// Function to get a random element from the array
int getRandom() {
    if (size <= 0) {
        printf("Array is empty. Cannot get a random element.\n");
        return -1;
    }

    // Generate a random index
    int randomIndex = rand() % size;

    // Return the element at the random index
    return arr[randomIndex];
}

// Function to search for an element in the hash map
void search(int x) {
    if (hashMap[x] != 0) {
        printf("%d is present at index %d.\n", x, hashMap[x]);
    } else {
        printf("%d is not present in the array.\n", x);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int choice, x;

    printf("1. Insert an element\n");
    printf("2. Remove an element\n");
    printf("3. Get a random element\n");
    printf("4. Search for an element\n");
    printf("5. Exit\n");
    while (1) {
        printf("Choose from the options provided above. Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                printf("Enter the element to remove: ");
                scanf("%d", &x);
                removeElement(x);
                break;
            case 3:
                x = getRandom();
                if (x != -1) {
                    printf("Random element: %d\n", x);
                }
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &x);
                search(x);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
