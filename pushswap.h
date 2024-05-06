/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:01:51 by marvin            #+#    #+#             */
/*   Updated: 2024/05/04 20:01:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void    push(int data, stack *A);
void    pop(stack *S);
void    printlist(stack *S);
void    swap(stack *S);
void    ss(stack *A, stack *B);
void    pusha(stack *A, stack *B);
void    pushb(stack *A, stack *B);
void    rotata(stack *S);
void    reverserotate(stack *S);
void    reverseboth(stack *A, stack *B);

#endif