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

// Do push and pop
// push = add element at the begining of stack
void    push(int data, stack *A)
{
    node *new = malloc(sizeof(node));
  
    new->data = data;
    new->next = A->head;
    A->head = new;
}

// pop = remove element from stack

void    pop(stack *A)
{
    node *temp = A->head;

    A->head = A->head->next;
    free(temp);
}

void printlist(stack *A)
{
    printf("----------\n");
    node *runner = A->head;
    while(runner)
    {
        printf("%d\n", runner->data);   
        runner = runner->next;
    }
    printf("----------\n");
}

int main()
{
    stack *A = malloc(sizeof(stack));
    A->head = NULL;
    
    stack *B = malloc(sizeof(stack));
    B->head = NULL;


    swap()

    push(1, A);
    push(2, A);
    push(3, A);
    push(4, A);
    push(5, A);

    pop(A);
    printlist(A);
    pop(A);
    printlist(A);
    pop(A);
    printlist(A);
    pop(A);
    printlist(A);
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

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


