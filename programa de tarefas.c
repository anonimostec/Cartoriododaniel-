#include <stdio.h>  // Biblioteca para entrada e sa�da de dados
#include <stdlib.h> // Biblioteca para fun��es do sistema e manipula��o de arquivos
#include <locale.h> // Biblioteca para suporte a caracteres especiais (acentos)
#include <string.h> // Biblioteca para manipula��o de strings

int registro() // Fun��o que cria um arquivo baseado no CPF e salva nome, sobrenome e cargo do usu�rio
{ 
    char arquivo[50]    // Vari�vel para armazenar o nome do arquivo (baseado no CPF)
    char cpf[40];        // CPF do usu�rio
    char nome[40];       // Nome do usu�rio
    char sobrenome[40];  // Sobrenome do usu�rio
    char cargo[40];      // Cargo do usu�rio

    printf("Digite o CPF a ser cadastrado: "); // Exibe mensagem para o usu�rio
    scanf("%s", cpf); // L� o CPF do usu�rio
    strcpy(arquivo, cpf); // Copia o CPF para ser usado como nome do arquivo

    FILE *file = fopen(arquivo, "w"); // Abre o arquivo no modo "escrita" (cria ou sobrescreve)
    fprintf(file, "%s,", cpf); // Escreve o CPF no arquivo e adiciona uma v�rgula
    fclose(file); // Fecha o arquivo ap�s gravar

    printf("Digite seu CPF sem pontos ou tra�os: "); // Exibe mensagem para o usu�rio
    scanf("%s", nome); // L� o nome do usu�rio
    file = fopen(arquivo, "a"); // Abre o arquivo no modo "anexar"
    fprintf(file, "%s," ,nome); // Adiciona o nome ao arquivo com uma v�rgula
    fclose(file); // Fecha o arquivo

    printf("Digite o sobrenome a ser cadastrado: "); // Exibe mensagem para o usu�rio
    scanf("%s", sobrenome); // L� o sobrenome do usu�rio
    file = fopen(arquivo, "a"); // Abre o arquivo no modo "anexar"
    fprintf(file, "%s,", sobrenome); // Adiciona o sobrenome ao arquivo com uma v�rgula
    fclose(file); // Fecha o arquivo

    printf("Digite o cargo a ser cadastrado: "); // Exibe mensagem para o usu�rio
    scanf("%s", cargo); // L� o cargo do usu�rio
    file = fopen(arquivo, "a"); // Abre o arquivo no modo "anexar"
    fprintf(file, "%s", cargo); // Adiciona o cargo ao arquivo
    fclose(file); // Fecha o arquivo

    printf("Registro salvo com sucesso no arquivo: %s\n", arquivo); // Informa que o registro foi salvo
    system("pause"); // Aguarda uma tecla para continuar
    return 0; // Retorna 0 indicando que a fun��o foi executada com sucesso
}

int consulta() { // Fun��o que l� e exibe os dados do arquivo correspondente ao CPF do usu�rio.
    setlocale(LC_ALL, "Portuguese"); // Suporte a caracteres especiais como acentos
    char cpf[40];  // CPF do usu�rio a ser consultado
    char conteudo[200];  // Buffer para armazenar os dados lidos do arquivo

    printf("Digite o CPF a ser consultado: "); // Exibe mensagem para o usu�rio
    scanf("%s", cpf); // L� o CPF do usu�rio

    FILE *file = fopen(cpf, "r"); // Tenta abrir o arquivo correspondente ao CPF no modo "leitura"
    if (file == NULL) { // Verifica se o arquivo n�o existe
        printf("CPF n�o localizado. Tente novamente!\n"); // Mensagem de erro
        system("pause"); // Aguarda uma tecla para continuar
        return 0; // Retorna 0 indicando que a consulta falhou
    }

    while (fgets(conteudo, 200, file) != NULL) { // L� uma linha do arquivo
        printf("\nInforma��es do usu�rio: %s", conteudo); // Exibe a linha lida
    }
    fclose(file); // Fecha o arquivo ap�s a leitura
    system("pause"); // Aguarda uma tecla para continuar
    return 0; // Retorna 0 indicando que a fun��o foi executada com sucesso
}

int deletar() { // Fun��o que exclui o arquivo correspondente ao CPF do usu�rio.
    char cpf[40]; // CPF do usu�rio a ser deletado

    printf("Digite o CPF do usu�rio que deseja deletar: "); // Exibe mensagem para o usu�rio
    scanf("%s", cpf); // L� o CPF do usu�rio

    if (remove(cpf) == 0) { // Tenta excluir o arquivo e verifica se foi bem-sucedido
        printf("Usu�rio deletado com sucesso!\n"); // Mensagem de sucesso
    } else { // Caso o arquivo n�o exista ou n�o possa ser exclu�do
        printf("Usu�rio n�o cadastrado ou CPF incorreto.\n"); // Mensagem de erro
    }
    system("pause"); // Aguarda uma tecla para continuar
    return 0; // Retorna 0 indicando que a fun��o foi executada com sucesso
}

int main() // Fun��o que exibe o menu e chama as fun��es conforme a escolha do usu�rio
{ 
    setlocale(LC_ALL, "Portuguese"); // Suporte a caracteres especiais como acentos
    int opcao = 0; // Vari�vel para armazenar a op��o escolhida pelo usu�rio

    while (1) // Loop principal para exibir o menu at� que o usu�rio escolha sair

	{
        system("cls"); // Limpa a tela
        printf("\nCart�rio do Daniel Gon�alves!\n"); // Cabe�alho do programa
        printf("Escolha a op��o desejada:\n"); // Instru��es para o usu�rio
        printf("\t1 - Registrar usu�rio\n"); // Op��o 1: Registro
        printf("\t2 - Consultar usu�rio\n"); // Op��o 2: Consulta
        printf("\t3 - Deletar usu�rio\n"); // Op��o 3: Dele��o
        printf("\t0 - Sair\n"); // Op��o 0: Sair
        printf("Digite a op��o desejada acima no menu: "); // Solicita a op��o ao usu�rio

        scanf("%d", &opcao); // L� a op��o escolhida
        system("cls"); // Limpa a tela antes de executar a pr�xima a��o

        switch (opcao) { // Verifica a op��o escolhida pelo usu�rio
        case 1:
            registro(); // Chama a fun��o registro() para registrar um novo usu�rio
            break;
        case 2:
            consulta(); // Chama a fun��o consulta() para consultar um usu�rio
            break;
        case 3:
            deletar(); // Chama a fun��o deletar() para excluir um usu�rio
            break;
        case 0:
            printf("Saindo do programa...\n"); // Mensagem de sa�da
            exit(0); // Encerra o programa
        default:
            printf("Op��o inv�lida! Tente novamente.\n"); // Mensagem para op��o inv�lida
            system("pause"); // Aguarda uma tecla para continuar
            break;
        }
    }
    return 0; // Retorna 0 indicando que o programa terminou corretamente
}

