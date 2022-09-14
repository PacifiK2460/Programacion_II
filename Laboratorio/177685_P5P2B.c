#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ranged_rand(int min, int max){
    return min + rand() % (max - min);
}

typedef enum clase{PROGRAMACION, ELECTRONICA, ARTES, DIBUJO, COSTURA};

int rangos[] = {100,120,140,160,180};
char clases[5][15]={{"PROGRAMACION"},{"ELECTRONICA"},{"ARTES"},{"DIBUJO"},{"COSTURA"}};

typedef struct{
 char *nom_al;//nombre del inscrito
 int edad;//edad del inscrito
 int id_al;//id unico para el inscrito
}TipoAl; 

void capturaIns(TipoAl* grupo, int n);
int generaID(TipoAl* grupo, int n);
void imprimeUno(TipoAl* grupo, int n);
void sort(TipoAl* grupo, int n);

int main(){
    srand(0);  
    int ngrupos = ranged_rand(2,5);
    TipoAl** grupos = (TipoAl**)malloc(ngrupos*sizeof(TipoAl*));
  
    int *Ngrupos = (int*)malloc(ngrupos * sizeof(int));
    int *clase = (int*)malloc(ngrupos * sizeof(int));
  
    //TipoGrup *grupos = (TipoGrup*)malloc(ngrupos * sizeof(TipoGrup));
    printf("%d Grupos creados.\n",ngrupos);

    //skip error cheking
    for(int i = 0; i < ngrupos; i++){
        Ngrupos[i] = ranged_rand(2,5);
        printf("\tGrupo %d: %d alumno(s)\n", i, Ngrupos[i]);
        clase[i] = ranged_rand(0,4);
        grupos[i] = (TipoAl*)malloc(Ngrupos[i] * sizeof(TipoAl));
        capturaIns(grupos[i], Ngrupos[i]);
        sort(grupos[i], Ngrupos[i]);
    }
    for(int i = 0; i < ngrupos; i++){
      imprimeUno(grupos[i], Ngrupos[i]);
    }
}

void capturaIns(TipoAl* grupos, int n){
    TipoAl* current;
    for(int i = 0; i < n; i++){
        current = &grupos[i];

        current->nom_al = malloc(50);
        printf("Nombre del alumno %d:", i);
        scanf("%50s", current->nom_al);

        current->edad = ranged_rand(21,35);
        current->id_al = generaID(grupos, n);;
      
    }
}

int generaID(TipoAl* grupo, int n){
    int to_assign = 0;
    while(1){
        int con = 0;
        to_assign = ranged_rand(rangos[grupo->clase],rangos[grupo->clase] + 11);
        TipoAl* current;
        for(int i = 0; i < n; i++){
            current = grupo[i];
            if(current->id_al == to_assign)
                con = 1;
        }
      if(con == 0)
          break;
    }
    return to_assign;
}

void imprimeUno(TipoAl* grupo, int n){
  printf("Grupo: %s\n",clases[]);
  TipoAl* current;
  for(int i = 0; i < n; i++){
    current = &grupo->Alumnos[i];

    printf("Nombre: %s\tEdad: %d\tID:%d\n", current->nom_al,current->edad, current->id_al);
  }
}

void sort(TipoAl* grupo, int n){
  while(1){
    int c = 0;
    for(int i = 0; i < (n)-1; i++){
      if(grupo[i].edad > grupo[i+1].edad){
        TipoAl temp = grupo->Alumnos[i+1];
        
        grupo[i+1].nom_al = grupo[i].nom_al;
        grupo[i+1].edad = grupo[i].edad;
        grupo[i+1].id_al = grupo[i].id_al;
        
        grupo[i].nom_al = temp.nom_al;
        grupo[i].edad = temp.edad;
        grupo[i].id_al = temp.id_al;
        c = 1;
      }
    } 
    if(c == 0) break;
  }
}