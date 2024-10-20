// banque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Compte.h"
#include "System.h"
int main()
{
    
   /* Compte compte1(1, "A", 1000.0);
    Compte_épargne compteEpargne1(2, "B", 2000.0, 2.5);

   
    cout << "Affichage des comptes " << endl;
    compte1.afficher();
    compteEpargne1.afficher();

    cout << "Dépôt de 500 DH dans le compte1:" << endl;
    compte1.depot(500);
    compte1.afficher();

  
    cout << "Retrait de 300 DH du compte1:" << endl;
    compte1.retrait(300);
    compte1.afficher();

    
    cout << "Transfert de 200 DH du compte1 vers compteEpargne1:" << endl;
   compte1.transfert(200, compteEpargne1);
    compte1.afficher();
    compteEpargne1.afficher();

    
    cout << "Application de l'intérêt au compteEpargne1:" << endl;
    compteEpargne1.appliquer_intérête();
    compteEpargne1.afficher();

  //  ofstream outFile("C:\\Users\\AdMin\\source\\repos\\banque\\file1.txt");
  //  compte1.ajouterAuFichier(outFile);

   
  ///  compteEpargne1.ajouteAuFichier2(outFile);*/
   
    Devise* a,*b,*c;
    a = new Devise(100, "Euro");
    b = new Devise(500, "Mad");  
    c = new Devise(10, "Mad");
    Compte compte1(1, "AAA", a);
    Compte compte2(1, "BBBBB", b);
    cout << "compte 1" << endl;
    compte1.afficher();
    cout << "compte 2" << endl;
    compte2.afficher();

    //compte2.depot(c);
    cout << "**************************apres transfert ***********************" << endl;
    compte2.transfert(compte1, c); //compte 2 fih 490 o 1 fih 110
    cout << "compte 1" << endl;
    compte1.afficher();
    cout << "compte 2" << endl;
    compte2.afficher();

   

    return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
