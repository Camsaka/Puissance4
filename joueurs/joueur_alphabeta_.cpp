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

bool Joueur_AlphaBeta_::coup_gagnant(Jeu jeu,int & coup)
{
	jeu.joue(coup);
	if (jeu.etat()==1) return true;
	else false;

}



// isMax -> Joueur
// p -> profondeur


int Joueur_AlphaBeta_::alphaBeta(Jeu jeu,int a,int b,bool isMax,int coup)
{

	if (jeu.etat()==1)
	{
		if (isMax) return -1;
		else return 1;	
	}

	// else if (coup_gagnant(jeu,coup) and isMax) return -100;
	// 	else if (coup_gagnant(jeu,coup) and !isMax) return 1000;


	Jeu J = jeu;
	int alpha =a;
	int beta =b;

	if (isMax)
		{
			int v = -9999;
			for(int i=0;i<jeu.nb_coups();++i)
			{
				J = jeu;
				J.joue(i);
				v = _max(v,alphaBeta(J,alpha,beta,false,i));
				 alpha = _max(alpha,v);
				std::cout<<"Alpha : "<<alpha<<std::endl;
				if (alpha>=beta) break;
			}
			return v;
		}

	else
		{
			int v = 9999;
			for(int i=0;i<jeu.nb_coups();++i)
			{
				J = jeu;
				J.joue(i);
				 v = _min(v,alphaBeta(J,alpha,beta,true,i));
				 beta = _min(beta,v);
				std::cout<<"Beta : "<<beta<<std::endl;
				if (alpha>=beta) break;
			}
			return v;
		}
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

int test=0;

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
	 // std::cout<<jeu.nb_coups();
	std::cout<<std::endl;
	int result = -99;
	Jeu J = jeu;

	if (test<3)
	{
		coup = 0;
		test++;
	}


else {
		for (int i=0;i<jeu.nb_coups();++i)
		{
			// "Joue" le coup en jeu[i] et regarde le score, compare avec tout les coups possibles quels choix prendre.
			// jeu.joue(i);
			J=jeu;
			J.joue(i);
			// std::cout<<"MINMAX : "<<minMax(J,false)<<"\t\n";
			// int score = minMax(J,false);
			   int score = alphaBeta(J,-999,999,false,i);
			// //int score = principal_variation_search(J,-999,999,false);
			  std::cout<<score;
			 // coup=0;
			 if (score>result)
			 {
			 	result=score;
			 	coup =i;
			 }
		}
	}
}

			