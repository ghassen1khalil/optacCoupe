#include<stdio.h>
#include<stdlib.h>
#include<new>
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
	int n;
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
	n=atoi(data);
	printf(" n = %d\n", n);
	printf("%s\n",data);

	fscanf_s(instanceFile,"%s",data, sizeof(data)); //lecture du nombre totale des pièces demandées du fichier de l'instance du probleme
	pb->nbTotPcs = atoi(data); //affectation de la valeur
	printf("%s\n",data);

	pb->taille = (int*) malloc (n * sizeof(int)); //allocation du tableau pour les tailles
	pb->nbDem = (int*) malloc (n * sizeof(int)); //allocation du tableau pour les quantité
	//pb->taille = new  int[pb->nbTaillesDem];
	//pb->nbDem = new int[pb->nbTaillesDem];

	//remplissage des tableaux des tailles et quantités
	//i=0;
	
	while (i < pb->nbTaillesDem)
	{
		/*fscanf_s(instanceFile,"%s",data,sizeof(data)); // lecture de la taille N°i
		pb->taille[i] = atoi(data);// affectation de la valeur
		printf("%s\n",data);

		fscanf_s(instanceFile,"%s",data,sizeof(data)); // lecture de la quantité N°i
		pb->nbDem[i] = atoi(data);// affectation de la valeur
		printf("%s\n",data);*/
		//fscanf_s(instanceFile,"%d %d",&xx,&yy);
		//printf("%d--%d\n",xx,yy);
		fscanf_s(instanceFile,"%d %d",&pb->taille[i],&pb->nbDem[i]);
		//printf("%d--%d\n",pb->taille[i],pb->nbDem[i]);
		i++;
	}
	return pb;
}


solution * initSol (problem * pb)
{
	solution * s;
	s = (solution *) malloc (sizeof(solution));
	int * tab, used,i,j,selected,v;
	tab = (int *)malloc(sizeof(int)* pb->nbTotPcs);
		for (i = 0;i<pb->nbTotPcs;i++)
			s->elem[i] = 0;
	used = 0; i = 0;selected = 0,v = 0;
	tab = eclatement (pb);
		i=0;
	while (i < pb->nbTaillesDem)
	{
		v = pb->taille[i];
		for (j=0;j<pb->nbDem[i];j++)
		{
			tab[i] = v;
			//printf("val = %d\n",tab[i]);
		}
		i++;
	}
	while ((used < pb->tailleBarre) && (i<= pb->nbTotPcs))
	{
		used+=tab[i];
		s->elem[i] = 1;
		selected++;
	}
	s->nbTaillesDem = pb->nbTaillesDem;
	s->objVal = used;
	s->tailleBarre = pb->tailleBarre;
	s->tailleTot = used;
	s->nbElem = selected;
	return s;
}


solution * copySol (solution * sol)
{
	int i;
	solution * s;
	s->tailleBarre = sol->tailleBarre;
	s->nbTaillesDem = sol->nbTaillesDem;
	s->objVal = sol->objVal;
	s->tailleTot = sol->tailleTot;
	s->nbElem = sol->nbElem;
	for (i=0;i<sol->nbTaillesDem;i++)
		s->elem = sol->elem;

	return s;

		
}



solution * recherche_locale(solution * sol, problem * pb)
{
	solution * s;
	int * tab = (int *)malloc(sizeof(int)* pb->nbTotPcs);
	int i,j,used,v,somme;
	somme = 0;
	used = 0;
	s = copySol(sol);
		i=0;
	while (i < pb->nbTaillesDem)
	{
		v = pb->taille[i];
		for (j=0;j<pb->nbDem[i];j++)
		{
			tab[i] = v;
			printf("val = %d\n",tab[i]);
		}
		i++;
	}
	while (used <= pb->tailleBarre)
	{
		for (i =0;i<pb->nbTotPcs;i++)
		{
			if (sol->elem[i] != sol->elem[i+1])
			{
				v = sol->elem[i];
				s->elem[i] = s->elem[i+1];
				s->elem[i+1] = v;
				if (sol->elem[i] == 0)
					somme+=tab[i];
			}

		}
	}
	s->objVal = used;
	s->tailleTot = used;
	return  s;
}

int * eclatement( problem * pb) // Fonction pour l'éclatement du tableau
{
	
	int i,j,v;
	int * tab = (int *)malloc(sizeof(int)* pb->nbTotPcs);
	i=0;
	while (i < pb->nbTaillesDem)
	{
		v = pb->taille[i];
		for (j=0;j<pb->nbDem[i];j++)
		{
			tab[i] = v;
			//printf("val = %d\n",tab[i]);
		}
		i++;
	}

	return tab;

}

solution * solVide (problem * pb)
{
	solution *s ;
	int i;
	s = (solution *) malloc (sizeof(solution));
	s->tailleBarre = 0;
	s->nbTaillesDem = 0;
	s->objVal = 0;
	s->tailleTot = 0;
	s->nbElem = 0;
	s->elem = (int *) malloc (sizeof(int)* pb->nbTotPcs);
	for (i=0;i<pb->nbTotPcs;i++)
		s->elem[i] = 0;
	return s;
}



void freeAll(problem *pb)
{
	free(pb->taille);
	free(pb->nbDem);
}

