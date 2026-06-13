// ALUNO DARLISON DE SOUSA SANTOS PIRES

#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 50
#define MAX_LETRAS 30

int main() {
    char banco_dados[MAX_REGISTROS][MAX_LETRAS];
    int opcao;
    int i, j;
    char nome[MAX_LETRAS];
    char novoNome[MAX_LETRAS];
    int encontrado;
    int posicao;
    int linhaVazia;
    char confirmacao;
    int totalNomes;
    
    for (i = 0; i < MAX_REGISTROS; i++) {
        banco_dados[i][0] = '\0';
    }
    
    printf("=== SISTEMA CRUD - TABELA DE NOMES ===\n");
    printf("Capacidade: %d registros\n", MAX_REGISTROS);
    printf("Cada nome: ate %d caracteres\n\n", MAX_LETRAS - 1);
    
    opcao = 1;
    
    while (opcao != 0) {
        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("1 - Incluir novo nome\n");
        printf("2 - Buscar nome\n");
        printf("3 - Modificar nome\n");
        printf("4 - Apagar nome\n");
        printf("5 - Listar todos os nomes\n");
        printf("0 - Sair\n");
        printf("====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("\n--- INCLUIR NOME ---\n");
                
                linhaVazia = -1;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (banco_dados[i][0] == '\0') {
                        linhaVazia = i;
                        break;
                    }
                }
                
                if (linhaVazia == -1) {
                    printf("ERRO: Banco de dados cheio!\n");
                    break;
                }
                
                printf("Digite o nome: ");
                scanf("%s", nome);
                
                encontrado = 0;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (banco_dados[i][0] != '\0') {
                        if (strcmp(banco_dados[i], nome) == 0) {
                            encontrado = 1;
                            break;
                        }
                    }
                }
                
                if (encontrado == 1) {
                    printf("ERRO: Nome '%s' ja existe!\n", nome);
                    printf("Crie um nome unico.\n");
                } else {
                    j = 0;
                    while (nome[j] != '\0') {
                        banco_dados[linhaVazia][j] = nome[j];
                        j++;
                    }
                    banco_dados[linhaVazia][j] = '\0';
                    printf("SUCESSO: Nome salvo na posicao %d!\n", linhaVazia);
                }
                break;
                
            case 2:
                printf("\n--- BUSCAR NOME ---\n");
                printf("Digite o nome para pesquisar: ");
                scanf("%s", nome);
                
                posicao = -1;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (banco_dados[i][0] != '\0') {
                        if (strcmp(banco_dados[i], nome) == 0) {
                            posicao = i;
                            break;
                        }
                    }
                }
                
                if (posicao != -1) {
                    printf("Nome encontrado no indice: %d\n", posicao);
                } else {
                    printf("Nome nao encontrado.\n");
                }
                break;
                
            case 3:
                printf("\n--- MODIFICAR NOME ---\n");
                printf("Digite o nome que deseja alterar: ");
                scanf("%s", nome);
                
                posicao = -1;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (banco_dados[i][0] != '\0') {
                        if (strcmp(banco_dados[i], nome) == 0) {
                            posicao = i;
                            break;
                        }
                    }
                }
                
                if (posicao == -1) {
                    printf("ERRO: Nome '%s' nao encontrado!\n", nome);
                    break;
                }
                
                printf("Digite o novo nome: ");
                scanf("%s", novoNome);
                
                encontrado = 0;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (banco_dados[i][0] != '\0' && i != posicao) {
                        if (strcmp(banco_dados[i], novoNome) == 0) {
                            encontrado = 1;
                            break;
                        }
                    }
                }
                
                if (encontrado == 1) {
                    printf("ERRO: Nome '%s' ja existe no sistema!\n", novoNome);
                } else {
                    j = 0;
                    while (novoNome[j] != '\0') {
                        banco_dados[posicao][j] = novoNome[j];
                        j++;
                    }
                    banco_dados[posicao][j] = '\0';
                    printf("SUCESSO: Nome alterado para '%s'!\n", novoNome);
                }
                break;
                
            case 4:
                printf("\n--- APAGAR NOME ---\n");
                printf("Digite o nome que deseja remover: ");
                scanf("%s", nome);
                
                posicao = -1;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (banco_dados[i][0] != '\0') {
                        if (strcmp(banco_dados[i], nome) == 0) {
                            posicao = i;
                            break;
                        }
                    }
                }
                
                if (posicao == -1) {
                    printf("ERRO: Nome '%s' nao encontrado!\n", nome);
                    break;
                }
                
                printf("Tem certeza que deseja apagar '%s'? (S/N): ", nome);
                scanf(" %c", &confirmacao);
                
                if (confirmacao == 'S' || confirmacao == 's') {
                    banco_dados[posicao][0] = '\0';
                    printf("SUCESSO: Nome removido!\n");
                } else {
                    printf("Operacao cancelada.\n");
                }
                break;
                
            case 5:
                printf("\n--- LISTA DE TODOS OS NOMES ---\n");
                printf("Indice | Nome\n");
                printf("-------|------------------------------\n");
                
                totalNomes = 0;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (banco_dados[i][0] != '\0') {
                        printf("%6d | %s\n", i, banco_dados[i]);
                        totalNomes++;
                    }
                }
                
                if (totalNomes == 0) {
                    printf("       | (banco de dados vazio)\n");
                }
                
                printf("-------|------------------------------\n");
                printf("Total de registros: %d / %d\n", totalNomes, MAX_REGISTROS);
                break;
                
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
            getchar();
        }
    }
    
    return 0;
}