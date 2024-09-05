#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Contact{
    char nom[30];
    char numero[20];
    char email[30];
};
int count =0;
struct Contact carnet[100];

void ajouterContact(){
    if(count ==100){ printf("le cartnet est plein");}
    else{
    printf("entrer le nom de contact\n");
    scanf("%s", &carnet[count].nom);
    printf("entrer le numero de contact\n");
    scanf("%s", &carnet[count].numero);
    printf("entrer l'email de contact\n");
    scanf("%s", &carnet[count].email);
    count++;
    }
}

void modifierContact(){
    char str1[30];
    printf("entrer le nom du contact que vous voulez modifier\n");
    scanf("%s", &str1);
    for (int i=0; i<count ; i++){
        if(!strcmp(str1, carnet[i].nom)){
            printf("entrez le nouveau numero \n");
            scanf("%s", &carnet[i].numero);
            printf("entrer le nouveau email\n");
            scanf("%s", &carnet[i].email);
        }
    }
    printf("le contact a ete modifie avec succes \n");

}
void afficherContacts(){
    printf("nom | numero | email\n");
    for(int i=0; i<count; i++){
        printf("%s | %s | %s\n", carnet[i].nom, carnet[i].numero, carnet[i].email);
    }
}

void rechercherContact(){
    char  str[30];
    printf("entrer le nom du contact que vous recherchez\n");
    scanf("%s", &str);
    for(int i=0; i<count ; i++){
        if(!strcmp(str, carnet[i].nom)){
            printf("le nom du contact : %s\n", carnet[i].nom);
            printf("son numero : %s\n", carnet[i].numero);
            printf("son email : %s \n\n", carnet[i].email);
            return;
        }
    }
    printf("Contact n'est pas trouve\n");
}

int rechercher(char * s){
    for(int i=0; i<count; i++){
        if(!strcmp(s, carnet[i].nom)){
            return i;
        }
    }
    return -1;
}

void supprimerContact(){
    char str[30];
    printf("entrer le nom du contact a supprimer \n");
    scanf("%s", &str);
    int index = rechercher(str);
    if(index==-1){
        printf("le contact n'existe pas \n");
    }else {
        for(int i = index; i< count -1; i++){
            carnet[i]=carnet[i+1];
        }
        count--;
        printf("le contact a ete supprime avec succes \n");
    }
}
int main(){
    int choix ;
    do{
        printf("---Menu---\n\n");
        printf("1- Ajouter un contact au carnet\n");
        printf("2- Modifier un contact\n");
        printf("3- Supprimer un contact\n");
        printf("4- Afficher tous les contacts\n");
        printf("5- Rechercher un contact\n");
        printf("0- Quitter \n");
        printf("\n Votre choix \n\n");
        scanf("%d", &choix);
        switch(choix){
            case 1: ajouterContact();
                break;
            case 2: modifierContact();
                break;
            case 3: supprimerContact();
                break ;
            case 4: afficherContacts();
                break ;
            case 5: rechercherContact();
                break;
            default:
                break ;
        }
    }while(choix!=0);
    return 0;
}
