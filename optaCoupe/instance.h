struct pbCoupe
{
	int tailleBarre; // taille de la barre
	int nbTaillesDem; // nombre totale des tailles demand�es
	int nbTotPcs;// nombre totale des pi�ces demand�es
	int * taille; // une taille demand�e
	int * nbDem; // la quantit� demand�e
};
struct solCoupe
{
	int tailleBarre;
	int nbTaillesDem;
	int objVal; // valeur de la fonction objectif
	int tailleTot; // taille totale des �l�ments s�l�ctionn�s
	int * elem ; // tableau binaire indiquant si l'�l�ment N�i est pris ou non
	int nbElem; // nombre d'�l�ments s�l�ctionn�s
};
typedef struct pbCoupe problem ;
typedef struct solCoupe solution ;

problem * chargerInstance(char * fichier);
solution * initSol  (problem * pb);
solution * recherche_locale( solution * sol, problem *pb);
int * eclatement (problem * pb);
void freeProblem(problem * pb);
void freeSolution(solution *  sol);