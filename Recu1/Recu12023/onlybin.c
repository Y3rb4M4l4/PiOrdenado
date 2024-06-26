/*Dada una matriz de chars de COLS columnas -donde COLS es una constante
previamente definida-, verificar las filas que representan números binarios. En cada
celda puede haber letras, dígitos, símbolos, etc.
Escribir una función onlyBin que reciba la matriz y la cantidad de filas de la misma, y
elimine de la matriz las filas que no representen números binarios. La función debe
retornar cuántas filas quedaron en la matriz.
Ejemplo: Con COLS = 6, si los valores ASCII de la matriz son:
1 0 1 0 1 2
3 1 4 A 1 2
1 1 1 1 1 0
a B 2 x 0 1
0 1 0 1 0 1
2 1 1 1 1 0
debe quedar de la siguiente forma y retornar 2, donde lo que quede almacenado en
las últimas cuatro filas no tiene importancia.
1 1 1 1 1 0
0 1 0 1 0 1
*/
//IMPORTANTE MANEJO ASCII, NO 1 Y 0 TIPO INT

//DEVUELVE NEWFILS(CONTADOR)

#define COLS 4

int onlyBin(char m[][COLS],int FILS){
    
    int newFils=0;
    for(int i=0;i<FILS;i++){
        int isBinary=1;
        for(int j=0;j<COLS;){
            int num=m[i][j];
            if(num!='0' && num!='1'){
                isBinary=0;
            }
        }
        if(isBinary){
            if(i!=newFils){ //------------------> es crucial para asegurar que solo se copien filas cuando es necesario, 
                                                //evitando así operaciones redundantes y asegurando la eficiencia del algoritmo.
                for(int j=0;j<COLS;j++){
                    m[newFils][j]=m[i][j];
                }
            }
            newFils++;
        }
    }
    return newFils;
}







// Solución alternativa practicamente igual


#include <stdio.h>
#include <string.h>

#define COLS 6

int onlyBin(char matrix[][COLS], int rows) {
    int validRows = 0;
    
    for (int i = 0; i < rows; i++) {
        int isBinary = 1;
        
        // chqueo si la fila actual es binaria
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != '0' && matrix[i][j] != '1') {
                isBinary = 0;
                break;
            }
        }
        
        // si la fila actual es binaria,la muevo a la posicion de validRow
        if (isBinary) {
            if (i != validRows) {
                for (int j = 0; j < COLS; j++) {
                    matrix[validRows][j] = matrix[i][j];
                }
            }
            validRows++;
        }
    }
    
    return validRows;
}
