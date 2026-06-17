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
 * @version 2.6.0
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
int buscarPorNome(char nome[]);
int buscarProduto(char nome[], char categoria[]);
int verificarValidade(int diasParaVencer);
int cadastrarAdm(char nome[], char email[], char senha[]);

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

/**
 * @brief Verifica que o sistema rejeita um produto com nome vazio.
 *
 * @details O campo nome é obrigatório. A função deve retornar erro 1
 *          quando uma string vazia for fornecida como nome.
 */
MU_TEST(test_cadastrar_produto_nome_vazio)
{
    mu_assert(
        cadastrarProduto("", 10, "Estoque", 15.50, 1) == 1,
        "Nome vazio deveria retornar erro 1"
    );
}


/**
 * @brief Verifica que o sistema rejeita uma quantidade negativa.
 *
 * @details Quantidades negativas são semanticamente inválidas para estoque.
 *          A função deve retornar erro 2 ao receber valor negativo.
 */
MU_TEST(test_cadastrar_produto_quantidade_invalida)
{
    mu_assert(
        cadastrarProduto("Arroz", -1, "Estoque", 15.50, 1) == 2,
        "Quantidade inválida deveria retornar erro 2"
    );
}

/**
 * @brief Verifica que o sistema rejeita um produto sem setor informado.
 *
 * @details O campo setor é obrigatório para localização do produto no estoque.
 *          A função deve retornar erro 3 quando uma string vazia for fornecida.
 */
MU_TEST(test_cadastrar_produto_setor_vazio)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "", 15.50, 1) == 3,
        "Setor vazio deveria retornar erro 3"
    );
}

/**
 * @brief Verifica que o sistema rejeita um preço negativo.
 *
 * @details Preços negativos são inválidos para produtos de mercado.
 *          A função deve retornar erro 4 ao receber valor negativo.
 */
MU_TEST(test_cadastrar_produto_preco_invalido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "Estoque", -1, 1) == 4,
        "Preço inválido deveria retornar erro 4"
    );
}

/**
 * @brief Verifica que o sistema rejeita um código de produto inválido.
 *
 * @details Códigos negativos não são aceitos como identificadores válidos.
 *          A função deve retornar erro 5 ao receber um código negativo.
 */
MU_TEST(test_cadastrar_produto_codigo_invalido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "Estoque", 15.50, -1) == 5,
        "Código inválido deveria retornar erro 5"
    );
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

/** @} */

/*****************************************************************/
/** @defgroup Testes Casos de Teste
 *  @brief Testes para as funÃ§Ãµes buscarPorNome() e buscarProduto().
 *  @{
 */

/**
 * @brief Verifica a busca de um produto pelo nome.
 *
 * @details O sistema deve localizar o produto "Arroz" previamente cadastrado
 *          e retornar 0 como indicativo de sucesso.
 */
MU_TEST(test_busca_por_nome)
{
    mu_assert_int_eq(
        0,
        buscarPorNome("Arroz")
    );
}

/**
 * @brief Verifica a busca completa de um produto por nome e categoria.
 *
 * @details A combinaÃ§Ã£o de nome "Arroz" e categoria "Graos" deve localizar
 *          o produto no sistema e retornar 0 como indicativo de sucesso.
 */
MU_TEST(test_busca_produto_completo)
{
    int resultado = buscarProduto("Arroz", "Graos");

    mu_assert_int_eq(
        0,
        resultado
    );
}

/** @} */

/*****************************************************************/
/** @defgroup Testes Validade Casos de Teste 
 *  @brief Testes para a funÃ§Ã£o verificarValidade().
 *  @{
 */

/**
 * @brief Verifica que um produto com zero dias para vencer Ã© classificado como vencido.
 *
 * @details Produto com diasParaVencer igual a 0 deve retornar PRODUTO_VENCIDO (0),
 *          indicando que o prazo de validade jÃ¡ se esgotou.
 */
MU_TEST(test_produto_vencido)
{
    mu_assert_int_eq(
        PRODUTO_VENCIDO,
        verificarValidade(0)
    );
}

/**
 * @brief Verifica que um produto com 14 dias para vencer Ã© classificado como prÃ³ximo do vencimento.
 *
 * @details Produto com diasParaVencer igual a 14 deve retornar PRODUTO_PROXIMO (1),
 *          indicando que o produto estÃ¡ dentro da janela de alerta de vencimento.
 */
MU_TEST(test_produto_proximo)
{
    mu_assert_int_eq(
        PRODUTO_PROXIMO,
        verificarValidade(14)
    );
}

/**
 * @brief Verifica que um produto com 30 dias para vencer Ã© classificado como dentro do prazo.
 *
 * @details Produto com diasParaVencer igual a 30 deve retornar PRODUTO_OK (2),
 *          indicando que o produto ainda estÃ¡ dentro do prazo de validade normal.
 */
MU_TEST(test_produto_ok)
{
    mu_assert_int_eq(
        PRODUTO_OK,
        verificarValidade(30)
    );
}


////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/** @} */

/*****************************************************************/
/** @defgroup Testes Casos de Teste
 *  @brief Testes para a funÃ§Ã£o cadastrarAdm().
 *  @{
 */

/**
 * @brief Verifica o cadastro de um administrador com dados vÃ¡lidos.
 *
 * @details O teste garante que o sistema aceite o cadastro quando nome,
 *          e-mail e senha estiverem preenchidos corretamente.
 */
MU_TEST(test_cadastrar_adm_valido)
{
    mu_assert(
        cadastrarAdm("Fulano", "Fulano@email.com", "123456") == 0,
        "Administrador valido deveria ser cadastrado"
    );
}

/**
 * @brief Verifica que o sistema rejeita um administrador com e-mail vazio.
 *
 * @details O campo e-mail Ã© obrigatÃ³rio para identificaÃ§Ã£o e login.
 *          A funÃ§Ã£o deve retornar erro 2 quando uma string vazia for fornecida.
 */
MU_TEST(test_cadastrar_adm_email_vazio)
{
    mu_assert(
        cadastrarAdm("Fulano", "", "123456") == 2,
        "Email vazio deveria retornar erro"
    );
}

/**
 * @brief Verifica que o sistema rejeita um administrador com senha vazia.
 *
 * @details A senha Ã© obrigatÃ³ria para autenticaÃ§Ã£o no sistema.
 *          A funÃ§Ã£o deve retornar erro 3 quando uma string vazia for fornecida.
 */
MU_TEST(test_cadastrar_adm_senha_vazia)
{
    mu_assert(
        cadastrarAdm("Fulano", "Fulano@email.com", "") == 3,
        "Senha vazia deveria retornar erro"
    );
}

/**
 * @brief Verifica que o sistema rejeita senhas com menos de 6 caracteres.
 *
 * @details Por polÃ­tica de seguranÃ§a, senhas devem ter no mÃ­nimo 6 caracteres.
 *          A funÃ§Ã£o deve retornar erro 4 quando a senha for muito curta.
 */
MU_TEST(test_cadastrar_adm_senha_curta)
{
    mu_assert(
        cadastrarAdm("Fulano", "Fulano@email.com", "12345") == 4,
        "Senha com menos de 6 caracteres deveria retornar erro"
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
    MU_RUN_TEST(test_cadastrar_produto_valido); //USAREMOS PARA APRESENTAR
    MU_RUN_TEST(test_cadastrar_produto_nome_vazio);
    MU_RUN_TEST(test_cadastrar_produto_quantidade_invalida);
    MU_RUN_TEST(test_cadastrar_produto_setor_vazio);
	MU_RUN_TEST(test_cadastrar_produto_preco_invalido);
	MU_RUN_TEST(test_cadastrar_produto_codigo_invalido);
	
	/* Busca de Produto */
    MU_RUN_TEST(test_busca_por_nome); //USAREMOS PARA APRESENTAR
    MU_RUN_TEST(test_busca_produto_completo);
    
    /* VerificaÃ§Ã£o de Validade */
    MU_RUN_TEST(test_produto_vencido); //USAREMOS PARA APRESENTAR
    MU_RUN_TEST(test_produto_proximo);
    MU_RUN_TEST(test_produto_ok);
    
     /* Cadastro de Administrador */
    MU_RUN_TEST(test_cadastrar_adm_valido); 
	MU_RUN_TEST(test_cadastrar_adm_email_vazio);
	MU_RUN_TEST(test_cadastrar_adm_senha_vazia);
	MU_RUN_TEST(test_cadastrar_adm_senha_curta); //USAREMOS PARA APRESENTARv
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
