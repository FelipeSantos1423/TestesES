/**
 * @file testes_comentado.c
 * @brief Sistema para estoque e controle de validade para Mercado
 *
 * @details Este arquivo contém os casos de teste do sistema de gerenciamento
 * de estoque e controle de validade para mercado. Cada função de teste
 * verifica um comportamento específico do sistema, cobrindo cadastro de
 * produtos, administradores, setores, login e verificação de validade.
 *
 * @authors Felipe Santos, Henrique Santos, Henry Wilson, Igor Ramos, João Guilherme
 * @date 2026
 * @version 2.1.0
 */

#include <stdio.h>
#include "minunit.h"

/** @defgroup StatusValidade Status de Validade do Produto
 *  @brief Constantes que representam o estado de validade de um produto.
 *  @{
 */
#define PRODUTO_VENCIDO 0  /**< Produto com prazo de validade expirado (0 dias ou menos). */
#define PRODUTO_PROXIMO 1  /**< Produto próximo do vencimento (até 15 dias). */
#define PRODUTO_OK      2  /**< Produto dentro do prazo de validade (mais de 15 dias). */
/** @} */

/** @defgroup Prototipos Protótipos das Funções do Sistema
 *  @brief Declarações das funções implementadas no sistema principal.
 *  @{
 */

int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt);

/** @} */

/*****************************************************************/
/** @defgroup Testes Casos de Teste 
 *  @brief Testes para a função cadastrarProduto().
 *  @{
 */

/**
 * @brief Verifica o cadastro de um produto com dados válidos.
 *
 * @details O teste garante que o sistema aceite o cadastro quando todos
 *          os campos obrigatórios estiverem preenchidos corretamente.
 *          Produto: "Arroz", quantidade 10, setor "Grãos", preço R$12,90, código 1.
 */
MU_TEST(test_cadastrar_produto_valido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "Grãos", 12.90, 1) == 0,
        "Erro ao cadastrar produto valido"
    );
}

/** @} */

/*****************************************************************/
/** @defgroup Suite Suite de Testes
 *  @brief Configuração e execução de todos os casos de teste do sistema.
 *  @{
 */

/**
 * @brief Executa todos os testes do sistema.
 */
MU_TEST_SUITE(test_suite)
{
    /* Cadastro de Produto */
    MU_RUN_TEST(test_cadastrar_produto_valido);
    
}

/** @} */

/**
 * @brief Função principal do programa de testes.
 *
 * @details Executa a suite de testes completa e exibe o relatório final
 *          com o resultado de cada caso de teste executado.
 *
 * @return Código de saída gerado pelo MinUnit.
 *         Retorna 0 se todos os testes passaram, diferente de 0 caso contrário.
 */
int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}
