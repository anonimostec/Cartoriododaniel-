#include <stdio.h>  // Biblioteca para entrada e saída de dados
#include <stdlib.h> // Biblioteca para funções do sistema e manipulação de arquivos
#include <locale.h> // Biblioteca para suporte a caracteres especiais (acentos)
#include <string.h> // Biblioteca para manipulação de strings

int registro() // Função que cria um arquivo baseado no CPF e salva nome, sobrenome e cargo do usuário
{ 
    char arquivo[50]    // Variável para armazenar o nome do arquivo (baseado no CPF)
    char cpf[40];        // CPF do usuário
    char nome[40];       // Nome do usuário
    char sobrenome[40];  // Sobrenome do usuário
    char cargo[40];      // Cargo do usuário

    printf("Digite o CPF a ser cadastrado: "); // Exibe mensagem para o usuário
    scanf("%s", cpf); // Lê o CPF do usuário
    strcpy(arquivo, cpf); // Copia o CPF para ser usado como nome do arquivo

    FILE *file = fopen(arquivo, "w"); // Abre o arquivo no modo "escrita" (cria ou sobrescreve)
    fprintf(file, "%s,", cpf); // Escreve o CPF no arquivo e adiciona uma vírgula
    fclose(file); // Fecha o arquivo após gravar

    printf("Digite seu CPF sem pontos ou traços: "); // Exibe mensagem para o usuário
    scanf("%s", nome); // Lê o nome do usuário
    file = fopen(arquivo, "a"); // Abre o arquivo no modo "anexar"
    fprintf(file, "%s," ,nome); // Adiciona o nome ao arquivo com uma vírgula
    fclose(file); // Fecha o arquivo

    printf("Digite o sobrenome a ser cadastrado: "); // Exibe mensagem para o usuário
    scanf("%s", sobrenome); // Lê o sobrenome do usuário
    file = fopen(arquivo, "a"); // Abre o arquivo no modo "anexar"
    fprintf(file, "%s,", sobrenome); // Adiciona o sobrenome ao arquivo com uma vírgula
    fclose(file); // Fecha o arquivo

    printf("Digite o cargo a ser cadastrado: "); // Exibe mensagem para o usuário
    scanf("%s", cargo); // Lê o cargo do usuário
    file = fopen(arquivo, "a"); // Abre o arquivo no modo "anexar"
    fprintf(file, "%s", cargo); // Adiciona o cargo ao arquivo
    fclose(file); // Fecha o arquivo

    printf("Registro salvo com sucesso no arquivo: %s\n", arquivo); // Informa que o registro foi salvo
    system("pause"); // Aguarda uma tecla para continuar
    return 0; // Retorna 0 indicando que a função foi executada com sucesso
}

int consulta() { // Função que lê e exibe os dados do arquivo correspondente ao CPF do usuário.
    setlocale(LC_ALL, "Portuguese"); // Suporte a caracteres especiais como acentos
    char cpf[40];  // CPF do usuário a ser consultado
    char conteudo[200];  // Buffer para armazenar os dados lidos do arquivo

    printf("Digite o CPF a ser consultado: "); // Exibe mensagem para o usuário
    scanf("%s", cpf); // Lê o CPF do usuário

    FILE *file = fopen(cpf, "r"); // Tenta abrir o arquivo correspondente ao CPF no modo "leitura"
    if (file == NULL) { // Verifica se o arquivo não existe
        printf("CPF não localizado. Tente novamente!\n"); // Mensagem de erro
        system("pause"); // Aguarda uma tecla para continuar
        return 0; // Retorna 0 indicando que a consulta falhou
    }

    while (fgets(conteudo, 200, file) != NULL) { // Lê uma linha do arquivo
        printf("\nInformações do usuário: %s", conteudo); // Exibe a linha lida
    }
    fclose(file); // Fecha o arquivo após a leitura
    system("pause"); // Aguarda uma tecla para continuar
    return 0; // Retorna 0 indicando que a função foi executada com sucesso
}

int deletar() { // Função que exclui o arquivo correspondente ao CPF do usuário.
    char cpf[40]; // CPF do usuário a ser deletado

    printf("Digite o CPF do usuário que deseja deletar: "); // Exibe mensagem para o usuário
    scanf("%s", cpf); // Lê o CPF do usuário

    if (remove(cpf) == 0) { // Tenta excluir o arquivo e verifica se foi bem-sucedido
        printf("Usuário deletado com sucesso!\n"); // Mensagem de sucesso
    } else { // Caso o arquivo não exista ou não possa ser excluído
        printf("Usuário não cadastrado ou CPF incorreto.\n"); // Mensagem de erro
    }
    system("pause"); // Aguarda uma tecla para continuar
    return 0; // Retorna 0 indicando que a função foi executada com sucesso
}

int main() // Função que exibe o menu e chama as funções conforme a escolha do usuário
{ 
    setlocale(LC_ALL, "Portuguese"); // Suporte a caracteres especiais como acentos
    int opcao = 0; // Variável para armazenar a opção escolhida pelo usuário

    while (1) // Loop principal para exibir o menu até que o usuário escolha sair

	{
        system("cls"); // Limpa a tela
        printf("\nCartório do Daniel Gonçalves!\n"); // Cabeçalho do programa
        printf("Escolha a opção desejada:\n"); // Instruções para o usuário
        printf("\t1 - Registrar usuário\n"); // Opção 1: Registro
        printf("\t2 - Consultar usuário\n"); // Opção 2: Consulta
        printf("\t3 - Deletar usuário\n"); // Opção 3: Deleção
        printf("\t0 - Sair\n"); // Opção 0: Sair
        printf("Digite a opção desejada acima no menu: "); // Solicita a opção ao usuário

        scanf("%d", &opcao); // Lê a opção escolhida
        system("cls"); // Limpa a tela antes de executar a próxima ação

        switch (opcao) { // Verifica a opção escolhida pelo usuário
        case 1:
            registro(); // Chama a função registro() para registrar um novo usuário
            break;
        case 2:
            consulta(); // Chama a função consulta() para consultar um usuário
            break;
        case 3:
            deletar(); // Chama a função deletar() para excluir um usuário
            break;
        case 0:
            printf("Saindo do programa...\n"); // Mensagem de saída
            exit(0); // Encerra o programa
        default:
            printf("Opção inválida! Tente novamente.\n"); // Mensagem para opção inválida
            system("pause"); // Aguarda uma tecla para continuar
            break;
        }
    }
    return 0; // Retorna 0 indicando que o programa terminou corretamente
}

