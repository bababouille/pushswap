#include "pushswap.h"
#include <limits.h>

int minimum(int a, int b) {
    return (a < b) ? 0 : 1;
}

void checkforboth(stack *A, stack *B, int i)
{
    node *tempA = A->head;
    node *tempB = B->head;
    int indexB = 0;

    while (tempB != NULL && tempB->data > tempA->data) 
    {
        indexB++;
        tempB = tempB->next;
    }
    i = minimum(i, A->number - i) == 0 ? i : A->number - i;
    indexB = minimum(indexB, B->number - indexB) == 0 ? indexB : B->number - indexB;
    if((minimum(i, A->number - i) == 0) && (minimum(indexB, B->number - indexB) == 0))
    {
        int x = 0;
        while (x < i && x < indexB) 
        {
            rotateboth(A, B);
            x++;
        }
    }
     else 
    {
        int x = 0;

        while(x < (A->number - i) && x < (B->number - indexB) ) 
        {
            reverseboth(A, B);
            x++;
        }
    }
}

int check(stack *A, stack *B)
{
  node *temp = A->head;
    int best_index = -1;
    int best_value = INT_MAX;
    int index = 0;

    while (temp != NULL) 
    {
        int moves_A = minimum(index, A->number - index) == 0 ? index : A->number - index;
        int moves_B = 0;
        node *temp2 = B->head;
        
        while (temp2 != NULL && temp->data > temp2->data) {
            moves_B++;
            temp2 = temp2->next;
        }
        moves_B = minimum(moves_B, B->number - moves_B) == 0 ? moves_B : B->number - moves_B;

        int value = moves_A + moves_B;
        if (value < best_value)
        {
            best_value = value;
            best_index = index;
        }
        index++;
        temp = temp->next;
    }
    return best_index;
}
int get_optimal_index(stack *A, stack *B) 
{
    node *temp = A->head;
    int best_index = -1;
    int best_value = INT_MAX;
    int index = 0;
    int checkinferior = 0;

    while (temp != NULL) 
    {
        int moves_A = minimum(index, A->number - index) == 0 ? index : A->number - index;
        int moves_B = 0;
        node *temp2 = B->head;
        
        while (temp2 != NULL && temp->data < temp2->data) {
            moves_B++;
            temp2 = temp2->next;
        }
        moves_B = minimum(moves_B, B->number - moves_B) == 0 ? moves_B : B->number - moves_B;

        int value = moves_A + moves_B;
        if (value < best_value)
        {
            best_value = value;
            best_index = index;
        }
        index++;
        temp = temp->next;
    }
    checkinferior = check(A, B);
    if(checkinferior < best_index)
    {
        return checkinferior;
    }

    return best_index;
}

void align_stack_a(stack *A, int optimal_index) 
{
    if (minimum(optimal_index, A->number - optimal_index) == 0) 
    {
        int i= 0;
        while (i < optimal_index) 
        {
            rotate(A);
            i++;
        }
    } 
    else 
    {
        int i = 0;
        while(i < (A->number - optimal_index)) 
        {
            reverserotate(A);
            i++;
        }
    }
}

void align_stack_b(stack *B, int indexB) 
{
    if (minimum(indexB, B->number - indexB) == 0) 
    {
        int i = 0;
        while ( i < indexB)
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

void align_stacks(stack *A, stack *B) 
{  
    int optimal_index = get_optimal_index(A, B);
    checkforboth(A, B, optimal_index);
    align_stack_a(A, optimal_index);
    
    node *tempA = A->head;
    node *tempB = B->head;
    int indexB = 0;

    while (tempB != NULL && tempB->data > tempA->data) 
    {
        indexB++;
        tempB = tempB->next;
    }

    align_stack_b(B, indexB);
    pushb(A, B);

    if (B->head->data < B->tail->data) 
    {
        if (indexB <= B->number / 2) 
        {
            int i = 0;
            while ( i < indexB) 
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
