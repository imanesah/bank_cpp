#pragma once
#include <iostream>
using namespace std;
#include <fstream>
class Compte
{
protected:
	
	int id;
	string property;
	double solde;
public:
	//Compte();

	Compte(int id, string property, double solde);
	void afficher() const;
	//void modifier_compte();
	bool depot(double D);
	bool retrait(double R);
	bool transfert(double T,  Compte& C);
	void ajouterAuFichier(ofstream& outFile) const;
    // static Compte* load
	~Compte();
	
};

class Compte_�pargne : public Compte {
private:
	double Taux_int�r�te;

public:
	Compte_�pargne(int id, string owner, double solde, double Taux_int�r�te);
	void appliquer_int�r�te();
	void afficher_compte_�pargne() const;
	void ajouteAuFichier2(ofstream& outFile) const;
	

};

