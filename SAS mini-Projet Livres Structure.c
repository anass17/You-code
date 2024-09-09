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
void rechercherLivre(livre livres[], int nbrLivres);
void trierLivres(livre livres[], int nbrLivres);

int main () {
	
	int choix;
	livre livres[50] = {{"First", "Anass", 12, 103.5}, {"Second", "Metoo", 23, 99.9}, {"Another", "Boutaib", 10, 125.7}, {"Last", "Again", 6, 113.9}};
	int nbrLivres = 4;
	
	while (1) {
		afficherMenu();
		scanf("%d", &choix);
		
		switch (choix) {
			case 1:
				nbrLivres = ajouterLivres(livres, nbrLivres);
				break;
			case 2:
				modifierLivres(livres, nbrLivres);
				break;
			case 4:
				rechercherLivre(livres, nbrLivres);
				break;
			case 5:
				trierLivres(livres, nbrLivres);
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
	printf("-----------------------------\n");
	printf("Voici la liste des operations valables:\n");
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
	
	if (sous_choix == 1) {
		printf("\n");
		printf("------------------------------------\n");
		printf("---   Ajouter un nouveau livre   ---\n");
		printf("------------------------------------\n\n");
		
		printf("Entrer les details de ce nouveau livre:\n");
		printf("Titre:     ");
		scanf("%s", livres[nbrLivres].titre);
		printf("Auteur:    ");
		scanf("%s", livres[nbrLivres].auteur);
		printf("Quantite:  ");
		scanf("%d", &livres[nbrLivres].quantite);
		printf("Prix:      ");
		scanf("%f", &livres[nbrLivres].prix);
		afficherLivres(livres, nbrLivres);
		nbrLivres++;
	} else if (sous_choix == 2) {
		printf("\n");
		printf("----------------------------------------------\n");
		printf("---   Ajouter pleusieurs nouveaux livres   ---\n");
		printf("----------------------------------------------\n\n");
		
		printf("Entrer le nombre d'elements que vous voulez ajouter\n\n-->  ");
		scanf("%d", &nbr);
		printf("\nEntrer les details de ce nouveau livre:\n");
		for (i = 1; i <= nbr; i++) {
			printf("\nLivre #%d\n\n", i);
			printf("Titre:     ");
			scanf("%s", livres[nbrLivres].titre);
			printf("Auteur:    ");
			scanf("%s", livres[nbrLivres].auteur);
			printf("Quantite:  ");
			scanf("%d", &livres[nbrLivres].quantite);
			printf("Prix:      ");
			scanf("%f", &livres[nbrLivres].prix);
			nbrLivres++;
		}
		afficherLivres(livres, nbrLivres);
	} else {
		printf("\nCe choix n'existe pas\n");	
	}
	return nbrLivres;
}

void modifierLivres(livre livres[], int nbrLivres) {
	char titre[50];
	int i;
	int sous_choix;
	
	afficherLivres(livres, nbrLivres);
	
	while (1) {
		printf("\nVeuillez choisir le titre de livre que vous voulez modifier\n\n-->  ");
		scanf("%s", titre);
		
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
		
		switch (sous_choix) {
			case 1:
				printf("\nEntrer le nouveau titre:  ");
				scanf("%s", livres[i].titre);
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
				scanf("%s", livres[i].titre);
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

void rechercherLivre(livre livres[], int nbrLivres) {
	char titre[50];
	
	afficherLivres(livres, nbrLivres);
	
	printf("\nEntrer le titre de livre a rechercher:  ");
	scanf("%s", titre);
	
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
	livre copie[50];
	int i;
	
	afficherLivres(livres, nbrLivres);
	
	for (i = 0; i < nbrLivres; i++) {
		copie[i] = livres[i];
	}
	
	printf("Trier les livres selon l'order:\n");
}
