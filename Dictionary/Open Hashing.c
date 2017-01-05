#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 3

typedef struct{
	char FN[24], LN[16], MI;
}nameType;

typedef struct node{
	nameType N;
	unsigned long idNumber;
	char course[4];
	struct node *next;
}nodeType, *nPtr;

typedef nPtr Dictionary[SIZE];

typedef enum{TRUE,FALSE}Boolean;

int main()
{
	
}
