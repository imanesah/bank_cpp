#include "Compte.h"
#include "Devise.h"
#include <fstream>


/*Compte::Compte() :id(0), property(""), solde(0)
{
}*/


void Compte::afficher() const {
	cout << "les information de compte sont: " << endl;
	cout << "ID -> " <<id << "; property -> " << property << " ; solde->  "  ;
	solde->afficherDevise();
	
}




// M�thode pour enregistrer les informations du compte dans un fichier


bool Compte::depot(Devise* montant )
{ 
	cout << "dkhl depot" << endl;
	
	string tmp = montant->type;
	
	
	if(this->solde->type == "Mad") {
		this->solde->solde= this->solde->solde + montant->to_mad(* montant);
		return true;
	}
	if (this->solde->type == "Dollar") {

		this->solde->solde= this->solde->solde + montant->to_dollar(* montant);
		return true;
	}
	if (this->solde->type == "Euro") {
		
		this->solde->solde = this->solde->solde + montant->to_euro(* montant);
		return true;
	}
	//cout << "nv solde est :" << this->solde->solde << " en " << this->solde->type << endl;
	return false;
	cout << "khrej depot" << endl; 
}

bool Compte::retrait(Devise* R)
{ 
	cout << "dkhl lretrait" << endl;
	if (this->solde->type != R->type) {
		cout << "le retrait est impossible doit etre meme type de devise " << endl;
		return false;
	}
	else if (this->solde->solde < R->solde) {
		cout << " le solde est insiffusant " << endl;
		return false;
	}
	else {
		this->solde->solde = this->solde->solde - R->solde;
		return true;
	}
	cout << "khrej men retrait " << endl;
}

bool Compte::transfert(Compte& C, Devise* montant)
{
	
	bool a;
	a=this->retrait(montant);
	if (a == true) {
		C.depot(montant);
		return true;
	}
	else {
		cout << "operation echoue" << endl;
		return false;
	}
	
}



void Compte::ajouterAuFichier(ofstream &outFile) const {
	
	if (outFile.is_open()) {
		outFile << " ==> les information de compte sont : " << "ID -> " << id << "; property -> " << property << " ; solde->  ";
		solde->ajouterdevise(outFile);
		
		cout << "Enregistr� dans le fichier avec succ�s" << endl;
	}
	else {
		cerr << "Erreur : Impossible d'ouvrir le fichier" << endl;
	}
}

Compte::~Compte()
{

	cout << " supp compte" << endl;
}




//Compte_�pargne::Compte_�pargne(int id, string property, double solde, double Taux_int�r�te):Compte(id,property,solde), Taux_int�r�te(Taux_int�r�te){ }

void Compte_�pargne::appliquer_int�r�te()
{
	//this->solde = this->solde + this->solde * (Taux_int�r�te / 100);
}

void Compte_�pargne::afficher() const
{
	cout << "ce compte est �pargne : " << endl;
	Compte::afficher();
	cout << "avec taux d'int�r�te : " << Taux_int�r�te <<endl;

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


