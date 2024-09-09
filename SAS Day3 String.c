#include <stdio.h>
#include <string.h>

int main () {
	
	char str[31];
	char str2[31];
	int op, i, j, count = 0;
	char caractere;
	
	printf("Entrer le numero d'exercice:\t");
	scanf("%d", &op);
	
	switch (op) {
		case 1:
			printf("Entrer une chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			
			printf("\nLa chaine de caracteres entree est '%s'\n", str);
			
			break;
		case 2:
			printf("Entrer une chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			
			for (i = 0; i < 30; i++) {
				if (str[i] == '\0') {
					break;
				}
				count++;
			}
			printf("\nLe nombre totale des caracteres est %d", count);
			
			break;
			
		case 3:
			printf("Entrer la 1ere chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			printf("Entrer la 2eme chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str2);
			
			strcat(str, str2);
			
			printf("\nLa chaine de caracteres resultante est: %s\n", str);
			break;
		case 4:
			printf("Entrer la 1ere chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			printf("Entrer la 2eme chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str2);
			
			if (strcmp(str, str2) == 0) {
				printf("\nLes deux chaine sont egales\n");
			} else {
				printf("\nLes deux chaine sont differentes\n");
			}
			break;
			
		case 5:
			printf("Entrer une chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			
			strrev(str);
			
			printf("\nLa chaine de caracteres resultante est: %s\n", str);
			
			break;
			
		case 6:
			printf("Entrer une chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			
			printf("Entrer un caractere:\t");
			getchar();
			scanf("%c", &caractere);
			
			for (i = 0; i < strlen(str); i++) {
				if (str[i] == caractere) {
					count++;
				}
			}
			printf("\nLe nombre d'occurrences de caractere '%c' dans la chaine de caractere est %d\n", caractere, count);
			break;
			
		case 7:
			printf("Entrer une chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			
			strupr(str);
			
			printf("\nLa chaine de caracteres resultante est: %s\n", str);
			break;
			
		case 8:
			printf("Entrer une chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			
			strlwr(str);
			
			printf("\nLa chaine de caracteres resultante est: %s\n", str);
			break;
			
		case 9:
			printf("Entrer une chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			
			j = 0;
			for (i = 0; i < strlen(str); i++) {
				if (str[i] != ' ') {
					str[j] = str[i];
					j++;
				}
			}
			str[j] = '\0';
			
			printf("\nLa chaine de caracteres resultante est: %s\n", str);
			break;
			
		case 10:
			printf("Entrer la chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str);
			
			printf("Entrer la sous-chaine de caracteres (max: 30):\t");
			getchar();
			scanf("%30[^\n]", str2);
			
			if (strstr(str, str2) != NULL) {
				printf("\nLa sous-chaine de caracteres etait trouver\n");
			} else {
				printf("\nLa sous-chaine de caracteres n'existe pas dans\n");
			}
			break;
		default:
			printf("\nCet exercice n'existe pas\n");
	}
	
	
	
	
	
	return 0;
}
