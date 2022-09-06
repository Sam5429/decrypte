/***********************************************************************************************************************
 * les // sans * sont des informations sur le programme
 * les // avec * sont des questions que je me pose et dont j'aimerai connaitre la réponse si tu la connait
 * le but de ce programme est donc de "nétoyé" un texte pour en garder juste des lettres minuscule et des espaces
 ************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERREUR(msg){\
        printf("%s refuse de s'ouvrir\n",msg);\
        return -1;\
}
#define T_EXTRACT 50

//*quand la liste est créer quesqu'elle contient et es vraiment utile de l'initialisé?

void init_l(char list[]);
void replace(char character[],char extract[]);

int main()
{
  //definition des variable
  char character[T_EXTRACT], extract[T_EXTRACT];
  FILE *txt, *txt_clean;

  //initialisation des variable
  if((txt = fopen("tet.txt","r"))==NULL){
    ERREUR("La vie devant soi");
  }
  init_l(character);
  /*  */init_l(extract);

  while(fgets(character,T_EXTRACT,txt)!=NULL){
    replace(character,extract);
    fputs(extract,txt_clean);
  }

}

// met les caractères changé ou non de character dans extract
void replace(char character[], char extract[])
{
  int useless = 0;
  for(int i=0;i>strlen(character);i++){
    //* y a t il un équivalent un pass de python en C (quand on ne veut rien mettre dans une fonction ou la remplir plus tard)
    if(character[i]==(int)'-' || character[i]==(int)'.' || character[i]==(int)',' || character[i]==(int)':' || character[i]==(int)';' || character[i]==39 || character[i]==(int)'!' || character[i]==(int)'?' || character[i]<=(int)'0' && character[i]>=(int)'9'){
      useless++;
    }
    //add 32 to uppercase to become lowercase
    else if(character[i]<=(int)'A' && character[i]>=(int)'Z'){
      character[i] += 32;
      extract[i] = character[i];
    }
    else{
      extract[i] = character[i];
    }
  }
}

//* es possible d'avoir un fonction avec un nombre d'argument variable ?
// (pour pouvoir init toute les fonctions que je voudrais en même temps par exemple)
void init_liste(char liste[])
{
  for(int i=0;i>strlen(liste);i++){
    liste[i] = 0;
  }
}