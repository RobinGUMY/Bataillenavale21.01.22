#include <stdio.h>
#include <conio.h>

#define MAX_TAB 10
#define DECAL 49
#define Adduser

int score = 50;

int carte[MAX_TAB][MAX_TAB];
int coupJouer[MAX_TAB][MAX_TAB];

void clear() {
    while (getchar() != '\n');
}

void init_carte() {
    carte[4][7] = 1;
    carte[7][4] = 2;
    carte[8][4] = 2;
    carte[5][9] = 3;
    carte[6][9] = 3;
    carte[7][9] = 3;
    carte[1][0] = 4;
    carte[1][1] = 4;
    carte[1][2] = 4;
    carte[1][3] = 4;
    carte[1][5] = 5;
    carte[1][6] = 5;
    carte[1][7] = 5;
    carte[1][8] = 5;
    carte[1][9] = 5;
}

void init_coup() {
    for (int i = 0; i < MAX_TAB; i++) {
        for (int y = 0; y < MAX_TAB; y++) {
            coupJouer[y][i] = 0;
        }
    }
}

void init_bateaux();


void afficher_coup() {
    printf("      A  B  C  D  E  F  G  H  I  J\n");
    printf("      _  _  _  _  _  _  _  _  _  _\n");
    for (int i = 0; i < MAX_TAB; i++) {
        printf("%2d  |", i + 1);
        for (int y = 0; y < MAX_TAB; y++) {
            if (coupJouer[y][i] == 0) {
                printf(" ~ ");
            } else {
                if (coupJouer[y][i] == 1) {
                    printf(" X ");
                } else {
                    printf(" 0 ");
                }

            }
        }
        printf("\n");
    }
}

void afficher_carte() {
    printf("      A  B  C  D  E  F  G  H  I  J\n");
    printf("      _  _  _  _  _  _  _  _  _  _\n");
    for (int i = 0; i < MAX_TAB; i++) {
        printf("%2d  |", i + 1);
        for (int y = 0; y < MAX_TAB; y++) {
            if (carte[y][i] == 0) {
                printf(" ~ ");
            } else {
                printf(" %d ", carte[y][i]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}


void demander_couper(char monchoix[2]) {
    printf("Merci de donner votre choix : ");

    scanf("%s", monchoix);
    clear();
}


void jouer_partie_normal(char choix[2], int index_col, int *BN, int *Partie) {

    init_carte();
    init_coup();

    while (choix[0] != 'L') {
        afficher_carte();
        afficher_coup();
        demander_couper(choix);
        printf("Vous avez choisi : %s\n", choix);
        printf("Votre col : %c et votre ligne : %c\n", choix[0], choix[1]);

        switch (choix[0]) {
            case 'a':
            case 'A':
                // ici on est sur la col 0
                index_col = 0;
                break;
            case 'b':
            case 'B':
                index_col = 1;
                break;
            case 'c':
            case 'C':
                index_col = 2;
                break;
            case 'd':
            case 'D':
                index_col = 3;
                break;
            case 'e':
            case 'E':
                index_col = 4;
                break;
            case 'f':
            case 'F':
                index_col = 5;
                break;
            case 'g':
            case 'G':
                index_col = 6;
                break;
            case 'h':
            case 'H':
                index_col = 7;
                break;
            case 'i':
            case 'I':
                index_col = 8;
                break;
            case 'j':
            case 'J':
                index_col = 9;
                break;
            case 'L':
                *BN = 0;
                break;
        }
        int index_ligne = choix[1] - DECAL;
        printf("\n\nscore : %d\n\n", score);
        if (index_ligne == 0) {
            //printf("%c", choix[2]);
            if (choix[2] == '0') {
                index_ligne = 9;
            }
        }

        printf("col : %d ligne : %d\n", index_col, index_ligne);
        if (carte[index_col][index_ligne] > 0) {
            printf("toucher ! \n");
            coupJouer[index_col][index_ligne] = 1;
        } else {
            printf("Out !\n");
            coupJouer[index_col][index_ligne] = 9;
            score--;
        }

        if (score == 0) {
            printf("Game Over!");
            Partie = 0;
            break;
        }

    }
}

void jouer_partie_autre(char choix[2], int index_col, int *BN) {
    init_carte();
    init_coup();
    while (choix[0] != 'L') {
        afficher_coup();
        demander_couper(choix);
        printf("Vous avez choisi : %s\n", choix);
        printf("Votre col : %c et votre ligne : %c\n", choix[0], choix[1]);

        switch (choix[0]) {
            case 'a':
            case 'A':
                // ici on est sur la col 0
                index_col = 0;
                break;
            case 'b':
            case 'B':
                index_col = 1;
                break;
            case 'c':
            case 'C':
                index_col = 2;
                break;
            case 'd':
            case 'D':
                index_col = 3;
                break;
            case 'e':
            case 'E':
                index_col = 4;
                break;
            case 'f':
            case 'F':
                index_col = 5;
                break;
            case 'g':
            case 'G':
                index_col = 6;
                break;
            case 'h':
            case 'H':
                index_col = 7;
                break;
            case 'i':
            case 'I':
                index_col = 8;
                break;
            case 'j':
            case 'J':
                index_col = 9;
                break;
            case 'L':
                *BN = 0;
                break;
        }
        int index_ligne = choix[1];
        if (index_ligne == 0) {
            //printf("%c", choix[2]);
            if (choix[2] == '0') {
                index_ligne = 9;
            }
        }

        printf("col : %d ligne : %d\n", index_col, index_ligne);
        if (carte[index_col][index_ligne] > 0) {
            printf("toucher ! \n");
            coupJouer[index_col][index_ligne] = 1;
        } else {
            printf("Out !\n");
            coupJouer[index_col][index_ligne] = 9;
        }
    }
}

int main(int argc, char *argv[]) {

    int BN = -1;
    int Aides, Scores, Jouer, selection = -1;
    int Partie = -1;
    int Pseudo;
    int index_col = 0;
    char choix[2];
    while (BN == -1) {

        printf("-------------------------\n");
        printf("|    Bataille Navale\t|\n");
        printf("-------------------------\n");
        printf("|\t1. Jouer   \t|\n");
        printf("-------------------------\n");
        printf("|\t2. Scores    \t|\n");
        printf("-------------------------\n");
        printf("|\t3. Aides   \t|\n");
        printf("-------------------------\n");
        printf("|\t4. Quitter   \t|\n");
        printf("-------------------------\n\n");

        printf("veuillez selectionner votre menu :\n");
        scanf("%d", &selection);

        while (selection < 1 || selection > 4) {
            printf("Erreur veuillez entrer un bon numero de menu\n");
            scanf("%d", &selection);
        }

        switch (selection) {

            case 1:
                printf("\n\n\t\t   | Jouer |\n");
                printf("-------------------------------------------------\n");
                printf("|\t veuillez entrer votre Pseudo   \t|\n");
                printf("-------------------------------------------------\n");
                scanf("%s", &Pseudo);
                printf("-------------------------------------------------\n");
                printf("|\t\t Bienvenue %s\t\t| \n", &Pseudo);

                printf("-------------------------------------------------\n");
                printf("\n\nveuillez choisir quel sera votre partie: \n");
                printf("-----------------------------------------\n");
                printf("|\t  1.  Partie normale     \t|\n");
                printf("-----------------------------------------\n");
                printf("|\t  2.  Partie de test     \t|\n");
                printf("-----------------------------------------\n\n");
                scanf("%d", &Partie);

                switch (Partie) {
                    case 1:
                        jouer_partie_normal(choix, index_col, &BN, &Partie);
                        break;
                    case 2:
                        jouer_partie_autre(choix, index_col, &BN);
                        break;

                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("Merci au revoir\n");
                BN = 0;
                break;
            default:


                break;
        }

    }
    return 0;
}
