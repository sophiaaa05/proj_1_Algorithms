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
#include <numeric>

using namespace std;

int max(int a, int b){
    return (a > b)? a:b;
}

int valor_max(int **marmore, int x, int y){
    for( int linha = 1; linha <= x ; linha ++){
        for( int coluna = 1; coluna <= y ; coluna ++){
            for(int k = 1; k <= coluna; k++){
               marmore[linha][coluna] = max(marmore[linha][coluna], marmore[linha-k][coluna] + marmore[k][coluna]);
            }
            for(int k = 1; k <= linha; k++){
               marmore[linha][coluna] = max(marmore[linha][coluna], marmore[linha][coluna-k] + marmore[linha][k]);
            }
        }
    }
    return marmore[x][y];
}

int main(){

    int x , y, n_pecas, linha, col, preco = 0;

    scanf("%d %d", &x, &y );
    scanf("%d", &n_pecas);
    int **marmore = new int *[x + 1];
    for(int i = 0; i < y + 1 ; i++){
        marmore[i] = new int [y + 1];
    }
    
    for(int i = 0; i < n_pecas; i++){
        scanf("%d %d %d", &linha, &col, &preco);
        if( linha < x && col < y){
            marmore[linha][col] = preco;
            marmore[col][linha] = preco;
        }
    }

    printf("%d\n", valor_max(marmore, x, y));
    return 0;
}