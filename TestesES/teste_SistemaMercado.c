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

#include <stdio.h>
#include "minunit.h"
#define PRODUTO_VENCIDO 0
#define PRODUTO_PROXIMO 1
#define PRODUTO_OK 2

/* Funções que estão no SistemaMercado.c */
int produtoVencido();
int produtoProximoVencimento();
int produtoDentroValidade();

/*Caso 1 - Henrique*/
MU_TEST(test_produto_vencido)
{
    mu_assert_int_eq(
        2,
        produtoVencido()
    );
}

/*Caso 2 - Henrique*/
MU_TEST(test_produto_proximo_vencimento)
{
    mu_assert_int_eq(
        2,
        produtoProximoVencimento()
    );
}

/*Caso 3 - Henrique*/
MU_TEST(test_produto_dentro_validade)
{
    mu_assert_int_eq(
        3,
        produtoDentroValidade()
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
    MU_RUN_TEST(test_produto_dentro_validade);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}
