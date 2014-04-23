#include<stdio.h>
#include<stdlib.h>
#include "instance.h"
void main()
{
	problem * prblm;
	solution * solConst;
	solution * solLoc;
	FILE file;
	int * tab;

	prblm = chargerInstance("coupe1.txt");
	system("pause");
	eclatement(prblm);
	system("pause");
}