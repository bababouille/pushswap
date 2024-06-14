#include "pushswap.h"
#include <limits.h>

// Function to calculate minimum number of moves to align the stack
int minimum(int a, int b) {
    return (a < b) ? 0 : 1;
}

// Function to get the optimal index for aligning stack B
int get_optimal_index(stack *A, stack *B) {
    node *temp = A->head;
    int best_index = -1;
    int best_value = INT_MAX;
    int index = 0;

    while (temp != NULL) {
        int moves_A = minimum(index, A->number - index) == 0 ? index : A->number - index;
        int moves_B = 0;
        node *temp2 = B->head;
        
        while (temp2 != NULL && temp->data < temp2->data) {
            moves_B++;
            temp2 = temp2->next;
        }
        moves_B = minimum(moves_B, B->number - moves_B) == 0 ? moves_B : B->number - moves_B;

        int value = moves_A + moves_B;
        if (value < best_value) {
            best_value = value;
            best_index = index;
        }
     
        index++;
        temp = temp->next;
    }
    return best_index;
}

// Function to align stack A to the optimal index
void align_stack_a(stack *A, int optimal_index) {
    if (minimum(optimal_index, A->number - optimal_index) == 0) {
        for (int i = 0; i < optimal_index; i++) {
            rotate(A);
        }
    } else {
        for (int i = 0; i < (A->number - optimal_index); i++) {
            reverserotate(A);
        }
    }
}

// Function to align stack B to the optimal position
void align_stack_b(stack *B, int indexB) {
    if (minimum(indexB, B->number - indexB) == 0) {
        for (int i = 0; i < indexB; i++) {
            rotate(B);
        }
    } else {
        for (int i = 0; i < (B->number - indexB); i++) {
            reverserotate(B);
        }
    }
}

// Function to align stacks A and B
void align_stacks(stack *A, stack *B) {  
    int optimal_index = get_optimal_index(A, B);
    align_stack_a(A, optimal_index);
    
    node *tempA = A->head;
    node *tempB = B->head;
    int indexB = 0;

    while (tempB != NULL && tempB->data > tempA->data) {
        indexB++;
        tempB = tempB->next;
    }

    align_stack_b(B, indexB);
    pushb(A, B);

    if (B->head->data < B->tail->data) {
        if (indexB <= B->number / 2) {
            for (int i = 0; i < indexB; i++) {
                reverserotate(B);
            }
        } else {
            for (int i = 0; i < (B->number - indexB); i++) {
                rotate(B);
            }
        }
    }
}

int main(int argc, char **argv) {
    stack *A = malloc(sizeof(stack));
    A->head = NULL;
    A->tail = NULL;
    A->number = 0;
    strcpy(A->name, "a");

    stack *B = malloc(sizeof(stack));
    B->head = NULL;
    B->tail = NULL;
    B->number = 0;
    strcpy(B->name, "b");

    for (int i = 1; i < argc; i++) {
        push(atoi(argv[i]), A);
    }

    pushb(A, B);
    pushb(A, B);


    if (B->head->data < B->head->next->data) {
        swap(B);
    }

    while (A->head) {
        align_stacks(A, B);
    }
    
    while (B->head) {
        pusha(A, B);
    }

    printlist(A);
    printlist(B);

    free(A);
    free(B);
    return 0;
}
