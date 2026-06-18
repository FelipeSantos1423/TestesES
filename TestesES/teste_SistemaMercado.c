/**
 * @file testes_comentado.c
 * @brief Sistema para estoque e controle de validade para Mercado
 *
 * @details Este arquivo contem os casos de teste do sistema de gerenciamento
 * de estoque e controle de validade para mercado. Cada funcao de teste
 * verifica um comportamento especifico do sistema, cobrindo cadastro de
 * produtos, administradores, setores, login e verificacao de validade.
 *
 * @authors Felipe Santos, Henrique Santos, Henry Wilson, Igor Ramos, Joao Guilherme
 * @date 2026
 * @version 2.19.0
 */

#include <stdio.h>
#include "minunit.h"

/** @defgroup StatusValidade Status de Validade do Produto
 * @brief Constantes que representam o estado de validade de um produto.
 * @{
 */
#define PRODUTO_VENCIDO 0  /**< Produto com prazo de validade expirado (0 dias ou menos). */
#define PRODUTO_PROXIMO 1  /**< Produto proximo do vencimento (ate 15 dias). */
#define PRODUTO_OK      2  /**< Produto dentro do prazo de validade (mais de 15 dias). */
/** @} */

/** @defgroup Prototipos Prototipos das Funcoes do Sistema
 * @brief Declaracoes das funcoes implementadas no sistema principal.
 * @{
 */

int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt);
int buscarPorNome(char nome[]);
int buscarProduto(char nome[], char categoria[]);
int verificarValidade(int diasParaVencer);
int cadastrarAdm(char nome[], char email[], char senha[]);
int loginAdm(char email[], char senha[]);
int cadastrarSetor(char nome[], char local[]);

/** @} */

/*****************************************************************/
/** @defgroup Testes Casos de Teste 
 * @brief Testes para a funcao cadastrarProduto().
 * @{
 */

/**
 * @brief Verifica o cadastro de um produto com dados validos.
 *
 * @details O teste garante que o sistema aceite o cadastro quando todos
 * os campos obrigatorios estiverem preenchidos corretamente.
 * Produto: "Arroz", quantidade 10, setor "Graos", preco R$12,90, codigo 1.
 */
MU_TEST(test_cadastrar_produto_valido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "Graos", 12.90, 1) == 0,
        "Erro ao cadastrar produto valido"
    );
}

/**
 * @brief Verifica que o sistema rejeita um produto com nome vazio.
 *
 * @details O campo nome eh obrigatorio. A funcao deve retornar erro 1
 * quando uma string vazia for fornecida como nome.
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
 * @details Quantidades negativas sao semanticamente invalidas para estoque.
 * A funcao deve retornar erro 2 ao receber valor negativo.
 */
MU_TEST(test_cadastrar_produto_quantidade_invalida)
{
    mu_assert(
        cadastrarProduto("Arroz", -1, "Estoque", 15.50, 1) == 2,
        "Quantidade invalida deveria retornar erro 2"
    );
}

/**
 * @brief Verifica que o sistema rejeita um produto sem setor informado.
 *
 * @details O campo setor eh obrigatorio para localizacao do produto no estoque.
 * A funcao deve retornar erro 3 quando uma string vazia for fornecida.
 */
MU_TEST(test_cadastrar_produto_setor_vazio)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "", 15.50, 1) == 3,
        "Setor vazio deveria retornar erro 3"
    );
}

/**
 * @brief Verifica que o sistema rejeita um preco negativo.
 *
 * @details Precos negativos sao invalidos para produtos de mercado.
 * A funcao deve retornar erro 4 ao receber valor negativo.
 */
MU_TEST(test_cadastrar_produto_preco_invalido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "Estoque", -1, 1) == 4,
        "Preco invalido deveria retornar erro 4"
    );
}

/**
 * @brief Verifica que o sistema rejeita um codigo de produto invalido.
 *
 * @details Codigos negativos nao sao aceitos como identificadores validos.
 * A funcao deve retornar erro 5 ao receber um codigo negativo.
 */
MU_TEST(test_cadastrar_produto_codigo_invalido)
{
    mu_assert(
        cadastrarProduto("Arroz", 10, "Estoque", 15.50, -1) == 5,
        "Codigo invalido deveria retornar erro 5"
    );
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

/** @} */

/*****************************************************************/
/** @defgroup Testes Casos de Teste
 * @brief Testes para as funcoes buscarPorNome() e buscarProduto().
 * @{
 */

/**
 * @brief Verifica a busca de um produto pelo nome.
 *
 * @details O sistema deve localizar o produto "Arroz" previamente cadastrado
 * e retornar 0 como indicativo de sucesso.
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
 * @details A combinacao de nome "Arroz" e categoria "Graos" deve localizar
 * o produto no sistema e retornar 0 como indicativo de sucesso.
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
 * @brief Testes para a funcao verificarValidade().
 * @{
 */

/**
 * @brief Verifica que um produto com zero dias para vencer eh classificado como vencido.
 *
 * @details Produto com diasParaVencer igual a 0 deve retornar PRODUTO_VENCIDO (0),
 * indicando que o prazo de validade ja se esgotou.
 */
MU_TEST(test_produto_vencido)
{
    mu_assert_int_eq(
        PRODUTO_VENCIDO,
        verificarValidade(0)
    );
}

/**
 * @brief Verifica que um produto com 14 dias para vencer eh classificado como proximo do vencimento.
 *
 * @details Produto com diasParaVencer igual a 14 deve retornar PRODUTO_PROXIMO (1),
 * indicando que o produto esta dentro da janela de alerta de vencimento.
 */
MU_TEST(test_produto_proximo)
{
    mu_assert_int_eq(
        PRODUTO_PROXIMO,
        verificarValidade(14)
    );
}

/**
 * @brief Verifica que um produto com 30 dias para vencer eh classificado como dentro do prazo.
 *
 * @details Produto com diasParaVencer igual a 30 deve retornar PRODUTO_OK (2),
 * indicando que o produto ainda esta dentro do prazo de validade normal.
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
 * @brief Testes para a funcao cadastrarAdm().
 * @{
 */

/**
 * @brief Verifica o cadastro de um administrador com dados validos.
 *
 * @details O teste garante que o sistema aceite o cadastro quando nome,
 * e-mail e senha estiverem preenchidos corretamente.
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
 * @details O campo e-mail eh obrigatorio para identificacao e login.
 * A funcao deve retornar erro 2 quando uma string vazia for fornecida.
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
 * @details A senha eh obrigatoria para autenticacao no sistema.
 * A funcao deve retornar erro 3 quando uma string vazia for fornecida.
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
 * @details Por politica de seguranca, senhas devem ter no minimo 6 caracteres.
 * A funcao deve retornar erro 4 quando a senha for muito curta.
 */
MU_TEST(test_cadastrar_adm_senha_curta)
{
    mu_assert(
        cadastrarAdm("Fulano", "Fulano@email.com", "12345") == 4,
        "Senha com menos de 6 caracteres deveria retornar erro"
    );
}


/**
 * @brief Verifica que o sistema rejeita nomes de administrador com numeros.
 *
 * @details Nomes de administradores devem conter apenas letras.
 * A funcao deve retornar erro 5 quando o nome contiver digitos numericos.
 */
MU_TEST(test_cadastrar_adm_nome_com_numero)
{
    mu_assert(
        cadastrarAdm("Fulano123", "Fulano@email.com", "123456") == 5,
        "Nome contendo numeros deveria retornar erro"
    );
}

////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/** @} */

/*****************************************************************/
/** @defgroup Testes Login Casos de Teste
 *  @brief Testes para a funcao loginAdm().
 *  @{
 */

/**
 * @brief Verifica o login de um administrador com credenciais validas.
 *
 * @details O sistema deve autenticar corretamente um administrador
 *          cujo e-mail e senha estejam cadastrados e corretos.
 */
MU_TEST(test_login_valido)
{
    mu_assert_int_eq(
        0,
        loginAdm("fulano@fulano.com", "123456")
    );
}

/**
 * @brief Verifica que o login falha quando o e-mail esta vazio.
 *
 * @details O campo e-mail e obrigatorio para autenticacao.
 *          A funcao deve retornar erro 1 quando uma string vazia for fornecida.
 */
MU_TEST(test_login_email_vazio)
{
    mu_assert_int_eq(
        1,
        loginAdm("", "123456")
    );
}

/**
 * @brief Verifica que o login falha quando a senha esta vazia.
 *
 * @details O campo senha e obrigatorio para autenticacao.
 *          A funcao deve retornar erro 2 quando uma string vazia for fornecida.
 */
MU_TEST(test_login_senha_vazia)
{
    mu_assert_int_eq(
        2,
        loginAdm("fulano@fulano.com", "")
    );
}

/**
 * @brief Verifica que o login falha para um e-mail nao cadastrado.
 *
 * @details O sistema nao deve autenticar e-mails inexistentes na base de dados.
 *          A funcao deve retornar erro 3 quando o e-mail nao for encontrado.
 */
MU_TEST(test_login_email_inexistente)
{
    mu_assert_int_eq(
        3,
        loginAdm("teste@gmail.com", "123456")
    );
}

/**
 * @brief Verifica que o login falha quando a senha esta incorreta.
 *
 * @details O sistema deve rejeitar autenticacao com senha errada para
 *          um e-mail valido e cadastrado. A funcao deve retornar erro 4.
 */
MU_TEST(test_login_senha_errada)
{
    mu_assert_int_eq(
        4,
        loginAdm("fulano@fulano.com", "999999")
    );
}

/** @} */

/*****************************************************************/
/** @defgroup Testes Casos de Teste
 *  @brief Testes para a função cadastrarSetor().
 *  @{
 */

/**
 * @brief Verifica o cadastro de um setor com dados válidos.
 *
 * @details O teste garante que o sistema aceite o cadastro quando nome
 *          e local estiverem preenchidos corretamente.
 *          Setor: "Graos", local: "Corredor A".
 */
MU_TEST(test_setor_valido)
{
    mu_assert_int_eq(
        0,
        cadastrarSetor("Graos", "Corredor A")
    );
}

/**
 * @brief Verifica que o sistema rejeita um setor com nome vazio.
 *
 * @details O campo nome é obrigatório para identificação do setor.
 *          A função deve retornar erro 1 quando o nome estiver vazio.
 */
MU_TEST(test_setor_nome_vazio)
{
    mu_assert_int_eq(
        1,
        cadastrarSetor("", "Corredor A")
    );
}

/**
 * @brief Verifica que o sistema rejeita um setor sem local informado.
 *
 * @details O campo local é obrigatório para localização física do setor.
 *          A função deve retornar erro 2 quando o local estiver vazio.
 */
MU_TEST(test_setor_local_vazio)
{
    mu_assert_int_eq(
        2,
        cadastrarSetor("Graos", "")
    );
}

/** @} */

/*****************************************************************/

/** @} */
/*****************************************************************/
/** @defgroup Suite Suite de Testes
 * @brief Configuracao e execucao de todos os casos de teste do sistema.
 * @{
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
    
    /* Verificacao de Validade */
    MU_RUN_TEST(test_produto_vencido); //USAREMOS PARA APRESENTAR
    MU_RUN_TEST(test_produto_proximo);
    MU_RUN_TEST(test_produto_ok);
    
     /* Cadastro de Administrador */
    MU_RUN_TEST(test_cadastrar_adm_valido); 
    MU_RUN_TEST(test_cadastrar_adm_email_vazio);
    MU_RUN_TEST(test_cadastrar_adm_senha_vazia);
    MU_RUN_TEST(test_cadastrar_adm_senha_curta); //USAREMOS PARA APRESENTAR
    MU_RUN_TEST(test_cadastrar_adm_nome_com_numero);
    
    
    /*Login de administrador*/
     MU_RUN_TEST(test_login_valido);
    MU_RUN_TEST(test_login_email_vazio);
    MU_RUN_TEST(test_login_senha_vazia);
    MU_RUN_TEST(test_login_email_inexistente);
    MU_RUN_TEST(test_login_senha_errada); //USAREMOS PARA APRESENTAR
    
    /*Cadastro de Setores*/
    MU_RUN_TEST(test_setor_valido);
    MU_RUN_TEST(test_setor_nome_vazio);
    MU_RUN_TEST(test_setor_local_vazio);
}

/** @} */

/**
 * @brief Funcao principal do programa de testes.
 *
 * @details Executa a suite de testes completa e exibe o relatorio final
 * com o resultado de cada caso de teste executado.
 *
 * @return Codigo de saida gerado pelo MinUnit.
 * Retorna 0 se todos os testes passaram, diferente de 0 caso contrario.
 */
int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}