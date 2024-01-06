// main.cpp

#include "banque.h"


int main() {
    Banque maBanque;

    while (true) {
        std::cout << "*------------------------------*" << std::endl;
        std::cout << "*    Gestion Banquaire         *" << std::endl;
        std::cout << "*------------------------------*" << std::endl;
        std::cout << "* |1|. Ajouter un compte       *" << std::endl;
        std::cout << "* |2|. Afficher les comptes    *" << std::endl;
        std::cout << "* |3|. Rechercher un compte    *" << std::endl;
        std::cout << "* |4|. Mettre à jour titulaire *" << std::endl;
        std::cout << "* |5|. Transférer de l'argent  *" << std::endl;
        std::cout << "* |6|. Supprimer un compte     *" << std::endl;
        std::cout << "* |7|. Ajouter de l'argent     *" << std::endl;
        std::cout << "* |8|. Retirer de l'argent     *" << std::endl;
        std::cout << "* |9|. Quitter                 *" << std::endl;
        std::cout << "*******************************" << std::endl;

        int choix;
        std::cout << "Choisissez une option : ";
        std::cin >> choix;

        switch (choix) {
            case 1: {
                int numero;
                std::string titulaire;
                float solde;

                std::cout << "Entrez le numéro de compte : ";
                std::cin >> numero;
                std::cout << "Entrez le nom du titulaire : ";
                std::cin.ignore(); // pour gérer les sauts de ligne restants
                std::getline(std::cin, titulaire);
                std::cout << "Entrez le solde initial : ";
                std::cin >> solde;

                Compte nouveauCompte(numero, titulaire, solde);
                maBanque.ajouterCompte(nouveauCompte);
                break;
            }
            case 2:
                maBanque.afficherComptes();
                break;
            case 3: {
                int numeroRecherche;
                std::cout << "Entrez le numéro de compte à rechercher : ";
                std::cin >> numeroRecherche;

                Compte* compteTrouve = maBanque.trouverCompte(numeroRecherche);

                if (compteTrouve) {
                    std::cout << "Compte trouvé : Numéro de compte : " << compteTrouve->getNumeroCompte() << ", Titulaire : " << compteTrouve->getTitulaire() << ", Solde : " << compteTrouve->getSolde() << std::endl;
                } else {
                    std::cout << "Compte non trouvé." << std::endl;
                }
                break;
            }
            case 4: {
                int numeroCompte;
                std::string nouveauTitulaire;

                std::cout << "Entrez le numéro de compte : ";
                std::cin >> numeroCompte;
                std::cout << "Entrez le nouveau titulaire : ";
                std::cin.ignore(); // pour gérer les sauts de ligne restants
                std::getline(std::cin, nouveauTitulaire);

                maBanque.mettreAJourTitulaire(numeroCompte, nouveauTitulaire);
                break;
            }
            case 5: {
                int compteSource, compteDestination;
                float montant;

                std::cout << "Entrez le numéro de compte source : ";
                std::cin >> compteSource;
                std::cout << "Entrez le numéro de compte destination : ";
                std::cin >> compteDestination;
                std::cout << "Entrez le montant à transférer : ";
                std::cin >> montant;

                maBanque.transfererArgent(compteSource, compteDestination, montant);
                break;
            }
            case 6: {
                int numeroCompte;
                std::cout << "Entrez le numéro de compte à supprimer : ";
                std::cin >> numeroCompte;
                maBanque.supprimerCompte(numeroCompte);
                break;
            }
            case 7: {
                int numeroCompte;
                float montant;
                std::cout << "Entrez le numéro de compte : ";
                std::cin >> numeroCompte;
                std::cout << "Entrez le montant à ajouter : ";
                std::cin >> montant;
                maBanque.ajouterArgent(numeroCompte, montant);
                break;
            }
            case 8: {
                int numeroCompte;
                float montant;
                std::cout << "Entrez le numéro de compte : ";
                std::cin >> numeroCompte;
                std::cout << "Entrez le montant à retirer : ";
                std::cin >> montant;
                maBanque.retirerArgent(numeroCompte, montant);
                break;
            }
            case 9:

                std::cout << "*------------------------------*" << std::endl;
                std::cout << "\tAu revoir !" << std::endl;
                std::cout << "*------------------------------*" << std::endl;
                return 0;
            default:
                std::cout << "Option invalide. Veuillez réessayer." << std::endl;
        }
    }

    return 0;
}
