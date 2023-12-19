// #include <stdio.h>
// #include <vector>
// #include <iostream>
// #include <stack>
// #include <numeric>

// using namespace std;

// vector<vector<int>> grafo;

// int dfs_recursiva(int v)
// {

//     if (grafo[v].size() == 0)
//     {
//         return 0;
//     }

//     int max = 0;

//     for (int i = 0; i < grafo[v].size(); i++)

//     {
//         int comparator = dfs_recursiva(grafo[v][i]);

//         if (max < comparator)
//         {
//             max = comparator;
//         }
//     }

//     return max + 1;
// }

// stack<int> pilha;

// vector<bool> visitada;

// int dfs_iterativa(int v)
// {

//     if (grafo[v].size() == 0)
//     {
//         return 0;
//     }
//     int max = 0;

//     for (int i = 0; i < grafo[v].size(); i++)
//     {
//         pilha.push(v);
//     }

//     return max + 1;
// }

// void tarjan_recursico(){

// }

// int main()
// {
//     int n_pessoas, m_relacoes = 0;
//     int a, b = 0;

//     scanf("%d %d", &n_pessoas, &m_relacoes);

//     grafo.resize(n_pessoas + 1);

//     for (int i = 0; i < m_relacoes; i++)
//     {
//         scanf("%d %d", &a, &b);
//         grafo[a].push_back(b);
//     }

//     for (int i = 1; i <= n_pessoas; i++)
//     {
//         printf("%d : ", i);
//         for (int j = 0; j < grafo[i].size(); j++)
//         {

//             printf("%d ", grafo[i][j]);
//         }
//         printf("\n");
//     }

//     for (int i = 1; i <= n_pessoas; i++)
//     {
//         int resultado = dfs_recursiva(i);
//         printf("meu i : %d meu resultado: %d\n", i, resultado);
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

// void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& finished) {
//     visited[node] = true;
//     for (int neighbor : graph[node]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, graph, visited, finished);
//         }
//     }
//     finished.push(node);
// }

// void fillOrder(int node, vector<vector<int>>& transposeGraph, vector<bool>& visited, stack<int>& finished) {
//     visited[node] = true;
//     for (int neighbor : transposeGraph[node]) {
//         if (!visited[neighbor]) {
//             fillOrder(neighbor, transposeGraph, visited, finished);
//         }
//     }
//     finished.push(node);
// }

// int maxInfectionSpread(int n, vector<vector<int>>& graph, vector<vector<int>>& transposeGraph) {
//     vector<bool> visited(n + 1, false);
//     stack<int> finished;

//     for (int i = 1; i <= n; ++i) {
//         if (!visited[i]) {
//             dfs(i, graph, visited, finished);
//         }
//     }

//     fill(visited.begin(), visited.end(), false);
//     int maxJumps = 0;

//     while (!finished.empty()) {
//         int node = finished.top();
//         finished.pop();

//         if (!visited[node]) {
//             maxJumps++;
//             fillOrder(node, transposeGraph, visited, finished);
//         }
//     }

//     return maxJumps;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> graph(n + 1);
//     vector<vector<int>> transposeGraph(n + 1);

//     for (int i = 0; i < m; ++i) {
//         int x, y;
//         cin >> x >> y;
//         graph[x].push_back(y);
//         transposeGraph[y].push_back(x);
//     }

//     int result = maxInfectionSpread(n, graph, transposeGraph);
//     cout << result << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& finished) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, finished);
        }
    }
    finished.push(node);
}

void fillOrder(int node, vector<vector<int>>& transposeGraph, vector<bool>& visited, vector<int>& component, int componentNumber) {
    visited[node] = true;
    component[node] = componentNumber;
    for (int neighbor : transposeGraph[node]) {
        if (!visited[neighbor]) {
            fillOrder(neighbor, transposeGraph, visited, component, componentNumber);
        }
    }
}

int maxInfectionSpread(int n, vector<vector<int>>& graph, vector<vector<int>>& transposeGraph) {
    vector<bool> visited(n + 1, false);
    stack<int> finished;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, finished);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<int> component(n + 1, -1);
    int componentNumber = 0;

    while (!finished.empty()) {
        int node = finished.top();
        finished.pop();

        if (!visited[node]) {
            componentNumber++;
            fillOrder(node, transposeGraph, visited, component, componentNumber);
        }
    }

    vector<int> componentCount(componentNumber + 1, 0);

    for (int i = 1; i <= n; ++i) {
        componentCount[component[i]]++;
    }

    int maxJumps = *max_element(componentCount.begin(), componentCount.end());

    return maxJumps;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<vector<int>> transposeGraph(n + 1);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        transposeGraph[y].push_back(x);
    }

    int result = maxInfectionSpread(n, graph, transposeGraph);
    cout << result << endl;

    return 0;
}

// void dfs_tarjan_recursivo(int v)
// {
//     d[v] = i;
//     low[v] = d[v];
//     i += 1;
//     visitada[v] = true;
//     pilha.push(v);
//     for (int u = 0; u < vizinhos[v]; u++)
//     {
//         if (visitada[u] == false)
//         {
//             dfs_tarjan_recursivo(u);
//             low[v] = min(low[v], low[u]);
//         }
//         else if (processado[u] == false)
//         {
//             low[v] = min(low[v], d[u]);
//         }
//     }
//     processado[v] = true;
//     if (low[v] = d[v]){
//         scc.clear();
//         scc_vertex = pilha.top();
//         pilha.pop();
//         while(scc_vertex != v){
//             scc.push_back(scc_vertex);
//             scc_vertex = pilha.top();
//             pilha.pop();
//         }
//         scc.push_back(scc_vertex);
//         //
//     }
// }

// void tarjan_recursico(){
//     for(int v = 0; v < grafo.size(); v++ ){
//         if(visitada[v] == false){
//             dfs_tarjan_recursivo(v);
//         }
//     }
// }



    // for (int i = 1; i <= n_pessoas; i++)
    // {
    //     printf("%d : ", i);
    //     for (int j = 0; j < grafo[i].size(); j++)
    //     {

    //         printf("%d ", grafo[i][j]);
    //     }
    //     printf("\n");
    // }
