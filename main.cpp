#include <iostream>

class DistributeurAutomatique {
private:
    int solde;

public:
    DistributeurAutomatique(int soldeInitial) {
        solde = soldeInitial;
    }

    int obtenirSolde() {
        return solde;
    }

    bool retirerArgent(int montant) {
        if (montant > solde) {
            return false;
        }
        solde -= montant;
        return true;
    }

    void deposerArgent(int montant) {
        solde += montant;
    }
};

int main() {
    DistributeurAutomatique distributeur(1000);
    int choix, montant;
    bool succes;
    do {
        std::cout << "1. Voir le solde" << std::endl;
        std::cout << "2. Retrait d'argent" << std::endl;
        std::cout << "3. Dépôt d'argent" << std::endl;
        std::cout << "4. Quitter" << std::endl;
        std::cout << "Entrez votre choix : ";
        std::cin >> choix;
        switch (choix) {
            case 1:
                std::cout << "Votre solde : " << distributeur.obtenirSolde() << std::endl;
                break;
            case 2:
                std::cout << "Votre solde disponible : " << distributeur.obtenirSolde() << std::endl;
                std::cout << "Entrez le montant à retirer : ";
                std::cin >> montant;
                succes = distributeur.retirerArgent(montant);
                if (succes) {
                    std::cout << "Retrait réussi..." << std::endl;
                } else {
                    std::cout << "Fonds insuffisants..." << std::endl;
                }
                break;
            case 3:
                std::cout << "Entrez le montant à déposer : ";
                std::cin >> montant;
                distributeur.deposerArgent(montant);
                std::cout << "Dépôt réussi..." << std::endl;
                break;
            case 4:
                std::cout << "Merci d'avoir utilisé notre distributeur automatique..." << std::endl;
                break;
            default:
                std::cout << "Choix invalide..." << std::endl;
        }
        std::cout << "\nVoulez-vous effectuer une autre transaction (o/n) : ";
    } while (true);

    return 0;
}
