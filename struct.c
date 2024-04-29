/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:59:17 by marvin            #+#    #+#             */
/*   Updated: 2024/04/27 15:59:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Student:
- name (string)
- id (string)
- age (int)
- grades (int array)
*/

typedef struct 
{
    char name[50];
    char id[10];
    int age;
    int grades[5];
} student;

typedef struct
{
    int x;
    int y;
}  point;

typedef struct
{
    int *array;
    int size;
    char name[30];
} data;

void print_student(student student1);

void print_points(point *points);

void print_array(data *array);


int main()
{ 
    
    student vasco;   
    
    strcpy(vasco.name, "Cambier Vasco");
    strcpy(vasco.id, "69AAS69");
    vasco.age = 29;
    vasco.grades[0] = 87;
    vasco.grades[1] = 75;
    vasco.grades[2] = 96;
    vasco.grades[3] = 34;
    vasco.grades[4] = 77;
    
    print_student(vasco);
   
    point p1 = {5, 10};
    point p2 = { 
                .x = 2, 
                .y = 8
                };

    printf("p1.x - %d\n", p1.x);
    printf("p1.y - %d\n", p1.y);

    printf("p2.x - %d\n", p2.x);
    printf("p2.y - %d\n", p2.y);

    p1 = p2;

    printf("p1.x - %d\n", p1.x);
    printf("p1.y - %d\n", p1.y);


    point points[10];

    for (int i = 0; i < 10; i++)
    {
        points[i].x = i;
        points[i].y = 10 - i;
    }

    print_points(points);

    data x; // vasco
    data y; // nikita
    data z; //jp

    x.array = malloc(sizeof(int) * 5);
    x.size = 5;
    strcpy(x.name, "vasco");
    y.array = malloc(sizeof(int) * 5);
    y.size = 5;
    strcpy(y.name, "nikita");
    z.array = malloc(sizeof(int) * 7);
    z.size = 7;
    strcpy(z.name, "jp");

    x.array[0] = 1;
    x.array[1] = 2;
    x.array[2] = 3;
    x.array[3] = 4;
    x.array[4] = 5;

    y.array[0] = 9;
    y.array[1] = 9;
    y.array[2] = 9;
    y.array[3] = 9;
    y.array[4] = 9;

    
    z.array[0] = 9;
    z.array[1] = 9;
    z.array[2] = 9;
    z.array[3] = 9;
    z.array[4] = 3;
    z.array[5] = 2;
    z.array[6] = 1;
    
    print_array(&x);
    print_array(&z);
    print_array(&y);


}

void print_points(point *points)
{
    for (int i = 0; i < 10; i++)
    {
        printf("p%d = (%d,%d)\n", i, points[i].x, points[i].y);
    }
}

void print_student(student student1)
{
    int i = 0;
    printf("Name - %s\n", student1.name);
    printf("Id - %s\n", student1.id);
    printf("Age - %d\n", student1.age);
    printf("Grades  - ");
    while(i < 5)
    {
        printf("%d  ", student1.grades[i]);
        i++;
    }
    printf("\n");
}

void print_array(data *data)
{
      int i = 0;
    while (i < data->size)
    {
        printf("%s[%d] = %d\n", (*data).name, i, data->array[i]);
        i++;
    }
}

// . = acceder un chant dune structure
// -> = acceder un chant dun pointeur vers une structure 
// data.name == (&data)->name
// data->name == (*data).name



