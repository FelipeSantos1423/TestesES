/**
* @brief Sistema para estoque e controle de validade para Mercado
*
* @details Este arquivo contem os casos de teste do sistema.
* @authors Felipe Santos, Henrique Santos, Henry Wilson, Igor Ramos, João Guilherme
* @date 2026
* @version 1.15.3
*/

#include <stdio.h>
#include "minunit.h"

/* Funcoes de validacao - Henrique */
int produtoVencido(int diasParaVencer);
int produtoProximoVencimento(int diasParaVencer);
int produtoDentroValidade(int diasParaVencer);

/* Funcoes de cadastro - Felipe */
int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt);
int cadastrarProdutoSemNome(char nome[]);
int cadastrarProdutoQuantidadeNegativa(int quantidade);

/* Funcoes de validacao - Henry */
int validarCodigoProduto(char codigo[]);
int cadastrarProdutoSemSetor(char setor[]);
int cadastrarProdutoQuantidadeNaoNumerica(char quantidade[]);

/* Funcoes de validacao - Joao Guilherme */
int cadastrarProdutoPrecoVazio(float preco);
int cadastrarProdutoPrecoNegativo(float preco);
int cadastrarProdutoCodigoVazio(int codigo);

/* Funcoes de validacao - Igor Ramos */
int cadastrarProdutoValidadeVazia(int validade);
int cadastrarProdutoEstoqueVazio(int estoque);
int cadastrarProdutoEstoqueNegativo(int estoque);

/*****************************************************************/
/* Casos de teste - Henrique */
/*****************************************************************/

/**
 * @brief Verifica se um produto vencido retorna o codigo correto.
 *
 * O teste envia uma quantidade negativa de dias para vencimento,
 * simulando um produto ja vencido.
 */
MU_TEST(test_produto_vencido)
{
    mu_assert_int_eq(1, produtoVencido(-2));
}

/**
 * @brief Verifica se um produto proximo do vencimento retorna o codigo correto.
 *
 * O teste envia uma quantidade de dias dentro da faixa considerada
 * como proxima ao vencimento.
 */
MU_TEST(test_produto_proximo_vencimento)
{
    mu_assert_int_eq(2, produtoProximoVencimento(5));
}

/**
 * @brief Verifica se um produto dentro da validade retorna o codigo correto.
 *
 * O teste envia uma quantidade de dias suficiente para que o produto
 * seja considerado dentro da validade.
 */
MU_TEST(test_produto_dentro_validade)
{
    mu_assert_int_eq(3, produtoDentroValidade(10));
}

/*****************************************************************/
/* Casos de teste - Felipe */
/*****************************************************************/

/**
 * @brief Verifica o cadastro de um produto com dados validos.
 *
 * O teste garante que o sistema aceite o cadastro quando todos
 * os campos obrigatorios estiverem preenchidos corretamente.
 */
MU_TEST(test_cadastrar_produto_valido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "Grãos", 12.90, 10) == 0,
        "Erro ao cadastrar produto valido"
    );
}

/**
 * @brief Verifica o comportamento ao cadastrar um produto sem nome.
 *
 * O teste garante que a mensagem de erro de nome não preenchido seja exebida.
 */
MU_TEST(test_cadastrar_produto_nome_vazio)
{
    mu_assert(
        cadastrarProdutoSemNome("") == 0,
        "Produto com nome preenchido. Teste mal sucedido (nome deve estar vazio)"
    );
}

/**
 * @brief Verifica o comportamento ao cadastrar um produto com quantidade negativa.
 *
 * O teste garante que o sistema exiba a mensagem de erro para quantidade negativa
 */
MU_TEST(test_cadastrar_produto_quantidade_negativa)
{
    mu_assert(
        cadastrarProdutoQuantidadeNegativa(-5) == 0,
        "Produto com quantidade positiva preenchido. Teste mal sucedido (quantidade deve estar negativa)"
    );
}

/*****************************************************************/
/* Casos de teste - Henry */
/*****************************************************************/

/**
 * @brief Verifica se o codigo do produto contem letras e numeros.
 *
 * O teste valida o comportamento do sistema para codigos
 * alfanumericos.
 */
MU_TEST(test_codigo_produto_com_letras_e_numeros)
{
    char codigo[] = "ABC123";

    int resultado = validarCodigoProduto(codigo);

    mu_assert_int_eq(0, resultado);
}

/**
 * @brief Verifica o cadastro de um produto sem setor informado.
 *
 * O teste garante que o sistema trate corretamente um setor vazio.
 */
MU_TEST(test_cadastrar_produto_setor_vazio)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "", 12.90, 10) == 0,
        "Erro ao cadastrar produto valido"
    );
}

/**
 * @brief Verifica o cadastro de um produto com quantidade nao numerica.
 *
 * O teste valida o tratamento de entradas invalidas para o campo quantidade.
 */
MU_TEST(test_cadastrar_produto_quantidade_nao_numerica)
{
    char quantidade[] = "ABC";

    int resultado = cadastrarProdutoQuantidadeNaoNumerica(quantidade);

    mu_assert_int_eq(0, resultado);
}

/*****************************************************************/
/* Casos de teste - Joao Guilherme */
/*****************************************************************/

/**
 * @brief Verifica o comportamento ao cadastrar um produto com preco vazio.
 *
 * O teste utiliza o valor zero para simular a ausencia de preco.
 */
MU_TEST(test_cadastrar_produto_preco_vazio)
{
    float preco = 0;

    int resultado = cadastrarProdutoPrecoVazio(preco);

    mu_assert_int_eq(0, resultado);
}

/**
 * @brief Verifica o comportamento ao cadastrar um produto com preco negativo.
 *
 * O teste garante que valores negativos sejam tratados adequadamente.
 */
MU_TEST(test_cadastrar_produto_preco_negativo)
{
    float preco = -10.0;

    int resultado = cadastrarProdutoPrecoNegativo(preco);

    mu_assert_int_eq(0, resultado);
}

/**
 * @brief Verifica o comportamento ao cadastrar um produto sem codigo.
 *
 * O teste utiliza o valor zero para representar um codigo vazio.
 */
MU_TEST(test_cadastrar_produto_codigo_vazio)
{
    int codigo = 0;

    int resultado = cadastrarProdutoCodigoVazio(codigo);

    mu_assert_int_eq(0, resultado);
}

/*****************************************************************/
/* Casos de teste - Igor Ramos */
/*****************************************************************/

/**
 * @brief Verifica o comportamento ao cadastrar um produto sem validade.
 *
 * O teste utiliza valor zero para representar validade nao informada.
 */
MU_TEST(test_cadastrar_produto_validade_vazia)
{
    int validade = 0;

    int resultado = cadastrarProdutoValidadeVazia(validade);

    mu_assert_int_eq(0, resultado);
}

/**
 * @brief Verifica o comportamento ao cadastrar um produto sem estoque.
 *
 * O teste utiliza valor zero para representar estoque vazio.
 */
MU_TEST(test_cadastrar_produto_quantidade_vazio)
{
    int quantidade = 0;

    int resultado = cadastrarProdutoQuantidadeVazio(quantidade);

    mu_assert_int_eq(0, resultado);
}

/**
 * @brief Verifica o comportamento ao cadastrar um produto com quantidade invalida (.
 *
 * O teste garante que o sistema trate corretamente valores invalidos
 * para o estoque.
 */
MU_TEST(test_cadastrar_produto_quantidade_invalida)
{
    char quantidade[] = "ABC";

    int resultado = cadastrarProdutoQuantidadeInvalida(quantidade);

    mu_assert_int_eq(0, resultado);
}

/*****************************************************************/
/* Suite de testes */
/*****************************************************************/

/**
 * @brief Executa todos os testes do sistema.
 *
 * Reune todos os casos de teste implementados pelos integrantes
 * do grupo e executa cada um deles.
 */
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

    MU_RUN_TEST(test_cadastrar_produto_preco_vazio);
    MU_RUN_TEST(test_cadastrar_produto_preco_negativo);
    MU_RUN_TEST(test_cadastrar_produto_codigo_vazio);

    MU_RUN_TEST(test_cadastrar_produto_validade_vazia);
    MU_RUN_TEST(test_cadastrar_produto_quantidade_vazio);
    MU_RUN_TEST(test_cadastrar_produto_quantidade_invalida);
}

/**
 * @brief Funcao principal do programa de testes.
 *
 * Executa a suite de testes e exibe o relatorio final.
 *
 * @return Codigo de saida gerado pelo MinUnit.
 */
int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}
