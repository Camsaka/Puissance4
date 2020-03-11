#pragma once

#include "joueur.h"

class Joueur_minmax : public Joueur
{
public:
	Joueur_minmax(std::string nom,bool joueur);
	char nom_abbrege() const override;
	void recherche_coup(Jeu, int & coup) override;
	int minMax(Jeu jeu,bool isMax);

};
