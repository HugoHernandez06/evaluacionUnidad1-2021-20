#include <stdlib.h>
#include "student.h"
#include <string.h>
#define MAX 1000

void feature1(FILE *fin, FILE *fout);
void feature2(FILE *fin, FILE *fout);
void feature3(FILE *fin, FILE *fout);
void feature4(FILE *fin, int **parr, int *length, char **op);

void feature6(FILE *fin, struct Obj_t *pobj);
void feature7(FILE *fout, struct Obj_t *pobj);

char *create_array(int);
void destroy_arrays(char *);

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

void feature4(FILE *fin, int **parr, int *length, char **op){
    int data = MAX;
    int count = 0;
    int i=0;
    char *buffer = create_array(data);
    while ((data = fgetc(fin))!= EOF)
    {
        if (data==10)
        {
            count++;
        }
        if (count >=1)
        {
            break;
        }
        buffer[i] = data;
        i++;
    }
    int size_op = MAX;
    char *opp = create_array(size_op);
    for (int j = 0; j < size_op; j++)
    {
        opp[j] = 0;
    }
    char aux;
    int k = 0;
    for (int j = 0; j > 0; j--) // USAR TABLA ASCII para ver los rangos de letras 
    {
        if (buffer[j] == 32) // 
        {
            break;
        }
        if (buffer[j]>31 && buffer[j]< 255 && buffer[j]!= 127)
        {
            aux = buffer[j];
            opp[k] = aux;
            buffer[j] = 0;
            k++;
        } 
    }
    
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

// Correcion Problemas Segmentation con uso de memoria dinamica
char *create_array(int s){
    return (char*)malloc(sizeof(int)*s);
}

// Feature 10 --- Limpiar ---
void destroy_arrays(char *this){
    free(this);
}