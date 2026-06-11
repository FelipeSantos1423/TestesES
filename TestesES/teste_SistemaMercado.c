/*
====================================================
ARQUIVO: teste_SistemaMercado.c
====================================================

Este arquivo contém os testes unitários do sistema
de estoque do supermercado utilizando a biblioteca
MinUnit.

Objetivo:
Verificar se as funções implementadas em
SistemaMercado.c apresentam o comportamento esperado.

Cada caso de teste representa um cenário de uso,
incluindo:

- cenráios válidos;
- cenários alternativos;
- cenários de excessãoo.

Os testes sÃ£o executados individualmente atravÃ©s
das macros da biblioteca MinUnit.

Exemplo:

- cadastrar produto válido;
- cadastrar produto com dados inválidos;
- remover produto existente;
- buscar produto inexistente;
- atualizar estoque.

Caso uma condição esperada não seja satisfeita,
o teste falha e uma mensagem de erro é exibida.

====================================================
*/

//PRODUTO_VENCIDO = 0
//PRODUTO_PROXIMO = 1
//PRODUTO_OK = 2

#include <stdio.h>
#include "minunit.h"

/* Funções que estão no SistemaMercado.c */
int produtoVencido();
int produtoProximoVencimento();

/*Caso 1 - Henrique*/

/**
 * @brief Verifica se um produto está vencido.
 *
 * Esta função simula a validação de um produto vencido
 * retornando o código correspondente ao status de vencimento.
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
 * @brief Verifica se um produto está próximo do vencimento.
 *
 * Esta função simula a situação em que um produto está
 * próximo da data de vencimento e deve ser monitorado.
 *
 * @return int Retorna 1 indicando produto próximo do vencimento.
 */
MU_TEST(test_produto_proximo_vencimento)
{
    mu_assert_int_eq(
        2,
        produtoProximoVencimento()
    );
}


/*****************************************************************/

/* Função que está no SistemaMercado.c */
int cadastrarProduto(char nome[], int quantidade);

MU_TEST(test_cadastrar_produto_valido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10) == 0,
        "Erro ao cadastrar produto valido"
    );
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_cadastrar_produto_valido);
    
    MU_RUN_TEST(test_produto_vencido);
	MU_RUN_TEST(test_produto_proximo_vencimento);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}
