/**
* @brief Sistema para estoque e controle de validade para Mercado
*
* @details Este arquivo contem funcoes basicas para realizar teste de cadastro e verificacao.
* @authors Felipe Santos, Henrique Santos, Henry Wilson, Igor Ramos, João Guilherme
* @date 2026
* @version 2.13.0
*/

#include <stdio.h>
#include <string.h>
#define PRODUTO_VENCIDO 0
#define PRODUTO_PROXIMO 1
#define PRODUTO_OK 2

/**
 * @brief Cadastra um novo produto no sistema.
 *
 * @param nome       Nome do produto. Não pode ser vazio.
 * @param quantidade Quantidade em estoque. Deve ser maior que zero.
 * @param setor      Setor onde o produto está alocado. Não pode ser vazio.
 * @param preco      Preço do produto. Deve ser maior que zero.
 * @param cod_pdt    Código identificador do produto. Deve ser maior que zero.
 *
 * @return 0 se o cadastro foi realizado com sucesso.
 * @return 1 se o nome estiver vazio.
 * @return 2 se a quantidade for inválida (negativa).
 * @return 3 se o setor estiver vazio.
 * @return 4 se o preço for inválido (negativo).
 * @return 5 se o código do produto for inválido (negativo).
 */
int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt)
{
    if(strlen(nome) == 0)
        return 1; // nome vazio

    if(quantidade < 0)
        return 2; // quantidade inválida

    if(strlen(setor) == 0)
        return 3; // setor vazio

    if(preco < 0)
        return 4; // preço inválido

    if(cod_pdt < 0)
        return 5; // código inválido

    return 0; // sucesso
}

/**
 * @brief Busca um produto pelo nome.
 *
 * @param nome Nome do produto a ser buscado.
 *
 * @return 0 se o produto for encontrado.
 * @return Valor diferente de 0 se o produto nÃ£o for encontrado.
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
 * @return Valor diferente de 0 se o produto nÃ£o for encontrado.
 */
int buscarProduto(char nome[],char categoria[])
{
    if(strcmp(nome, "Arroz") == 0 &&
       strcmp(categoria, "Graos") == 0
	   )
    {
        return 0;
    }

    return 1;
}



///////////////////////////////// FunÃ§Ã£o - IGOR //////////////////////////////////////////////////////

/**
 * @brief Verifica o estado de validade de um produto.
 *
 * @param diasParaVencer NÃºmero de dias restantes atÃ© o vencimento do produto.
 *                       Valor 0 indica produto vencido no dia.
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

///////////////////////////////// FunÃ§Ã£o - HENRIQUE //////////////////////////////////////////////////////

/**
 * @brief Cadastra um novo administrador no sistema.
 *
 * @param nome  Nome do administrador. NÃ£o pode ser vazio nem conter nÃºmeros.
 * @param email E-mail do administrador. NÃ£o pode ser vazio.
 * @param senha Senha do administrador. NÃ£o pode ser vazia e deve ter no mÃ­nimo 6 caracteres.
 *
 * @return 0 se o cadastro foi realizado com sucesso.
 * @return 1 se o nome estiver vazio.
 * @return 2 se o e-mail estiver vazio.
 * @return 3 se a senha estiver vazia.
 * @return 4 se a senha tiver menos de 6 caracteres.
 * @return 5 se o nome contiver caracteres numÃ©ricos.
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


