#ifndef __HEADER_H__
#define __HEADER_H__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define WHITE	0
#define GRAY	1
#define BLACK	2

#define BNV		0	// bad number of vertices"
#define BNE		1	// bad number of edges
#define BV		2	// bad vertex
#define BNL		3	// bad number of lines
#define ITS		4	// impossible to sort


typedef struct List_st {
	struct Elem_st *value;
	struct List_st *next;
}list;

typedef struct Elem_st {
	int color;
	int count;
	int number;
	list *head;
}elem;

void errors(int k);
void verify_values(int n, int m);
void verify_include(int n, int v);
void verify_sort(elem *graf, int num);

#endif