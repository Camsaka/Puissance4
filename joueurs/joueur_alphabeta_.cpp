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
	// if (jeu.etat()==1)
	// {
	// 	if (isMax) return -100;
	// 	else return 100;
	// }
	// else if (isMax) return -10;
	// else return 10;
	if (jeu.etat()==1)
	{
		if (isMax) return -10000;
		else return 10000;
	}

	for (int i=0;i<MAX_LARGEUR;++i)
	{
		if (isMax and (jeu.plateau()->_hauteur[i]==4) )
		{
			return -100;
		}
		else if(!isMax and (jeu.plateau()->_hauteur[i]==4 )) return 100;

		if (isMax and (jeu.plateau()->_hauteur[i]==3 ) )
		{
			return -50;
		}
		else if(!isMax and (jeu.plateau()->_hauteur[i]==3) ) return 50;

		if (isMax and (jeu.plateau()->_hauteur[i]==2 ) )
		{
			return -30;
		}
		else if(!isMax and (jeu.plateau()->_hauteur[i]==2) ) return 30;
	}



		for (int i=0;i<MAX_LARGEUR;++i)
	{
		if (isMax and (jeu.plateau()->_pions[i]==4))
		{
			return -100;
		}
		else if(!isMax and (jeu.plateau()->_pions[i]==4)) return 100;

		if (isMax and (jeu.plateau()->_pions[i]==3))
		{
			return -50;
		}
		else if(!isMax and (jeu.plateau()->_pions[i]==3)) return 50;

			if (isMax and (jeu.plateau()->_pions[i]==2))
		{
			return -30;
		}
		else if(!isMax and (jeu.plateau()->_pions[i]==2)) return 30;
	}

	if (isMax) return -10;
	else return 10;
	
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
// int eval(Jeu j,bool isMax){
// 	if (isMax){
// 		return -1;
// 	}
// 	else return 1;	
// }

int Joueur_AlphaBeta_::alphaBeta(Jeu jeu,int a,int b,bool isMax,int & coup, int depth, int ab)
{


	// else if (coup_gagnant(jeu,coup) and isMax) return -100;
	// 	else if (coup_gagnant(jeu,coup) and !isMax) return 1000;
	Jeu J = jeu;	
	if (J.etat()==ALIGNEMENT or depth ==0){ return eval(J,isMax);}
	int alpha =a;
	int beta =b;
	int v = 0;
	int mult;
	if (ab==0) {mult=1;} else {mult=-1;};

	if (isMax)
	{
		v = -9999;
		for(int i=0;i<J.nb_coups()-1;++i)
		{
			if(J.coup_licite(i)){
				// J = jeu;
				J.joue(mult*(i+1));
				v = _max(v,alphaBeta(J,alpha,beta,false,i,depth-1,ab));
				alpha = _max(alpha,v);
			}
				// std::cout<<"Alpha : "<<alpha<<std::endl;
			if (alpha>=beta) break;
		}
		return v;
	}

	else
	{
		v = 9999;
		for(int i=0;i<J.nb_coups()-1;++i)
		{
			if(J.coup_licite(i)){
				// J = jeu;
				J.joue(mult*(i+1));
				v = _min(v,alphaBeta(J,alpha,beta,true,i,depth-1,ab));
				beta = _min(beta,v);
			}
				// std::cout<<"Beta : "<<beta<<std::endl;
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
	coup =0;
	int alpha =-999;
	int beta =999;
	int score =0;
	Jeu J = jeu;

	int tour= jeu.nb_coups();
	int ab = tour%2;
	int mult = 1;
	if (ab == 1) { mult=-1; }


	for (int i=0;i<7;++i)
	{
		if(J.coup_licite(i)){
			// J = jeu;
			J.joue(mult*(i+1));;
			score = alphaBeta(J,alpha,beta,false,i,1000,ab);
			std::cout<<score;
			if (score>result){ result=score; coup =i;}
		}
	}
}


