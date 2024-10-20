#pragma once

#include <vector>
#include <string>
#include "Compte.h"

class System
{
private:
    std::vector<Compte*> comptes; // Renommer le membre pour éviter le conflit
public:
    std::string name;
    void ajouter_compte(Compte* compte);

    void supprimer_compte(Compte* compte);

    ~System();
};
