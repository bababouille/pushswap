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

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct
{
    struct node *head;
} stack;


// push = add element at the begining of stack
void    push(int data, stack *A);
// pop = remove element from stack
void    pop(stack *A);
void printlist(stack *A);

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void swap(stack *AB)
{
    node *temp = AB->head->next; //temp points to node 2
    
    AB->head->next = temp->next; // A->head->next points to node 3
    temp->next = AB->head; // temp->next points to node 1
    AB->head = temp; // A->head points to null 2
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


int main()
{
    stack *A = malloc(sizeof(stack));
    A->head = NULL;
    
    stack *B = malloc(sizeof(stack));
    B->head = NULL;

    push(1, A); push(2, A); push(3, A); push(4, A); push(5, A);
    push(9, B); push(8, B); push(7, B); push(6, B); push(5, B);
    

    // swap(A);
    // swap(B);

    // pop(A);

    // pusha(A, B);
    // pushb(A, B);
    // ss(A, B);
  
    printlist(A);
    printlist(B);
}
void printlist(stack *AB)
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

void    pop(stack *AB)
{
    node *temp = AB->head;

    AB->head = AB->head->next;
    free(temp);
}

void    push(int data, stack *A)
{
    node *new = malloc(sizeof(node));
  
    new->data = data;
    new->next = A->head;
    A->head = new;
}

// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// rr : ra and rb at the same time.

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

// rrr : rra and rrb at the same time.


