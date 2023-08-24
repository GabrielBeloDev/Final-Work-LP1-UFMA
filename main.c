#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// PARA ESSE TRABALHO USAMOS O CONCEITO DE PROGRAMAÇÃO DINÂMICA, DIVIDINDO O PROBLEMA EM PROBLEMA MENORES,
// O QUE TAMBÉM É CHAMADO DE DIVISÃO E CONQUISTA. PARA ESSE TRABALHO TAMBÉM USAMOS CONTEÚDOS APRENDIDOS DURANTE
// A DISCIPLINA, COMO STRUCTS, ALOCAÇÃO DINÂMICA DE MEMÓRIA, PONTEIROS E ARQUIVOS.

// CRIAÇÃO DE ESTRUTURA STRUCT PARA ARMAZENAR VALOR E PESO DO ITEM
struct item
{
    int valor;
    int peso;
};

int max(int a, int b);
void problemaMochila(int maxCap, int *pesos, int *valores, int n);

int main()
{
    int numero_itens = 0;
    int maxCap;
    // CRIAÇÃO DE VETOR STRUCT E ALOCAÇÃO DE MEMÓRIA PARA O MESMO, QUE INICIA COM 0, JÁ QUE NÃO TEMOS
    //  O NÚMERO DE ITENS ATÉ O MOMENTO
    struct item *itens = malloc(numero_itens * sizeof(struct item));
    if (itens == NULL)
    {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    FILE *arquivo;
    int num1, num2;
    // AQUI ABRIMOS O ARQUIVO NO MODO LEITURA PARA EXTRAÇÃO DE DADOS QUE SERVIRÃO
    // PARA PREENCHIMENTO DOS VETORES DE ITENS COM PESOS E VALORES, ALÉM DA CAPACIDADE MÁXIMA
    // DA MOCHILA E O NÚMERO DE ITENS
    arquivo = fopen("arquivo_entrada.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // BOTAMOS UM CONTADOR NA LEITURA DO ARQUIVO, PARA QUE A PRIMEIRA LINHA SEJA LIDA DIFERENTE
    // DAS DEMAIS, JÁ QUE É NELA QUE CONTÉM O NÚMERO DE ITENS E A CAPACIDADE MÁXIMA DA MOCHILA
    int cont = 0;
    while (fscanf(arquivo, "%d %d", &num1, &num2) == 2)
    {

        if (cont == 0)
        {
            numero_itens = num1;
            maxCap = num2;
            itens = realloc(itens, numero_itens * sizeof(struct item));
        }
        else
        {
            itens[cont - 1].valor = num1;
            itens[cont - 1].peso = num2;
        }

        cont++;
    }

    // DEFINIMOS DOIS VETORES PARA PESOS E VALORES RESPECTIVAMENTE PARA PASSARMOS OS DADOS DO VETOR DA STRUCT
    int vetorPesos[numero_itens];
    int vetorValores[numero_itens];
    for (int j = 0; j < numero_itens; j++)
    {
        vetorPesos[j] = itens[j].peso;
        vetorValores[j] = itens[j].valor;
    }

    problemaMochila(maxCap, vetorPesos, vetorValores, numero_itens);
    fclose(arquivo);
    free(itens);
}

// ESSA FUNÇÃO SERVE PARA RETORNAR O MAIOR VALOR ENTRE DOIS INTEIROS
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void problemaMochila(int maxCap, int *pesos, int *valores, int n)
{
    int i, cap;
    int **K;
    // ALOCAÇÃO DE MEMÓRIA PARA A TABELA K COM NUMERO DE COLUNAS "n" E LINHAS "maxCap"
    K = (int **)malloc(sizeof(int *) * (n + 1));
    for (i = 0; i <= n; i++)
        K[i] = (int *)malloc(sizeof(int) * (maxCap + 1));

    // CONSTRÓI TABELA K
    for (i = 0; i <= n; i++)
    {
        for (cap = 0; cap <= maxCap; cap++)
        {

            if (i == 0 || cap == 0)
                K[i][cap] = 0;
            else if (pesos[i - 1] <= cap)
                K[i][cap] = max(valores[i - 1] + K[i - 1][cap - pesos[i - 1]], K[i - 1][cap]);
            else
                K[i][cap] = K[i - 1][cap];
        }
    }

    // DEFINIÇÃO DE VETOR QUE IRÁ CONTER OS ITENS ESCOLHIDOS PARA A SOLUÇÃO
    int solucao[n];
    i = 0;

    // AQUI EXTRAIMOS QUAIS ITENS FAZEM PARTE DA SOLUÇÃO
    for (; n > 0; n--)
    {
        if (K[n][maxCap] <= 0)
            break;
        if (K[n][maxCap] > K[n - 1][maxCap])
        {
            solucao[i] = n;
            ++i;
            maxCap = maxCap - pesos[n - 1];
        }
    }
    solucao[i] = -1;

    // AQUI SE PRINTA OS ITENS ESCOLHIDOS COM RESPECTIVOS VALORES E PESOS
    for (int j = i - 1; j >= 0; j--)
    {
        printf("Item %d - Valor: %d - Peso: %d\n", solucao[j], valores[solucao[j] - 1], pesos[solucao[j] - 1]);
    }

    // LIBERAÇÃO DE MEMÓRIA DA TABELA K
    free(K);
}
