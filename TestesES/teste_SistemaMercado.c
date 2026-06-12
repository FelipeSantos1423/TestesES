/*
====================================================
ARQUIVO: teste_SistemaMercado.c
====================================================

Este arquivo contem os testes unitarios do sistema
de estoque do supermercado utilizando a biblioteca
MinUnit.

Objetivo:
Verificar se as funcoes implementadas em
SistemaMercado.c apresentam o comportamento esperado.

Cada caso de teste representa um cenario de uso,
incluindo:

- cenarios validos;
- cenarios alternativos;
- cenarios de excecao.

Os testes sao executados individualmente atraves
das macros da biblioteca MinUnit.

Exemplo:

- cadastrar produto valido;
- cadastrar produto com dados invalidos;
- remover produto existente;
- buscar produto inexistente;
- atualizar estoque.

Caso uma condicao esperada nao seja satisfeita,
o teste falha e uma mensagem de erro e exibida.

====================================================
*/

//PRODUTO_VENCIDO = 0
//PRODUTO_PROXIMO = 1
//PRODUTO_OK = 2

#include <stdio.h>
#include "minunit.h"

/* Funcoes que estao no SistemaMercado.c */
int produtoVencido();
int produtoProximoVencimento();
int produtoDentroValidade();


/*Caso 1 - Henrique*/

/**
 * @brief Verifica se um produto esta vencido.
 *
 * Esta funcao simula a validacao de um produto vencido
 * retornando o codigo correspondente ao status de vencimento.
 *
 * @return int Retorna 0 indicando produto vencido.
 */
MU_TEST(test_produto_vencido)
{
    mu_assert_int_eq(
        1,
        produtoVencido()
    );
}

/*Caso 2 - Henrique*/
/**
 * @brief Verifica se um produto esta proximo do vencimento.
 *
 * Esta funcao simula a situacao em que um produto esta
 * proximo da data de vencimento e deve ser monitorado.
 *
 * @return int Retorna 1 indicando produto proximo do vencimento.
 */
MU_TEST(test_produto_proximo_vencimento)
{
    mu_assert_int_eq(
        2,
        produtoProximoVencimento()
    );
}

/*Caso 3 - Henrique*/
/**
 * @brief Verifica se um produto esta dentro da validade.
 *
 * Esta funcao simula a validacao de um produto que ainda
 * pode ser comercializado normalmente.
 *
 * @return int Retorna 2 indicando produto dentro da validade.
 */
MU_TEST(test_produto_dentro_validade)
{
    mu_assert_int_eq(
        3,
        produtoDentroValidade()
    );
}

/*****************************************************************/

/*Caso 1 - Felipe*/
int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt);
int cadastrarProdutoSemNome(char nome[]);
int cadastrarProdutoQuantidadeNegativa(int quantidade);

MU_TEST(test_cadastrar_produto_valido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "", 12.90, 10) == 0,
        "Erro ao cadastrar produto valido"
    );
}

/*Caso 2 - Felipe*/
MU_TEST(test_cadastrar_produto_nome_vazio)
{
    mu_assert(
        cadastrarProdutoSemNome("") == 0,
        "Produto com nome preenchido. Teste mal sucedido (nome deve estar vazio)"
    );
}

/*Caso 3 - Felipe*/
MU_TEST(test_cadastrar_produto_quantidade_negativa)
{
    mu_assert(
        cadastrarProdutoQuantidadeNegativa(-5) == 0,
        "Produto com quantidade positiva preenchido. Teste mal sucedido (quantidade deve estar negativa)"
    );
}

/*****************************************************************/
int validarCodigoProduto(char codigo[]);
int cadastrarProdutoSemSetor(char setor[]);

/*Caso 1 - Henry*/
MU_TEST(test_codigo_produto_com_letras_e_numeros)
{
    char codigo[] = "ABC123";

    int resultado = validarCodigoProduto(codigo);

    mu_assert_int_eq(0, resultado);
}

/*Caso 2 - Henry*/
MU_TEST(test_cadastrar_produto_setor_vazio)
{
    char setor[] = "";

    int resultado = cadastrarProdutoSemSetor(setor);

    mu_assert_int_eq(0, resultado);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_cadastrar_produto_valido);
    MU_RUN_TEST(test_cadastrar_produto_nome_vazio);
    MU_RUN_TEST(test_cadastrar_produto_quantidade_negativa);

    MU_RUN_TEST(test_produto_vencido);
    MU_RUN_TEST(test_produto_proximo_vencimento);
    MU_RUN_TEST(test_produto_dentro_validade);
    
    MU_RUN_TEST(test_codigo_produto_com_letras_e_numeros);
    MU_RUN_TEST(test_cadastrar_produto_setor_vazio);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}