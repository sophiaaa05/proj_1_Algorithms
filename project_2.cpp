#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

vector<vector<int>> grafo, transposto;
//vector<int> d, low, final, vizinhos, scc;
//int scc_vertex = 0;
vector<bool> visitada;//, processado;
//int i = 0;
//stack<int> pilha;

int dfs_recursiva(int v)
{

    if (grafo[v].size() == 0)
    {
        return 0;
    }

    int max = 0;

    for (size_t i = 0; i < grafo[v - 1].size(); i++)
    {
        int comparator = dfs_recursiva(grafo[v][i]);

        if (max < comparator)
        {
            max = comparator;
        }
    }
    return max + 1;
}

// int dfs_2(int v){
//     visitada[v] = true;
//     for (int vizinho : grafo[v]) {
//         if (!visitada[vizinho]) {
//             dfs_2(vizinho);
//         }
//     }
//     pilha.push(v);
// }


int main()
{
    int n_pessoas, m_relacoes = 0;
    int a, b = 0;

    scanf("%d %d", &n_pessoas, &m_relacoes);

    grafo.resize(n_pessoas + 1);
    transposto.resize(n_pessoas +1 );

    for (int i = 0; i < m_relacoes; i++)
    {
        scanf("%d %d", &a, &b);
        grafo[a].push_back(b);
        transposto[b].push_back(a);
    }

    int max_num = 0;
    for (int i = 1; i <= n_pessoas; i++)
    {
        max_num = max(max_num, dfs_recursiva(i));
    }

    printf("%d\n", max_num);

    return 0;
}