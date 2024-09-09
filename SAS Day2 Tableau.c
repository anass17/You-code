// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

int main() {
    
    // Exercice 1:
    
//	int i, T[] = {5, 6, 9, 3, 7, 0, 3};
//	
//	for(i = 0; i < sizeof(T) / sizeof(int); i++) {
//	 printf("%d\n", T[i]);
//	}
    
    
    // Exercice 2:
    
//	int i, n;
//	
//	printf("Entrer le nombre d'elements a saisir: \t");
//	scanf("%d", &n);
//	
//	if (n < 1) {
//	 printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
//	 return 0;
//	}
//	
//	if (n > 200) {
//	 printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
//	 return 0;
//	}
//	
//	int T[n];
//	
//	
//	printf("Entrer les valeurs de tableau:\n");
//	for(i = 0; i < n; i++) {
//	 printf("%d => ", i + 1);
//	 scanf("%d", &T[i]);
//	}
//	
//	printf("\nLes valeurs de tableau\n");
//	for(i = 0; i < n; i++) {
//	 printf("%d => %d\n", i + 1, T[i]);
//	}
    
    
    // Exercice 3:
    
    // int i, n, somme = 0;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // for(i = 0; i < n; i++) {
    //     somme += T[i];
    // }
    
    // printf("\nLa somme des elements de tableau est: %d\n", somme);
    
    
    // Exercice 4:
    
    // int i, n, max = 0;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // max = T[0];
    
    // for(i = 1; i < n; i++) {
    //     if (T[i] > max) {
    //         max = T[i];
    //     }
    // }
    
    // printf("\nLe max des elements de tableau est: %d\n", max);
    
    
    // Exercice 5:
    
    // int i, n, min = 0;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // min = T[0];
    
    // for(i = 1; i < n; i++) {
    //     if (T[i] < min) {
    //         min = T[i];
    //     }
    // }
    
    // printf("\nLe min des elements de tableau est: %d\n", min);


    // Exercice 6:
    
    // int i, n, fact;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // printf("Entrer la valeur de facteur:\t");
    // scanf("%d", &fact);
    
    // for(i = 0; i < n; i++) {
    //     printf("%d\n", T[i] * fact);
    // }
    
    
    // Exercice 7:
    
    // int i, j, n, inter;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // for (j = 0; j < n; j++) {
    //     for(i = 1; i < n - j; i++) {
    //         if (T[i - 1] > T[i]) {
    //             inter = T[i - 1];
    //             T[i - 1] = T[i];
    //             T[i] = inter;
    //         }
    //     }
    // }
    
    // for (i = 0; i < n; i++) {
    //     printf("%d\n", T[i]);
    // }
    
    
    // Exercice 8:
    
    // int i, n;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    // int B[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // for(i = 0; i < n; i++) {
    //     B[i] = T[i];
    // }
    
    // printf(" T1  -   T2\n");
    // for (i = 0; i < n; i++) {
    //     printf("%3d  -  %3d\n", T[i], B[i]);
    // }
    
    
    // Exercice 9:
    
    // int i, n, inter;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // for(i = 0; i < n / 2; i++) {
    //     inter = T[i];
    //     T[i] = T[n - i - 1];
    //     T[n - i - 1] = inter;
    // }
    
    // for (i = 0; i < n; i++) {
    //     printf("%d\n", T[i]);
    // }
    
    
    // Exercice 10:
    
    // int i, n, element;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // printf("Entrer la valeur a rechercher:\n");
    // scanf("%d", &element);
    
    // for(i = 0; i < n; i++) {
    //     if (T[i] == element) {
    //         printf("L'element %d est le %deme dans le tableau", element, i + 1);
    //         break;
    //     }
    // }
    
    // if (i == n) {
    //     printf("L'element %d n'existe pas dans le tableau", element);
    // }
    
    // Exercice 11:
    
    // int i, n, oldV, newV;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // printf("Entrer la valeur a remplacer:\n");
    // scanf("%d", &oldV);
    
    // printf("Entrer la nouvelle valeur:\n");
    // scanf("%d", &newV);
    
    // for(i = 0; i < n; i++) {
    //     if (T[i] == oldV) {
    //         T[i] = newV;
    //     }
    // }
    
    // for(i = 0; i < n; i++) {
    //     printf("%d\n", T[i]);
    // }
    
    
    // Exercice 12:
    
    // int i, n;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // for(i = 0; i < n; i++) {
    //     if (T[i] % 2 == 0) {
    //         printf("%d\n", T[i]);
    //     }
    // }
    
    // Exercice 13:
    
    // int i, n;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // for(i = 0; i < n; i++) {
    //     if (T[i] % 2 == 1) {
    //         printf("%d\n", T[i]);
    //     }
    // }
    
    // Exercice 14:
    
    // int i, n, somme;
    
    // printf("Entrer le nombre d'elements a saisir: \t");
    // scanf("%d", &n);
    
    // if (n < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n];
    
    // printf("Entrer les valeur de tableau:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // somme = 0;
    
    // for(i = 0; i < n; i++) {
    //     somme += T[i];
    // }
    
    // printf("Le moyenne des elements est: %.2f", (float) somme / n);
    
    
    // Exercice 15:
    
    // int i, n1, n2;
    
    // printf("Entrer le nombre d'elements de 1er tableaux: \t");
    // scanf("%d", &n1);
    
    // if (n1 < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n1 > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // printf("Entrer le nombre d'elements de 2er tableaux: \t");
    // scanf("%d", &n2);
    
    // if (n2 < 1) {
    //     printf("\nErreur: Le tableau doit avoir au moins une valeur\n");
    //     return 0;
    // }
    
    // if (n2 > 200) {
    //     printf("\nErreur: Vous avez passe la limite (max: 200 elements)");
    //     return 0;
    // }
    
    // int T[n1];
    // int B[n2];
    
    // printf("Entrer les valeur de 1er tableau:\n");
    // for(i = 0; i < n1; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &T[i]);
    // }
    
    // printf("Entrer les valeur de 2er tableau:\n");
    // for(i = 0; i < n2; i++) {
    //     printf("%d => ", i + 1);
    //     scanf("%d", &B[i]);
    // }
    
    // int F[n1 + n2];
    
    // for(i = 0; i < n1; i++) {
    //     F[i] = T[i];
    // }
    
    // for(i = 0; i < n2; i++) {
    //     F[i + n1] = B[i];
    // }
    
    // for (i = 0; i < n1 + n2; i++) {
    //     printf("%d\n", F[i]);
    // }

    return 0;
}
