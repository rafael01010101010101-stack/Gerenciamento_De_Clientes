# Cadastro e Busca de Clientes utilizando Mapa Hash em C

## Descrição
Este projeto foi desenvolvido na linguagem C utilizando a estrutura de dados Mapa Hash. O programa possui um sistema de cadastro e busca de clientes, armazenando seus nomes e números de telefone.

## Funcionalidades
- Cadastrar novos clientes.
- Armazenar nomes e números de telefone.
- Buscar clientes pelo nome.
- Exibir os dados do cliente encontrado.
- Impedir o cadastro de clientes duplicados.
- Verificar se o mapa está cheio.
- Tratar colisões utilizando o método de endereçamento aberto com sondagem linear.

## Estrutura de dados
O programa utiliza um mapa hash implementado com um vetor de estruturas do tipo `Cliente`, com capacidade para armazenar até 100 clientes.

Para tratar colisões, foi utilizado o método de endereçamento aberto com sondagem linear. Quando uma posição já está ocupada, o programa verifica a próxima posição disponível até encontrar um espaço vazio.

## Principais funções

- `funcaoHash()`: calcula o índice de armazenamento utilizando a soma dos caracteres do nome e o resto da divisão pelo tamanho da tabela.
- `inserir()`: cadastra um novo cliente, verifica se já existe um cadastro com o mesmo nome e procura uma posição disponível.
- `buscar()`: procura um cliente pelo nome, percorrendo as posições da tabela até encontrar o cadastro correspondente ou concluir que ele não existe.

## Tecnologias utilizadas
- Linguagem C
- Biblioteca stdio.h
- Biblioteca string.h
- Biblioteca stdlib.h

## Como funciona
O programa apresenta um menu interativo no terminal, permitindo que o usuário escolha entre cadastrar um cliente ou realizar uma busca.

Durante o cadastro, o nome informado passa pela função hash, que calcula o índice onde os dados serão armazenados. Caso ocorra uma colisão, é utilizada a sondagem linear para encontrar outra posição disponível.

Na busca, o programa utiliza novamente a função hash e percorre a tabela até encontrar o cliente desejado.

## Objetivo
Praticar os conceitos de Mapa Hash, funções hash, endereçamento aberto e sondagem linear, desenvolvendo um sistema simples de cadastro e busca de clientes.
