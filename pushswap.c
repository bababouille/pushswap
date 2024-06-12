/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:06:21 by marvin            #+#    #+#             */
/*   Updated: 2024/03/08 16:06:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int minimum(int a, int b) {
    return (a < b) ? 0 : 1;
}

// Helper function to get the optimal index for aligning stack B
int get_optimal_index(stack *A, stack *B) {
    node *temp = A->head;
    int best_index = -1;
    int best_value = INT_MAX;
    int index = 0;

    while (temp != NULL) {
        int value = 0;
        int moves_A = minimum(index, A->number - index) == 0 ? index : A->number - index;
        int moves_B = 0;
        node *temp2 = B->head;
        
        // Calculate the number of moves needed in stack B
        while (temp2 != NULL && temp->data < temp2->data) {
            moves_B++;
            temp2 = temp2->next;
        }
        moves_B = minimum(moves_B, B->number - moves_B) == 0 ? moves_B : B->number - moves_B;
        moves_B = moves_B * 2;
        // Total moves to align this element
        printf("OLD VALUE = %d\n", value);
        value = moves_A + moves_B;
        printf("NEW VALUE = %d\n", value);

        if (value < best_value) {
            best_value = value;
            best_index = index;
        }
        printlist(A);
        printlist(B);
        printf("BEST VALUE%d\nMOVE A%d : MOVE B%d\nBEST INDEX%d\n", best_value,moves_A, moves_B, best_index);
        index++;
        temp = temp->next;
    }
    return best_index;
}

void align_stacks(stack *A, stack *B) {  
    node *tempA = A->head;
    int optimal_index = get_optimal_index(A, B);

    // Move tempA to the optimal index using a while loop
    int i = 0;
    while (i < optimal_index) 
    {
        tempA = tempA->next;
        i++;
    }
    // Align stack A
    if (minimum(optimal_index, A->number - optimal_index) == 0) 
    {
        i = 0;
        while (i < optimal_index) 
        {
            rotate(A);
            i++;
        }
    } 
    else 
    {
        i = 0;
        while (i < (A->number - optimal_index)) 
        {
            reverserotate(A);
            i++;
        }
    }
    // Align stack B
    node *tempB = B->head;
    int indexB = 0;
    
    printf("tempA DATA ID = %d\n", tempA->data);
    printlist(A);

    while (tempB != NULL && tempB->data > tempA->data) 
    {
        indexB++;
        tempB = tempB->next;
    }
           
    if (minimum(indexB, B->number - indexB) == 0) 
    {
        i = 0; 
        printf("+++++++++++++BEFORE WHILE |||IF|||++++++++++++++\n");
        printf("INDEXB = %d\n", indexB );
        printf("B->NUMBER VALUE = %d\n", B->number);
        printlist(B);
        while (i < indexB) {
            rotate(B);
            i++;
        }
        printf("+++++++++++++BEFORE PUSHB ||| IF |||++++++++++++++\n");
        printlist(B);
        pushb(A, B);
        printf("+++++++++++++AFTER PUSHB ||| IF |||++++++++++++++\n");
        printlist(B);
        if(B->head->data < B->tail->data){
        while( i > 0)
        {
            reverserotate(B);
            i--;
        }}
        printf("+++++++++++++AFTER WHILE |||IF|||++++++++++++++\n");
        printlist(B);
    } 
    else 
    {
        i = 0;
        printf("+++++++++++++BEFORE WHILE |||ELSE|||++++++++++++++\n");
        printf("INDEX = %d\n", indexB );
        printf("B->NUMBER VALUE = %d\n", B->number);
        printlist(B);
        while (i < (B->number - indexB)) 
        {
            reverserotate(B);
            i++;
        }
        printf("+++++++++++++BEFORE PUSHB ||| ELSE |||++++++++++++++\n");
        printlist(B);
        pushb(A, B);
        printf("+++++++++++++AFTER PUSHB++++++++++++++\n");
        printlist(B);
        printf("VALUE OF I %d\n", i);
        if(B->head->data < B->tail->data){
        while(i > 0)
        {
            printf("+++++++++++++INSIDE WHILE |||ELSE|||++++++++++++++\n");
            rotate(B);
            printf("+++++++++++++AFTER WHILE |||ELSE|||++++++++++++++\n");
            i--;
        } 
        }
        printf("+++++++++++++AFTER WHILE |||ELSE|||++++++++++++++\n");
        printlist(B);
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
    printf("B NUMBER AFTER PB %d\n", B->number) ;
    if(B->head->data < B->head->next->data)
    {
        swap(B);
    }
    while(A->head)
    {
       align_stacks(A, B);
    }
    while(B->head)
    {
        pusha(A, B);
    }   
    printlist(A);
    printlist(B);
    free(A);
    free(B);
}