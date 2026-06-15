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

/*Caso de teste 1 - Henrique*/
/**
 * @brief Verifica se é exibida a mensagem de "produto está vencido".
 *
 * Esta funcao simula a validacao de um produto vencido
 * retornando o codigo correspondente ao status de vencimento.
 *
 * @param diasParaVencer Dias restantes para vencimento
 * @return int Retorna 1 indicando produto vencido.
 */

int produtoVencido(int diasParaVencer)
{
	if(diasParaVencer <=0){
		return 1;
	}   
	return 0;
}

/*Caso de teste 2 - Henrique*/
/**
 * @brief Verifica se um produto esta proximo do vencimento.
 *
 * Esta funcao simula a situacao em que um produto esta
 * proximo da data de vencimento e deve ser monitorado.
 *
 * @param diasParaVencer
 * @return int Retorna 2 indicando produto proximo do vencimento.
 */
int produtoProximoVencimento(int diasParaVencer)
{
    	if(diasParaVencer > 0 && diasParaVencer <=7){
		return 2;
	}   
}

/*Caso de teste 3 - Henrique*/
/**
 * @brief Verifica se um produto esta dentro da validade.
 *
 * Esta funcao simula a validacao de um produto que ainda
 * pode ser comercializado normalmente.
 *
 * @param diasParaVencer
 * @return int Retorna 3 indicando produto dentro da validade.
 */
int produtoDentroValidade(int diasParaVencer)
{
    	if(diasParaVencer >7){
		return 3;
	}   
}

/*Caso 1 - Felipe*/
/**
 * @brief Verifica se um produto esta sendo cadastrado corretamente.
 *
 * Esta funcao simula o cadastro de um produto com todos os campos preenchidos corretamente.
 *
 * @param nome Nome do produto.
 * @param quantidade Quantidade do produto.
 * @param setor Setor que produto será armazenado
 * @param preco Preço do produto
 * @param cod_pdt Código do produto
 * @return int Retorna 0 indicando produto cadastrado com sucesso.
 */
int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt)
{
    return 0;
}

/*Caso 2 - Felipe*/
/**
 * @brief Verifica se um produto é impedido de ser cadastrado sem nome.
 *
 * Esta funcao simula o cadastro de um produto sem nome.
 *
 * @param nome Nome do produto.
 *
 * @return int Retorna 0 indicando nome invalido.
 */
int cadastrarProdutoSemNome(char nome[])
{
    if(nome[0] == '\0')
    {
    	printf("Caso 2.2 - Mensagem de erro: Produto não pode ser cadastrado sem nome\n");
        return 0;
    }

    return 1;
}

/*Caso 3 - Felipe*/
/**
 * @brief Verifica se um produto esta sendo cadastrado com quantidade invalida.
 *
 * Esta funcao simula o cadastro de um produto com quantidade em estoque negativa.
 *
 * @param quantidade Quantidade em estoque do produto.
 *
 * @return int Retorna 0 indicando quantidade invalida.
 */
int cadastrarProdutoQuantidadeNegativa(int quantidade)
{
    if(quantidade < 0)
    {
    	printf("Caso 2.3 - Mensagem de erro: Produto não pode ser cadastrado com quantidade negativa");
        return 0;
    }

    return 1;
}


/*Caso 1 - Henry*/
/**
 * @brief Verifica se o codigo do produto é composto apenas por numeros.
 *
 * Esta função simula o preenchimento do campo "codigo do produto" com caracteres invalidos.
 *
 * @param codigo Codigo do produto.
 *
 * @return Retorna 0 indicando codigo invalido.
 */
int validarCodigoProduto(char codigo[])
{
    return 0;
}

/*Caso 2 - Henry*/
/**
 * @brief Verifica se o produto esta sendo cadastrado com o setor vazio.
 *
 * Esta funcao simula o preenchimento incorreto do campo
 * "Setor armazenado", deixando-o vazio.
 *
 * @param setor Setor do produto.
 *
 * @return Retorna 0 indicando setor invalido.
 */
int cadastrarProdutoSemSetor(char nome[], int quantidade, char setor[], float preco, int cod_pdt)
{
    return 0;
}

/*Caso 3 - Henry*/
/**
 * @brief Verifica se a quantidade do produto possui valor nao numerico.
 *
 * Esta funcao simula o preenchimento incorreto do campo
 * quantidade com caracteres alfabeticos.
 *
 * @param quantidade Quantidade informada pelo usuario.
 *
 * @return Retorna 0 indicando quantidade invalida.
 */
int cadastrarProdutoQuantidadeNaoNumerica(char quantidade[])
{
    return 0;
}

//Caso 1 - JoaoGuilherme//
/**
 * @brief Verifica se o preco do produto foi informado.
 *
 * Esta funcao simula o preenchimento incorreto do campo
 * preco com valor vazio (igual a 0).
 *
 * @param preco Preco informado pelo usuario.
 *
 * @return Retorna 0 indicando preco invalido.
 */

int cadastrarProdutoPrecoVazio(float preco) {
    if (preco == 0) {
        return 0; // invÃ¡lido
    }
    return 1; // vÃ¡lido
}

//Caso 2 - JoaoGuilherme//
/**
 * @brief Verifica se o produto pode ser cadastrado com um valor negativo.
 *
 * Esta funcao simula o preenchimento incorreto do campo
 * preco com um valor menor que zero.
 *
 * @param preco Preco informado pelo usuario.
 *
 * @return Retorna 0 indicando preco invalido.
 */
int cadastrarProdutoPrecoNegativo(float preco) {
    if (preco < 0) {
        return 0; // invÃ¡lido
    }
    return 1; // vÃ¡lido
}

//Caso 3- JoaoGuilherme//
/**
 * @brief Verifica se o codigo do produto foi informado.
 *
 * Esta funcao simula o preenchimento incorreto do campo
 * codigo com valor vazio (igual a 0).
 *
 * @param codigo Codigo informado pelo usuario.
 *
 * @return Retorna 0 indicando codigo invalido.
 */
int cadastrarProdutoCodigoVazio(int codigo)
{
    if (codigo == 0) {
        return 0; // invÃ¡lido
    }
    return 1; // vÃ¡lido
}
//Caso 1 - Igor Ramos//

/**
 * @brief Verifica se a validade do produto foi informada.
 *
 * Esta funcao simula o preenchimento incorreto do campo
 * validade com valor vazio.
 *
 * @param validade Data de validade informada pelo usuario.
 *
 * @return Retorna 0 indicando validade invalida.
 */
int cadastrarProdutoValidadeVazia(int validade)
{
    if (validade == 0) {
        return 0; // inválida
    }
    return 1; // válida
}
//Caso 2 - Igor Ramos//

/**
 * @brief Verifica se a quantidade em estoque foi informada.
 *
 * Esta funcao simula o preenchimento incorreto do campo
 * estoque com valor vazio (igual a 0).
 *
 * @param estoque Quantidade em estoque informada pelo usuario.
 *
 * @return Retorna 0 indicando estoque invalido.
 */
 
 // Caso 3 - Igor Ramos//

/**
 * @brief Verifica se a quantidade em estoque é negativa.
 *
 * Esta funcao simula o preenchimento incorreto do campo
 * estoque com um valor menor que zero.
 *
 * @param estoque Quantidade em estoque informada pelo usuario.
 *
 * @return Retorna 0 indicando estoque invalido.
 */
int cadastrarProdutoQuantidadeInvalida(int quantidade)
{
        return 0; // inválido
}


int cadastrarProdutoQuantidadeVazio(int quantidade)
{
    if (quantidade == 0) {
        return 0; // inválido
    }
    return 1; // válido
}

