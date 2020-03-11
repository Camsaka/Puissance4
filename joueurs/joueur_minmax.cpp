#include "joueur_minmax.h"

Joueur_minmax::Joueur_minmax(std::string nom,bool joueur)
	:Joueur(nom,joueur)
	{}



char Joueur_minmax::nom_abbrege() const
{
    return 'M';
}

	int max(int a, int b) 
	{
	return ((a>=b)? a:b) ;
	}
	int min(int a, int b) 
	{
	return ((a<=b)? a:b) ;
	}


int Joueur_minmax::minMax(Jeu jeu,bool isMax)
{
	// Regarde si le jeu est fini, retourne le score de l'évaluation.
	// if (p==h) // 
	if (jeu.fini())
	{
		if(isMax) return  -1;
		else return 1;
	}
	int bestScore;
	if (isMax) // Joueur qui cherche à maximiser son score
	{
		bestScore = -9999;
		for (int i=0;i<jeu.nb_coups();++i)
		{
			// "Joue" le coup en i et ensuite ajoute/compare le score avec le bestScore.
			Jeu J(jeu.etat());
			J.joue(i);
			int score = minMax(J,false);
			bestScore = max(score,bestScore);
		}
		return bestScore;
	}
	else {

		bestScore = 9999;
		for (int i=0;i<jeu.nb_coups();++i)
		{
			Jeu J(jeu.etat());
			J.joue(i);
			int score = minMax(J,true);
			bestScore= min(score,bestScore);
		}
		return bestScore;
	}
}

void Joueur_minmax::recherche_coup(Jeu jeu, int & coup)
{
	int result = -99;

	for (int i=0;i<jeu.nb_coups();++i)
	{
		Jeu J(jeu.etat());
		J.joue(i);
		int score = minMax(J,false);
		if (score>result)
		{
			result = score;
			coup = i;
		}
	}

}