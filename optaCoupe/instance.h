struct pbCoupe
{
	int tailleBarre; // taille de la barre
	int nbTaillesDem; // nombre totale des tailles demandées
	int nbTotPcs;// nombre totale des pièces demandées
	int * taille; // une taille demandée
	int * nbDem; // la quantité demandée
};
struct solCoupe
{
	int tailleBarre;
	int nbTaillesDem;
	int objVal; // valeur de la fonction objectif
	int tailleTot; // taille totale des éléments séléctionnés
	int * elem ; // tableau binaire indiquant si l'élément N°i est pris ou non
	int nbElem; // nombre d'éléments séléctionnés
};
typedef struct pbCoupe problem ;
typedef struct solCoupe solution ;

problem * chargerInstance(char * fichier);
solution * initSol  (problem * pb);
solution * recherche_locale( solution * sol, problem *pb);
int * eclatement (problem * pb);
void freeProblem(problem * pb);
void freeSolution(solution *  sol);