// banque.h

#include <iostream>
#include <vector>
#include <string>

class Compte {
private:
    int numeroCompte;
    std::string titulaire;
    float solde;

public:
    Compte(int n, const std::string& t, float s);
    int getNumeroCompte() const;
    const std::string& getTitulaire() const;
    float getSolde() const;
    void deposer(float montant);
    void retirer(float montant);
    void changerTitulaire(const std::string& nouveauTitulaire);
};

class Banque {
private:
    std::vector<Compte> comptes;

public:
    void ajouterCompte(const Compte& compte);
    void afficherComptes() const;
    Compte* trouverCompte(int numeroCompte);
    void mettreAJourTitulaire(int numeroCompte, const std::string& nouveauTitulaire);
    void transfererArgent(int source, int destination, float montant);
    void supprimerCompte(int numeroCompte);
    void ajouterArgent(int numeroCompte, float montant);
    void retirerArgent(int numeroCompte, float montant);
};
