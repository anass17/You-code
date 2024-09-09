#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct produit {			// Definir la structure qui va prend les details de produit
	int code;				// Le code
	char nom[30];			// Le nom
	int quantite;
	float prix;
	struct produit *suivantNom;
	struct produit *suivantPrix;
};

struct produit *teteNom = NULL;
struct produit *tetePrix = NULL;

int lireProduits();
int ajouterProduit();
void listerProduits();
void acheterProduit();
void rechercher();
void etatStock();
void alimenterStock();
void supprimerProduit();
void afficherStats();

int main () {
	
	int op, nbrPro, i, count = 0;
	
	if (lireProduits() == 0) {
		return 0;
	}

	do {
		printf("\n");
		printf("###############################\n");
		printf("###### Le Menu Principal ######\n");
		printf("###############################\n\n");
		
		printf("Veuillez choisir une operation (1-9) parmi la liste suivante:\n\n");
		printf("1. Ajouter un nouveau produit\n");					// Done
		printf("2. Ajouter plusieur nouveaux produits\n");			// Done
		printf("3. Lister tous les produits\n");					// Done
		printf("4. Acheter un produit\n");							// Done
		printf("5. Rechercher les produits\n");						// Done
		printf("6. L\'etat du stock\n");							// Done
		printf("7. Alimenter le stock\n");							// Done
		printf("8. Supprimer un produit\n");						// Done
		printf("9. Les statistiques de vente\n");					// Done
		printf("0. Sortir\n");
		printf("\n");
		
		printf("Votre choix:\t");
		scanf("%d", &op);
		
		switch (op) {
			case 1:
				printf("\n");
				printf("#################################\n");
				printf("##### 1. Ajouter un produit #####\n");
				printf("#################################\n\n");
				printf("Entrer les details de ce nouveau produit:\n");
				
				ajouterProduit();

				break;
			case 2:
				printf("\n");
				printf("#########################################\n");
				printf("##### 2. Ajouter plusieurs produits #####\n");
				printf("#########################################\n\n");
				printf("Entrer le nombre d'elements a ajouter:\t");
				scanf("%d", &nbrPro);
				printf("\n");
				
				if (nbrPro < 1) {
					printf("Vous devez ajouter au moins un element\n");
					break;
				}
				
				count = 0;
				i = 1;
				
				for (i = 1; i <= nbrPro; i++) {
					printf("\nEntrer les details de ce nouveau produit #%d:\n", i);
					count += ajouterProduit();
				}
				
				// Afficher un message qui contient le nombre de produits ajouter
				if (count == 0) {
					printf("\nAucun produit etait ajouter\n", count);	
				} else if (count == 1) {
					printf("\n1 produit est ajouter\n", count);	
				} else {
					printf("\n%d produits sont ajouter\n", count);	
				}
				
				
				break;
			case 3:
				printf("\n");
				printf("######################################\n");
				printf("##### 3. Lister tous les produit #####\n");
				printf("######################################\n\n");
				
				listerProduits();
				
				break;
			case 4:
				printf("\n");
				printf("#################################\n");
				printf("##### 4. Acheter un produit #####\n");
				printf("#################################\n\n");
				
				acheterProduit();
				
				break;
			case 5:
				printf("\n");
				printf("######################################\n");
				printf("##### 5. Rechercher les produits #####\n");
				printf("######################################\n\n");
				
				rechercher();
				break;
			case 6:
				printf("\n");
				printf("##############################\n");
				printf("##### 6. L'etat du stock #####\n");
				printf("##############################\n\n");
				
				etatStock();
				break;
			case 7:
				printf("\n");
				printf("#################################\n");
				printf("##### 7. Alimenter le stock #####\n");
				printf("#################################\n\n");
				
				alimenterStock();
				
				break;
			case 8:
				printf("\n");
				printf("###################################\n");
				printf("##### 8. Supprimer un produit #####\n");
				printf("###################################\n\n");
				
				supprimerProduit();
				
				break;
			case 9:
				printf("\n");
				printf("########################################\n");
				printf("##### 9. Les statistiques de vente #####\n");
				printf("########################################\n\n");
				
				afficherStats();
				break;
			case 0:
				printf("\nMerci pour l'utilisation de ce programme. Au revoir!\n");
				break;
			default:
				printf("Cet operation n'est pas valid\n");
		}
		
		do {
			printf("\n");
			printf("#########################################\n");
			printf("1. Returner au menu\n");
			printf("0. Sortir\n\n");
			
			scanf("%d", &op);
			
			if (op == 0) {
				printf("\nMerci pour l'utilisation de ce programme. Au revoir!\n");
				return 0;
			} else if (op != 1) {
				printf("\nCet operation n'existe pas\n");
			}
		} while (op != 0 && op != 1);
	} while(op != 0);

	
	return 0;
}

// 0. Lire le fichier produits.txt et stocker les produits

int lireProduits() {
	struct produit *nouveau, *courantNom, *courantPrix, *prec;							// Le pointeur qui va etre retourner
	
	FILE *fichier;
	char content[256];
	
	fichier = fopen("produits.txt", "r");
	
	if (fichier == NULL) {
		printf("Erreur: Le programme ne peut pas ouvrir le fichier produits.txt\n");
		return 0;
	}

	while (fgets(content, sizeof(content), fichier) != NULL) {
		nouveau = malloc(sizeof(struct produit));
		
		if (nouveau == NULL) {
			printf("Erreur: Le programme ne peut pas reserver une autre espace\n");
			return 0;
		}
		
		nouveau -> code = atoi(content);
		fgets(content, sizeof(content), fichier);
		strcpy(nouveau -> nom, content);
		nouveau -> nom[strlen(nouveau -> nom) - 1] = '\0';			// Supprimer '\n' a la fin de chaine de characteres
		fgets(content, sizeof(content), fichier);
		nouveau -> quantite = atoi(content);
		fgets(content, sizeof(content), fichier);
		nouveau -> prix = atof(content);
		fgets(content, sizeof(content), fichier);
		
		// Name list
		
		nouveau -> suivantNom = NULL;
		
		if (teteNom == NULL) {
			teteNom = nouveau;
		} else {
			courantNom -> suivantNom = nouveau;
		}
		courantNom = nouveau;
		
		// Price test
		
		courantPrix = tetePrix;
		prec = NULL;
		
		while (courantPrix != NULL && courantPrix -> prix > nouveau -> prix) {
			prec = courantPrix;
			courantPrix = courantPrix -> suivantPrix;
		}
	
		nouveau -> suivantPrix = courantPrix;
		
		if (prec == NULL) {
			tetePrix = nouveau;
		} else {
			prec -> suivantPrix = nouveau;
		}
        
    }
	fclose(fichier);

	return 1;
}

// 1-2. Ajouter un produit

int ajouterProduit () {							// Ajouter un produit, retourner un pointeur vers le nouvel element
	struct produit *nouveau, *courant, *prec;		// Pointeur qui va etre retourner
	nouveau = malloc(sizeof(struct produit));		// Reserver une espace memoire
	
	FILE *fichier;
	
	if (nouveau == NULL) {							// Si malloc n'est pas reserve une espace dans la memoire
		printf("Erreur: Le programme ne peut pas reserver une autre espace memoire\n");
        return 0;
    }
    
	fichier = fopen("produits.txt", "w");
	
	if (fichier == NULL) {
		printf("Erreur: Le programme ne peut pas ouvrir le fichier produits.txt\n");
	}
	int codeValide = 1;
	char valeur[50];
	int i;
	
	while(codeValide) {	
		printf("Code:\t");
		scanf("%s", valeur);								// Lire la valeur de code
		for (i = 0; i < strlen(valeur); i++) {
			if (isdigit(valeur[i])) {
				codeValide = 0;
				continue;
			} else {
				printf("\nErreur: La valeur doit etre un nombre\n\n");
				codeValide = 1;
				break;
			}
		}
		
	}
	
	nouveau->code = atoi(valeur);
	
	while(getchar() != '\n');								// Supprimer le char '\n' de 'input buffer'
	
	printf("Nom:\t");
	fgets(nouveau->nom, sizeof(nouveau->nom) - 1, stdin);		// Lire le nom de produit
	
	int len = strlen(nouveau->nom);
    if (len > 0 && nouveau->nom[len - 1] == '\n') {			// Si le dernier char est '\n', supprimer le
        nouveau->nom[len - 1] = '\0';
    }
	
	codeValide = 1;
	
	while(codeValide) {
		printf("Quantite:\t");
		scanf("%s", valeur);								// Lire la valeur de quantite
		for (i = 0; i < strlen(valeur); i++) {
			if (isdigit(valeur[i])) {
				codeValide = 0;
				continue;
			} else {
				printf("\nErreur: La valeur doit etre un nombre\n\n");
				codeValide = 1;
				break;
			}
		}
		
	}
	
	nouveau->quantite = atoi(valeur);
	
	printf("Prix:\t");
	scanf("%f", &nouveau->prix);								// Lire la valeur de prix
	
	// Name List
	
	courant = teteNom;
	prec = NULL;
	
	while (courant != NULL && strcmp(courant -> nom, nouveau -> nom) < 0) {
		fprintf(fichier, "%d\n%s\n%d\n%.2f\n---\n", courant -> code, courant -> nom, courant -> quantite, courant -> prix);
		prec = courant;
		courant = courant -> suivantNom;
	}

	nouveau -> suivantNom = courant;
	
	if (prec == NULL) {
		teteNom = nouveau;
	} else {
		prec -> suivantNom = nouveau;
	}
	
	fprintf(fichier, "%d\n%s\n%d\n%.2f\n---\n", nouveau -> code, nouveau -> nom, nouveau -> quantite, nouveau -> prix);
	
	while (courant != NULL) {
		fprintf(fichier, "%d\n%s\n%d\n%.2f\n---\n", courant -> code, courant -> nom, courant -> quantite, courant -> prix);
		courant = courant -> suivantNom;
	}
	
	fclose(fichier);
	fichier = NULL;
	
	// Price List
	
	courant = tetePrix;
	prec = NULL;
	
	while (courant != NULL && courant -> prix > nouveau -> prix) {
		prec = courant;
		courant = courant -> suivantPrix;
	}

	nouveau -> suivantPrix = courant;
	
	if (prec == NULL) {
		tetePrix = nouveau;
	} else {
		prec -> suivantPrix = nouveau;
	}
	
	printf("\nLe produit etait ajoute\n");

	return 1;
}

// 3. Lister tous les produits

void listerProduits() {
	struct produit *current;
	
	int count = 0, op;
	
	if (teteNom == NULL) {
		printf("La liste des produits est vide\n");
		return;
	}
	
	printf("Lister les produits selon:\n");
	printf("1. L\'ordre alphabetique croissant du nom\n");
	printf("2. L\'ordre decroissant de prix\n");
	printf("\n");
	
	scanf("%d", &op);
		
	switch (op) {
		case 1:
			printf("-------------------------------------------------\n");
			printf("La liste des produits selon l'order du nom:\n");
			printf("-------------------------------------------------\n");
			
			current = teteNom;
			
			while (current != NULL) {
				printf("Code: %d\n", current -> code);
				printf("Nom: %s\n", current -> nom);
				printf("Quantite: %d\n", current -> quantite);
				printf("Prix: %.2f DH\n", current -> prix);
				printf("-------------------------------------------------\n");
				
				count++;
				
				current = current -> suivantNom;
			}
			break;
		case 2:
			printf("-----------------------------------------------\n");
			printf("La liste des produits selon l'order du prix:\n");
			printf("-----------------------------------------------\n");
			
			current = tetePrix;
			
			while (current != NULL) {
				printf("Code: %d\n", current -> code);
				printf("Nom: %s\n", current -> nom);
				printf("Quantite: %d\n", current -> quantite);
				printf("Prix: %.2f DH\n", current -> prix);
				printf("-------------------------------------------------\n");
				
				count++;
				
				current = current -> suivantPrix;
			}
			break;
		default:
			printf("Cet operation n'existe pas\n");
	}
	
	printf("\nLe nombre total des produits: %d\n", count);

}

// 4. Acheter un produit

void acheterProduit() {
	struct produit *current = teteNom;
	
	int qu, code, trouver = 0;
	float prixTTC;
	
	time_t t;
	struct tm *full_time;
	
	if (current == NULL) {
		printf("La liste des produits est vide\n");
		return;
	}
	
	FILE *fichier, *fichier2 = fopen("produits.txt", "w");
	
	if (fichier2 == NULL) {
		printf("Erreur: Le programme ne peut pas ouvrir le fichier produit.txt\n");
		return;
	}
	
	printf("Entrer le code de produit:\t");
	scanf("%d", &code);

	while (current != NULL) {
		if (current -> code == code) {
			if (current -> quantite == 0) {
				printf("\nMalheureusement la quantite est null\n");
			} else {
				printf("Entrer la quantite que tu veux acheter (%d produits valables):\t", current -> quantite);
				scanf("%d", &qu);
				
				if (qu < 1) {
					printf("\nVeuillez choisir un quantite superieur ou egale a 1\n");
				} else if (current -> quantite < qu) {
					printf("\nMalheureusement! La quantite valable est insuffisante (%d produit(s) valable(s))\n", current -> quantite);
				} else {
					current -> quantite -= qu;
					prixTTC = qu * (current -> prix + 0.15 * current -> prix);
					
					printf("\nVous avez acheter %d produit(s) de code %d, prix TTC total = %.2f DH\n", qu, current -> code, prixTTC);
					printf("La quantite qui reste est: %d\n", current -> quantite);
					
					fichier = fopen("achats.txt", "a");
					
					if (fichier != NULL) {
						
						time(&t);
	
						full_time = localtime(&t);
						
						fprintf(fichier, "%02d/%02d/%d -- %.2f\n", full_time -> tm_mday, full_time -> tm_mon + 1, full_time -> tm_year + 1900, prixTTC);	
					}
					
					fclose(fichier);
					
					fichier = NULL;
					
					
				}	
			}
			trouver = 1;
		}
		
		fprintf(fichier2, "%d\n", current -> code);
		fprintf(fichier2, "%s\n", current -> nom);
		fprintf(fichier2, "%d\n", current -> quantite);
		fprintf(fichier2, "%.2f\n", current -> prix);
		fprintf(fichier2, "---\n");
		
		current = current -> suivantNom;
	}
	
	fclose(fichier2);
	
	if (trouver == 0) {
		printf("Le produit choisi n'exist pas\n");
	}
}

// 5. Rechercher les produits

void rechercher() {
	struct produit *current = teteNom;
	
	int op, nombre, count = 0;
	
	if (teteNom == NULL) {
		printf("La liste des produits est vide\n");
		return;
	}
	
	printf("Rechercher Par:\n");
	printf("1. Code\n");
	printf("2. Quantite\n");
	printf("\n");
	
	scanf("%d", &op);
	
	switch (op) {
		case 1:
			printf("\nEntrer le code de produit a rechercher:\t");
			scanf("%d", &nombre);
			printf("\n");
			
			printf("------------------------------------------\n");
			printf("Le resultat de recherche:\n");
			printf("------------------------------------------\n");
			while (current != NULL) {
				if (current -> code == nombre) {
					printf("Code: %d\n", current -> code);
					printf("Nom: %s\n", current -> nom);
					printf("Quantite: %d\n", current -> quantite);
					printf("Prix: %.2f DH\n", current -> prix);
					printf("------------------------------------------\n");
					break;
				}
				current = current -> suivantNom;
			}
			
			if (current == NULL) {
				printf("\nCe produit n'existe pas\n");	
			}
			break;
		case 2:
			printf("Entrer la quantite a rechercher:\t");
			scanf("%d", &nombre);
			printf("\n");
			
			printf("------------------------------------------\n");
			printf("Le resultat de recherche:\n");
			printf("------------------------------------------\n");
			while (current != NULL) {
				if (current -> quantite == nombre) {
					printf("Code: %d\n", current -> code);
					printf("Nom: %s\n", current -> nom);
					printf("Quantite: %d\n", current -> quantite);
					printf("Prix: %.2f DH\n", current -> prix);
					printf("------------------------------------------\n");
					count++;
				}
				current = current -> suivantNom;
			}
			
			if (count == 0) {
				printf("\nAucun produit de quantite %d trouver\n", nombre);	
			} else {
				printf("\nLe nombre de produit(s) trouver: %d\n", count);
			}
			break;
		default:
			printf("\nCet operation n'existe pas\n");
	}
}

// 6. Afficher l'etat du stock

void etatStock() {
	struct produit *current = teteNom;
	
	int count = 0;
	
	if (current == NULL) {
		printf("La liste des produits est vide\n");
		return;
	}
	
	printf("------------------------------------------\n");
	printf("Les produits dont la quantite < 3:\n");
	printf("------------------------------------------\n");
	
	while (current != NULL) {
		if (current -> quantite < 3) {
			printf("Code: %d\n", current -> code);
			printf("Nom: %s\n", current -> nom);
			printf("Quantite: %d\n", current -> quantite);
			printf("Prix: %.2f DH\n", current -> prix);
			printf("------------------------------------------\n");
			
			count++;
		}
		
		current = current -> suivantNom;
	}
	
	if (count == 0) {
		printf("\nAucun produit trouver\n");
	} else {
		printf("\nLe nombre de produits trouver est: %d\n", count);
	}
}

// 7. Alimenter le stock

void alimenterStock() {
	struct produit *current = teteNom;
	
	// Qu -> La quantite qu'on ajoute
	// Code -> Code du produit
	// Trouver -> Le produit existe (1) ou non (0);
	int qu, code, trouver = 0;
	
	FILE *fichier = fopen("produits.txt", "w");
	
	// Si le programme ne peut pas ouvrir le fichier, afficher un message
	if (fichier == NULL) {
		printf("Erreur: Le programme ne peut pas ouvrir le fichier produits.txt");
		return;
	}
	
	// Si la liste est vide
	if (current == NULL) {
		printf("La liste des produits est vide\n");
		return;
	}
	
	// Lire la valeur de code
	printf("Entrer le code de produit:\t");
	scanf("%d", &code);

	while (current != NULL) {
		if (current -> code == code) {
			printf("Entrer la quantite que tu veux ajouter:\t");
			scanf("%d", &qu);
			
			if (qu < 1) {
				printf("\nLa quantite doit etre inferieur a 0\n");
			} else {
				current -> quantite += qu;
				
				printf("\n");
				printf("------------------------------------------\n");
				printf("Le produit apres l\'alimentation\n");
				printf("------------------------------------------\n");
				
				printf("Code: %d\n", current -> code);
				printf("Nom: %s\n", current -> nom);
				printf("Quantite: %d\n", current -> quantite);
				printf("Prix: %.2f DH\n", current -> prix);
				printf("------------------------------------------\n");
			
			}
			
			trouver = 1;
		}
		
		// Stocker les nouveaux details de produits dans le fichier produits.txt
		fprintf(fichier, "%d\n", current -> code);
		fprintf(fichier, "%s\n", current -> nom);
		fprintf(fichier, "%d\n", current -> quantite);
		fprintf(fichier, "%.2f\n", current -> prix);
		fprintf(fichier, "---\n");
		
		// Pointe vers l'element suivant
		current = current -> suivantNom;
	}
	
	fclose(fichier);
	
	if (trouver == 0) {
		printf("\nLe produit choisi n'exist pas\n");
	}
}

// 8. Supprimer les produits

void supprimerProduit() {
	struct produit *c1, *c2, *prec1 = NULL, *prec2 = NULL;
	c1 = teteNom;
	c2 = tetePrix;
	
	FILE *fichier;
	int code;
	
	if (teteNom == NULL) {
		printf("La liste des produits est vide\n");
		return;
	} 
	
	printf("Entrer le code de produit:\t");
	scanf("%d", &code);
	
	// Price List
	
	while (c2 != NULL && c2 -> code != code) {
		prec2 = c2;
		c2 = c2 -> suivantPrix;
	}
	
	if (c2 == NULL) {
		printf("\nCe produit n'existe pas\n");
		return;	
	}
	
	if (prec2 == NULL) {
		tetePrix = c2 -> suivantPrix;
	} else {
		prec2 -> suivantPrix = c2 -> suivantPrix;
	}
	
	// Name List
	
	fichier = fopen("produits.txt", "w");
	
	if (fichier == NULL) {
		printf("Erreur: Le programme ne peut pas ouvrir le fichier produits.txt\n");
		return;
	}
	
	while (c1 != NULL && c1 -> code != code) {
		fprintf(fichier, "%d\n%s\n%d\n%.2f\n---\n", c1 -> code, c1 -> nom, c1 -> quantite, c1 -> prix);
		prec1 = c1;
		c1 = c1 -> suivantNom;
	}
	
	if (prec1 == NULL) {
		teteNom = c1 -> suivantNom;
		prec1 = teteNom;
	} else {
		prec1 -> suivantNom = c1 -> suivantNom;
		prec1 = prec1 -> suivantNom;
	}
	
	free(c1);
	c1 = prec1;
	
	while (c1 != NULL) {
		fprintf(fichier, "%d\n%s\n%d\n%.2f\n---\n", c1 -> code, c1 -> nom, c1 -> quantite, c1 -> prix);
		c1 = c1 -> suivantNom;
	}
	
	printf("\nLe produit etait supprime\n");

	fclose(fichier);
}

// 9. Afficher les statistiques

void afficherStats() {
	
	FILE *fichier;
	char content[30], date[11], current_date[11];
	float prix, moyenne = 0, somme = 0, max = 0, min = 0;
	int count = 0;
	
	time_t t;
	struct tm *full_time;		// Struct that represent day, month, hour, min, sec, ...
	
	// Get the current date
	time(&t);						// Return the number of seconds since 1/1/1970
	full_time = localtime(&t);		// Transform those seconds stored in &t into struct tm object
	
	if (strftime(current_date, sizeof(current_date), "%d/%m/%Y", full_time) == 0) {
		printf("Erreur: Le programme ne peut pas trouver la date d'aujourd'hui\n");
		return;
	}
	
	fichier = fopen("achats.txt", "r");
	
	if (fichier == NULL) {
		printf("Erreur: Le programme ne peut pas ouvrir le fichier achats.txt\n");
		return;
	}
	
	while(fgets(content, sizeof(content), fichier) != NULL) {
		strncpy(date, content, 10);
		if (strcmp(date, current_date) == 0) {
			prix = atof(content + 14);
			somme += prix;
			if (max < prix) {
				max = prix;
			}
			if (prix < min || min == 0) {
				min = prix;
			}
			count++;
			
		}
	}
	
	if (count == 0) {
		moyenne = 0;
	} else {
		moyenne = somme / count;
	}
	
	printf("-----------------------------------------------------------------------------\n");
	printf("Les statistiques des produits vendus en journee courante (%s) sont:\n", current_date);
	printf("-----------------------------------------------------------------------------\n");
	printf("Le total    |  %.2f DH\n", somme);
	printf("-----------------------------------------------------------------------------\n");
	printf("La moyenne  |  %.2f DH\n", moyenne);
	printf("-----------------------------------------------------------------------------\n");
	printf("Le max      |  %.2f DH\n", max);
	printf("-----------------------------------------------------------------------------\n");
	printf("Le min      |  %.2f DH\n", min);
	printf("-----------------------------------------------------------------------------\n");
	
	fclose(fichier);
}
