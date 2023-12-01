/*

    Hey visitor ! This is code of mine that helps in finding maximum independent set in a binary tree.
    Explanation : Maximum independent set in an binary tree refers to the set (collection) that contains 
    all the nodes that are not connected directly. That is no parent-child related nodes.

    Feel free to explore the code below and Do not forget to check the explanation first at the bottom.

*/


#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int finder(struct Node* root)
{
    // base case: empty tree
    if (root == NULL) {
        return 0;
    }
 
    // Case 1: Exclude the current node from the maximum independent set and
    // recur for its left and right child
    int excl = finder(root->left) + finder(root->right);
 
    // Case 2: Include the current node in the maximum independent set and
    // recur for its grandchildren
    int incl = 1;
 
    if (root->left) {
        incl += finder(root->left->left) + finder(root->left->right);
    }
 
    if (root->right) {
        incl += finder(root->right->left) + finder(root->right->right);
    }
 
    // return the maximum number of nodes possible by either
    // including or excluding the current node
    return fmax(excl, incl);
}


void insertNode(struct Node** root, int val) {
    if (*root == NULL) {
        *root = newNode(val);
    } 
    else {
        struct Node* temp = *root;
        while (1) {
            if (val < temp->data) {
                if (temp->left == NULL) {
                    temp->left = newNode(val);
                    break;
                } 
                else{
                    temp = temp->left;
                }
            } 
            else{
                if (temp->right == NULL) {
                    temp->right = newNode(val);
                    break;
                } 
                else {
                    temp = temp->right;
                }
            }
        }
    }
}


int main() {
    struct Node* root = NULL;
    int choice, val;


    printf("\n1. Insert a node\n");
    printf("2. Print the size of maximum independent set\n");
    printf("3. Any other key to exit\n");
    
    do {
        printf("\nEnter the choice as per menu : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value of the node to insert: ");
                scanf("%d", &val);
                insertNode(&root, val);
                break;

            case 2:
                if (root == NULL) {
                    printf("Binary tree is empty. Insert nodes first.\n");
                } else {
                    int result = finder(root);
                    printf("The size of the maximum independent set is: %d\n", result);
                }
                break;

            default:
                printf("\n------ Exiting the program ------\n\n_");
                break;
        }

    } while (choice == 1 || choice == 2);

    free(root);

    return 0;
}


/*

---- Approach and Explanation ----

1. In this program, we are using structure to create nodes of binary tree.

2. In the main function you can see we run the loop with option 1 is to add a node and 2 to find the 
    maximum independent set.

3. For creation of binary tree we are using two function that insert and newNode. newNode function create
    a fresh node and put the value provided to the node's data part. whereas insert function connect the node
    to the right place in the tree. If the root is empty then, the first value will become root, and all further 
    nodes will be connected as per binary search tree insertion concept.

4. For finding the maximum independent set, we are using finder function, it takes the root as argument and calculate 
    the set size as : 
    i) if the root is null that means there is no node in binary tree so no independent set, so it returns zero.
    ii) it recursively search for left and right sub-tree in two different ways. 
    iii) In first way it includes the parent node at each stage and in second way it exclude the parent node.
    iv) and the no of recursive calls are then stored as integer in different variables incl & excl in both 
        different ways that tell us about no of edges involved that helps in finding direct connection and ultimately 
        maximum independent set.
    iv) And at last whichever gives the maximum value is the set size.

5. Hope it helps, feel free to explore the code above.

*/