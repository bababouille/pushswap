#include "pushswap.h"
#include <limits.h>

int minimum(int a, int b) 
{
    return (a < b) ? 0 : 1;
}

int checkforboth(stack *A, stack *B, int a, int b)
{
    
    a = minimum(a, A->number - a) == 0 ? a : A->number - a;
    b = minimum(b, B->number - b) == 0 ? b : B->number - b;
    int x;
   
    if((minimum(a, A->number - a) == 0) && (minimum(b, B->number - b) == 0))
    {
        int x = 0;
        while (x < a && x < b) 
        {
            rotateboth(A, B);
            x++;
        }
        return x;
    }
     else if ((minimum(a, A->number - a) == 1) && (minimum(b, B->number - b) == 1))
    {
        x = 0;
        while(x < (A->number - a) && x < (B->number - b) ) 
        {
            reverseboth(A, B);
            x++;
        }
        return x;
    }
    return 0;
}

// int check(stack *A, stack *B)
// {
//   node *temp = A->head;
//     int best_index = -1;
//     int best_value = INT_MAX;
//     int index = 0;

//     while (temp != NULL) 
//     {
//         int moves_A = minimum(index, A->number - index) == 0 ? index : A->number - index;
//         int moves_B = 0;
//         node *temp2 = B->head;
        
//         while (temp2 != NULL && temp->data > temp2->data) {
//             moves_B++;
//             temp2 = temp2->next;
//         }
//         moves_B = minimum(moves_B, B->number - moves_B) == 0 ? moves_B : B->number - moves_B;

//         int value = moves_A + moves_B;
//         if (value < best_value)
//         {
//             best_value = value;
//             best_index = index;
//         }
//         index++;
//         temp = temp->next;
//     }
//     return best_index;
// }
int get_index_B(stack *A, stack *B, int a)
{
    node *temp = A->head;
    node *tempb = B->head;
    // printf("+++++++++++++++++START START START++++++++++++++++++++\n\n\n\n\n\n");
    // printf("A->HEAD->DATA IS %d B->HEAD->DATA IS %d\n", A->head->data, B->head->data);
    int indexb = 0;
    // int indexa = a;
    //a = index a
    while(a > 0)
    {
        temp = temp->next;
        a--;
    }

    while (tempb != NULL && (temp->data < tempb->data))
    {
        tempb = tempb->next;
        indexb++;
       
    }
    // printf("--------------A LIST--------------\n");
    // printlist(A);
    // printf("--------------B LIST--------------\n");
    // printlist(B);
    // printf("A->NUMBER = %d B->number = %d\n", A->number, B->number);
    // printf("A INDEX IS %d B INDEX IS %d\n", indexa, indexb);
    if(tempb)
    {
    // printf("TEMP A DATA IS %d TEMP B DATA IS %d\n", temp->data, tempb->data);
    }
    return indexb;
    // printf("--------------A LIST--------------\n");
    // printlist(A);
    // printf("--------------B LIST--------------\n");
    // printlist(B);
    // printf("+++++++++++++++++END END END++++++++++++++++++++\n");
}
int check_MAX_B(stack *B)
{

}
int get_index_A(stack *A, stack *B) 
{
    node *temp = A->head;
    int best_index = -1;
    int best_value = INT_MAX;
    int index = 0;
    // int checkinferior = 0;

    while (temp != NULL) 
    {
        int moves_A = minimum(index, A->number - index) == 0 ? index : A->number - index;
        int moves_B = 0;
        node *temp2 = B->head;
        
        while (temp2 != NULL && temp->data < temp2->data) 
        {
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
    // checkinferior = check(A, B);
    // if(checkinferior < best_index)
    // {
    //     return checkinferior;
    // }
    // printf("WHATS MY INDEX FOR A %d\n", best_index);
    return best_index;
}

void align_stack_a(stack *A, int indexA) 
{
    if (minimum(indexA, A->number - indexA) == 0) 
    {
        int i= 0;
        while (i < indexA) 
        {
            rotate(A);
            i++;
        }
    } 
    else 
    {
        int i = 0;
        while(i < (A->number - indexA)) 
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
    int indexA = get_index_A(A, B);
    int indexB = get_index_B(A, B, indexA);
    int check = 0;
    // printf("OUTHERE BITCH A%d\n", indexA);
    // printf("OUTHERE BITCH B%d\n", indexB);
    check = checkforboth(A, B, indexA, indexB);
    
    indexA = indexA - check;
    indexB = indexB - check;

    align_stack_a(A, indexA);
    printf("B INDEX IS BEFORE ALLIGN %d\n", indexB);
    printf("CHECK FOR B IS %d\n", check);
    align_stack_b(B, indexB);

    pushb(A, B);

    printf("--------------A LIST--------------\n");
    printlist(A);
    printf("--------------B LIST--------------\n");
    printlist(B);
    printf("B->number = %d\n", B->number);
    printf("B INDEX IS %d\n", indexB);
    printf("CHECK FOR B AFTER IS %d\n", check);
    // indexA = indexA + check;
    // indexB = indexB + check;
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
    
    int i = argc - 1;
    while (i >= 1) 
    {
        push(atoi(argv[i]), A);
        i--;
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
