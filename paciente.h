#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    int id;
    char cpf[20];
    char nome[100];
    int idade;
    char data_cadastro[11]; // AAAA-MM-DD + '\0'
} Paciente;

#endif
