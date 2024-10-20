#pragma once

#include <iostream>
using namespace std;
using namespace std;
class Devise
{
//protected: 
public:
	double solde;
	string type;

	Devise(double solde,const string& type) : solde(solde),type(type) {}
	double to_mad(Devise& montant);
	double to_dollar(Devise& montant);
	double to_euro(Devise& montant);
	void afficherDevise();
	void ajouterdevise(ofstream& outFile) const;
    ~Devise() {}
	
};

class Dollar : public Devise
{
public:
	//double convertir(string& type);
	//double to_mad();
	//double to_euro();
};

class Mad : public Devise
{
public:
	//double convertir(string& type);
	//double to_dollar();
	//double to_euro();
};
class Euro : public Devise
{
public:
	//double convertir(string& type);
	//double to_dollar();
	//double to_mad();

};


