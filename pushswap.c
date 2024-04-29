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

struct node
{
    int value;
    struct node* next;
};
typedef struct node node_t;

void printlist(node_t *head){
    node_t *temporary = head;
    
    while (temporary != NULL){
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

int main()
{
    node_t n1, n2, n3;
    node_t *head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    //link them up
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL; //so we know when to stop.

    printlist(head);

    return 0;
}
