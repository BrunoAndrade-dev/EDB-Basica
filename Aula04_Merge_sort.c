#include <stdio.h>

void merge (int*v , int inicio ,int middle ,  int fim ){
    int com1 , com2, tam;
    int *Aaux ;
    com1 = inicio ;
    com2 = middle +1 ;
    tam = fim - inicio +1 ;
    Aaux = (int*)malloc(tam*sizeof(int)) ;

    int k = 0 ;
    while (com1 <= middle && com2 <= fim){
        if (v[com1] <= v[com2]){
            Aaux[k]= v[com1] ;
            com1 ++ ;
        }else {
            Aaux[k] = v[com2] ;
            com2++ ;
        }
    }
    while (com1 <= meio) {
        Aaux[k] = v[com1] ;
        k++ ;
        com1++ ;
    }
    while (com2<=fim) {
        Aaux[k] = v[com2] ;
        k++;
        com2++ ;

    }
    for (k=inicio ; k<=fim ; k++){
        v[k] = Aaux[k - inicio] ;
    }


void merge_sort (int *v , int left , int right){
    if (left<right ){
        int middle = (left+rigth)/2;
        merge_sort(v, left ,middle) ;
        merge_sort(v, middle+1 , right);
        merge(v , middle , right) ;
    }
}
