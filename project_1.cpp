// cortar na horizontal ou vertical
// sai da linha se já tiver as dimensoes dadas pelo cliente ou se já não for possível ser uma peça



// OBJETIVO - calcula o valor máximo de peças que pode ser obtido a cortar o mármore consoante as dimensões dadas
// recebe X*Y
// lista com n tipo de pecas (todos com dimensoes diferentes)
// cada peca tem dimensoes a*b e um preço p

#include <stdio.h>

int main(){
    int x , y, n_lines, line, column, price = 0;
    scanf("%d %d", &x, &y );
    scanf("%d", &n_lines);
    for(int i =0; i < n_lines; i++){
        scanf("%d%d%d", &line, &column, price);
    }
    
}