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


int inbetween(stack *A, stack *B)
{  
    if((A->head->data > B->head->next->data) && (A->head->data < B->head->data))
    {
        rotate(B);
        pushb(A, B);
        reverserotate(B);
        return 1;
    }
    else if(A->head->data > B->head->data && A->head->data < B->tail->data)
            {
                pushb(A, B);
                return 1;
            }
    else if(A->head->data < B->head->data && A->head->data > B->head->next->data)
            {
                rotate(B);
                pushb(A, B);
                return 1;
            }
    else if((A->tail->data > B->head->data && A->tail->data < B->tail->data))
            {
                reverserotate(A);
                pushb(A, B);
                return 1;
            }
    else if((A->tail->data < B->head->data && A->tail->data > B->head->next->data))
            {
                reverserotate(A);
                pushb(A, B);
                swap(B);
                return 1;
            }
    return 0;
}

void    get_it_done(stack *A, stack *B)
{
    while(1)
    {
        if(A->head == NULL)
        {
            break;
        }
        else if(A->head->data > B->head->data)
        {
            pushb(A, B);
        }
        else if(A->head->data < B->tail->data)
        {
            pushb(A, B);
            rotate(B);
        }
        else if(A->head->data < B->head->data && A->head->data > B->head->next->data)
        {
            pushb(A,B);
            swap(B);
        }
        else if((A->head->next != NULL) && (A->head->next->data > B->head->data))
        {
            swap(A);
            pushb(A, B);
        } 
        else if((A->head->next != NULL) && (A->head->next->data < B->tail->data))
        {
            swap(A);
            pushb(A, B);
            rotate(B);
        }     
        else if((A->head->next != NULL) && (A->head->next->data < B->head->data && A->head->next->data > B->head->next->data))
        {
            swap(A);
            pushb(A, B);
            swap(B);
        }
        else if(A->tail->data > B->head->data)
        {
            reverserotate(A);
            pushb(A, B);
        }
        else if(A->tail->data < B->tail->data)
        {
            reverserotate(A);
            pushb(A, B);
            rotate(B);
        }
        else if(A->tail->data < B->head->data && A->tail->data > B->head->next->data)
        {
            reverserotate(A);
            pushb(A, B);
            swap(B);
        }
        else
        {
            rotate(B);
            while(!inbetween(A, B))
            {
                rotate(B);
            }       
        }
        while (B->head->data < B->tail->data)
        { 
            if (A->head != NULL && (A->head->data > B->head->data && A->head->data < B->tail->data))
            {
                pushb(A, B);
            }
            else if (A->head != NULL && (A->head->data < B->head->data && A->head->data > B->head->next->data))
            {
                rotate(B);
                pushb(A, B);
            }
            else if (A->tail != NULL && (A->tail->data > B->head->data && A->tail->data < B->tail->data))
            {
                reverserotate(A);
                pushb(A, B);
            }
            else if (A->tail != NULL && (A->tail->data < B->head->data && A->tail->data > B->head->next->data))
            {
                reverserotate(A);
                pushb(A, B);
                swap(B);
            }
            reverserotate(B);
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
    if(B->head->data < B->head->next->data)
    {
        swap(B);
    }
    while(A->head)
    {
      get_it_done(A, B);
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