#include <stdlib.h>
#include "student.h"
#include <string.h>
#define MAX 1000

void feature1(FILE *fin, FILE *fout);
void feature2(FILE *fin, FILE *fout);
void feature3(FILE *fin, FILE *fout);


void feature6(FILE *fin, struct Obj_t *pobj);
void feature7(FILE *fout, struct Obj_t *pobj);

void feature1(FILE *fin, FILE *fout){
    char buffer[MAX];
    char *status = NULL;

    status = fgets(buffer, MAX, fin); 
    if (status!=NULL)
    {
        strtok(buffer, "\n");
        printf("La Primera línea fin es: '%s'\n", buffer);
        fputs(buffer,fout);
    }else{
        printf("Error en la linea del Archivo");
    }
}

void feature2(FILE *fin, FILE *fout){
    char buffer[MAX];
    char *status = NULL;
    status = fgets(buffer, MAX, fin);
    if (status!= NULL)
    {
        strtok(buffer, "\n");
	    printf("Frase archivo fin: %s\n", buffer);
	    int leng = strlen(buffer);
        for (int i = 0; i < leng/2; i++)
        {      
            char tmp = buffer[i];
            buffer[i] = buffer[leng - i - 1];
            buffer[leng - i - 1] = tmp;
        }
	    printf("Frase Invertida: %s\n", buffer);
        fputs("\n",fout);
        fputs(buffer,fout);
    }else{
        printf("Error en la linea del Archivo");
    }
}

void feature3(FILE *fin, FILE *fout){
    char *nums = 0;
    int totalSum = 0;
    fscanf(fin, "%m[^\n]",&nums);
    strtok(nums, "\n");
    printf("Valores de Arreglo %s\n", nums);
    char tmp[] = " ";
    char *token = strtok(nums, tmp);
    totalSum += atoi(token);
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, tmp);
        if (token !=NULL)
        {
            totalSum=atoi(token)+totalSum;
        }      
    }
    printf("Suma Vector: %d\n", totalSum);
    fputs("\n",fout);
    fprintf(fout,"%d\n",totalSum);
    // ------------ 
    char thrash[MAX];
    fgets(thrash, MAX, fin);
    strtok(thrash, "\n");
    // ------------
    // Esto se elimina cuando se solucionen los errores de F4-F5
    char bufferP4[MAX];
    fgets(bufferP4, MAX, fin);
    strtok(bufferP4, "\n");
	printf("Feature4: %s\n", bufferP4);
    fputs(bufferP4,fout);
    // --------------------
}

void feature6(FILE *fin, struct Obj_t *pobj){
    char buffer[MAX];
    char *status = NULL;
    status = fgets(buffer, MAX, fin);
    if (status!=NULL)
    {
        strtok(buffer, "\n");
	    printf("Nombre y Cedula: %s\n", buffer);
        char *token;
        token = strtok(buffer,",");
        char *nombre = token;
        char *token1;
        token1 = strtok(NULL,"");
        int cedula = atoi(token1);

        pobj->nombre=nombre;
        pobj->cedula=cedula;

        printf("Nombre: %s\n",pobj->nombre);
        printf("Cedula: %d\n",pobj->cedula);
    }else{
        printf("Error en la linea del archivo");
    }

}

void feature7(FILE *fout, struct Obj_t *pobj){
    fprintf(fout,"\n");
    fprintf(fout,"%d",pobj->cedula);
    fprintf(fout,",");
    fprintf(fout,"%s",pobj->nombre);
}

