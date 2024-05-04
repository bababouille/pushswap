/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:03:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/04 20:03:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void printlist(stack *S)
{
    printf("----------\n");
    node *runner = AB->head;
    while(runner)
    {
        printf("%d\n", runner->data);  
        runner = runner->next;
    }
    printf("----------\n");
}

void    pop(stack *S)
{
    node *temp = S->head;

    S->head = S->head->next;
    free(temp);
}

void    push(int data, stack *S)
{
    node *new = malloc(sizeof(node));
  
    new->data = data;
    new->next = S->head;
    S->head = new;
}

void    pusha(stack *A, stack *B)
{
    push(B->head->data, A);
    pop(B);
}

void    pushb(stack *A, stack *B)
{
    push(A->head->data, B);
    pop(A);
}

void ss(stack *A, stack *B)
{
    node *temp = A->head->next; //temp points to node 2
    
    A->head->next = temp->next; // A->head->next points to node 3
    temp->next = A->head; // temp->next points to node 1
    A->head = temp; // A->head points to null 2

    node *temp2 = B->head->next; //temp points to node 2
    
    B->head->next = temp2->next; // A->head->next points to node 3
    temp2->next = B->head; // temp->next points to node 1
    B->head = temp2; // A->head points to null 2
}

void swap(stack *S)
{
    node *temp = S->head->next; // temp points to node 2

    S->head->next = temp->next; // A->head->next points to node 3
    temp->next = S->head; // temp->next points to node 1
    S->head = temp; // A->head points to null 2

    printf("s%s\n", S->name);
}

void rotata(stack *S)
{
    node *temp = S->head;
    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = S->head;
    temp = temp->next;
    S->head = S->head->next; 
    temp->next = NULL;
}

void reverserotate(stack *S)
{
    node *temp = S->head; // temp = 1st node 

    while (temp->next->next != NULL)
    { 
        temp = temp->next;
    }
    temp->next->next = S->head; // NULL is now = to 1st node
    S->head = temp->next; // 1st node equal to second to last node
    temp->next = NULL; // second to last node points to NULL
}

void reverseboth(stack *A, stack B)
{
    node *temp = A->head; // temp = 1st node 

    while (temp->next->next != NULL)
    { 
        temp = temp->next;
    }
    temp->next->next = A->head; // NULL is now = to 1st node
    A->head = temp->next; // 1st node equal to second to last node
    temp->next = NULL; // second to last node points to NULL

    node *temp = B->head; // temp = 1st node 

    while (temp->next->next != NULL)
    { 
        temp = temp->next;
    }
    temp->next->next = B->head; // NULL is now = to 1st node
    B->head = temp->next; // 1st node equal to second to last node
    temp->next = NULL; // second to last node points to NULL
}
