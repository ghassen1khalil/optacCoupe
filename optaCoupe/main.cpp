#include<stdio.h>
#include<stdlib.h>
#include <cstdlib>
#include "instance.h"
void main()
{
	problem * prblm;
	solution * solConst;
	solution * solLoc;
	FILE file;
	
	int i;
	printf("hello git");
	prblm = chargerInstance("coupe1.txt");
	int * tab = (int *) malloc (prblm->nbTotPcs * sizeof(int));
	solConst = initSol(prblm);
	system("pause");
}