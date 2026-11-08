#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Cliente
{
    char nome[200];
    char numero[20];
};

#define TAMANHO 100

struct Cliente tabela[TAMANHO];

int funcaoHash(char nome[])
{
    int soma = 0;
    
    for(int i = 0; nome[i] != '\0'; i++)
    {
        soma += nome[i];
    }
    
    
    return soma % TAMANHO;
}

int totalClientes = 0;

void inserir(char nome[], char numero[])
{
    
    if(totalClientes >= TAMANHO)
    {
        printf("O mapa está cheio!");
        return;
    }
    
    int indice = funcaoHash(nome);
    
    while(tabela[indice].nome[0] != '\0')
    {
        if(strcmp(tabela[indice].nome, nome) == 0)
        {
            printf("Cliente já cadastrado!");
            return;
        }
        
        indice = (indice + 1) % TAMANHO;
    }
    
    strcpy(tabela[indice].nome, nome);
    strcpy(tabela[indice].numero, numero);
    
    totalClientes++;
    printf("Cliente cadastrado com sucesso!\n");
}

void buscar(char nome[])
{
    int indice = funcaoHash(nome);
    int inicio = indice;
    
    while(tabela[indice].nome[0] != '\0')
    {
        if(strcmp(tabela[indice].nome, nome) == 0)
        {
            printf("Cliente encontrado!\n");
            printf("Nome: %s", tabela[indice].nome);
            printf("\n");
            printf("Número: %s", tabela[indice].numero);
            return;
        }
        
        indice = (indice + 1) % TAMANHO;
        
        if(indice == inicio)
        {
            break;
        }
    }
    printf("Nenhum cliente foi encontrado!\n");
}

int main()
{
    int opcao;
    char nome[200];
    char numero[20];
    
    for(int i = 0; i < TAMANHO; i++)
    {
        tabela[i].nome[0] = '\0';
    }
    
    do
    {
        printf("\n-- MENU DO MAPA -- \n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar cliente!\n");
        printf("2- Buscar clientes!\n");
        printf("\nEscolha uma das opções acima:");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 0:
                printf("Encerrando o programa...");
                break;
            case 1:
                printf("\n\nVocê escolheu inserir um cliente!\n");
                
                printf("Informe o nome do cliente: ");
                scanf(" %199[^\n]", nome);
                printf("\n");
                
                printf("Informe o número do cliente: ");
                scanf(" %19s", numero);
                printf("\n");
                
                inserir(nome, numero);
                break;
            case 2:
                printf("\n\nVocê escolheu buscar um cliente!\n");
                
                printf("Informe o nome de um cliente: ");
                scanf(" %199[^\n]", nome);
                printf("\n");
                
                buscar(nome);
                break;
            default:
                printf("Insira um valor valído!");
                break;
        }
    }while(opcao != 0);
    return 0;
}