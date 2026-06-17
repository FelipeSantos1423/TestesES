/**
* @brief Sistema para estoque e controle de validade para Mercado
*
* @details Este arquivo contem funcoes basicas para realizar teste de cadastro e verificacao.
* @authors Felipe Santos, Henrique Santos, Henry Wilson, Igor Ramos, João Guilherme
* @date 2026
* @version 1.15.3
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


