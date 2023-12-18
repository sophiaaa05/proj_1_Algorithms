#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>
// #include <algorithm>


using namespace std;

vector<vector<int>> grafo;
vector<int> d, low;
vector<bool> visitada;
int tempo = 0;
stack<int> pilha;

void tarjan_dfs(int u){
    d[u] = low[u] = ++tempo;
    pilha.push(u);
    visitada[u] = true;

    for(int v :grafo[u]){
        
    }

}

int main(){
    int n_pessoas , m_relacoes;
    int a,b;
    
    scanf("%d %d", n_pessoas, m_relacoes);

    grafo.resize(n_pessoas);

    for (int i = 0; i <m_relacoes; i++){
        scanf("%d %d", a, b);
        grafo[a].push_back(b);
    }

}