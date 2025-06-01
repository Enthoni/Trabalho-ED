# HealthSys - Sistema de Gerenciamento de Pacientes

## Descrição

Este projeto é a **Parte I** do trabalho de Estrutura de Dados (IFES - Serra), que consiste na implementação de um sistema de gerenciamento de pacientes em linguagem C.

O sistema é executado no terminal Linux e realiza:

- Leitura dos dados a partir de um arquivo CSV.
- Armazenamento dos pacientes em um vetor estático.
- Consulta de pacientes por **nome** ou **CPF** (busca por prefixo).
- Listagem de todos os pacientes cadastrados.

---

## Estrutura do Projeto

| Arquivo           | Descrição                                                   |
| ----------------- | ----------------------------------------------------------- |
| `main.c`          | Função principal com o menu e controle de fluxo             |
| `bd_paciente.c`   | Implementação das funções do TAD `BDPaciente`               |
| `bd_paciente.h`   | Interface do TAD `BDPaciente`                               |
| `paciente.h`      | Definição da estrutura `Paciente` com os campos necessários |
| `bd_paciente.csv` | Base de dados dos pacientes (formato CSV, com cabeçalho)    |
| `Makefile`        | Script para compilar facilmente no Linux                    |

---

## TADs Utilizados

### `Paciente`

Representa um paciente individual com os seguintes campos:

* `id` (int)
* `cpf` (string)
* `nome` (string)
* `idade` (int)
* `data_cadastro` (string - formato AAAA-MM-DD)

### `BDPaciente`

Estrutura que representa o banco de dados em memória:

* Vetor estático de `Paciente`
* Contador `quantidade` de pacientes carregados

---

## Decisões de Implementação

* Utilização de vetor estático para simplificar a alocação e controle de memória.
* Modularização do código com arquivos `.c` e `.h`.
* Busca por prefixo utilizando `strncmp()`.
* Leitura segura do CSV com `fgets()` e `sscanf()`.

---

## Autor

**Enthoni Araujo Fontis Serafim**
Curso de Bacharelado em Sistemas de Informação
Instituto Federal do Espírito Santo - Campus Serra

```