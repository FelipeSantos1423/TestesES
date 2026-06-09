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

- cenários válidos;
- cenários alternativos;
- cenários de exceção.

Os testes são executados individualmente através
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

/* Função que está no SistemaMercado.c */
int cadastrarProduto(char nome[], int quantidade);

MU_TEST(test_cadastrar_produto_valido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10) == 1,
        "Erro ao cadastrar produto valido"
    );
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_cadastrar_produto_valido);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}