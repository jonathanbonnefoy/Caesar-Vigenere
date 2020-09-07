#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "chiffrement.h"
#include <malloc.h>
#include <ctype.h>
#include <time.h>

void cesar (char msg[], int key) {
        char* indexMsg = msg;
        time_t temps;
        int indexCrypt;
	// Cryptage avec code de cesar
        while (*indexMsg !='\0') {
		// Cas ou texte en majuscule
                if (*indexMsg >= 'A' && *indexMsg <= 'Z') {
                        indexCrypt = (((*indexMsg - 'A') + key) + 26) %26; // ajout de 26 car le modulo n'opere pas sur des nombres negatifs
                        *indexMsg = (indexCrypt + 'A');
                }
		// Cas ou texte en minuscule
                else if (*indexMsg >= 'a' && *indexMsg <= 'z') {
                        indexCrypt = (((*indexMsg - 'a') + key) + 26) %26;
                        *indexMsg = (indexCrypt + 'a');
                }
                indexMsg ++;
        }

	printf("\nVoici le message chiffre : \n%s\n", msg);

	// Ecriture du message crypte dans un fichier
        FILE* fic;
        fic = fopen("messageChiffreCesar.txt", "a");
        if (fic == NULL) {
                printf("Erreur à l'ouverture du fichier texte\n");
        } else {
		time(&temps);
                fprintf(fic, "Message crypte le %s\r%s\n",ctime(&temps), msg);
                fclose(fic);
        }
}


void vigenere (char msg[], char key[]) {
        // Declaration des variables
        char* indexMsg = msg, *indexKey = key;
        time_t temps;
        int indexCrypt;

	// Chiffrement avec Vigenere
        while (*indexMsg != '\0') {
		// Remet l'indice de parcours de la clef a zero quand il atteint la fin de la clef
                if (*indexKey == '\0' || *indexKey == '\n') {
                        indexKey = &key[0];
		}
                if (isalpha(*indexKey)) {
                    // Cas ou le caractere courant du message est en majuscule
                    if (*indexMsg >= 'A' && *indexMsg <= 'Z') {
                            indexCrypt = ((*indexMsg - 'A') + (toupper(*indexKey) - 'A') + 26) % 26; // ajout de 26 car le modulo n'opere pas sur des nombres negatifs
                            *indexMsg = (indexCrypt + 'A');
                            indexKey ++;
                    // Cas ou le caractere courant du message est en minuscule.
                    } else if (*indexMsg >= 'a' && *indexMsg <= 'z') {
                            indexCrypt = ((*indexMsg - 'a') + (tolower(*indexKey) - 'a') + 26) % 26;
                            *indexMsg = (indexCrypt + 'a');
                            indexKey ++;
                    }
                    indexMsg ++;
                }
        }

        printf("\nVoici le message chiffre : \n%s\n", msg);

	//Ecriture du message chiffre dans un fichier
        FILE* fic;
        fic = fopen("messageChiffreVigenere.txt", "a");
        if (fic == NULL) {
                printf("Erreur à l'ouverture du fichier texte\n");
        } else {
                time(&temps);
                fprintf(fic, "Message crypte le %s\r%s\n",ctime(&temps), msg);
                fclose(fic);
        }
}


void decryptCesar (char msg[], int key) {
        // Declaration des variables
        char* indexMsg = msg;
        int indexCrypt;
        time_t temps;
        // Dechiffrement code de Cesar
        while (*indexMsg !='\0') {
                // Cas ou le caractere courant du message est en majuscule
                if (*indexMsg >= 'A' && *indexMsg <= 'Z') {
                        indexCrypt = (((*indexMsg - 'A') - key) + 26) %26; // ajout de 26 car le modulo n'opere pas sur des nombres negatifs
                        *indexMsg = (indexCrypt + 'A');
                }
                // Cas ou le caractere courant du message est en minuscule
                else if (*indexMsg >= 'a' && *indexMsg <= 'z') {
                        indexCrypt = (((*indexMsg - 'a') - key) + 26) %26;
                        *indexMsg = (indexCrypt + 'a');
                }
                indexMsg ++;
        }

        printf("\nVoici le message dechiffre : \n%s\n", msg);

    //Ecriture du message chiffre dans un fichier
        FILE* fic;
        fic = fopen("messageDechiffreCesar.txt", "a");
        if (fic == NULL) {
                printf("Erreur à l'ouverture du fichier texte\n");
        } else {
                time(&temps);
                fprintf(fic, "Message decrypte le %s\r%s\n", ctime(&temps), msg);
                fclose(fic);
        }
}

void decryptVigenere (char msg[], char key[]) {
        // Declaration des variables
        char* indexMsg = msg, *indexKey = key;
        int indexCrypt;
        time_t temps;
        printf("%s\n", msg);
        // Dechiffrement Vigenere
        while (*indexMsg != '\0') {
                // Remet l'indice de parcours de la clef a zero quand il atteint la fin de la clef
                if (*indexKey == '\0' || *indexKey == '\n')
                        indexKey = &key[0];
                if (isalpha(*indexKey)) {
                    // Cas ou le caractere courant du message est en majuscule
                    if (*indexMsg >= 'A' && *indexMsg <= 'Z') {
                            indexCrypt = ((*indexMsg - 'A') - (toupper(*indexKey) - 'A') + 26) % 26; // ajout de 26 car le modulo n'opere pas sur des nombres negatifs
                            *indexMsg = (indexCrypt + 'A');
                            indexKey ++;
                    // Cas ou le caractere courant du message est en minuscule
                    } else if (*indexMsg >= 'a' && *indexMsg <= 'z') {
                            indexCrypt = ((*indexMsg - 'a') - (tolower(*indexKey) - 'a') + 26) % 26;
                            *indexMsg = (indexCrypt + 'a');
                            indexKey ++;
                    }
                    indexMsg ++;
                }
        }

        printf("\nVoici le message dechiffre : \n%s\n", msg);

        //Ecriture du message chiffre dans un fichier
        FILE* fic;
        fic = fopen("messageDechiffreVigenere.txt", "a");
        if (fic == NULL) {
                printf("Erreur à l'ouverture du fichier texte\n");
        } else {
                time(&temps);
                fprintf(fic, "Message decrypte le %s\r%s\n",ctime(&temps), msg);
                fclose(fic);
        }
}


bool estAlphanumerique (wchar_t msg[]) {
        wchar_t* ptrME = msg; 			//pointeur sur le message msg
        while (*ptrME != '\0') {
		wprintf(L"%lc\n", *ptrME);
        	if (iswspace(*ptrME)==0 && iswalnum(*ptrME)==0 && *ptrME != '\n') // si le charactere courant est ni alphanumerique 
	                return false;                                                 // ni un espace, tabulation ou autre blank char
                ptrME++;                                                          // alors retourne faux, vrai sinon
        }
        return true;
}


char* convertirAccents (wchar_t msg[]) {
        wchar_t* ptrCh = msg;
        char* messageASCII;
        messageASCII = (char*)malloc(sizeof(char) * wcslen(msg));  // creer un chaine de type char pour contenir le message desaccentuer
        size_t taille;
        while(*ptrCh != '\0'){
                switch (*ptrCh) {
                        case L'é':
                        case L'ê':
                        case L'ë':
                        case L'è':
                                *ptrCh = L'e';
                                break;
                        case L'É':
                        case L'Ë':
                        case L'Ê':
                        case L'È':
                                *ptrCh = L'E';
                                break;
                        case L'à':
                                *ptrCh = L'a';
                                break;
                        case L'À':
                                *ptrCh = L'A';
                                break;
                        case L'ù':
                        case L'û':
                                *ptrCh = L'u';
                                break;
                        case L'Ù':
                        case L'Û':
                                *ptrCh = L'U';
                                break;
                        case L'ô':
                        case L'ö':
                                *ptrCh = L'o';
                                break;
                        case L'Ö':
                        case L'Ô':
                                *ptrCh = L'O';
                                break;
                        case L'ï':
                        case L'î':
                                *ptrCh = L'i';
                                break;

                        case L'Ï':
                        case L'Î':
                                *ptrCh = L'I';
                                break;
                        default:
                                break;
                        }
                ptrCh++;
        }
        taille = wcstombs(messageASCII, msg, wcslen(msg)); // Convertit le message de type wchar_t, deja desaccentue, dans une chaine de type char
        return messageASCII;
}

