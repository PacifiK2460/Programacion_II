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

typedef struct{
    int alumnos;
    TipoAl *Alumnos;
    clase clase;
}TipoGrup

void capturaIns(TipoGrup* grupo);
int generaID(TipoGrup* grupo, TipoAl* alumno);

int main(){
    srand(time(0));
    int grupos = RAND;
    TipoGrup *grupos = (TipoGrup*)malloc(grupos * sizeof(TipoGrup));

    //skip error cheking
    for(int i = 0; i < grupos; i++){
        grupos[i]->alumnos = ranged_rand(2,5);
        grupos[i]->Alumnos = (TipoAl*)malloc(grupos[i]->alumnos * sizeof(TipoAl));
        grupos[i]->nombre = ranged_rand(0,4);
        capturaIns(grupos[i]);
    }

}

void capturaIns(void* grupo){
    TipoAl* current;
    for(int i = 0; i < grupo->alumnos; i++){
        current = grupo->Alumnos[i];

        current->alumnos = malloc(50);
        scanf("%50s", current->nom_al);

        current->edad = ranged_rand(21,35);
        current->id_al = generaID(grupo, current);
    }
}

int generaID(TipoGrup* grupo, TipoAl* alumno){
    int to_assign = 0;
    int con = 1;
    while(con){
        int con = 0;
        int to_assign = ranged_rand(grupo->clase,grupo->clase + 11);
        TipoAl* current;
        for(int i = 0; i < grupo->alumnos; i++){
            current = grupo->Alumnos[i];
            if(current->id == to_assign)
                con = 1;
        }
    }
    return to_assign;
}