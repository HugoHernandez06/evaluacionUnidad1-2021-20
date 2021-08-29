#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]){
    int length = 0;
    int *parr = NULL;
    char *op = NULL;
    struct Obj_t pobj;

    if(argc !=3){
        printf("Numero incorrecto de archivos\n");
    }

    FILE *fin = fopen(argv[1],"r+");
    if(fin == NULL){
        perror("Error al abrir archivo de entrada: \n");
        return (EXIT_FAILURE);
    }

    FILE *fout = fopen(argv[2],"w+");
    if(fout == NULL){
        perror("Error al abrir archivo de salida: \n");
        return (EXIT_FAILURE);
    }
    
    feature1(fin,fout);
    feature2(fin,fout);
    feature3(fin,fout);


    feature6(fin, &pobj);

    fclose(fin);
    fflush(fout);
    fclose(fout);
    return EXIT_SUCCESS;
}
