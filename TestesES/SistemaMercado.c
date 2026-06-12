/*
====================================================
ARQUIVO: SistemaMercado.c
====================================================

Este arquivo contem as funcoes do sistema de estoque
do supermercado.

Sua responsabilidade e implementar as regras de negocio,
como:

- cadastrar produtos;
- remover produtos;
- atualizar estoque;
- buscar produtos;
- consultar informacoes.

As funcoes deste arquivo serao utilizadas e validadas
pelos testes unitarios presentes no arquivo
teste_SistemaMercado.c.

Durante a fase de testes, algumas funcoes podem ser
implementadas como stubs (simulacoes), retornando
valores pre-definidos para permitir a execucao dos
testes sem a necessidade de desenvolver o sistema
completo.

====================================================
*/

/**
* @brief Sistema para Mercado
*
* @details Este arquivo contem funcoes basicas para realizar teste de cadastro e verificacao.
* @author Felipe
* @date 2026
* @version 1.6.1
*/

#include <stdio.h>
#include <string.h>

/*Caso de teste 1 - Henrique*/


/**
 * @brief Verifica se um produto esta vencido.
 *
 * Esta funcao simula a validacao de um produto vencido
 * retornando o codigo correspondente ao status de vencimento.
 *
 * @return int Retorna 1 indicando produto vencido.
 */

int produtoVencido(int diasParaVencer)
{
	if(diasParaVencer <=0){
		return 1;
	}   
}

/*Caso de teste 2 - Henrique*/
/**
 * @brief Verifica se um produto esta proximo do vencimento.
 *
 * Esta funcao simula a situacao em que um produto esta
 * proximo da data de vencimento e deve ser monitorado.
 *
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
 * @return int Retorna 2 indicando produto dentro da validade.
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
 * Esta funcao simula o cadastro de um produto.
 *
 * @param nome Nome do produto.
 * @param quantidade Quantidade do produto.
 *
 * @return int Retorna 0 indicando produto cadastrado com sucesso.
 */
int cadastrarProduto(char nome[], int quantidade, char setor[], float preco, int cod_pdt)
{
    return 0;
}

/*Caso 2 - Felipe*/
/**
 * @brief Verifica se um produto esta sendo cadastrado incorretamente.
 *
 * Esta funcao simula o cadastro de um produto.
 *
 * @param nome Nome do produto.
 *
 * @return int Retorna 0 indicando nome invalido.
 */
int cadastrarProdutoSemNome(char nome[])
{
    if(nome[0] == '\0')
    {
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
        return 0;
    }

    return 1;
}


/*Caso 1 - Henry*/
/**
 * @brief Verifica se o codigo do produto e composto apenas de numeros.
 *
 * Esta funcao simula o preenchimento do campo
 * "codigo do produto" com caracteres invalidos.
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
int cadastrarProdutoSemSetor(char setor[])
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
