#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Représentation d'une voiture
struct Voiture {
    int id;
    char categorie[50];
    char marque[50];
    char couleur[50];
    char etat[50];    //  disponible ,  nondisponile,  enPanne
    float tarif;
};
// Représentation d'un client
struct Client {
    int idc;
    char nom[50];
    char prenom[50];
    char adresse[50];
    int telephone;
    int point;
};
// Représentation d'une location
struct Location {
    int idl;
    int id;
    int idc;
    char AgenceDepart[50];
    char AgenceRetour[50];
    char DateDebut[50];
    int nombrej;   // Nombre de jours de location
    float coutTotal;
};
void Afficher_Menu();
void CategorieVoiture(struct Voiture *cars, int numV);
void Listelocalisation();
void verifierVoiture(struct Voiture *cars, int numV);
void AjoutClient(struct Client **clients, int *numC);
void louerVoiture(struct Voiture *cars, int numV, struct Client *clients, int numC, struct Location **locations, int *numL);
void ListeClients(struct Client *clients, int numC);
void SupprimerClient(struct Client **clients, int *numC);
void AjoutVoiture(struct Voiture **cars, int *numV);
void SupprimerVoiture(struct Voiture **cars, int *numV);
void ModifVoiture(struct Voiture *cars, int numV);
void RetourVoiture(struct Voiture *cars, int numV);
void ConsulterPoints(struct Client *clients, int numC);
void ConsulterHistorique(struct Location *locations, int numL);
void quitterProgramme(struct Voiture *cars, int numV, struct Client *clients, int numC, struct Location *locations, int numL) {
    free(cars);
    free(clients);
    free(locations);
    exit(0);
}

int main() {
    struct Voiture *cars = NULL;
    struct Client *clients = NULL;
    struct Location *locations = NULL;
    int numV = 100;
    int numC = 100;
    int numL = 100;
    int ch;

    cars = (struct Voiture *)malloc(sizeof(struct Voiture) * numV);
    clients = (struct Client *)malloc(sizeof(struct Client) * numC);
    locations = (struct Location *)malloc(sizeof(struct Location) * numL);

    cars = (struct Voiture *)malloc(sizeof(struct Voiture) * (numV));
    if (cars == NULL) {
        printf("Erreur d'allocation mémoire pour le tableau de voitures.\n");
        exit(EXIT_FAILURE);
    }
    clients = (struct Client *)malloc(sizeof(struct Client) * (numC));
    if (clients == NULL) {
        printf("Erreur d'allocation mémoire pour le tableau de clients.\n");
        exit(EXIT_FAILURE);
    }
    locations = (struct Location *)malloc(sizeof(struct Location) * (numL));
    if (locations == NULL) {
        printf("Erreur d'allocation mémoire pour le tableau de locations.\n");
        exit(EXIT_FAILURE);
    }
    numV = 100;
    numC = 100;
    numL = 100;
    // Initialisation de voitures
    cars[0].id = 1;
    strcpy(cars[0].categorie, "economique");
    strcpy(cars[0].marque, "ToyotaYaris");
    strcpy(cars[0].couleur, "gris");
    strcpy(cars[0].etat, "disponible");
    cars[0].tarif = 95;

    cars[1].id = 2;
    strcpy(cars[1].categorie, "economique");
    strcpy(cars[1].marque, "Clio");
    strcpy(cars[1].couleur, "bleu");
    strcpy(cars[1].etat, "disponible");
    cars[1].tarif = 95;

    cars[2].id = 3;
    strcpy(cars[2].categorie, "economique");
    strcpy(cars[2].marque ,"Peugeot301");
    strcpy(cars[2].etat, "disponible");
    cars[2].tarif = 110;

    cars[3].id = 4;
    strcpy(cars[3].categorie, "luxueuse");
    strcpy(cars[3].marque, "MercedesClasseE");
    strcpy(cars[3].couleur, "noir");
    strcpy(cars[3].etat, "disponible");
    cars[3].tarif = 220;

    cars[4].id = 5;
    strcpy(cars[4].categorie,"luxueuse");
    strcpy(cars[4].marque, "PorchePanamera");
    strcpy(cars[4].couleur, "blanc");
    strcpy(cars[4].etat, "disponible");
    cars[4].tarif = 300;

    cars[5].id = 6;
    strcpy(cars[5].categorie, "spotive");
    strcpy(cars[5].marque,"Ferrari");
    strcpy(cars[5].couleur, "rouge");
    strcpy(cars[5].etat, "disponible");
    cars[5].tarif = 1200;

    cars[6].id = 7;
    strcpy(cars[6].categorie, "minivan");
    strcpy(cars[6].marque, "VolkswagenTransporter9places");
    strcpy(cars[6].couleur, "gris");
    strcpy(cars[6].etat, "disponible");
    cars[6].tarif = 900;
   //premier client
    clients[0].idc = 1;
    strcpy(clients[0].nom, "AMRI");
    strcpy(clients[0].prenom, "EYA");
    strcpy(clients[0].adresse, "Tunis");
    clients[0].telephone =123 ;
    clients[0].point = 0 ;
    //premiere location
    locations[0].idl=1;
    locations[0].id = 1;
    locations[0].idc = 1;
    strcpy(locations[0].AgenceDepart, "Tunis");
    strcpy(locations[0].AgenceRetour, "Ariana");
    strcpy(locations[0].DateDebut, "30/12/2023");
    locations[0].nombrej = 2;   // Nombre de jours de location
    locations[0].coutTotal= cars[locations[0].id-1].tarif*locations[0].nombrej;

    do {
        Afficher_Menu();
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                CategorieVoiture(cars, numV);
                break;
            case 2:
                Listelocalisation();
                break;
            case 3:
                verifierVoiture(cars, numV);
                break;
            case 4:
                AjoutClient(&clients, &numC);
                break;
            case 5:
                louerVoiture(cars, numV, clients, numC, &locations, &numL);
                break;
            case 6:
                SupprimerClient(&clients, &numC);
                break;
            case 7:
                AjoutVoiture(&cars, &numV);
                break;
            case 8:
                SupprimerVoiture(&cars, &numV);
                break;
            case 9:
                ModifVoiture(cars, numV);
                break;
            case 10:
                ConsulterPoints(clients, numC);
                break;
            case 11:
                ConsulterHistorique(locations, numL);
                break;
            case 12:
                RetourVoiture(cars, numV);
                break;
            case 13:
                ListeClients(clients, numC);
                break;
            case 14:
                quitterProgramme(cars,numV,clients,numC,locations,numL);
                break;
            default:
                printf(" Veuillez ressayer s'il vous plaît.\n");
        }
    } while (ch != 14);
    return 0;
}
void Afficher_Menu() {
    printf("\n***  APPLICATION DE LOCATION DE VOITURES : E-CARS ***\n");
    printf("1- Choisir la categorie de voiture : E-CARS vous offre quatre categories (economique,luxueuse,sportive,minivan)\n");
    printf("2- Afficher nos localisations \n");
    printf("3- Verifier si un voiture est disponible\n");
    printf("4- Ajouter un nouveau client \n");
    printf("5- Louer une voiture \n");
    printf("6- Supprimer un client existant \n");
    printf("7- Ajouter une nouvelle voiture \n");
    printf("8- Supprimer une voiture en panne \n");
    printf("9- Mettre a jour les informations d'une voiture \n");
    printf("10- Consulter mes points merci \n");
    printf("11- Consulter l'historique \n");
    printf("12- Retour d'une voiture en cas de reclamation \n");
    printf("13-Afficher la liste des clients \n");
    printf("14-Quitter le programme \n");
    printf(" Saisir votre choix :\n");
}

void CategorieVoiture(struct Voiture *cars, int numV) {
    char categ[50];
    printf("Donner une categorie : ");
    scanf("%s", categ);
    printf("\nVoitures de la categorie %s :\n", categ);
    int i;
    for (i = 0; i < numV; i++) {
        if (strcmp(cars[i].categorie, categ) == 0) {
            printf("ID: %d, Marque: %s, Couleur: %s, Etat: %s, Tarif: %.2f\n",
                   cars[i].id, cars[i].marque, cars[i].couleur, cars[i].etat, cars[i].tarif);
        }
    }
}
void Listelocalisation() {
    printf("1.Tunis ;2.Bardo ;3.Ariana ;4.Ben Arous \n");
}
void verifierVoiture(struct Voiture *cars, int numV) {
    int idv;
    printf("Entrez l'ID de la voiture à vérifier : ");
    scanf("%d", &idv);

    for (int i = 0; i < numV; i++) {
        if (cars[i].id == idv) {
            if (strcmp(cars[i].etat, "disponible") == 0) {
                printf("La voiture avec l'ID %d est disponible.\n", idv);
            } else if (strcmp(cars[i].etat, "nondisponible") == 0) {
                printf("La voiture avec l'ID %d est actuellement louee.\n", idv);
            } else if (strcmp(cars[i].etat, "enPanne") == 0) {
                printf("La voiture avec l'ID %d est en panne.\n", idv);
            } else {
                printf("Identificateur non valide, veuillez ressayer.\n");
            }
            return;
        }
    }
    printf("Aucune voiture avec l'ID %d n'a ete trouvee.\n", idv);
}
void AjoutVoiture(struct Voiture **cars, int *numV) {
    *numV = *numV + 1;
    *cars = (struct Voiture *)realloc(*cars, sizeof(struct Voiture) * (*numV));

    if (*cars == NULL) {
        printf("Erreur d'allocation mémoire pour la nouvelle voiture.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez les informations de la nouvelle voiture :\n");
    (*cars)[*numV - 1].id = *numV;
    printf("Categorie : ");
    scanf("%s", (*cars)[*numV - 1].categorie);
    printf("Marque : ");
    scanf("%s", (*cars)[*numV - 1].marque);
    printf("Couleur : ");
    scanf("%s", (*cars)[*numV - 1].couleur);
    printf("Etat (disponible, nondisponible, enPanne) : ");
    scanf("%s", (*cars)[*numV - 1].etat);
    printf("Tarif : ");
    scanf("%f", &((*cars)[*numV - 1].tarif));

    printf("Nouvelle voiture ajoutee avec succès.\n");
}

void ModifVoiture(struct Voiture *cars, int numV) {
    int idv;
    printf("Entrez l'ID de la voiture à modifier : ");
    scanf("%d", &idv);

    for (int i = 0; i < numV; i++) {
        if (cars[i].id == idv) {
            printf("Entrez les nouveaux détails de la voiture :\n");
            printf("Categorie : ");
            scanf("%s", cars[i].categorie);
            printf("Marque : ");
            scanf("%s", cars[i].marque);
            printf("Couleur : ");
            scanf("%s", cars[i].couleur);
            printf("Etat (disponible, nondisponible, enPanne) : ");
            scanf("%s", cars[i].etat);
            printf("Tarif : ");
            scanf("%f", &cars[i].tarif);

            printf("Voiture modifiee avec succes.\n");
            return;
        }
    }

    printf("Aucune voiture avec l'ID %d n'a ete trouvee.\n", idv);
}

void SupprimerVoiture(struct Voiture **cars, int *numV) {
    int idv;
    printf("Entrez l'ID de la voiture à supprimer : ");
    scanf("%d", &idv);
    int i,j;
    for (i = 0; i < *numV; i++) {
        if ((*cars)[i].id == idv) {
            for (j = i; j < *numV - 1; j++) {
                (*cars)[j] = (*cars)[j + 1];
            }
            *numV = *numV - 1;
            *cars = (struct Voiture *)realloc(*cars, sizeof(struct Voiture) * (*numV));

            printf("Voiture supprimee avec succes.\n");
            return;
        }
    }

    printf("Aucune voiture avec l'ID %d n'a ete trouvee.\n", idv);
}

void AjoutClient(struct Client **clients, int *numC) {
    *numC = *numC + 1;
    *clients = (struct Client *)realloc(*clients, sizeof(struct Client) * (*numC));

    if (*clients == NULL) {
        printf("Erreur d'allocation mémoire pour le nouveau client.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez les informations du nouveau client :\n");
    (*clients)[*numC - 1].idc = *numC;
    printf("Nom : ");
    scanf("%s", (*clients)[*numC - 1].nom);
    printf("Prenom : ");
    scanf("%s", (*clients)[*numC - 1].prenom);
    printf("Adresse : ");
    scanf("%s", (*clients)[*numC - 1].adresse);
    printf("Telephone : ");
    scanf("%d", &((*clients)[*numC - 1].telephone));
    printf("Points : ");
    scanf("%d", &((*clients)[*numC - 1].point));

    printf("Nouveau client ajoute avec succes.\n");
}
void SupprimerClient(struct Client **clients, int *numC) {
    int idc;
    printf("Entrez l'ID du client a supprimer : ");
    scanf("%d", &idc);

    for (int i = 0; i < *numC; i++) {
        if ((*clients)[i].idc == idc) {
            for (int j = i; j < *numC - 1; j++) {
                (*clients)[j] = (*clients)[j + 1];
            }
            *numC = *numC - 1;
            *clients = (struct Client *)realloc(*clients, sizeof(struct Client) * (*numC));

            printf("Client supprimé avec succès.\n");
            return;
        }
    }

    printf("Aucun client avec l'ID %d n'a ete trouve.\n", idc);
}
void ListeClients(struct Client *clients, int numC) {
    printf("\nListe des clients :\n");
    for (int i = 0; i < numC; i++) {
        printf("ID: %d, Nom: %s, Prenom: %s, Adresse: %s, Telephone: %d, Points: %d\n",
               clients[i].idc, clients[i].nom, clients[i].prenom, clients[i].adresse,
               clients[i].telephone, clients[i].point);
    }
}
void ConsulterPoints(struct Client *clients, int numC) {
    int idc;
    printf("Entrez l'ID du client pour consulter les points : ");
    scanf("%d", &idc);
    for (int i = 0; i < numC; i++) {
        if (clients[i].idc == idc) {
            printf("Le client avec l'ID %d a maintenant %d points.\n", idc, clients[i].point);
            return;
        }
    }
    printf("Aucun client avec l'ID %d n'a ete trouve.\n", idc);
}
void louerVoiture(struct Voiture *cars, int numV, struct Client *clients, int numC, struct Location **locations, int *numL) {
    int idc, idv, jours;
    printf("Entrez l'ID du client : ");
    scanf("%d", &idc);

    int clientExiste = 0;
    int ptmerci =0;
    for (int i = 0; i < numC; i++) {
        if (clients[i].idc == idc) {
            clientExiste = 1;
            clients[i].point += 20;
            ptmerci = clients[i].point;
            break;
        }
    }

    if (!clientExiste) {
        printf("Aucun client avec l'ID %d n'a ete trouve.\n", idc);
        return;
    }

    printf("Entrez l'ID de la voiture à louer : ");
    scanf("%d", &idv);
    int voitureDisponible = 0;
    for (int i = 0; i < numV; i++) {
        if (cars[i].id == idv && strcmp(cars[i].etat, "disponible") == 0) {
            voitureDisponible = 1;
            break;
        }
    }
    if (!voitureDisponible) {
        printf("La voiture avec l'ID %d n'est pas disponible.\n", idv);
        return;
    }
    printf("Entrez le nombre de jours de location : ");
    scanf("%d", &jours);
    for (int i = 0; i < numV; i++) {
        if (cars[i].id == idv) {
            strcpy(cars[i].etat, "nondisponible");
            break;
        }
    }

    float tarif = cars[idv - 1].tarif;
    float coutTotal = tarif * jours;
    if (ptmerci = 120){
        coutTotal -=100;
    }
    if (jours > 2) {
        coutTotal *= 0.9;  // Réduction de 10% pour plus de 2 jours
    }
    if (jours > 5) {
        coutTotal *= 0.8;  // Réduction de 20% pour plus de 5 jours
    }
    *locations = realloc(*locations, (*numL + 1) * sizeof(struct Location));
    if (*locations == NULL) {
        printf("Erreur d'allocation mémoire pour la location.\n");
        exit(EXIT_FAILURE);
    }
    (*locations)[*numL].idl = *numL + 1;
    (*locations)[*numL].id = idv;
    (*locations)[*numL].idc = idc;
    strcpy((*locations)[*numL].AgenceDepart, "Agence de depart");
    strcpy((*locations)[*numL].AgenceRetour, "Agence de retour");
    strcpy((*locations)[*numL].DateDebut, "30/12/2023");  //
    (*locations)[*numL].nombrej = jours;
    (*locations)[*numL].coutTotal = coutTotal;
    (*numL)++;
    printf("Location e avec succes. Cout total : %.2f\n", coutTotal);
}

void ConsulterHistorique(struct Location *locations, int numL) {
    int idl;
    printf("Entrez l'ID de la location a consulter : ");
    scanf("%d", &idl);

    for (int i = 0; i < numL; i++) {
        if (locations[i].idl == idl) {
            printf("ID de la location : %d\n", locations[i].idl);
            printf("ID de la voiture louée : %d\n", locations[i].id);
            printf("ID du client : %d\n", locations[i].idc);
            printf("Agence de départ : %s\n", locations[i].AgenceDepart);
            printf("Agence de retour : %s\n", locations[i].AgenceRetour);
            printf("Date de début : %s\n", locations[i].DateDebut);
            printf("Nombre de jours de location : %d\n", locations[i].nombrej);
            printf("Cout total : %.2f\n", locations[i].coutTotal);
            return;
        }
    }

    printf("Aucune location avec l'ID %d n'a ete trouvee.\n", idl);
}
void RetourVoiture(struct Voiture *cars, int numV) {
    int idv;
    char localisation[50];
    char cause[100];
    printf("Entrez l'ID de la voiture à retourner : ");
    scanf("%d", &idv);
    int voitureExiste = 0;
    int index = -1;

    for (int i = 0; i < numV; i++) {
        if (cars[i].id == idv) {
            voitureExiste = 1;
            index = i;
            break;
        }
    }
    if (!voitureExiste) {
        printf("Aucune voiture avec l'ID %d n'a ete trouvee.\n", idv);
        return;
    }
    if (strcmp(cars[index].etat, "enPanne") == 0) {
        printf("La voiture est en panne. Suppression en cours...\n");
        for (int i = index; i < numV - 1; i++) {
            cars[i] = cars[i + 1];
        }
        printf("La voiture en panne a été supprimée.\n");
        return;
    }
    printf("Entrez la localisation du retour : ");
    scanf("%s", localisation);
    printf("Entrez la cause du retour : ");
    scanf("%s", cause);
    strcpy(cars[index].etat, "disponible");
    float sanction = 0.5 * cars[index].tarif;
    printf("La voiture est disponible. Sanction financière : %.2f\n", sanction);
}
