#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
#define EMPTY 1
#define DELETED 0

typedef struct{
	char FN[24], LN[16], MI;
}nameType;

typedef struct{
	nameType name;
	char course[5];
	int yearLevel;
	unsigned long idNumber;
}studType;

typedef studType Dictionary[SIZE];

typedef enum{TRUE,FALSE}Boolean;

void initDictionary(Dictionary D);

int main()
{
	Dictionary A;
	initDictionary(A);
	
	return 0;
}

void initDictionary(Dictionary D)
{
	int i;
	for(i=0;i<SIZE;i++){
		D[i].yearLevel = EMPTY;
	}
}
