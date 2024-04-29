/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essy2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:45:51 by marvin            #+#    #+#             */
/*   Updated: 2024/04/28 17:45:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    char name[50];
    int age;
    int *exams;
    int size;
    int number[2];
} student42;


int main()
{   

    student42 students[2];
    strcpy(students[0].name, "vasco hubert de oliveira cambier");
    students[0].age = 29;
    students[0].size = 4;
    students[0].exams = (int *)malloc(4 * sizeof(int));
    students[0].exams[0] = 22;
    students[0].exams[1] = 67;
    students[0].exams[2] = 92;
    students[0].exams[3] = 100;
    
    strcpy(students[1].name, "nikita tyunyayev");
    students[1].age = 29;
    students[1].exams = malloc(sizeof(int) * 5);
    students[1].size = 5;
    students[1].exams[0] = 43;
    students[1].exams[1] = 21;
    students[1].exams[2] = 96;
    students[1].exams[3] = 77;
    students[1].exams[4] = 34;
    int i = 0;

    while(i < 2)
    {
        printf("Student name: %s\nStudent age:%d\n", students[i].name, students[i].age);
        int j = 0;
        int x = 0;
        while(j < students[i].size)
        {
            printf("Student %s exam number %d score = %d\n", students[i].name, j + 1, students[i].exams[j]);
            x += students[i].exams[j];
            j++;
        }
        printf("Student %s total average points is : %d\n", students[i].name, x / students[i].size);
        i++;
    }
}