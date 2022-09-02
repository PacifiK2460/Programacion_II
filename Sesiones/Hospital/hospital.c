#include <stdio.h>
#include <stdlib.h>
typedef struct Medico Medico;

typedef struct Paciente{
    Medico* Medico;
    char* Nombre;
    // ...
} Paciente;

typedef struct Medico{
    Paciente* Pacientes[10];
    char* Nombre;
    // ...
} Medico;

typedef struct Hospital{
    Paciente* Pacientes[10];
    Medico* Medicos[5];
    char* Nombre;
} Hospital;

int main(){

    Medico* medico1 = malloc(sizeof(Medico));
    medico1->Nombre = "MJuan";
    Medico* medico2 = malloc(sizeof(Medico));
    medico2->Nombre = "MPedro";
    Medico* medico3 = malloc(sizeof(Medico));
    medico3->Nombre = "MLuis";
    Medico* medico4 = malloc(sizeof(Medico));
    medico4->Nombre = "MMaria";
    Medico* medico5 = malloc(sizeof(Medico));
    medico5->Nombre = "MAna";

    Paciente* paciente1 = malloc(sizeof(Paciente));
    paciente1->Nombre = "PJuan";
    paciente1->Medico = medico1;
    Paciente* paciente2 = malloc(sizeof(Paciente));
    paciente2->Nombre = "PPedro";
    paciente2->Medico = medico2;
    Paciente* paciente3 = malloc(sizeof(Paciente));
    paciente3->Nombre = "PLuis";
    paciente3->Medico = medico3;
    Paciente* paciente4 = malloc(sizeof(Paciente));
    paciente4->Nombre = "PMaria";
    paciente4->Medico = medico4;
    Paciente* paciente5 = malloc(sizeof(Paciente));
    paciente5->Nombre = "PAna";
    paciente5->Medico = medico5;
    Paciente* paciente6 = malloc(sizeof(Paciente));
    paciente6->Nombre = "PJuan";
    paciente6->Medico = medico1;
    Paciente* paciente7 = malloc(sizeof(Paciente));
    paciente7->Nombre = "PPedro";
    paciente7->Medico = medico2;
    Paciente* paciente8 = malloc(sizeof(Paciente));
    paciente8->Nombre = "PLuis";
    paciente8->Medico = medico3;
    Paciente* paciente9 = malloc(sizeof(Paciente));
    paciente9->Nombre = "PMaria";
    paciente9->Medico = medico4;
    Paciente* paciente10 = malloc(sizeof(Paciente));
    paciente10->Nombre = "PAna";
    paciente10->Medico = medico5;

    medico1->Pacientes[0] = paciente1;
    medico1->Pacientes[1] = paciente2;
    medico2->Pacientes[0] = paciente3;
    medico2->Pacientes[1] = paciente4;
    medico3->Pacientes[0] = paciente5;
    medico3->Pacientes[1] = paciente6;
    medico4->Pacientes[0] = paciente7;
    medico4->Pacientes[1] = paciente8;
    medico5->Pacientes[0] = paciente9;
    medico5->Pacientes[1] = paciente10;


    Hospital hospital = {
        .Pacientes = {
            paciente1,
            paciente2,
            paciente3,
            paciente4,
            paciente5,
            paciente6,
            paciente7,
            paciente8,
            paciente9,
            paciente10
        },
        .Medicos = {
            medico1,
            medico2,
            medico3,
            medico4,
            medico5
        },
        .Nombre = "Hospital de la Universidad"
    };

    printf("> %s\nListado de Medicos: ", hospital.Nombre);
    for(int i = 0; i < 5; i++){
        printf("%s atiende a:p\n", hospital.Medicos[i]->Nombre);
        for(int j = 0; j < 3; j++){
            printf("\t%s\n", hospital.Medicos[i]->Pacientes[j]->Nombre);
        }
    }

    printf("\nListado de Pacientes: ");
    for(int i = 0; i < 10; i++){
        printf("\t%s es atendido por %s\n", hospital.Pacientes[i]->Nombre, hospital.Pacientes[i]->Medico->Nombre);
    }

}