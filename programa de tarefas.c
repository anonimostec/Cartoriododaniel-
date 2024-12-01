#include <stdio.h>  // Biblioteca para entrada e saída de dados
#include <stdlib.h> // Biblioteca para funções do sistema e manipulação de arquivos
#include <locale.h> // Biblioteca para suporte a caracteres especiais (acentos)
#include <string.h> // Biblioteca para manipulação de strings

int registro() { // Função para registrar um usuário
    char arquivo[50];    // Nome do arquivo (baseado no CPF)
    char cpf[40];        // CPF do usuário
    char nome[40];       // Nome do usuário
    char sobrenome[40];  // Sobrenome do usuário
    char cargo[40];      // Cargo do usuário

    printf("Digite o CPF a ser cadastrado (sem pontos ou traços): ");
    scanf("%s", cpf);
    strcpy(arquivo, cpf);

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(file, "%s,", cpf);
    fclose(file);

    printf("Digite seu nome: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite seu sobrenome: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite seu cargo: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("Registro salvo com sucesso no arquivo: %s\n", arquivo);
    system("pause");
    return 0;
}

int consulta()  
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("CPF não localizado. Tente novamente!\n");
        system("pause");
        return 1;
    }

    printf("\nInformações do usuário:\n");
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    fclose(file);
    system("pause");
    return 0;
}

int deletar() { 
    char cpf[40];

    printf("Digite o CPF do usuário que deseja deletar: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Usuário não cadastrado ou CPF incorreto.\n");
    }
    system("pause");
    return 0;
}

int main() 
{ 
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;

    while (1) 
	{
        system("cls");
        printf("\nCartório do Daniel Gonçalves!\n");
        printf("Escolha a opção desejada:\n");
        printf("\t1 - Registrar usuário\n");
        printf("\t2 - Consultar usuário\n");
        printf("\t3 - Deletar usuário\n");
        printf("\t4 - Sair do sistema\n");
        printf("Digite a opção desejada: ");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
        case 1:
            registro();
            break;
        case 2:
            consulta();
            break;
        case 3:
            deletar();
            break;
        case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
        default:
            printf("Opção inválida! Tente novamente.\n");
            system("pause");
            break;
        }
    }
    return 0;
}

