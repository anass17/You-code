#include <stdio.h>
#include <string.h>

struct livre {
	char titre[50];
	char auteur[50];
	int quantite;
	float prix;
};

typedef struct livre livre;

void afficherMenu();
void afficherLivres(livre livres[], int nbrLivres);
int ajouterLivres(livre livres[], int nbrLivres);
void modifierLivres(livre livres[], int nbrLivres);
int supprimerLivre(livre livres[], int nbrLivres);
void rechercherLivre(livre livres[], int nbrLivres);
void trierLivres(livre livres[], int nbrLivres);
void afficherStatistics(livre livres[], int nbrLivres);

int main () {
	
	int choix;
	livre livres[50] = {{"Premier livre", "Anass Boutaib", 12, 103.5}, {"Autre", "Moi", 1, 12.9}, {"3eme livre", "Unknown", 23, 99.9}, {"The last one", "No one", 10, 125.7}};
	int nbrLivres = 4;
	
	while (1) {
		afficherMenu();
		scanf("%d", &choix);
		getchar();
		
		switch (choix) {
			case 1:
				nbrLivres = ajouterLivres(livres, nbrLivres);
				break;
			case 2:
				modifierLivres(livres, nbrLivres);
				break;
			case 3:
				nbrLivres = supprimerLivre(livres, nbrLivres);
				break;
			case 4:
				rechercherLivre(livres, nbrLivres);
				break;
			case 5:
				trierLivres(livres, nbrLivres);
				break;
			case 6:
				afficherStatistics(livres, nbrLivres);
				break;
			case 0:
				printf("\nMerci pour l'utilisation de ce programme. Au revoir!\n");
				return 0;
			default:
				printf("\nCe choix n'est pas valable\n");
		}
	}
	
	return 0;
}

void afficherMenu() {
	printf("\n");
	printf("-----------------------------\n");
	printf("---   Le menu principal   ---\n");
	printf("-----------------------------\n\n");
	printf("Voici la liste des operations valables:\n\n");
	printf("1. Ajouter un ou plusieurs livres\n");
	printf("2. Modifier un livre\n");
	printf("3. Supprimer un livre\n");
	printf("4. Rechercher un livre\n");
	printf("5. Trier les livres\n");
	printf("6. Afficher les statistiques\n");
	printf("0. Sortir\n");
	printf("\n-->  ");
}

void afficherLivres(livre livres[], int nbrLivres) {
	int i;
	
	printf("\nLa liste des livres valables est:\n\n");
	
	for (i = 0; i < nbrLivres; i++) {
		printf("Titre:     %s\n", livres[i].titre);
		printf("Auteur:    %s\n", livres[i].auteur);
		printf("Quantite:  %d\n", livres[i].quantite);
		printf("Prix:      %.2f DH\n", livres[i].prix);
		printf("\n");
	}
}

int ajouterLivres(livre livres[], int nbrLivres) {
	int sous_choix, i, nbr;
	
	printf("------------------------------------------\n");
	printf("---   Ajouter un ou plusieurs livres   ---\n");
	printf("------------------------------------------\n\n");
	
	if (nbrLivres == 50) {
		printf("( ! ) Le max d'elements est 50");
		return 50;
	}
	
	printf("1. Ajouter un livre\n");
	printf("2. Ajouter plusieurs livres\n");
	printf("\n-->  ");
	scanf("%d", &sous_choix);
	getchar();
	
	if (sous_choix == 1) {
		printf("\n");
		printf("------------------------------------\n");
		printf("---   Ajouter un nouveau livre   ---\n");
		printf("------------------------------------\n\n");
		
		printf("Entrer les details de ce nouveau livre:\n");
		printf("Titre:     ");
		scanf("%[^\n]", livres[nbrLivres].titre);
		getchar();
		printf("Auteur:    ");
		scanf("%[^\n]", livres[nbrLivres].auteur);
		getchar();
		printf("Quantite:  ");
		scanf("%d", &livres[nbrLivres].quantite);
		printf("Prix:      ");
		scanf("%f", &livres[nbrLivres].prix);
		nbrLivres++;
		afficherLivres(livres, nbrLivres);
	} else if (sous_choix == 2) {
		printf("\n");
		printf("----------------------------------------------\n");
		printf("---   Ajouter pleusieurs nouveaux livres   ---\n");
		printf("----------------------------------------------\n\n");
		
		printf("Entrer le nombre d'elements que vous voulez ajouter\n\n-->  ");
		scanf("%d", &nbr);
		getchar();
		printf("\nEntrer les details de ce nouveau livre:\n");
		for (i = 1; i <= nbr; i++) {
			printf("\nLivre #%d\n\n", i);
			printf("Titre:     ");
			scanf("%[^\n]", livres[nbrLivres].titre);
			getchar();
			printf("Auteur:    ");
			scanf("%[^\n]", livres[nbrLivres].auteur);
			getchar();
			printf("Quantite:  ");
			scanf("%d", &livres[nbrLivres].quantite);
			printf("Prix:      ");
			scanf("%f", &livres[nbrLivres].prix);
			getchar();
			nbrLivres++;
		}
		afficherLivres(livres, nbrLivres);
	} else {
		printf("\nCe choix n'existe pas\n");	
	}
	return nbrLivres;
}

void modifierLivres(livre livres[], int nbrLivres) {
	printf("\n");
	printf("-----------------------------\n");
	printf("---   Modifier un livre   ---\n");
	printf("-----------------------------\n\n");
		
	char titre[50];
	int i;
	int sous_choix;
	
	afficherLivres(livres, nbrLivres);
	
	while (1) {
		printf("\nVeuillez entrer le titre de livre que vous voulez modifier:  ");
		scanf("%[^\n]", titre);
		getchar();
		
		i = 0;
		while (i < nbrLivres && strcmp(livres[i].titre, titre) != 0) {
			i++;
		}
		
		if (i == nbrLivres) {
			printf("\nCe livre ne se trouve pas\n");
			continue;
		}
		
		printf("\nLes details de ce livre sont:\n");
		printf("Titre:     %s\n", livres[i].titre);
		printf("Auteur:    %s\n", livres[i].auteur);
		printf("Quantite:  %d\n", livres[i].quantite);
		printf("Prix:      %.2f DH\n", livres[i].prix);
		
		printf("\nVous voulez modifier:\n");
		printf("1. Le titre\n");
		printf("2. La quantite\n");
		printf("3. Le prix\n");
		printf("4. Tous les champs\n");
		printf("0. Annuler\n");
		printf("\n-->  ");
		scanf("%d", &sous_choix);
		getchar();
		
		switch (sous_choix) {
			case 1:
				printf("\nEntrer le nouveau titre:  ");
				scanf("%[^\n]", livres[i].titre);
				getchar();
				break;
			case 2:
				printf("\nEntrer la nouvelle quantite:  ");
				scanf("%d", &livres[i].quantite);
				break;
			case 3:
				printf("\nEntrer le nouveau prix:  ");
				scanf("%f", &livres[i].prix);
				break;
			case 4:
				printf("\nEntrer le nouveau titre:  ");
				scanf("%[^\n]", livres[i].titre);
				getchar();
				printf("\nEntrer la nouvelle quantite:  ");
				scanf("%d", &livres[i].quantite);
				printf("\nEntrer la nouvelle prix:  ");
				scanf("%f", &livres[i].prix);
				break;
			case 0:
				return;
			default:
				printf("\nCe choix n'est pas valable\n");
				continue;
		}
		afficherLivres(livres, nbrLivres);
		return;
	}
	
}

int supprimerLivre(livre livres[], int nbrLivres) {
	int i;
	char titre[50];
	char conf;
	
	if (nbrLivres == 0) {
		printf("\nLa liste est vide\n");
		return nbrLivres;
	}
	
	afficherLivres(livres, nbrLivres);
	
	printf("\nVeuillez entrer le titre du livre que vous voulez supprimer:  ");
	scanf("%[^\n]", titre);
	getchar();
	
	i = 0;
	while (i < nbrLivres && strcmp(livres[i].titre, titre) != 0) {
		i++;	
	}
	
	if (i == nbrLivres) {
		printf("\nCe livre ne se trouve pas\n");
		return nbrLivres;
	}
	
	printf("\nLes details de ce livre sont:\n");
	printf("Titre:     %s\n", livres[i].titre);
	printf("Auteur:    %s\n", livres[i].auteur);
	printf("Quantite:  %d\n", livres[i].quantite);
	printf("Prix:      %.2f DH\n\n", livres[i].prix);
	
	do {
		printf("Confirmer la suppression de ce livre (O/N)");
		scanf("%c", &conf);
	} while (conf != 'O' && conf != 'N');
	
	if (conf == 'O') {
		for (i = i; i < nbrLivres - 1; i++) {
			livres[i] = livres[i + 1];
		}
		nbrLivres--;
		printf("\nLe livre a ete supprimer\n");
		afficherLivres(livres, nbrLivres);
	} else {
		printf("\nL'operation de suppression a ete annuler\n");
	}
	
	return nbrLivres;
}


void rechercherLivre(livre livres[], int nbrLivres) {
	printf("\n");
	printf("-------------------------------\n");
	printf("---   Rechercher un livre   ---\n");
	printf("-------------------------------\n\n");
	
	char titre[50];
	
	afficherLivres(livres, nbrLivres);
	
	printf("\nEntrer le titre de livre a rechercher:  ");
	scanf("%[^\n]", titre);
	getchar();
	
	int i = 0;
	while(i < nbrLivres && strcmp(livres[i].titre, titre) != 0) {
		i++;
	}
	
	if (i == nbrLivres) {
		printf("\nCe livre ne se trouve pas\n");
	} else {
		printf("\nLes details de ce livre sont:\n");
		printf("Titre:     %s\n", livres[i].titre);
		printf("Auteur:    %s\n", livres[i].auteur);
		printf("Quantite:  %d\n", livres[i].quantite);
		printf("Prix:      %.2f DH\n", livres[i].prix);
	}
	
}

void trierLivres(livre livres[], int nbrLivres) {
	printf("\n");
	printf("---------------------------\n");
	printf("---   Trier les livre   ---\n");
	printf("---------------------------\n\n");
	
	int i, j;
	livre temp;
	int sous_choix;
	
	afficherLivres(livres, nbrLivres);
	
	printf("Trier les livres selon l'order:\n");
	printf("1. Croissant\n");
	printf("2. Decroissant\n");
	printf("0. Annuler\n");
	printf("\n-->  ");
	scanf("%d", &sous_choix);
	
	while (1) {
		if (sous_choix == 1) {
			for (i = 0; i < nbrLivres - 1; i++) {
				for (j = 0; j < nbrLivres - i - 1; j++) {
					if (strcmp(livres[j].titre, livres[j + 1].titre) > 0) {
						temp = livres[j];
						livres[j] = livres[j+1];
						livres[j+1] = temp;
					}
				}
			}
			afficherLivres(livres, nbrLivres);
			break;
		} else if (sous_choix == 2) {
			for (i = 0; i < nbrLivres - 1; i++) {
				for (j = 0; j < nbrLivres - i - 1; j++) {
					if (strcmp(livres[j].titre, livres[j + 1].titre) < 0) {
						temp = livres[j];
						livres[j] = livres[j+1];
						livres[j+1] = temp;
					}
				}
			}
			afficherLivres(livres, nbrLivres);
			break;
		} else if (sous_choix == 0) {
			printf("\nL'operation a ete annuler\n");
			return;
		} else {
			printf("\nCe choix n'est pas valable\n");
		}
	}
}

void afficherStatistics(livre livres[], int nbrLivres) {
	int sous_choix, i, count, somme = 0;
	float prix_total = 0;
	livre max[3] = {0};
	
	if (nbrLivres == 0) {
		printf("\n( ! ) La liste est vide\n");
		return;
	}
	
	printf("\n");
	printf("-----------------------------------\n");
	printf("---   Afficher les statistics   ---\n");
	printf("-----------------------------------\n\n");
	printf("1. Afficher la percentage de chaque quantite dans le stockage\n");
	printf("2. Afficher le prix total des livres dans le stockage\n");
	printf("3. Afficher les livres dont la quantite est inferieur a 3\n");
	printf("4. Afficher les trois livres dont le prix est le plus grand\n");
	printf("0. Annuler\n");
	printf("\n-->  ");
	scanf("%d", &sous_choix);
	
	switch (sous_choix) {
		case 1:
			for (i = 0; i < nbrLivres; i++) {
				somme += livres[i].quantite;
			}
			for (i = 0; i < nbrLivres; i++) {
				printf("Titre:      %s\n", livres[i].titre);
				printf("Quantite:   %d\n", livres[i].quantite);
				printf("Percentage: %.2f%%\n\n", (float) (livres[i].quantite * 100) / somme);
			}
			break;
		case 2:
			for (i = 0; i < nbrLivres; i++) {
				prix_total += (float) livres[i].prix * livres[i].quantite;
			}
			printf("\nLe prix total de tous les livres est: %.2f DH\n", prix_total);
			break;
		case 3:
			count = 0;
			printf("\n");
			for (i = 0; i < nbrLivres; i++) {
				if (livres[i].quantite < 3) {
					printf("Titre:     %s\n", livres[i].titre);
					printf("Auteur:    %s\n", livres[i].auteur);
					printf("Quantite:  %d\n", livres[i].quantite);
					printf("Prix:      %.2f DH\n\n", livres[i].prix);
					count++;
				}
			}
			
			if (count == 0) {
				printf("\nAucun livre trouver\n");
			}
			break;
		case 4:
			for (i = 0; i < nbrLivres; i++) {
				if (max[0].prix < livres[i].prix) {
					max[2] = max[1];
					max[1] = max[0];
					max[0] = livres[i];
				} else if (max[1].prix < livres[i].prix) {
					max[2] = max[1];
					max[1] = livres[i];
				} else if (max[2].prix < livres[i].prix) {
					max[2] = livres[i];
				}
			}
			printf("\n");
			for (i = 0; i < 3; i++) {
				printf("Titre:     %s\n", max[i].titre);
				printf("Auteur:    %s\n", max[i].auteur);
				printf("Quantite:  %d\n", max[i].quantite);
				printf("Prix:      %.2f DH\n\n", max[i].prix);
				printf("\n");
			}
			break;
		case 0:
			printf("\nL'operation a ete annuler\n");
			break;
		default:
			printf("\nCe choix n'est pas valide\n");
	}
}
