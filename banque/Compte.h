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
		outFile.close(); // Fermer le fichier apr�s avoir ajout�
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

class Compte_�pargne : public Compte {
private:
	double Taux_int�r�te;

public:
//	Compte_�pargne(int id, string owner, double solde, double Taux_int�r�te);
	void appliquer_int�r�te();
	void afficher() const;
	void ajouteAuFichier2(ofstream& outFile) const;
	

};

