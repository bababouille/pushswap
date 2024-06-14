#include "pushswap.h"
#include <limits.h>

// Returns 0 if a < b, otherwise 1
int minimum(int a, int b) 
{
    return (a < b) ? 0 : 1;
}

int flowchart(int moves_A, int moves_B)
{
    int x = 0;
    while (moves_A > x && moves_B > x)
    {
        x++;
        moves_A--;
        moves_B--;
    } 
    // printf("X + TOOOO = %d\n", x);
    x = x / 2;
    return x;
    
    }
// Rotates both stacks A and B optimally
void checkforboth(stack *A, stack *B, int i) 
{
    node *tempA = A->head;
    node *tempB = B->head;
    int indexB = 0;

    // Find the position in B where tempA->data should be inserted
    while (tempB != NULL && tempB->data > tempA->data) 
    {
        indexB++;
        tempB = tempB->next;
    }

    // Calculate the minimal rotation steps for A and B
    i = (minimum(i, A->number - i) == 0) ? i : A->number - i;
    indexB = (minimum(indexB, B->number - indexB) == 0) ? indexB : B->number - indexB;
    printf("--------------HERE----------------------\n");
    // Rotate or reverse both stacks together as much as possible
    
    if ((minimum(i, A->number - i) == 0)) 
    {
        int x = 0;
        while (x < i && x < indexB) {
            rotateboth(A, B);
            x++; 
            printf("@@@@@@@@@@@@@@@@@@@@@@HERE@@@@@@@@@@@@@@@@@@@@@\n");
              
        }
    } 
    
    if ((minimum(i, A->number - i) == 1) && (minimum(indexB, B->number - indexB) == 1))
    {
        int x = 0;
        while ((x < (A->number - i)) && (x < (B->number - indexB))) 
        {
            reverseboth(A, B);
            x++;
           printf("+++++++++++++++++++HERE+++++++++++++++++++++++\n");
        }
    }
}


int check(stack *A, stack *B) 
{
    node *temp = A->head;
    int best_index = -1;
    int best_value = INT_MAX;
    int index = 0;
    int x = 0;

    // Iterate through each element in stack A
    while (temp != NULL) {
        int moves_A = (minimum(index, A->number - index) == 0) ? index : A->number - index;
        int moves_B = 0;
        int moves_X = 0;
        node *temp2 = B->head;

        // Find the position in B where temp->data should be inserted
        while (temp2 != NULL && temp->data > temp2->data) {
            moves_B++;
            temp2 = temp2->next;
        }
        moves_X = (minimum(moves_B, B->number - moves_B) == 0) ? moves_B : B->number - moves_B;

        // Calculate total moves required
         x = flowchart(index, moves_B);
        int value = moves_A + moves_X;
        if(index == moves_A && moves_B == moves_X)
        {  
            value = value - x;
        }
        else if( index != moves_A || moves_B != moves_X)
        {
            value = value - x;
        }
      
        if (value < best_value) {
            best_value = value;
            best_index = index;
        }
        index++;
        temp = temp->next;
    }
    return best_index;
}

// Gets the optimal index considering both directions and minimal moves
int get_optimal_index(stack *A, stack *B) 
{
    node *temp = A->head;
    int best_index = -1;
    int best_value = INT_MAX;
    int index = 0;
    
    int x = 0;

    // Iterate through each element in stack A
    while (temp != NULL) {
        int moves_A = (minimum(index, A->number - index) == 0) ? index : A->number - index;
        int moves_B = 0;
        int indexB = 0;
        node *temp2 = B->head;

        // Find the position in B where temp->data should be inserted
        while (temp2 != NULL && temp->data < temp2->data) 
        {
            moves_B++;
            temp2 = temp2->next;
            indexB++;
        }
        moves_B = (minimum(moves_B, B->number - moves_B) == 0) ? moves_B : B->number - moves_B;

        // Calculate total moves required
        //check if they both flow to the same direction
        // printf("..........A LIST..........\n");
        // printlist(A);
        // printf("..........B LIST..........\n");
        // printlist(B);
        // printf("AT INDEX NUMBER %d FROM %d NUMBERS ||| THE MOVES ON AAAAAAAAAAAAAAAAAAA = %d\n", index, A->number, moves_A);
        // printf("AT INDEX NUMBER %d FROM %d NUMBERS ||| THE MOVES ON BBBBBBBBBBBBBBBBBBB = %d\n", indexB, B->number, moves_B);
    
        x = flowchart(moves_A, moves_B);
        int value = moves_A + moves_B;
        value = value - x;
        if (value < best_value) {
            best_value = value;
            best_index = index;
        }
        
        index++;
        temp = temp->next;
    }
    printf("THE BEST INDEX A CHOSEN WAS %d\n", best_index);
    // Compare with result from check function
    int check_inferior = check(A, B);
    if (check_inferior < best_index) 
    {
        return check_inferior; 
    }
    return best_index;
}

   

// Align stack A to the optimal index
void align_stack_a(stack *A, int optimal_index) 
{
    if (minimum(optimal_index, A->number - optimal_index) == 0) 
    {
        int i = 0;
        while (i < optimal_index) {
            rotate(A);
            i++;
            printf("&&&&&&&&&&&&&&&&&&&&&&&&HERE&&&&&&&&&&&&&&&&&&&&&&&\n");
        }
    } else {
        int i = 0;
        while (i < (A->number - optimal_index)) {
            reverserotate(A);
            i++;
            printf("&&&&&&&&&&&&&&&&&&&&&&&&HERE&&&&&&&&&&&&&&&&&&&&&&&\n");
        }
    }
}

// Align stack B to the optimal index
void align_stack_b(stack *B, int indexB) 
{
    if (minimum(indexB, B->number - indexB) == 0) 
    {
        int i = 0;
        while (i < indexB) 
        {
            rotate(B);
            i++;
        }
    } 
    else 
    {
        int i = 0;
        while (i < (B->number - indexB)) 
        {
            reverserotate(B);
            i++;
        }
    }
}

// Align both stacks and push the top of stack A to stack B
void align_stacks(stack *A, stack *B) 
{
    int optimal_index = get_optimal_index(A, B);
  
    checkforboth(A, B, optimal_index);
    align_stack_a(A, optimal_index);

    node *tempA = A->head;
    node *tempB = B->head;
    int indexB = 0;

    // Find the position in B where tempA->data should be inserted
    while (tempB != NULL && tempB->data > tempA->data) 
    {
        indexB++;
        tempB = tempB->next;
    }

    align_stack_b(B, indexB);
    pushb(A, B);

    // Correct B if necessary
    if (B->head->data < B->tail->data) 
    {
        if (indexB <= B->number / 2) 
        {
            int i = 0;
            while (i < indexB) 
            {
                reverserotate(B);
                i++;
            }
        } 
        else 
        {
            int i = 0;
            while (i < (B->number - indexB)) 
            {
                rotate(B);
                i++;
            }
        }
    }
}


int main(int argc, char **argv) 
{
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
    
    int i = 1;
    while (i < argc) 
    {
        push(atoi(argv[i]), A);
        i++;
    }

    pushb(A, B);
    pushb(A, B);


    if (B->head->data < B->head->next->data) 
    {
        swap(B);
    }

    while (A->head) 
    {
        align_stacks(A, B);
    }
    
    while (B->head) 
    {
        pusha(A, B);
    }

    printlist(A);
    printlist(B);

    free(A);
    free(B);
    return 0;
}
