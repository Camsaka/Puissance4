#include "joueur_alphabeta_.h"


Joueur_AlphaBeta_::Joueur_AlphaBeta_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_AlphaBeta_::nom_abbrege() const
{
    return 'A';
}


// Revoir la fonction evaluation ..
int Joueur_AlphaBeta_::eval(Jeu jeu, bool isMax)
{
	if (isMax) return -1;
	else return 1;
}

	int _max(int a, int b)
	{
	return ((a>=b)? a:b) ;
	}
	int _min(int a, int b)
	{
	return ((a<=b)? a:b) ;
	}


// isMax -> Joueur
// p -> profondeur


int Joueur_AlphaBeta_::alphaBeta(Jeu jeu,int a,int b,bool isMax)
{
// 	if (jeu.fini())
// 	{
// 		if (isMax) return -1;
// 		else return 1;
// 	}

// 	int alpha =a;
// 	int beta =b;

// 	if (isMax)
// 		{
// 			int v = -9999;
// 			for(int i=0;i<jeu.nb_coups();++i)
// 			{
// 				Jeu J(jeu.etat());
// 				J.joue(i);
// 				v = _max(v,alphaBeta(J,alpha,beta,false));
// 				alpha = _max(alpha,v);
// 				//std::cout<<"Alpha : "<<alpha<<std::endl;
// 				if (alpha>=beta) break;
// 			}
// 			return v;
// 		}

// 	else
// 		{
// 			int v = 9999;
// 			for(int i=0;i<jeu.nb_coups();++i)
// 			{
// 				Jeu J(jeu.etat());
// 				J.joue(i);
// 				v = _min(v,alphaBeta(J,alpha,beta,true));
// 				beta = _min(beta,v);
// 				//std::cout<<"Beta : "<<beta<<std::endl;
// 				if (alpha>=beta) break;
// 			}
// 			return v;
// 		}
}
/*
int principal_variation_search(Jeu jeu,int a,int b, bool isMax)
{
	if (jeu.fini())
	{
		if (isMax) return -1;
		else return 1;
	}

	int alpha = a;
	int beta = b;

	if (isMax)
	{
		for (int i =0;i<jeu.nb_coups();++i)
		{
			Jeu J(jeu.etat());
			int score = principal_variation_search(J,beta,alpha,false);
			if (alpha < score and score < beta)
			{
				int score2 = principal_variation_search(J,beta,score,true);
				alpha = _max(alpha,score2);
			}
			if (alpha >= beta) break;
			return alpha;
		}

	}
	else
	{
		for (int i=0;i<jeu.nb_coups();++i)
		{
			Jeu J(jeu.etat());
			int score = principal_variation_search(J,alpha-1,alpha,true);
			if (alpha < score and score < beta)
			{
				int score2 = principal_variation_search(J,beta,score,true);
				alpha = _max(alpha,score2);
			}
			if (alpha >= beta) break;
			return alpha;
		}


	}

}
*/

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
	// jeu.print_coups();
	// std::cout<<std::endl;
	// int result = -99;

	// 	for (int i=0;i<jeu.nb_coups();++i)
	// 	{
	// 		// "Joue" le coup en jeu[i] et regarde le score, compare avec tout les coups possibles quels choix prendre.
	// 		// jeu.joue(i);
	// 		Jeu J(jeu.etat());
	// 		J.joue(i);
	// 		// std::cout<<"MINMAX : "<<minMax(J,false)<<"\t\n";
	// 		// int score = minMax(J,false);
	// 		int score = alphaBeta(J,-999,999,false);
	// 		//int score = principal_variation_search(J,-999,999,false);
	// 		if (score>result)
	// 		{
	// 			result=score;
	// 			coup =i;
	// 		}
	// 	}
}
