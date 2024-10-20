#include "Devise.h"
#include <fstream>

/*double Dollar::convertir(string& type)
{
	double newsolde = this->solde;
	if (this->type == "Mad") {
		newsolde=to_mad();
		
	}
	if (this->type == "Euro") {
		newsolde = to_euro();
	}
	return newsolde;
	
}

double Dollar::to_mad()
{
	this->solde = this->solde * 10;
	return this->solde;
}

double Dollar::to_euro()
{

	this->solde = this->solde * 0.85;
	return this->solde;
}

double Mad::convertir(string& type)
{
	double newsolde = this->solde;
	if (this->type == "Dollar") {
		newsolde = to_dollar();
	}
	if (this->type == "Euro") {
		newsolde = to_euro();
	}
	return newsolde;
}

double Mad::to_dollar()
{
	this->solde = this->solde / 10;
	return this->solde;
}

double Mad::to_euro()
{
	
	this->solde = this->solde * 0.085;
	return this->solde;
}

double Euro::convertir(string& type)
{
	double newsolde = this->solde;
	if (this->type == "Dollar") {
		newsolde = to_dollar();
	}
	if (this->type == "Mad") {
		newsolde = to_mad();
	}
	return newsolde;
}

double Euro::to_dollar()
{
	this->solde = this->solde / 0.85;
	return this->solde;
	
}

double Euro::to_mad()
{
	this->solde = this->solde / 0.085;
	return this  ->solde;
}
*/

double Devise::to_mad(Devise& montant)
{
  
	if (montant.type == "Dollar") {
		this->solde =  montant.solde * 10;
		return this->solde;
	}
	if (montant.type == "Euro") {
		this->solde =  montant.solde / 0.085;
		return this->solde;
	}if (montant.type == "Mad") {
		this->solde =  montant.solde;
		return this->solde;
	}
	return 0;
}

double Devise::to_dollar(Devise& montant)
{
	if(montant.type == "Euro"){
		this->solde =  montant.solde / 0.85;
		return this->solde;
	}
	if (montant.type == "Mad") {
		cout << "kan flwl " << montant.solde << endl;
		cout << "ghayweli " << montant.solde / 10 << endl;
		this->solde =  montant.solde / 10;
		return this->solde;
	
	}
	if (montant.type == "Dollar") {
		this->solde = this->solde  ;
		return this->solde;
	}
	return 0;
}

double Devise::to_euro(Devise& montant)
{
	if (montant.type == "Dollar") {
		this->solde =  montant.solde * 0.85;
		return this->solde;
	}
	if (montant.type == "Mad") {
		this->solde =  montant.solde * 0.085;
		return this->solde;
	}
	if (montant.type == "Euro") {
		this->solde = this->solde  ;
		return this->solde;
	}
	return 0;
}

void Devise::afficherDevise()
{
	cout <<  solde <<type << endl;
}
void Devise::ajouterdevise(ofstream& outFile) const
{
	if(outFile.is_open()) {
		outFile << solde << " "<< type << endl;
	
	}
	else {
		cerr << "Erreur : Impossible d'ouvrir le fichier" << endl;
	}
}
