#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd_paciente.h"

void carregarDados(BDPaciente* bd, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    char linha[256];
    bd->quantidade = 0;

    // Pula o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) && bd->quantidade < MAX_PACIENTES) {
        Paciente* p = &bd->pacientes[bd->quantidade];
        sscanf(linha, "%d,%19[^,],%99[^,],%d,%10s",
               &p->id, p->cpf, p->nome, &p->idade, p->data_cadastro);
        bd->quantidade++;
    }

    fclose(arquivo);
}

void listarPacientes(const BDPaciente* bd) {
    printf("\nID  CPF               Nome                    Idade  Data_Cadastro\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < bd->quantidade; i++) {
        Paciente p = bd->pacientes[i];
        printf("%-3d %-17s %-22s %-6d %s\n",
               p.id, p.cpf, p.nome, p.idade, p.data_cadastro);
    }

    printf("\nTotal de pacientes: %d\n", bd->quantidade);
}

void consultarPaciente(const BDPaciente* bd) {
    int opcao;
    char busca[100];

    printf("\nEscolha o modo de consulta:\n");
    printf("1 - Por nome\n");
    printf("2 - Por CPF\n");
    printf("3 - Voltar ao menu\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    getchar(); // Limpar buffer

    if (opcao == 3) return;

    printf("Digite o valor de busca: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0'; // Remover '\n'

    printf("\nResultados encontrados:\n");
    printf("ID  CPF               Nome                    Idade  Data_Cadastro\n");
    printf("---------------------------------------------------------------\n");

    int encontrados = 0;
    for (int i = 0; i < bd->quantidade; i++) {
        Paciente p = bd->pacientes[i];
        if ((opcao == 1 && strncmp(p.nome, busca, strlen(busca)) == 0) ||
            (opcao == 2 && strncmp(p.cpf, busca, strlen(busca)) == 0)) {
            printf("%-3d %-17s %-22s %-6d %s\n",
                   p.id, p.cpf, p.nome, p.idade, p.data_cadastro);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum paciente encontrado.\n");
    }
}
