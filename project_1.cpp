// cortar na horizontal ou vertical
// sai da linha se já tiver as dimensoes dadas pelo cliente ou se já não for possível ser uma peça



// OBJETIVO - calcula o valor máximo de peças que pode ser obtido a cortar o mármore consoante as dimensões dadas
// recebe X*Y
// lista com n tipo de pecas (todos com dimensoes diferentes)
// cada peca tem dimensoes a*b e um preço p

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
const int MAX = 1024;

int max(int a, int b){
    return (a > b)? a:b;
}


struct Peca
{
    int linha, col, preco;
};



int valor_max(Peca pecas[],int n_linhas, int x, int y){
    
    int tabela[MAX][MAX] = {0};
    for(int i = 1; i <= n_linhas;i++){
        for(int j= x; j>= 0; j--){
            for(int k= y; k>=0; k--){
                if (j >= pecas[i - 1].linha && k >= pecas[i - 1].col) {
                    tabela[j][k] = max(tabela[j][k], tabela[j - pecas[i - 1].linha][k - pecas[i - 1].col] + pecas[i - 1].preco);
                }
                if (j >= pecas[i - 1].col && k >= pecas[i - 1].linha) {
                    tabela[j][k] = max(tabela[j][k], tabela[j - pecas[i - 1].col][k - pecas[i - 1].linha] + pecas[i - 1].preco);
                }
            }   
        }   
    }
    return tabela[x][y];
}

int main(){

    int x , y, n_linhas= 0;
    scanf("%d %d", &x, &y );
    scanf("%d", &n_linhas);
    Peca pecas[2* n_linhas];

    for(int i =0; i < n_linhas; i++){
        scanf("%d %d %d", &pecas[i].linha, &pecas[i].col, &pecas[i].preco);
        pecas[n_linhas + i] = {pecas[i].col, pecas[i].linha, pecas[i].preco};

    }

    printf("%d\n", valor_max(pecas,2* n_linhas, x, y));
    return 0;
}