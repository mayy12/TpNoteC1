/*TP-Programmation C ING1 GM01 - Maysa BAKHTI et Sanâa AÏT-BELLA*/
/*Ce document programmé en c répond aux attente de la partie 2 du projet à savoir créer une file de processus*/
/*Création: 02/12/2022*/
/*Date de dernière modification: 10/12/2022*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define true 1
#define false 0

// Création du type processus qui est caractérisé par son nom sa durée d'execution et de sa priorité dans la file d'ordonnancement
typedef struct processus processus;
struct processus{
    char unsigned nom;
    int duree_exec;
    int priorite;
};
//Création de la structure file qui va nous permettre de répondre aux attentes de l'exercice
typedef struct file{
    processus value;
    struct file *next;
}file, *file1;
// Initialisation de la file qui est vide donc le premier et le dernier élément est necessairement vide
file *first = NULL;
file *last = NULL;
static int nb_elements = 0;


// Fonction qui permet de vérifier si la file est vide ou non
int est_vide(void){
    if(first == NULL && last == NULL){
       return true; 
    }
    
    else{
        return false;
    }
    return 0;
}

// Procédure qui nous permet d'afficher la file 
void afficher(void){
    if(est_vide()){
        printf("Rien a afficher car file vide\n");
        return;
    }
    file *tmp = first;

    while(tmp != NULL){
        printf("[%c] [%d] [%d]\n", tmp->value.nom, tmp->value.duree_exec, tmp->value.priorite);
        tmp = tmp->next;
    }
    printf("\n");
}
// Procédure qui nous permet d'ajouter des éléments à la file de processus
void ajouter(processus x){
    file *elmt;
    elmt = malloc(sizeof(file));
    if(elmt == NULL){
        fprintf(stderr, "Erreur allocation dynamique\n");
        exit(EXIT_FAILURE);
    }
    elmt->value.nom = x.nom;
    elmt->value.duree_exec = x.duree_exec;
    elmt->value.priorite = x.priorite;
    elmt->next = NULL;

    if(est_vide()){
        first = elmt;
        last = elmt;
    }
    else{
        last->next = elmt;
        last = elmt;
    }
    nb_elements++;
}
// Procédure qui nous permet de supprimer des processus de la file
void supprimer(void){
    if(est_vide()){
        printf("Rien a retirer car file vide\n");
        return;
    }
    file *tmp=first;
    if(first == last){
        first = NULL;
        last = NULL;
    }
    else{
        first = first->next;
        
    }
    free(tmp);
    nb_elements--;
}
// Supprimer la file de processus entièrement
void supp_file(void){
    if(est_vide()){
        printf("rien a supprimer file déjà vide");
        return;
    }
    while(!est_vide()){
        supprimer();
    }
}
//Programme principale
int main(void)
{
    // Initialisation d'un premier processus
    processus p1;
    p1.nom='1';
    p1.duree_exec=2;
    p1.priorite=2;
    // Ajout du processus à la file
    ajouter(p1);
    // Attente le temps de durée d'execution de 2 secondes 
    printf("La durée d'execution du processus et de 2 secondes, attendez ...\n");
    sleep(2);
    afficher();
    //Initialisation d'un second processus
    processus p2;
    p2.nom = '2';
    p2.duree_exec = 4;
    p2.priorite = 3;
    // Ajout du processus à la file
    ajouter(p2);
    // Attente le temps de durée d'execution de 4 secondes
    printf("La durée d'execution du processus et de 4 secondes, attendez ...\n");
    sleep(4);
    afficher();
    // Initialisation d'un troisième processus
    processus p3;
    p3.nom = '3';
    p3.duree_exec = 3;
    p3.priorite = 4;
    // Ajout du processus
    ajouter(p3);
    // Attente de 3 secondes
    printf("La durée d'execution du processus et de 3 secondes, attendez ...\n");
    sleep(3);
    afficher();
    // Défiler (=supprimer le 1e processus)
    printf("On supprime le premier processus \n");
    supprimer();

    
    afficher();
    // Défiler (=supprimer le 2e qui passe premier car le premier a était supprimer precedemment)
    printf("On supprime le deuxième processus \n");
    supprimer();
    // Défiler (= supprimer le dernier élement de la file)
    afficher();
    printf("On supprime le troisième processus \n");
    supprimer();

    afficher();  
}
