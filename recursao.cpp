#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

vector<vector<int>> grafo;

int dfs_recursiva(int v)
{

    if (grafo[v].size() == 0)
    {
        return 0;
    }

    int max = 0;

    for (int i = 0; i < grafo[v].size(); i++)

    {
        int comparator = dfs_recursiva(grafo[v][i]);

        if (max < comparator)
        {
            max = comparator;
        }
    }

    return max + 1;
}

stack<int> pilha;

vector<bool> visitada;

int dfs_iterativa(int v)
{

    if (grafo[v].size() == 0)
    {
        return 0;
    }
    int max = 0;

    for (int i = 0; i < grafo[v].size(); i++)
    {
        pilha.push(v);
    }

    return max + 1;
}

void tarjan_recursico(){

}

int main()
{
    int n_pessoas, m_relacoes = 0;
    int a, b = 0;

    scanf("%d %d", &n_pessoas, &m_relacoes);

    grafo.resize(n_pessoas + 1);

    for (int i = 0; i < m_relacoes; i++)
    {
        scanf("%d %d", &a, &b);
        grafo[a].push_back(b);
    }

    for (int i = 1; i <= n_pessoas; i++)
    {
        printf("%d : ", i);
        for (int j = 0; j < grafo[i].size(); j++)
        {

            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i <= n_pessoas; i++)
    {
        int resultado = dfs_recursiva(i);
        printf("meu i : %d meu resultado: %d\n", i, resultado);
    }

    return 0;
}