#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

int max(int a, int b){
    return (a > b)? a:b;
}

vector<vector<int>> grafo;
// vector<int> d, low, final;
// vector<bool> visitada;
// int tempo = 0;
stack<int> pilha;

int dfs_recursiva(int v)
{

    if (grafo[v].size() == 0)
    {
        return 0;
    }

    int max = 0;

    for (size_t i = 0; i < grafo[v-1].size() ; i++)
    {
        int comparator = dfs_recursiva(grafo[v][i]);

        if (max < comparator)
        {
            max = comparator;
        }
    }
    return max + 1;
}

// int dfs_iterativa(int v)
// {
//     if (grafo[v].empty())
//     {
//         return 0;
//     }

//     int max_path = 0;

//     return max_path + 1;
// }


void tarjan_recursivo(){
    
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

    // for (int i = 1; i <= n_pessoas; i++)
    // {
    //     printf("%d : ", i);
    //     for (int j = 0; j < grafo[i].size(); j++)
    //     {

    //         printf("%d ", grafo[i][j]);
    //     }
    //     printf("\n");
    // }
    int max_num = 0;
    for (int i = 1; i <= n_pessoas; i++)
    {
        max_num = max(max_num, dfs_recursiva(i));
        
    }

    printf("%d\n", max_num);

    return 0;
}