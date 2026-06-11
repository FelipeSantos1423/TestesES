/*
====================================================
ARQUIVO: SistemaMercado.c
====================================================

Este arquivo contém as funções do sistema de estoque
do supermercado.

Sua responsabilidade é implementar as regras de negócio,
como:

- cadastrar produtos;
- remover produtos;
- atualizar estoque;
- buscar produtos;
- consultar informações.

As funções deste arquivo serão utilizadas e validadas
pelos testes unitários presentes no arquivo
teste_SistemaMercado.c.

Durante a fase de testes, algumas funções podem ser
implementadas como stubs (simulações), retornando
valores pré-definidos para permitir a execução dos
testes sem a necessidade de desenvolver o sistema
completo.

====================================================
*/
#include <stdio.h>

/*caso de teste 1 - Henrique*/
int produtoVencido()
{
    return 1;
}

/*caso de teste 2 - Henrique*/
int produtoProximoVencimento()
{
    return 2;
}

/*caso de teste 3 - Henrique*/
int produtoDentroValidade()
{
    return 3;
}

/*Caso 1 - Felipe*/
/**
 * @brief Verifica se um produto est� cadastrando corretamento.
 *
 * Esta fun��o simula o cadastro de um produto 
 *
 * @param nome Nome do produto.
 * @param quantidade Quantidade do produto.
 *
 * @return int Retorna 0 indicando produto cadastrado com sucesso.
 */
/*caso de teste 1 - Felipe*/
int cadastrarProduto(char nome[], int quantidade)
{
    return 0;
}

/*Caso 2 - Felipe*/
/**
 * @brief Verifica se um produto est� cadastrando incorretamente.
 *
 * Esta fun��o simula o cadastro de um produto.
 *
 * @param nome Nome do produto.
 *
 * @return int Retorna 1 indicando nome inv�lido.
 */
 /*caso de teste 1 - Felipe*/
int cadastrarProdutoSemNome(char nome[])
{
    if(nome[0] == '\0')
    {
        return 1;
    }

    return 0;
}
