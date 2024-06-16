#include "pushswap.h"
#include <limits.h>
// make function that checks wich best index in a stack has the lowest value to exchange with b
// keep in mind the best value = index A + index B unless they rotate the same way
// also we
int check_for_rotations(stack *A, stack *B, int index_a, int index_b)
{
    int x = 0;
    int y = 0;

    if((index_a < A->number / 2) && (index_b < B->number / 2))
    {
        while(index_a > x && index_b > x)
        {
            x++;
        }
        return x;
    }
    else if((index_a > A->number / 2) && (index_b > B->number / 2))
    {
        while(index_a > x && index_b > x)
        {
            y++;
        }
        return y;
    }
    return 0;
}
void best_index_B(stack *B, int x)
{
    B->best_index = x;
}

void rotate_both(stack *A, stack *B, int a)
{
    int x = 0;
    int b = B->best_index;
    if(a < A->number / 2 && b < B->number / 2)
    {   
        while(a > x && b > x)
        {
            rotateboth(A, B);
            x++;
        }
        
    }
    else if (a > A->number / 2 && b > B->number / 2)
    {
        while(a > x && b > x)
        {
            reverseboth(A, B);
            x++;
        }
    }
}

int index_A_for_B_rotate(stack *A, stack *B)
{
    node *a = A->head;
    node *b = B->head;
    int index_a = 0;
    int best_index_a = 0;
    int index_b;
    int best_index_b = 0;
    int value = 0;
    int best_value = INT_MAX;
    int rotations = 0;
    int number_B = B->number;
    int half_number_B = number_B / 2;

    while (a != NULL)
    {
        index_b = 0;
        while(b != NULL && half_number_B <= number_B && a->data < b->data)
        {
            index_b++;
            half_number_B++;
            b = b->next;
            
        }
        rotations = check_for_rotations(A, B, index_a, index_b); 
        value = (index_a + index_b) - rotations;
       
        if(value < best_value)
        {
            best_value = value;
            best_index_a = index_a;
            best_index_b = index_b;
        }
        a = a->next;
        number_B++;
        index_a++;
    }
    best_index_B(B, best_index_b);
    printf("WHAT IS INDEX A %d\n", best_index_a);
    return best_index_a;
}

int index_A_for_B_reverse(stack *A, stack *B)
{
    node *a = A->head;

    int index_a = 0;
    int best_index_a = 0;
    int index_b = 0;
    int best_index_b = 0;
    int value = 0;
    int best_value = INT_MAX;
    int rotations = 0;
    int number_b = B->number;
    int half_number_b = number_b / 2;
    
    while (a != NULL)
    {
        node *b = B->head;
        index_b = 0;
        while(b != NULL && index_b <= half_number_b)
        {
            b = b->next;
            index_b++;
        }
        index_b = number_b - index_b;     
        while(b != NULL && a->data < b->data)
        {
            index_b--;
            b = b->next;
        }
        rotations = check_for_rotations(A, B, index_a, index_b); 
        value = (index_a + index_b) - rotations;

        if(value < best_value)
        {
            best_value = value;
            best_index_a = index_a;
            best_index_b = index_b;
        }
        a = a->next;
        index_a++;
    }
    best_index_B(B, best_index_b);
    printf("WHAT IS INDEX A %d\n", best_index_a);
    return best_index_a;
}

int index_for_A(stack *A, stack *B)
{
    int index_one = index_A_for_B_rotate(A, B);
    int index_two = index_A_for_B_reverse(A, B);
    if (index_one > index_two)
    {
        return index_two;
    }
    return index_one;
}
void sort(stack *A, stack *B)
{
    int index_A = index_for_A(A, B);
    printf("WHAT IS INDEX A %d\n", index_A);
    rotate_both(A, B, index_A);
    rotate_A();
    rotate_B();
    
    pushb(A, B);

    // best_value();
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
    B->best_index = 0;
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
        sort(A, B);
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
