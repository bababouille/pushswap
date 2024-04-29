/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:30:24 by marvin            #+#    #+#             */
/*   Updated: 2024/04/28 15:30:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char name[50];
    int age;
    int *exams;
    int size;
} student42;

void ft_printexam(student42 *student);

int main()
{   
    int x = 1;
    student42 vasco;
    strcpy(vasco.name, "vasco hubert de oliveira cambier");
    vasco.age = 29;
    vasco.exams = malloc(sizeof(int) * 3);
    vasco.size = 3;
    vasco.exams[0] = 22;
    vasco.exams[1] = 67;
    vasco.exams[2] = 92;

    student42 nikita;
    strcpy(nikita.name, "nikita tyunyaev");
    nikita.age = 29;
    nikita.exams = malloc(sizeof(int) * 5);
    nikita.size = 5;
    nikita.exams[0] = 43;
    nikita.exams[1] = 21;
    nikita.exams[2] = 96;
    nikita.exams[3] = 77;
    nikita.exams[4] = 34;


    ft_printexam(&vasco);
    ft_printexam(&nikita);
}

void    ft_printexam(student42 *student)
{
    printf("Student name: %s\nStudent age:%d\n", student->name, student->age);
    int i = 0;
    int m = 0;
    while(i < student->size)
    {
        printf("Student %s exam number %d score = %d\n", student->name, i + 1, student->exams[i]);
        m += student->exams[i];
        i++;
    }
    printf("Student %s total average points is : %d\n", student->name, m / student->size);

}