/**
* @brief Sistema para estoque e controle de validade para Mercado
*
* @details Este arquivo contem funcoes basicas para realizar teste de cadastro e verificacao.
* @authors Felipe Santos, Henrique Santos, Henry Wilson, Igor Ramos, Joao Guilherme
* @date 2026
* @version 2.17.0
*/

#include <stdio.h>
#include <string.h>
#define PRODUTO_VENCIDO 0
#define PRODUTO_PROXIMO 1
#define PRODUTO_OK 2

/**
 * @brief Cadastra um novo produto no sistema.
 *
 * @param nome        Nome do produto. Nao pode ser vazio.
 * @param quantidade Quantidade em estoque. Deve ser maior que zero.
 * @param setor      Setor onde o produto esta alocado. Nao pode ser vazio.
 * @param preco      Preco do produto. Deve ser maior que zero.
 * @param cod_pdt    Codigo identificador do produto. Deve ser maior que zero.
 *
 * @return 0 se o cadastro foi realizado com sucesso.
 * @return 1 se o nome estiver vazio.
 * @return 2 se a quantidade for invalida (negativa).
 * @return 3 se o setor estiver vazio.
 * @return 4 se o preco for invalido (negativo).
 * @return 5 se o codigo do produto for invalido (negativo).
 */
int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt)
{
    if(strlen(nome) == 0)
        return 1; // nome vazio

    if(quantidade < 0)
        return 2; // quantidade invalida

    if(strlen(setor) == 0)
        return 3; // setor vazio

    if(preco < 0)
        return 4; // preco invalido

    if(cod_pdt < 0)
        return 5; // codigo invalido

    return 0; // sucesso
}

/**
 * @brief Busca um produto pelo nome.
 *
 * @param nome Nome do produto a ser buscado.
 *
 * @return 0 se o produto for encontrado.
 * @return Valor diferente de 0 se o produto nao for encontrado.
 */
int buscarPorNome(char nome[])
{
    if(strcmp(nome, "Arroz") == 0)
        return 0;

    return 1;
}

/**
 * @brief Busca um produto pelo nome e categoria.
 *
 * @param nome      Nome do produto a ser buscado.
 * @param categoria Categoria (setor) do produto.
 *
 * @return 0 se o produto for encontrado.
 * @return Valor diferente de 0 se o produto nao for encontrado.
 */
int buscarProduto(char nome[], char categoria[])
{
    if(strcmp(nome, "Arroz") == 0 &&
       strcmp(categoria, "Graos") == 0
       )
    {
        return 0;
    }

    return 1;
}



///////////////////////////////// Funcao - IGOR //////////////////////////////////////////////////////

/**
 * @brief Verifica o estado de validade de um produto.
 *
 * @param diasParaVencer Numero de dias restantes ate o vencimento do produto.
 * Valor 0 indica produto vencido no dia.
 *
 * @return PRODUTO_VENCIDO (0) se diasParaVencer for igual a 0.
 * @return PRODUTO_PROXIMO (1) se diasParaVencer estiver entre 1 e 15 dias.
 * @return PRODUTO_OK      (2) se diasParaVencer for maior que 15 dias.
 */
int verificarValidade(int diasParaVencer)
{
    if(diasParaVencer <= 0)
        return PRODUTO_VENCIDO;

    if(diasParaVencer <= 14)
        return PRODUTO_PROXIMO;

    return PRODUTO_OK;
}

///////////////////////////////// Funcao - HENRIQUE //////////////////////////////////////////////////////

/**
 * @brief Cadastra um novo administrador no sistema.
 *
 * @param nome  Nome do administrador. Nao pode ser vazio nem conter numeros.
 * @param email E-mail do administrador. Nao pode ser vazio.
 * @param senha Senha do administrador. Nao pode ser vazia e deve ter no minimo 6 caracteres.
 *
 * @return 0 se o cadastro foi realizado com sucesso.
 * @return 1 se o nome estiver vazio.
 * @return 2 se o e-mail estiver vazio.
 * @return 3 se a senha estiver vazia.
 * @return 4 se a senha tiver menos de 6 caracteres.
 * @return 5 se o nome contiver caracteres numericos.
 */
int cadastrarAdm(char nome[], char email[], char senha[])
{
    int i;
    
    if(strlen(nome) == 0)
        return 1;

    if(strlen(email) == 0)
        return 2;

    if(strlen(senha) == 0)
        return 3;

    if(strlen(senha) < 6)
        return 4;

    for(i = 0; nome[i] != '\0'; i++)
    {
        if(nome[i] >= '0' && nome[i] <= '9')
            return 5;
    }

    return 0;
}

///////////////////////////////// Funcao - HENRY /////////////////////////////////////////////////
/**
 * @brief Realiza o login de um administrador no sistema.
 *
 * @param email E-mail do administrador. Nao pode ser vazio.
 * @param senha Senha do administrador. Nao pode ser vazia.
 *
 * @return 0 se o login for realizado com sucesso.
 * @return 1 se o e-mail estiver vazio.
 * @return 2 se a senha estiver vazia.
 * @return 3 se o e-mail nao for encontrado no sistema.
 * @return 4 se a senha estiver incorreta.
 */
int loginAdm(char email[], char senha[])
{
    if(strlen(email) == 0)
        return 1;

    if(strlen(senha) == 0)
        return 2;

    if(strcmp(email, "fulano@fulano.com") != 0)
        return 3;

    if(strcmp(senha, "123456") != 0)
        return 4;

    return 0;
}

///////////////////////////////// Funcao - JOAO GUILHERME /////////////////////////////////////////////////
/**
 * @brief Cadastra um novo setor no sistema.
 *
 * @param nome  Nome do setor. Não pode ser vazio.
 * @param local Localização física do setor. Não pode ser vazia.
 *
 * @return 0 se o cadastro foi realizado com sucesso.
 * @return 1 se o nome estiver vazio.
 * @return 2 se o local estiver vazio.
 */
int cadastrarSetor(char nome[], char local[])
{
    if(strlen(nome) == 0)
        return 1;

    if(strlen(local) == 0)
        return 2;

    return 0;
}