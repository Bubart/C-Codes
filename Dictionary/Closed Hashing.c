#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
#define EMPTY -1
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
void insert(Dictionary D, studType P);
void display(Dictionary D);

int main()
{
	Dictionary A;
	initDictionary(A);

	studType P = {{"Robert", "Lim", 'L'}, "BSCS", 2, 15101137};
	studType P1 = {{"Robert", "Lim", 'L'}, "BSCS", 2, 15101130};

	insert(A, P);


	
	display(A);
	
	return 0;
}

void initDictionary(Dictionary D)
{
	int i;
	for(i=0;i<SIZE;i++){
		
		D[i].yearLevel = EMPTY;
	}
}

int hash(unsigned long x)
{
	int sum;
	while (x!=0){
		sum +=(x%10);
		x/=10;
 }
	return sum % SIZE;
}

Boolean isMember(Dictionary D, studType P)
{
	int i, hv;
	Boolean retval = FALSE;
	
	hv = hash(P.idNumber);
	
	if(D[hv].idNumber == P.idNumber){
		retval = TRUE;
	}else{
		i = hv;
		//do{i =(i+1)%SIZE;}while(i!= hv && D[i].yearLevel != P.idNumber);
		for(i = hv ; i!=hv && D[i].idNumber != P.idNumber; i = (i+1)%SIZE){}
		printf("%d %d\n", D[i].idNumber, P.idNumber);
	}
	
	if(i != hv){
		retval = TRUE;
	}else{
		retval = FALSE;
	}
	
	return retval;
}

void insert(Dictionary D, studType P)
{
	int hv, i, ctr;
	
	hv = hash(P.idNumber);
	
	if(isMember(D,P)==FALSE){
		if(D[hv].yearLevel == EMPTY || D[hv].yearLevel == DELETED){
			D[hv] = P;
		}else{
			for(i = hv ; i < SIZE && (D[i].yearLevel != EMPTY && D[i].yearLevel !=DELETED )==1 ; i = (i+1)%SIZE){}
			D[i] = P;
		}
	}else{
		printf("Already in the dictionary");
	}
}

void display(Dictionary D)
{
	int i;
	for(i=0;i<SIZE;i++){
		printf("Index %d: %d", i, D[i].idNumber);
		printf("\n");
	}
}
