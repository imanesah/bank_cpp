#include "System.h"
#include <string>
#include <fstream>
#include "Compte.h"

void System::ajouter_compte(Compte* compte)
{
	comptes.push_back(compte);
}

void System::supprimer_compte(Compte* compte)
{

}

System::~System()
{
	cout << "Dtor" << endl;
}
