Nous sommes BONNEFOY Jonathan et CAULI Sacha, deux étudiants en première année
de DUT Informatique à l'université Paul Sabatier - Toulouse III. 

Ce programme résulte de la continuité pédagogique lors du confinement.
Nous avons donc réalisé ce projet en C dans le cadre de notre module M2101 - 
Architecture et programmation des bases d'un système informatique.

Notre application consiste à proteger des texte confidentiels, en les chiffrant.
Il y a possibilité de chiffrer et déchiffrer un texte suivant l'algorithme de 
César ou celui de Vigenère. Avant de chiffrer ou déchiffrer le texte, ce dernier
passe alors une vérification pour savoir s'il est bien alphanumérique. Si ce
n'est pas le cas, alors un message d'erreur est renvoyé à l'utilisateur. Dans 
l'autre cas, les accents du texte sont retirés grâce à une fonction nommé 
"convertirAccents". Après le traitement du texte, le résultat est affiché à 
l'utilisateur et est aussi sauvegardé dans un fichier texte. Enfin, un makefile
accompagne notre programme permettant à l'utilisateur de compiler le fichier
principal ainsi que tout autre fichier ayant une extension ".c". Il assure
le nettoyage des fichiers compilés par la suite.

Pour réaliser ce programme, nous avons codé 6 fonctions que nous avons regroupé
dans un paquetage appelé chiffrement. En voici la liste exhaustive de ces
fonctions, ainsi que leurs paramètres d'entrée :

- bool estAlphanumerique (wchar_t msg[]);
Ceci est la fonction permettant de savoir si la chaine de wide characters msg 
passée en entrée contient uniquement des caractères alphanumériques. 
Les caractères passant ce test sont : ceux de l'alphabet (majuscules ou 
minuscules, les chiffres, les caractères vérifiés par la fonction "iswspace"
ainsi que le saut d'une ligne '\n'. estAlphanumerique renvoie true si msg est 
bien alphanumérique, false sinon.

- char* convertirAccents (wchar_t msg[]);
Ceci est la fonction qui convertir tous les caractères spéciaux de la chaine de 
wide characters que l'on puisse trouver dans la langue française. Au travers de 
cette fonction, les caractères convertis en leur équivalent non-accentués sont 
les suivants :
        É, é, Ê, ê, Ë, ë, È, è, À, à, Ù, ù, Û, û, Ô, ô, Ö, ö, Ï, ï, Î, î

- void cesar (char msg[], int key);
Ceci est la fonction permettant le chiffrement d'un texte par l'algorithme de 
César. Il prend en entrée une chaîne de caractère msg ainsi qu'un entier key.
Le message msg sera alors chiffré avec le décalage key. Post-traitement, elle
affiche le message crypté puis le stocke dans le fichier texte 
"messageChiffreCesar.txt" dans lequel nous pouvons retrouver un historique
des autres chiffrements via l'algorithme de césar. 

- void vigenere (char msg[], char key[]);
Ceci est la fonction permettant le chiffrement d'un texte par l'algorithme de 
Vigenère. Il prend en entrée une chaîne de caractère msg ainsi qu'une chaine de
caractère key. Le message msg sera alors chiffré avec le décalage key. 
Post-traitement, elle affiche le message crypté puis le stocke dans le fichier 
texte "messageChiffreVigenere.txt" dans lequel nous pouvons retrouver un 
historique des autres chiffrements via l'algorithme de Vigenère.

- void decryptCesar (char msg[], int key);
Ceci est la fonction permettant le déchiffrement d'un texte par l'algorithme de 
César. Il prend en entrée une chaîne de caractère msg ainsi qu'un entier key.
Le message msg sera alors déchiffré avec le décalage key. Post-traitement, elle
affiche le message décrypté puis le stocke dans le fichier texte 
"messageDechiffreCesar.txt" dans lequel nous pouvons retrouver un historique
des autres déchiffrements via l'algorithme de césar.

- void decryptVigenere (char msg[], char key[]);
Ceci est la fonction permettant le déchiffrement d'un texte par l'algorithme de 
Vigenère. Il prend en entrée une chaîne de caractère msg ainsi qu'une chaine de
caractère key. Le message msg sera alors déchiffré avec le décalage key. 
Post-traitement, elle affiche le message décrypté puis le stocke dans le fichier 
texte "messageDechiffreVigenere.txt" dans lequel nous pouvons retrouver un 
historique des autres déchiffrements via l'algorithme de Vigenère.

Lien du dépôt GIT : 
https://framagit.org/jonathan.bonnefoy/projetc.git

© ChiffrementIUT 2020, Tous droit reservés à BONNEFOY Jonathan, CAULI Sacha