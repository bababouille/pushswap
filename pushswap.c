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
    return 0;
}

void    get_it_done(stack *A, stack *B)
{
    int rotatecount = 0;
    while(1)
    {
        if(A->head == NULL)
        {
            break;
        }
        else if(A->head->data > B->head->data)
        {
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->head->data < B->tail->data)
        {
            pushb(A, B);
            rotate(B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->head->data < B->head->data && A->head->data > B->head->next->data)
        {
            pushb(A,B);
            swap(B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if((A->head->next != NULL) && (A->head->next->data > B->head->data))
        {
            swap(A);
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        } 
        else if(A->tail->data > B->head->data)
        {
            reverserotate(A);
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if((A->head->next != NULL) && (A->head->next->data < B->tail->data))
        {
            swap(A);
            pushb(A, B);
            rotate(B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->tail->data < B->tail->data)
        {
            reverserotate(A);
            pushb(A, B);
            rotate(B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else
        {
            rotate(B);
            rotatecount++;
            while(!inbetween(A, B))
            {
                rotate(B);
                rotatecount++;
            }       
        }
        rotatecount = 0;
        while (B->head->data < B->tail->data)
        {
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
    printf("Head Data %d\n",B->head->data);
    printf("Head NEXT Data %d\n",B->head->next->data);
    if(B->head->data < B->head->next->data)
    {
        printf("Head Data %d\n",B->head->data);
        printf("Head NEXT Data %d\n",B->head->next->data);
        swap(B);
    }
    printf("Head Data %d\n",B->head->data);
    printf("Head NEXT Data %d\n",B->head->next->data);
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