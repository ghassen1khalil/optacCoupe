#include<stdio.h>
#include<stdlib.h>
#include <cstdlib>
#include "instance.h"
void main()
{
	printf("hello git");
	problem * prblm;
	solution * solConst;
	solution * solLoc;
	FILE file;
	
	int i;
	
	prblm = chargerInstance("coupe1.txt");
	int * tab = (int *) malloc (prblm->nbTotPcs * sizeof(int));
	solConst = initSol(prblm);
	system("pause");
}