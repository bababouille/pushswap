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

#include "pushswap.h"

void    get_it_done(stack *A, stack *B)
{
    int rotatecount = 0;

    while(A->head)
    {
        if(A->head != NULL && A->head->data > B->head->data)
        {
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->head != NULL && A->head->data < B->tail->data)
        {
            pushb(A, B);
            rotate(B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->head != NULL && A->head->next->data > B->head->data)
        {
            swap(A);
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->head != NULL && A->head->next->data < B->tail->data)
        {
            swap(A);
            pushb(A, B);
            rotate(B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->head != NULL && A->tail->data > B->head->data)
        {
            reverserotate(A);
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->head != NULL && A->tail->data < B->tail->data)
        {
            reverserotate(A);
            pushb(A, B);
            rotate(B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if (A->head == NULL)
        {
            while(B->head)
            {
                pusha(A, B);
            }
            break;
        }
        else
        {
            rotate(B);
            rotatecount++;
        }
    }  

if (A->head != NULL || rotatecount > 0)
    {
        int i = 0;
        while(i <= rotatecount)
        {
            reverserotate(B);
            i++;
        }
        rotatecount = 0;
        i = 0;
        get_it_done(A, B);
    } 
}


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

    push(14, A); push(22, A); push(35, A); push(48, A); push(54, A);
    printlist(A);
    printf("TAIL A IS %d\n", A->tail->data);
    pushb(A, B);
    pushb(A, B);

    get_it_done(A, B);

    printlist(A);
    printlist(B);
}