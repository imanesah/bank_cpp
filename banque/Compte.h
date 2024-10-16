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

class Compte_épargne : public Compte {
private:
	double Taux_intérête;

public:
	Compte_épargne(int id, string owner, double solde, double Taux_intérête);
	void appliquer_intérête();
	void afficher_compte_épargne() const;
	void ajouteAuFichier2(ofstream& outFile) const;
	

};

