// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    
    int op, i, total = 3;
    char titre[50][30] = {"Do not be sad", "Book with no name", "Bright Sky"};
    char author[50][30] = {"Unknown", "Anass Boutaib", "LLK"};
    float prix[50] = {76.6, 33.9, 102.8};
    int quantite[50] = {12, 5, 7};
    char rech[30];
    int qu;
    
    do {
        printf("\n\n");
        
        printf("***************************\n");
        printf("***   Menu Principale   ***\n");
        printf("***************************\n\n");
        
        printf("La liste des operations valables est:\n\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre à jour la quantité d'un livre.\n");
        printf("5. Supprimer un livre du stock.\n");
        printf("6. Afficher le nombre total de livres en stock.\n");
        printf("0. Sortir\n\n");
        
        printf("-->   ");
        scanf("%d", &op);
        
        switch (op) {
            case 1: 
                printf("\n****************************\n");
                printf("***   Ajouter un livre   ***\n");
                printf("****************************\n\n");
                
                printf("Entrer le titre du livre:\n");
                printf("-->   ");
                scanf("%*[\n]");
                scanf("%[^\n]", titre[total]);
                
                printf("\nEntrer l'author du livre:\n");
                printf("-->   ");
                scanf("%*[\n]");
                scanf("%[^\n]", author[total]);
                
                printf("\nEntrer le prix du livre:\n");
                printf("-->   ");
                scanf("%.2f", &prix[total]);
                
                printf("\nEntrer la quantite du livre:\n");
                printf("-->   ");
                scanf("%d", &quantite[total]);
                total++;
                
                printf("\nBien! Le livre etait ajouter\n");
                
                break;
            case 2:
                printf("\n*********************************\n");
                printf("***   Afficher tous les livre   ***\n");
                printf("***********************************\n\n");
                
                printf("La liste des livres:\n\n");
                for (i = 0; i < total; i++) {
                    printf("Titre:    %s\n", titre[i]);
                    printf("Author:   %s\n", author[i]);
                    printf("Prix:     %.2f DH\n", prix[i]);
                    printf("Quantite: %d\n", quantite[i]);
                    printf("\n");
                }
                
                break;
            case 3:
                printf("\n*****************************\n");
                printf("***   Rechercher un livre   ***\n");
                printf("*******************************\n\n");
                
                printf("Entrer le titre du livre:\n");
                printf("-->   ");
                scanf("%*[\n]");
                scanf("%[^\n]", rech);
                for (i = 0; i < total; i++) {
                    if (strcmp(titre[i], rech) == 0) {
                        printf("\nCe livre existe:\n");
                        printf("Titre:    %s\n", titre[i]);
                        printf("Author:   %s\n", author[i]);
                        printf("Prix:     %.2f DH\n", prix[i]);
                        printf("Quantite: %d\n", quantite[i]);
                        break;
                    }
                }
                if (i == total) {
                    printf("\nLe livre n'existe pas\n");
                }
                break;
            case 4:
                printf("\n********************************\n");
                printf("***   Mettre a jour quantite   ***\n");
                printf("**********************************\n\n");
                
                printf("Entrer le titre du livre:\n");
                printf("-->   ");
                getchar();
                scanf("%[^\n]", rech);
                for (i = 0; i < total; i++) {
                    if (strcmp(titre[i], rech) == 0) {
                        printf("\nEntrer la nouvelle quantite\n");
                        printf("-->   ");
                        scanf("%d", &qu);
                        
                        quantite[i] = qu;
                        break;
                    }
                }
                break;
            case 6:
                printf("\n");
                printf("****************************\n");
                printf("***   Total des livres   ***\n");
                printf("****************************\n\n");
                printf("Le nombre total des livres est: %d\n", total);
                break;
            case 0:
                printf("\nMerci de l'utilisation de ce programme, au revoir!\n");
                break;
                
        }
    } while (op != 0);
    
    return 0;
}
