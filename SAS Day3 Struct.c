#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personne {
	char nom[30];
	char prenom[30];
	int age;
};

struct etudiant {
	char nom[30];
	char prenom[30];
	int notes[5];
};

struct rect {
	float longueur;
	float largeur;
};

struct point {
	float x;
	float y;
};

struct livre {
	char titre[30];
	char auteur[30];
	int annee;
};

float airRect(struct rect r) {
	return r.largeur * r.longueur;
}

struct livre initLivre(char titre[], char auteur[], int annee) {
	struct livre l;
	strcpy(l.titre, titre);
	strcpy(l.auteur, auteur);
	l.annee = annee;
	return l;
}

int main () {
	
	// Exercice 1:
	
//	struct personne p = {"Boutaib", "Anass", 23};
//	
//	printf("\nJe m'appelle %s %s et j'ai %d ans\n", p.prenom, p.nom, p.age);
	
	// Exercice 2:
	
//	struct etudiant anass = {"Boutaib", "Anass", {15, 12, 10, 16, 8}};
//	
//	printf("\nNom:          %s\n", anass.nom);
//	printf("Prenom:       %s\n", anass.prenom);
//	printf("\nLes notes d'etudiant:\n\n");
//	printf("Physique:     %d\n", anass.notes[0]);
//	printf("Informatique: %d\n", anass.notes[1]);
//	printf("Mathematique: %d\n", anass.notes[2]);
//	printf("Chimie:       %d\n", anass.notes[3]);
//	printf("Biology:      %d\n", anass.notes[4]);

	// Exercice 3:
	
//	struct rect rect1 = {6.5, 13};
//	
//	printf("\nL'aire de rectangle de longueur %.2f et de largeur %.2f est %.2f\n", rect1.longueur, rect1.largeur, airRect(rect1));
	
	// Exercice 4:
	
//	struct point *p1 = malloc(sizeof(struct point));
//	
//	p1 -> x = 13.6;
//	
//	p1 -> y = 7.2;
//	
//	printf("\nLes coordonnes de point sont (%.2f, %.2f)\n", p1 -> x, p1 -> y);

	// Exercice 5:
	
	struct livre livre1 = initLivre("Do not be sad", "Unknown Person", 2014);
	
	printf("\nLes donnees de livre:\n");
	printf("Titre:  %s\n", livre1.titre);
	printf("Auteur: %s\n", livre1.auteur);
	printf("Annee:  %d\n", livre1.annee);
	
	
	return 0;
}

