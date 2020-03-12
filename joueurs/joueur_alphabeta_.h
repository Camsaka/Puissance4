#pragma once


#include "joueur.h"
#include<bits/stdc++.h> 


class Joueur_AlphaBeta_ : public Joueur
{
public:
  Joueur_AlphaBeta_(std::string nom, bool joueur);
  char nom_abbrege() const override;
  void recherche_coup(Jeu, int & coup) override;
  int eval(Jeu jeu,bool isMax);
  int minMax(Jeu jeu,bool isMax);
  int alphaBeta(Jeu jeu,int alpha,int beta,bool isMax,int & coup, int depth, int ab);
  int log2(int n);
  // void rechercheMinMax(bool joueur,int profondeur,int coup);

};
