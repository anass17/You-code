#include <stdio.h>
#include <string.h>

struct contact {
	char nom[31];
	char numero[16];
	char email[31];
};

int main() {
	
	int operation;
	int totaleContact = 2;
	struct contact listeContact[50] = {{"Anass Boutaib", "0645788745", "anass.bt@gmail.com"}, {"Mohamed Alami", "0678954213", "md.alami.26@gmail.com"}};
	
	char nom[31];
	int i;
	int count;
	char confirmation;
	
	while (1) {
		
		printf("\n");
		printf("-------------------------------\n");
		printf("---     Menu Principale     ---\n");
		printf("-------------------------------\n");
		printf("\n");
		
		printf("La liste des operations valable est:\n\n");
		printf("1. Ajouter un contact\n");
		printf("2. Modifier un contact\n");
		printf("3. Supprimer un contact\n");
		printf("4. Afficher tous les contact\n");
		printf("5. Rechercher un contact\n");
		printf("0. Sortir\n");
		
		printf("\n-->  ");
		scanf("%d", &operation);
		getchar();
	
		switch (operation) {
			case 1:
				printf("\n");
				printf("----------------------------------\n");
				printf("---     Ajouter un contact     ---\n");
				printf("----------------------------------\n");
				printf("\n");
				
				if (totaleContact == 50) {
					printf("\nErreur: Le programme ne peut ajouter un autre contact\n");
					break;
				}
				
				printf("Veuillez entrer les donnees de contact:\n");
				printf("Nom    [Max: 30]\n-->  ");
				scanf("%30[^\n]", listeContact[totaleContact].nom);
				getchar();
				printf("Numero [Max: 15]\n-->  ");
				scanf("%15[^\n]", listeContact[totaleContact].numero);
				getchar();
				printf("Email  [Max: 30]\n-->  ");
				scanf("%30[^\n]", listeContact[totaleContact].email);
				getchar();
				
				printf("\nLe contact etait ajouter!\n");
				totaleContact++;
				
				break;
			case 2:
				printf("\n");
				printf("-----------------------------------\n");
				printf("---     Modifier un contact     ---\n");
				printf("-----------------------------------\n");
				printf("\n");
				
				if (totaleContact == 0) {
					printf("La liste des contacts est vide\n");
					break;
				}
				
				printf("Entrer le nom du contact pour le modifier:\n-->  ");
				scanf("%30[^\n]", nom);
				getchar();
				
				for (i = 0; i < totaleContact; i++) {
					if (strcmp(nom, listeContact[i].nom) == 0) {
						printf("\n\nLes details de contact:\n\n");
						printf("Nom:                  %s\n", listeContact[i].nom);
						printf("Numero de Telephone:  %s\n", listeContact[i].numero);
						printf("Address Email:        %s\n", listeContact[i].email);
						printf("\n");
						break;
					}
				}
				
				if (i == totaleContact) {
					printf("\nCe contact n'existe pas\n");
					break;
				}
				
				printf("\nVeuillez choisir l'inforamtion a modifier\n");
				printf("1. Modifier le numero de telephone\n");
				printf("2. Modifier l'address mail\n");
				printf("3. Modifier les deux\n");
				printf("-->  ");
				
				scanf("%d", &operation);
				
				switch (operation) {
					case 1:
						printf("\nEntrer le nouveau numero de telephone:\n");
						scanf("%s", listeContact[i].numero);
						printf("\nLe numero de telephone etait modifie\n");
						break;
					case 2:
						printf("\nEntrer le nouveau address mail:\n");
						scanf("%s", listeContact[i].email);
						printf("\nL'address mail etait modifie\n");
						break;
					case 3:
						printf("\nEntrer le nouveau numero de telephone:\n");
						scanf("%s", listeContact[i].numero);
						printf("\nEntrer le nouveau address mail:\n");
						scanf("%s", listeContact[i].email);
						printf("\nLe numero de telephone et l'address mail ont ete modifie\n");
						break;
					default:
						printf("\nCe choix n'est valide\n");
				}
				break;
			case 3:
				printf("\n");
				printf("------------------------------------\n");
				printf("---     Supprimer un contact     ---\n");
				printf("------------------------------------\n");
				printf("\n");
				
				if (totaleContact == 0) {
					printf("La liste des contacts est vide\n");
					break;
				}
				
				printf("Entrer le nom du contact pour le supprimer:\n-->  ");
				scanf("%30[^\n]", nom);
				getchar();
				
				for (i = 0; i < totaleContact; i++) {
					if (strcmp(nom, listeContact[i].nom) == 0) {
						printf("\n\nLes details de contact:\n\n");
						printf("Nom:                  %s\n", listeContact[i].nom);
						printf("Numero de Telephone:  %s\n", listeContact[i].numero);
						printf("Address Email:        %s\n", listeContact[i].email);
						printf("\n");
						break;
					}
				}
				
				if (i == totaleContact) {
					printf("\nCe contact n'existe pas\n");
					break;
				} else {
					printf("\nConfirmer la suppression de ce contact: (Y/N)\n-->  ");
					scanf("%c", &confirmation);
					getchar();
					if (confirmation == 'Y' || confirmation == 'y') {
						printf("A");
						for (i = i; i < totaleContact; i++) {
							listeContact[i] = listeContact[i + 1];
						}
						totaleContact--;
						printf("\nLe contact a ete supprimer\n");
					}
				}
				
				break;
			case 4:
				printf("\n");
				printf("------------------------------------------\n");
				printf("---     Afficher tous les contacts     ---\n");
				printf("------------------------------------------\n");
				printf("\n");
				
				if (totaleContact == 0) {
					printf("La liste des contact est vide\n");
					break;
				}
				
				printf("+-----------------------------------------------------------------------------------+\n");
				printf("| %-30s | %-15s | %-30s |\n", "Nom", "Numero", "Address Email");
				printf("+-----------------------------------------------------------------------------------+\n");
				
				for (i = 0; i < totaleContact; i++) {
					printf("| %-30s | %-15s | %-30s |\n", listeContact[i].nom, listeContact[i].numero, listeContact[i].email);
					printf("+-----------------------------------------------------------------------------------+\n");
				}
				
				printf("\nLe nombre de resultats est: %d\n", totaleContact);
				
				break;
			case 5:
				printf("\n");
				printf("-------------------------------------\n");
				printf("---     Rechercher un contact     ---\n");
				printf("-------------------------------------\n");
				printf("\n");
				
				if (totaleContact == 0) {
					printf("La liste des contact est vide\n");
					break;
				}
				
				printf("\nVeuillez entrer le nom de contact a rechercher\n-->  ");
				scanf("%30[^\n]", nom);
				getchar();
				
				count = 0;
				
				printf("\nListe des reultat trouver:\n\n");
				printf("+-----------------------------------------------------------------------------------+\n");
				printf("| %-30s | %-15s | %-30s |\n", "Nom", "Telephone", "Address Email");
				printf("+-----------------------------------------------------------------------------------+\n");
				for (i = 0; i < totaleContact; i++) {
					if (strstr(listeContact[i].nom, nom) != NULL) {
						printf("| %-30s | %-15s | %-30s |\n", listeContact[i].nom, listeContact[i].numero, listeContact[i].email);
						printf("+-----------------------------------------------------------------------------------+\n");
						count++;
					}
				}
				
				if (count == 0) {
					printf("| %-81s |\n", "Aucun resultat trouve");
					printf("+-----------------------------------------------------------------------------------+\n");
				} else {
					printf("\nLe nombre totale des resultat est: %d\n", count);
				}			
				
				break;
			case 0:
				printf("\nMerci pour l'utilisation de ce programme. Au revoir!\n");
				return 0;
				
			default:
				printf("\nCet operation n'existe pas\n");
		}
	}
	
	return 0;
}


