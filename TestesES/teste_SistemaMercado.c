//PRODUTO_VENCIDO = 0
//PRODUTO_PROXIMO = 1
//PRODUTO_OK = 2

#include <stdio.h>
#include "minunit.h"

/* Funcoes que estao no SistemaMercado.c */
int produtoVencido(int diasParaVencer);
int produtoProximoVencimento(int diasParaVencer);
int produtoDentroValidade(int diasParaVencer);

//PRODUTO_VENCIDO = 1
//PRODUTO_PROXIMO = 2
//PRODUTO_OK = 3

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
        produtoVencido(-2)
    );
}

//if diasparaVencer == 0 venceu
//if dias paraVencer <=7 ta pra vencer
//if >7 ta longe de vencer

/*Caso 2 - Henrique*/
MU_TEST(test_produto_proximo_vencimento)
{
    mu_assert_int_eq(
        2,
        produtoProximoVencimento(5)
    );
}

/*Caso 3 - Henrique*/
MU_TEST(test_produto_dentro_validade)
{
    mu_assert_int_eq(
        3,
        produtoDentroValidade(8)
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
int cadastrarProdutoQuantidadeNaoNumerica(char quantidade[]);

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

/*Caso 2 - Henry*/


MU_TEST(test_cadastrar_produto_quantidade_nao_numerica)
{
    char quantidade[] = "ABC";

    int resultado = cadastrarProdutoQuantidadeNaoNumerica(quantidade);

    mu_assert_int_eq(0, resultado);
}
//Caso 1 - JoaoGuilherme//

MU_TEST(test_cadastrar_produto_preco_vazio)
{
    float preco = 0;

    int resultado = cadastrarProdutoPrecoVazio(preco);

    mu_assert_int_eq(0, resultado);
}
//Caso 2 - JoaoGuilherme//
MU_TEST(test_cadastrar_produto_preco_negativo)
{
    float preco = -10.0;

    int resultado = cadastrarProdutoPrecoNegativo(preco);

    mu_assert_int_eq(1, resultado);
}
//Caso 3 - JoaoGuilherme//
MU_TEST(test_cadastrar_produto_codigo_vazio)
{
    int codigo = 0;

    int resultado = cadastrarProdutoCodigoVazio(codigo);

    mu_assert_int_eq(0, resultado);
}
// Caso 1 - Igor Ramos//
MU_TEST(test_cadastrar_produto_validade_vazia)
{
    int validade = 0;

    int resultado = cadastrarProdutoValidadeVazia(validade);

    mu_assert_int_eq(0, resultado);
}
// Caso 2 - Igor Ramos//
MU_TEST(test_cadastrar_produto_estoque_vazio)
{
    int estoque = 0;

    int resultado = cadastrarProdutoEstoqueVazio(estoque);

    mu_assert_int_eq(0, resultado);
}
// Caso 3 - Igor Ramos//
MU_TEST(test_cadastrar_produto_estoque_negativo)
{
    int estoque = -10;

    int resultado = cadastrarProdutoEstoqueNegativo(estoque);

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
    MU_RUN_TEST(test_cadastrar_produto_quantidade_nao_numerica);
    
    MU_RUN_TEST (test_cadastrar_produto_preco_vazio);
    MU_RUN_TEST (test_cadastrar_produto_preco_negativo);
    MU_RUN_TEST (test_cadastrar_produto_codigo_vazio);
    
    MU_RUN_TEST(test_cadastrar_produto_validade_vazia);
    MU_RUN_TEST(test_cadastrar_produto_estoque_vazio);
    MU_RUN_TEST(test_cadastrar_produto_estoque_negativo);


}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}
