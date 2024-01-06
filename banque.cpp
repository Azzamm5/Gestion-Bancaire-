// banque.cpp
#include<iostream>
#include "banque.h"

Compte::Compte(int n, const std::string& t, float s) : numeroCompte(n), titulaire(t), solde(s) {
}

int Compte::getNumeroCompte() const {
    return numeroCompte;
}

const std::string& Compte::getTitulaire() const {
    return titulaire;
}

float Compte::getSolde() const {
    return solde;
}

void Compte::deposer(float montant) {
    solde += montant;
    std::cout << "Dépôt de " << montant << " effectué." << std::endl;
    std::cout << "Nouveau solde : " << solde << std::endl;
}

void Compte::retirer(float montant) {
    if (montant > solde) {
        std::cout << "Solde insuffisant pour effectuer le retrait." << std::endl;
    } else {
        solde -= montant;
        std::cout << "Retrait de " << montant << " effectué" << std::endl;
        std::cout << "Nouveau solde : " << solde << std::endl;
    }
}

void Compte::changerTitulaire(const std::string& nouveauTitulaire) {
    titulaire = nouveauTitulaire;
    std::cout << "Le titulaire du compte a été mis à jour : " << titulaire << std::endl;
}

void Banque::ajouterCompte(const Compte& compte) {
    comptes.push_back(compte);
    std::cout << "$------------------------------$" << std::endl;
    std::cout << "Compte ajouté avec succès." << std::endl;
    std::cout << "$------------------------------$" << std::endl<< std::endl;
}

void Banque::afficherComptes() const {
    std::cout << "Liste des comptes :" << std::endl;
    for (const auto& compte : comptes) {
        std::cout << "*------------------------------*" << std::endl;
        std::cout << "-> Numéro de compte : " << compte.getNumeroCompte() <<  std::endl;
        std::cout << "-> Titulaire : " << compte.getTitulaire() << std::endl;
        std::cout << "-> Solde : " << compte.getSolde() << std::endl;
        std::cout << "*------------------------------*" << std::endl;
    }
}

Compte* Banque::trouverCompte(int numeroCompte) {
    for (auto& compte : comptes) {
        if (compte.getNumeroCompte() == numeroCompte) {
            return &compte;
        }
    }
    return nullptr;
}

void Banque::mettreAJourTitulaire(int numeroCompte, const std::string& nouveauTitulaire) {
    Compte* compte = trouverCompte(numeroCompte);
    if (compte) {
        compte->changerTitulaire(nouveauTitulaire);
    } else {
        std::cout << "Compte non trouvé." << std::endl;
    }
}

void Banque::transfererArgent(int source, int destination, float montant) {
    Compte* compteSource = trouverCompte(source);
    Compte* compteDestination = trouverCompte(destination);

    if (compteSource && compteDestination) {
        if (compteSource->getSolde() >= montant) {
            compteSource->retirer(montant);
            compteDestination->deposer(montant);
            std::cout << "Transfert effectué avec succès." << std::endl;
        } else {
            std::cout << "Solde insuffisant pour effectuer le transfert." << std::endl;
        }
    } else {
        std::cout << "Compte source ou compte destination non trouvé." << std::endl;
    }
}

void Banque::supprimerCompte(int numeroCompte) {
    auto it = std::remove_if(comptes.begin(), comptes.end(),
        [numeroCompte](const Compte& compte) { return compte.getNumeroCompte() == numeroCompte; });

    if (it != comptes.end()) {
        comptes.erase(it, comptes.end());
        std::cout << "Compte supprimé avec succès." << std::endl;
    } else {
        std::cout << "Compte non trouvé." << std::endl;
    }
}

void Banque::ajouterArgent(int numeroCompte, float montant) {
    Compte* compte = trouverCompte(numeroCompte);
    if (compte) {
        compte->deposer(montant);
    } else {
        std::cout << "Compte non trouvé." << std::endl;
    }
}

void Banque::retirerArgent(int numeroCompte, float montant) {
    Compte* compte = trouverCompte(numeroCompte);
    if (compte) {
        compte->retirer(montant);
    } else {
        std::cout << "Compte non trouvé." << std::endl;
    }
}
