#include "Compte.h"
#include <fstream>

/*Compte::Compte() :id(0), property(""), solde(0)
{
}*/

Compte::Compte(int id, string property, double solde):id(id), property(property), solde(solde)
{
	//ajouterAuFichier("C:\\Users\\AdMin\\source\\repos\\banque\\file1.txt");

}
void Compte::afficher() const {
	cout << id << ",  " << property << ",  " << solde << endl;
}


// M�thode pour enregistrer les informations du compte dans un fichier


bool Compte::depot(double montant )
{
	if (montant > 0){
	this->solde = this->solde + montant;
	return true;
	}
	return false;
}

bool Compte::retrait(double montant)
{
	if (montant >0 && this->solde > montant) {
		this->solde = this->solde - montant;
		return true;
	}
	return false;
}

bool Compte::transfert(double montant,  Compte& C)
{
	if(montant > 0 && this->solde >= montant){
		this->solde = this->solde - montant;
		C.solde = C.solde + montant;
		return true;
	}
	return false;
	
}
void Compte::ajouterAuFichier(ofstream &outFile) const {
	
	if (outFile.is_open()) {
		outFile << id << " " << property << " " << solde << endl;
		outFile.close();
	}
	else {
		cerr << "Erreur : Impossible d'ouvrir le fichier "  << endl;
	}
}

Compte::~Compte()
{

	cout << " supp compte" << endl;
}




Compte_�pargne::Compte_�pargne(int id, string property, double solde, double Taux_int�r�te):Compte(id,property,solde), Taux_int�r�te(Taux_int�r�te){ }

void Compte_�pargne::appliquer_int�r�te()
{
	this->solde = this->solde + this->solde * (Taux_int�r�te / 100);
}

void Compte_�pargne::afficher_compte_�pargne() const
{
	cout << id << ",  " << property << ",  " << solde << ",  " << Taux_int�r�te <<endl;

}

void Compte_�pargne::ajouteAuFichier2(ofstream& outFile) const
{
	if (outFile.is_open()) {
		outFile << "id : " << id << " property:  " << property << " solde :  " << solde << " taux:  " << Taux_int�r�te << endl;
		outFile.close();
	}
	else {
		cerr << "Erreur : Impossible d'ouvrir le fichier " << endl;
	}

}


