#include<stdio.h>
#include<stdlib.h>
#include "instance.h"

problem *pb;
solution * slConstructive;
solution * slLocale;
errno_t err;
FILE * instanceFile;
char data[10];
int i;

problem * chargerInstance (char * fichier) // Chargement de l'instance du problème
{
	if ((err= fopen_s(&instanceFile,fichier,"r")) != 0)
		exit(1);
	else
		{
			printf("Ouverture du fichier avec succès ...\n");
			//system("pause");
		}
	pb = (problem*) malloc(sizeof(problem));
	fscanf_s(instanceFile,"%s",data, sizeof(data)); //lecture de la taille de barre du fichier de l'instance du probleme
	pb->tailleBarre = atoi(data); //affectation de la valeur
	printf("%s\n",data);

	fscanf_s(instanceFile,"%s",data, sizeof(data)); //lecture du nombre des tailles demandées du fichier de l'instance du probleme
	pb->nbTaillesDem = atoi(data); //affectation de la valeur
	printf("%s\n",data);

	fscanf_s(instanceFile,"%s",data, sizeof(data)); //lecture du nombre totale des pièces demandées du fichier de l'instance du probleme
	pb->nbTotPcs = atoi(data); //affectation de la valeur
	printf("%s\n",data);

	//pb->taille = (int*) malloc (pb->nbTaillesDem * sizeof(int)); //allocation du tableau pour les tailles
	//pb->nbDem = (int*) malloc (pb->nbTaillesDem * sizeof(int)); //allocation du tableau pour les quantité
	pb->taille = new int[pb->nbTaillesDem];
	pb->nbDem = new int[pb->nbTaillesDem];

	//remplissage des tableaux des tailles et quantités
	while (i < pb->nbTaillesDem)
	{
		fscanf_s(instanceFile,"%s",data,sizeof(data)); // lecture de la taille N°i
		pb->taille[i] = atoi(data);// affectation de la valeur
		printf("%s\n",data);

		fscanf_s(instanceFile,"%s",data,sizeof(data)); // lecture de la quantité N°i
		pb->nbDem[i] = atoi(data);// affectation de la valeur
		printf("%s\n",data);

		i++;
	}
	return pb;
}

solution * solConst( problem * pb) // Solution Constructive
{
	slConstructive = (solution*)malloc(sizeof(solution));
	slConstructive->tailleBarre = pb->tailleBarre; // récupération de la taille de barre
	slConstructive->nbTaillesDem = pb->nbTaillesDem; // récupération du nombre des tailles demandées
	slConstructive->elem = (int*) malloc (sizeof(int)* slConstructive->nbTaillesDem); //allocation de la taille du tableau Booléen Elem
	slConstructive->objVal = 0; // initialisation de la Fonction Objectif
	slConstructive->tailleTot = 0; // intialisation de la taille totale séléctionnée

}

int * eclatement( problem * pb) // Fonction pour l'éclatement du tableau
{
	
	int i,j,v;
	int * tab = (int *)malloc(sizeof(int)* pb->nbTaillesDem);
	i=0;
	while (i < pb->nbTaillesDem)
	{
		v = pb->taille[i];
		for (j=0;j<pb->nbDem[i];j++)
		{
			tab[i] = v;
			i++;
		}
		
	}

	return tab;

}