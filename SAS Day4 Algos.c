#include <stdio.h>

// Affihage du tableau

void afficherTableau(int tableau[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d  ", tableau[i]);
	}
	printf("\n");
}

// Tri A bulle

void triABulles(int tableau[], int size) {
	int i, j, temp;
	int changements = 0;
	
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (tableau[j] > tableau[j + 1]) {
				temp = tableau[j];
				tableau[j] = tableau[j + 1];
				tableau[j + 1] = temp;
				changements++;
			}
		}
	}
	printf("\nLe nombre de changements: %d\n", changements);
}

// Tri par insertion

void triParInsertion(int tableau[], int size) {
	int i, j, temp;
	
//	for (i = 1; i < size; i++) {
//		temp = tableau[i];
//		for (j = i - 1; j >= 0; j--) {
//			if (tableau[j] > temp) {
//				tableau[j + 1] = tableau[j];
//			} else {
//				break;
//			}
//		}
//		tableau[j + 1] = temp;
//	}
	
	for (i = 1; i < size; i++) {
        temp = tableau[i];
        j = i - 1;
        
        while (j >= 0 && tableau[j] > temp) {
            tableau[j + 1] = tableau[j];
            j--;
        }
        
        tableau[j + 1] = temp;
    }
}

// Tri par selection

void triParSelection(int tableau[], int size) {
	int i, j, temp, min;
	
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (tableau[j] < tableau[min]) {
				min = j;
			}
		}
		temp = tableau[min];
		tableau[min] = tableau[i];
		tableau[i] = temp;
	}
}

int main () {
	
	int ex;
	int nbr = 6;
	int Tab[] = {4, 2, 9, 7, 10, 0};
	int i;
	
	printf("Entrer le numero de l'exercice\n");
	scanf("%d", &ex);
	
	switch (ex) {
		case 1:
			printf("\n*****   Exercice 1   *****\n\n");
			
			printf("Les elements du tableau sont:\n");
			afficherTableau(Tab, nbr);
			triABulles(Tab, nbr);
			printf("\n\nLe tableau trie (Tri a bulles) est:\n");
			afficherTableau(Tab, nbr);
			break;
		case 2:
			printf("\n*****   Exercice 2   *****\n\n");
			
			printf("Les elements du tableau sont:\n");
			afficherTableau(Tab, nbr);
			triParInsertion(Tab, nbr);
			printf("\n\nLe tableau trie (Tri par insertion) est:\n");
			afficherTableau(Tab, nbr);
			break;
		case 3:
			printf("\n*****   Exercice 3   *****\n\n");
			
			printf("Les elements du tableau sont:\n");
			afficherTableau(Tab, nbr);
			triParSelection(Tab, nbr);
			printf("\n\nLe tableau trie (Tri par selection) est:\n");
			afficherTableau(Tab, nbr);
			break;
			
		default:
			printf("\nCet exercice ne se trouve pas\n");
	}
	
	// temp = 7
	// 2 4 7 3 9 0
	//   j i
	
	// 2 4 7 3 9 0
	//   j i
	
	// j = i - 1
	
	
	return 0;
}
