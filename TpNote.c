/*TP-Programmation C ING1 GM01 - Maysa BAKHTI et Sanâa AÏT-BELLA*/
/*Ce document programmé en c est en réponse au sujet 1 du projet consistant en l'extraction des données d'un fichier csv et en manipulant ses données
pour calculer la distance de similarité entre le logement x et les autres logement et permettant de comparé les prix entre plusieurs logements*/
/*Création: 01/11/2022*/
/*Date de derniere modification: 10/12/2022*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Création de la structure logement contenant les caractéristique du logement
struct Logement{

float latitude;
float longitude;
char city[100];
int zipcode;
char state[100];
short int accommodation;
char room_type[100];
double bedrooms;
double bathrooms;
double beds;
double price;
float cleaning_free;
float security_nights;
short int minimum_nights;
short int maximum_nights;
short int number_of_reviews;

};




int main(){
// Initialisation du tableau ligne qui repertoriera les cases d'une ligne correspondant aux caractéristiques du logement
char ligne[1000];
// pointeur pour balayer les sous-chaînes obtenues
char *ptr_chaine ; 
// Numéro de la ligne dans le fichier csv
short int num_ligne = 1 ;
struct Logement l1;
// Initialisation de la variable qui correspondra au numéro logement
short int data_entier;
// Logement x le logement crée par défaut
struct Logement x;
int i;
int j;
// Tableau repertoriant les caractéristiques du logement x
int tab[8];
// tableau image du fichier csv 
float tab1[7918];
int k=0;
float dist = 0;
float tmp;

FILE *fichier;

fichier=fopen("airbnb_donnees_propres.csv","r");//ouverture du fichier airbnb_données_propres.csv en lecture
if(!fichier)
{
        return EXIT_FAILURE;

}
   
while (fgets(ligne, 1000, fichier) != NULL)
{
    printf("\n%s", ligne);
    num_ligne++ ;//parcours toutes les lignes du fichier csv
        ptr_chaine = strtok (ligne, ",");
       
// appel d'initialisation de strtok. Séparateur = ';'
/* on lit une cellule (colonne) après l'autre jusqu'à la fin de la ligne.*/

// Lecture cellule 1 correspondant à la case numéro logement que l'on ne va pas traiter car elle n'a pas d'importance dans le calcul de la distance
if (sscanf(ptr_chaine,"%hd", &data_entier))
        {
            ptr_chaine = strtok (NULL, ",");
        }

// Lecture cellule 2 :

        if (sscanf(ptr_chaine,"%hd", &l1.accommodation) != 1)
        {
            puts("\nPb de lecture cellule 2!");
            l1.accommodation=-11111;
        }
        ptr_chaine = strtok (NULL, ","); // remplace le prochain séparateur trouvé par 0

// Lecture cellule 3 :

        if (sscanf(ptr_chaine,"%lf", &l1.bedrooms) != 1)
        {
            puts("\nPb de lecture cellule 3!");
                   l1.bedrooms=-111.11;
        }
        ptr_chaine = strtok (NULL, ","); // remplace le prochain séparateur trouvé par 0

// Lecture cellule 4 :

        if (sscanf(ptr_chaine,"%lf", &l1.bathrooms) != 1)
        {
            puts("\nPb de lecture cellule 4!");
            l1.bathrooms=-111.11;
        }
        ptr_chaine = strtok (NULL, ","); // remplace le prochain séparateur trouvé par 0

// Lecture cellule 5 :

        if (sscanf(ptr_chaine,"%lf", &l1.beds) != 1)
        {
            puts("\nPb de lecture cellule 5!");
            l1.beds=-111.11;
        }
        ptr_chaine = strtok (NULL, ","); // remplace le prochain séparateur trouvé par 0

// Lecture cellule 6 :

        if (sscanf(ptr_chaine,"%lf", &l1.price) != 1)
        {
            puts("\nPb de lecture cellule 6!");
            l1.price=-111.11;
        }
        ptr_chaine = strtok (NULL, ","); // remplace le prochain séparateur trouvé par 0

// Lecture cellule 7 :

        if (sscanf(ptr_chaine,"%hd", &l1.minimum_nights) != 1)
        {
            puts("\nPb de lecture cellule 7!");
            l1.minimum_nights=-11111;
        }
        ptr_chaine = strtok (NULL, ","); // remplace le prochain séparateur trouvé par 0
       
// Lecture cellule 8 :

        if (sscanf(ptr_chaine,"%hd", &l1.maximum_nights) != 1)
        {
            puts("\nPb de lecture cellule 8 ");
            l1.maximum_nights=-11111;
        }
        ptr_chaine = strtok (NULL, ","); // remplace le prochain séparateur trouvé par 0

// Lecture cellule 9:

        if (sscanf(ptr_chaine,"%hd", &l1.number_of_reviews) != 1)
        {
            puts("\nPb de lecture cellule 9!");
            l1.number_of_reviews=-11111;
        }
        ptr_chaine = strtok (NULL, ","); // remplace le prochain séparateur trouvé par 0

// affichages de chaque case correspondant à chaque caractéristique d'une ligne, ligne par ligne jusqu'à la fin du fichier:

        printf("\n\t accomodation (entier): %11hd", l1.accommodation );
        printf("\n\t bedrooms (entier): %11.1lf", l1.bedrooms);
        printf("\n\t bathrooms (reel) : %11.1lf", l1.bathrooms);
        printf("\n\t beds (entier): %11.1lf", l1.beds);
        printf("\n\t price (entier): %11.1lf", l1.price);
        printf("\n\t minimum_nights : %11hd", l1.minimum_nights);
        printf("\n\t maximum_nights : %11hd", l1.maximum_nights);
        printf("\n\t number of reviews : %11hd\n", l1.number_of_reviews);

//Création du logement x:

        x.bedrooms=3;

        x.bathrooms=1;
        x.accommodation=5;
        x.beds=1;
        x.price=1;
        x.minimum_nights=1;
        x.maximum_nights=1;
        x.number_of_reviews=1;
       
//On crée un tableau tab contenant toutes les caractéristiques du logement x  

      tab[0]=x.accommodation;
        tab[1]=x.bedrooms;
        tab[2]=x.bathrooms;
        tab[3]=x.beds;
        tab[4]=x.price;
        tab[5]=x.minimum_nights;
        tab[6]=x.maximum_nights;
        tab[7]=x.number_of_reviews;



// Calcule de la distance de similarité
    for (i = 1; i < 10; i++)
    {
      dist = dist + pow(tab[i] -ligne[i],2);
      }
    dist = sqrt(dist);
    printf("\n\tDistance de similarité = %f\n", dist);
   
// On crée un tableau tab1 qui récupère toutes les valeurs de dist correspondant au résultat de calcule du logement x par rapport à chaque ligne du fichier csv

    tab1[k]=dist;
    k++;
}  


//parcours et affiche les élements du tableau non trié
// Mettre en commentaire pour voir les autres parties de l'execution 
printf("Tableau non trié\n");
for(i=1;i<7917;i++)
{
printf("%f\n",tab1[i]);
}

//permute les élements du tableau

for(i=1;i<=7917-1;i++)
{
j=i;
while( j>0 && tab1[j-1] > tab1[j])
{
  tmp = tab1[j];
          tab1[j] = tab1[j-1];
          tab1[j-1]=tmp;
          j--;
}
}
printf("\n*** TABLEAU TRIE ***\n");

//affiche les élements du tableau trié
// Mettre en commentaire pour voir les autres parties de l'execution 
for(i=1;i<7917;i++)
{
printf("%f\n",tab1[i]);
}

int somme;
float moyenne;
float moyenne1;
float moyenne2;
float moyenne3;
float moyenne4;
      somme=0;
      float somme1=0;
      float somme2=0;
      float somme3=0;
      float somme4=0;
     
printf("\n*** Tableau avec les k=30 plus proches voisins ***\n");
for(i=1;i<30;i++)
{
/*printf("%f\n",tab1[i]);*/
somme += l1.price;
somme1+= l1.minimum_nights;
somme2+= l1.beds;
somme3+= l1.bedrooms;

}
moyenne = (float)somme / (float)30;
moyenne1 = (float)somme1 / (float)30;
moyenne2 = (float)somme2 / (float)30;
moyenne3= (float)somme3 / (float)30;
printf("La moyenne des prix, pour k=30, est de : %f\n", moyenne);
printf("La moyenne des nuit minimum, pour k=30, est de : %f\n", moyenne1);
printf("La moyenne des lits, pour k=30, est de : %f\n", moyenne2);
printf("La moyenne des chambres, pour k=30, est de : %f\n", moyenne3);
printf("\n*** TABLEAU avec les k=50 plus proches voisins ***\n");
for(i=1;i<50;i++)
{
    ligne[i]=l1.price;
    somme += ligne[i];

}
moyenne = (float)somme / (float)50;
printf("La moyenne des prix, pour k=50, est de : %f\n", moyenne);


//Fermeture du fichier csv

    fclose (fichier);
    return EXIT_SUCCESS;
    return 0;
}
