#include <stdio.h>
#include "../../libs/llist/llist.h"
#include "../../libs/io/io.h"
#include "../../libs/sstring/sstring.h"

int ranged_rand(int min, int max){
    return min + rand() % (max - min);
}


int rangos[] = {100,120,140,160,180};
char clases[5][15]={{"PROGRAMACION"},{"ELECTRONICA"},{"ARTES"},{"DIBUJO"},{"COSTURA"}};

enum clase{PROGRAMACION, ELECTRONICA, ARTES, DIBUJO, COSTURA};

typedef struct{
    int clase;
    LList* alumnos;
}grupo;

void agregarGrupo(LList* grupos);
void agregarAlumno(grupo* grupo);
int generarID(grupo* grupo);

typedef struct{
 String nombre;//nombre del inscrito
 int edad;//edad del inscrito
 int id;//id unico para el inscrito
}alumno; 


int main(){
    LList* Grupos = LList_new();

    int continuar = 1;
    do{
        input("Agrgar grupo? (1/0): ", evaluarInt(&continuar, stdin));
        if(continuar != 1) break;

        agregarGrupo(Grupos);
    }while(continuar);

    printf("Grupos: %d\n", LList_size(Grupos));
    for(int i = 0; i < LList_size(Grupos); i++){
        grupo* current = (grupo*)LList_get(Grupos, i);
        
        printf("\tGrupo %d: %s %d alumnos\n", i,clases[current->clase], LList_size(current->alumnos));

        for(int j = 0; j < LList_size(current->alumnos); j++){
            alumno* currentAlumno = (alumno*)LList_get(current->alumnos, j);
            printf("\t\tAlumno %d: %s, %d, %d\n", j, currentAlumno->nombre, currentAlumno->edad, currentAlumno->id);
        }
    }

}

void agregarGrupo(LList* grupos){
    grupo* current = (grupo*)malloc(sizeof(grupo));
    current->alumnos = LList_new();
    current->clase = ranged_rand(0,4);
    int continuar = 1;
    do{
        input("Agrgar alumno? (1/0): ", evaluarInt(&continuar, stdin));
        if(continuar != 1) break;

        agregarAlumno(current);
    }while(continuar);
    LList_add(grupos, current);
}

void agregarAlumno(grupo* grupo){
    alumno* current = (alumno*)malloc(sizeof(alumno));
    current->nombre = malloc(50);
    printf("Nombre del alumno: ");
    scanf(" %s", current->nombre);
 getchar();
  //input("Nombre del alumno: ", evaluarString(name, stdin));
    //printf("Alumno: %s\n", current->nombre);
    current->edad = ranged_rand(21,35);
    current->id = generarID(grupo);

    LList_add(grupo->alumnos, current);
}

int generarID(grupo* grupo){
    int to_assign = 1;
    while(to_assign == 1){
        to_assign = ranged_rand(rangos[grupo->clase], rangos[grupo->clase] + 11);
        alumno* current;
        for(int i = 0; i < LList_size(grupo->alumnos); i++){
            current = (alumno*)LList_get(grupo->alumnos, i);
            if(current->id == to_assign) {
                to_assign = 1;
                break;
            }
        }
    }
    return to_assign;
}