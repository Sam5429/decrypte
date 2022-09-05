#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERREUR(msg){\
        printf("%s refuse de s'ouvrir\n",msg);\
        return -1;\
}

int simple(int lettre);

int main()
{
  int lettre;
  FILE *txt, *txt_clean;

  if((txt = fopen("tet.txt","r"))==NULL){
    ERREUR("La vie devant soi");
  }
}

int simple(int lettre)
{
  if(lettre==(int)'-' || lettre==(int)'.' || lettre==(int)',' || lettre==(int)':' || lettre==(int)';' || lettre==39 || lettre==(int)'!' || lettre==(int)'?' || lettre<=(int)'0' && lettre>=(int)'9'){
    return 0;
  }
  if(lettre==(int)'û' || lettre==(int)'ù'){
    return (int)'u';
  }
  if(lettre==(int)'à'){
    return (int)'a';
  }
  if(lettre==(int)'é' || lettre==(int)'è' || lettre==(int)'ê'){
    return (int)'e';
  }
  if(lettre==(int)'ï'){
    return (int)'i';
  }
  if(lettre<=(int)'A' && lettre>=(int)'Z'){
    lettre += 32;
    return lettre;
  }
}