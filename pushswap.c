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

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct
{
    struct node *head;
    struct node *tail;
    char name[128];
} stack;

int main()
{
    stack *A = malloc(sizeof(stack));
    A->head = NULL;
    A->tail = NULL;
    strcpy(A->name, "a");

    stack *B = malloc(sizeof(stack));
    B->head = NULL;
    B->tail = NULL;
    strcpy(B->name, "b");

    push(1, A); push(2, A); push(3, A); push(4, A); push(5, A);
    push(9, B); push(9, B); push(9, B); push(9, B); push(9, B);
    
    printf("After push\n");
    printlist(A);

    swap(A);
    swap(B);

    printf("After swap\n");
    printlist(A);
   
    
    ss(A, B);
    
    printf("After SS\n");
    printlist(A);

    // pop(A);

    pusha(A, B);
    // pushb(A, B);

    printf("After pusha\n");
    printlist(A);
    
    rotata(A);
    printf("After rotate\n");
    printlist(A);

    reverserotate(A);
    printf("After rev rotate\n");
    printlist(A);
}

