#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "chiffrement.h"

void main() {
        // Declaration de variables
        setlocale(LC_ALL, "fr_FR.utf8");
        wchar_t message [500];
        wchar_t ligne [100];
	int cleCesar, reponse, tailleEntree = 500;

        // Affichage du menu
        printf("Entrer un numero correspondant aux chiffrements :\n");
        printf("1) Chiffrement par l'algorithme de Cesar.\n");
        printf("2) Chiffrement par l'algorithme de Vigenere.\n");
        printf("3) Dechifrement par l'algorithme de Cesar.\n");
        printf("4) Dechiffrement par l'algorithme de Vigenere.\n");

        // Entree de la reponse
	fgetws(ligne, tailleEntree, stdin);
        reponse = wcstol(ligne, NULL, 10);  // wcstol traduit un wchar_t en entier
	while (reponse<1 || reponse>4) {    //Tant que la reponse est differente des options proposees, redemande une reponse
                printf("Erreur : veuillez entrer un chiffre valide entre 1 et 4.\n");
                fgetws(ligne, tailleEntree, stdin);
                reponse = wcstol(ligne, NULL, 10);
	}

        // Entree du message
        printf("Veuillez entrer le message a traiter :\n");
        fgetws(message, tailleEntree, stdin);

	char* messageConvert;
	messageConvert = (char*) malloc (sizeof(char) * wcslen(message));

        // verifie si le texte est bien alphanumerique
        if (!estAlphanumerique(message)) {
        	printf("Erreur : votre texte comprend des caracteres non-alphanumeriques.\n");
        } else {

                // Traitement selon la reponse
                switch (reponse) {

                case 1 :
                        printf("Veuillez entrer un nombre compris entre 1 et 26 (clef) avec lequel le message sera chiffre: \n");
                        fgetws(ligne, tailleEntree, stdin);
		      	cesar(convertirAccents(message), wcstol(ligne, NULL, 10));
			printf("\nLe message crypte a ete ajoute dans le fichier messageChiffreCesar.txt.\n");
                break;

                case 2 :
                        printf("Veuillez entrer la cle avec laquelle le message sera chiffre: \n");
                        fgetws(ligne, tailleEntree, stdin);
	                vigenere(convertirAccents(message), convertirAccents(ligne));          // Conversion des accents de la clef
                        printf("\nLe message crypte a ete ajoute dans le fichier messageChiffreVigenere.txt.\n");
                break;

                case 3 :
                        printf("Veuillez entrer un nombre compris entre 1 et 26 (clef) avec lequel le message sera dechiffre: \n");
                        fgetws(ligne, tailleEntree, stdin);
                        decryptCesar(convertirAccents(message), wcstol(ligne, NULL, 10));
                        printf("\nLe message decrypte a ete ajoute dans le fichier messageDechiffreCesar.txt.\n");
                break;

                case 4 :
                        printf("Veuillez entrer la cle avec laquelle le message sera dechiffre: \n");
                        fgetws(ligne, tailleEntree, stdin);
                        decryptVigenere(convertirAccents(message), convertirAccents(ligne));   // Conversion des accents de la clef
                        printf("\nLe message decrypte a ete ajoute dans le fichier messageDechiffreVigenere.txt.\n");
                break;

                }
        }
}
