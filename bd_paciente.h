#ifndef BD_PACIENTE_H
#define BD_PACIENTE_H

#include "paciente.h"

#define MAX_PACIENTES 1000

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int quantidade;
} BDPaciente;

void carregarDados(BDPaciente* bd, const char* nome_arquivo);
void listarPacientes(const BDPaciente* bd);
void consultarPaciente(const BDPaciente* bd);

#endif
