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




// Méthode pour enregistrer les informations du compte dans un fichier


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
		
		cout << "Enregistré dans le fichier avec succès" << endl;
	}
	else {
		cerr << "Erreur : Impossible d'ouvrir le fichier" << endl;
	}
}

Compte::~Compte()
{

	cout << " supp compte" << endl;
}




//Compte_épargne::Compte_épargne(int id, string property, double solde, double Taux_intérête):Compte(id,property,solde), Taux_intérête(Taux_intérête){ }

void Compte_épargne::appliquer_intérête()
{
	//this->solde = this->solde + this->solde * (Taux_intérête / 100);
}

void Compte_épargne::afficher() const
{
	cout << "ce compte est épargne : " << endl;
	Compte::afficher();
	cout << "avec taux d'intérête : " << Taux_intérête <<endl;

}

void Compte_épargne::ajouteAuFichier2(ofstream& outFile) const
{
	if (outFile.is_open()) {
		outFile << "id : " << id << " property:  " << property << " solde :  " << solde << " taux:  " << Taux_intérête << endl;
		outFile.close();
	}
	else {
		cerr << "Erreur : Impossible d'ouvrir le fichier " << endl;
	}

}


