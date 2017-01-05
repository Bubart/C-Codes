#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26

typedef struct{
	char FN[24], LN[16], MI;
}nameType;

typedef struct{
	nameType N;
	unsigned long idNumber;
	char course[4];
}studRec;

typedef struct node{
	studRec S;
	struct node *next;
}nodeType, *nPtr;

typedef nPtr Dictionary[SIZE];

typedef enum{TRUE,FALSE}Boolean;

void init(Dictionary D);
void insert(Dictionary D, studRec S);
int hash(char LN[]);
void display(Dictionary D);

int main()
{
	Dictionary A;
	init(A);
	studRec P = {
					{"Robert","Lim", 'L'}, 15101137, "BSCS"
					
				};
	insert(A, P);
	insert(A, P);
	display(A);
	return 0;
}

void init(Dictionary D)
{
	int i;
	for(i=0;i<SIZE;i++){
		D[i] = NULL;
	}
}

void display(Dictionary D)
{
	int i;
	nPtr temp;
	printf("FIRST NAME\tLAST NAME\tMI\tCOURSE\tID NUMBER\n\n");
	for(i=0;i<SIZE;i++){
		temp = D[i];
		while(temp!=NULL){
			
			printf("%s\t%s\t%c\t%s\t%d", temp->S.N.FN, temp->S.N.LN, temp->S.N.MI, temp->S.course, temp->S.idNumber);
			temp = temp->next;
		}

	}
}

int hash(char LN[])
{
	return LN[0] - 'A'; /*0  for A, 2 for B, etc*/
}

void insert(Dictionary D, studRec S)
{
	nPtr temp;
	int h;
	h = hash(S.N.LN);
	if(D[h] == NULL){
		D[h] = (nPtr)malloc(sizeof(nodeType));
		D[h]->S = S;
		D[h]->next = NULL;
	}else{
		
	}
	
	
	
	
}
