/*
====================================================
ARQUIVO: SistemaMercado.c
====================================================

Este arquivo cont√©m as fun√ß√µes do sistema de estoque
do supermercado.

Sua responsabilidade √© implementar as regras de neg√≥cio,
como:

- cadastrar produtos;
- remover produtos;
- atualizar estoque;
- buscar produtos;
- consultar informa√ß√µes.

As fun√ß√µes deste arquivo ser√£o utilizadas e validadas
pelos testes unit√°rios presentes no arquivo
teste_SistemaMercado.c.

Durante a fase de testes, algumas fun√ß√µes podem ser
implementadas como stubs (simula√ß√µes), retornando
valores pr√©-definidos para permitir a execu√ß√£o dos
testes sem a necessidade de desenvolver o sistema
completo.

====================================================
*/

/**
* @brief Sistema para Mercado 
*
* @details Este arquivo contÈm funÁıes b·sicas para realizar teste de cadastro, verificaÁ„o
* @author Felipe
* @ date 2026
* @version 1.5.0
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
 * @brief Verifica se um produto est· cadastrando corretamento.
 *
 * Esta funÁ„o simula o cadastro de um produto 
 *
 * @param nome Nome do produto.
 * @param quantidade Quantidade do produto.
 *
 * @return int Retorna 0 indicando produto cadastrado com sucesso.
 */
/*caso de teste 1 - Felipe*/
int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt)
{
    return 0;
}

/*Caso 2 - Felipe*/
/**
 * @brief Verifica se um produto est· cadastrando incorretamente.
 *
 * Esta funÁ„o simula o cadastro de um produto.
 *
 * @param nome Nome do produto.
 *
 * @return int Retorna 0 indicando nome inv·lido.
 */
 /*caso de teste 2 - Felipe*/
int cadastrarProdutoSemNome(char nome[])
{
    if(nome[0] == '\0')
    {
        return 0;
    }

    return 1;
}

/*Caso 3 - Felipe*/
/**
 * @brief Verifica se um produto est· sendo cadastrado com quantidade inv·lida.
 *
 * Esta funÁ„o simula o cadastro de um produto com quantidade em estoque negativa.
 *
 * @param quantidade Quantidade em estoque do produto.
 *
 * @return int Retorna 0 indicando quantidade inv·lida. 
 */
/*Caso de teste 3 - Felipe*/
int cadastrarProdutoQuantidadeNegativa(int quantidade)
{
    if(quantidade < 0)
    {
        return 0;
    }

    return 1;
}

