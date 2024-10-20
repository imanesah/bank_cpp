#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include "Devise.h"
class Compte
{
protected:
	
	int id;
	string property;
	Devise* solde;
public:
	//Compte();

	Compte(int id, const string& property, Devise* initialSolde) : id(id), property(property), solde(initialSolde)
	{
		ofstream outFile("C:\\Users\\AdMin\\source\\repos\\banque\\file1.txt", ios::app);
		this->ajouterAuFichier(outFile);
		outFile.close(); // Fermer le fichier après avoir ajouté
	}
	void afficher() const;
	//sdouble convertir(const string& type);
	//void modifier_compte();
	bool depot(Devise* D);
	bool retrait(Devise* R);
	bool transfert(Compte& C , Devise * montant);
	void ajouterAuFichier(ofstream& outFile) const;
    // static Compte* load
	~Compte();
	
};

class Compte_épargne : public Compte {
private:
	double Taux_intérête;

public:
//	Compte_épargne(int id, string owner, double solde, double Taux_intérête);
	void appliquer_intérête();
	void afficher() const;
	void ajouteAuFichier2(ofstream& outFile) const;
	

};

