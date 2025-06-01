#include <stdio.h>
#include <stdlib.h>
#include "bd_paciente.h"

int main() {
    BDPaciente bd;
    carregarDados(&bd, "bd_paciente.csv");

    char opcao;

    while (1) {
        printf("\nHealthSys\n");
        printf("1 - Consultar paciente\n");
        printf("5 - Imprimir lista de pacientes\n");
        printf("Q - Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                consultarPaciente(&bd);
                break;
            case '5':
                listarPacientes(&bd);
                break;
            case 'Q':
            case 'q':
                printf("Encerrando o sistema.\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
