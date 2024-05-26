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
    printf("INSIDE INBETWEEN\n");

    if((A->head->data > B->head->next->data) && (A->head->data < B->head->data))
    {
        printf("Condition IB!: 2\n");
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
    int i = 0;

    while(1)
    {
        if(A->head == NULL)
        {
            break;
        }
        else if(A->head->data > B->head->data)
        {
            printf("Condition 1: A->head->data > B->head->data\n");
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if(A->head->data < B->tail->data)
        {
            printf("Condition 2: A->head->data < B->tail->data\n");
            pushb(A, B);
            rotate(B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if((A->head->next != NULL) && (A->head->next->data > B->head->data))
        {
            printf("Condition 3: A->head->next->data > B->head->data\n");
            swap(A);
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        } 
        else if(A->tail->data > B->head->data)
        {
            printf("Condition 4: A->tail->data > B->head->data\n");
            reverserotate(A);
            pushb(A, B);
            if(rotatecount > 0)
            {
                break;
            }
        }
        else if((A->head->next != NULL) && (A->head->next->data < B->tail->data))
        {
            printf("Condition 5: A->head->next->data < B->tail->data\n");\
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
            printf("Condition 6: A->tail->data %d < B->tail->data %d\n", A->tail->data, B->tail->data);
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
            printf("Else case: rotating B\n");
            rotate(B);
            rotatecount++;
            while(!inbetween(A, B))
            {
                rotate(B);
                rotatecount++;
            }   
            printf("OUTSIDE INBETWEEN\n");
            
        }
        printf("UN PRINT PLUS COOL POUR A\n");
        printlist(A);
        if (A->number > 0)
        {printf("TAIL A IS %d\n", A->tail->data);}
        printf("UN PRINT PLUS COOL POUR B\n");
        printlist(B);
        if (B->number > 0)
        {printf("TAIL B IS %d\n", B->tail->data);}

    }
    printf("ROTATE COUNT IS :%d\n", rotatecount);
    while(i < rotatecount)
    {
        reverserotate(B);
        i++;
    }
    rotatecount = 0;
    i = 0;
}


int main()
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

    push(10, A); push(85, A); push(15, A);push(100, A); push(438, A); push(16, A); push(55, A); push(535, A); 
    printlist(A);
    pushb(A, B);
    pushb(A, B);
  
    if(B->head->data < B->head->next->data)
    {
        swap(B);
    }
    printf("ITS A\n");
    printlist(A);
    printf("ITS B\n");
    printlist(B);

    while(A->head)
    {
      get_it_done(A, B);
      printf("GET IT DONE! GOT DONE!!\n");  
      printlist(B);
    }
    printf("WROOR!!\n");  
    while(B->head)
    {
        pusha(A, B);
    }   
    printlist(A);
   
    free(A);
    free(B);
    
}