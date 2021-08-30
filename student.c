#include <stdlib.h>
#include "student.h"
#include <string.h>
#include <stdint.h> 
#define MAX 1000

void feature1(FILE *fin, FILE *fout);
void feature2(FILE *fin, FILE *fout);
void feature3(FILE *fin, FILE *fout);
void feature6(FILE *fin, struct Obj_t *pobj);
void feature7(FILE *fout, struct Obj_t *pobj);
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length);
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length);


char *create_array(int);
int *create_arrayInt(int size);
void destroy_arrays(char *);
void destroy_arraysInt(int *this);

void feature1(FILE *fin, FILE *fout){
    char buffer[MAX];
    char *status = NULL;

    status = fgets(buffer, MAX, fin); 
    if (status!=NULL)
    {
        strtok(buffer, "\n");
        //printf("La Primera línea fin es: '%s'\n", buffer);
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
	    //printf("Frase archivo fin: %s\n", buffer);
	    int leng = strlen(buffer);
        for (int i = 0; i < leng/2; i++)
        {      
            char tmp = buffer[i];
            buffer[i] = buffer[leng - i - 1];
            buffer[leng - i - 1] = tmp;
        }
	    //printf("Frase Invertida: %s\n", buffer);
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
    //printf("Suma Vector: %d\n", totalSum);
    fputs("\n",fout);
    fprintf(fout,"%d\n",totalSum);
    // ------------ 
    char thrash[MAX];
    fgets(thrash, MAX, fin);
    strtok(thrash, "\n");
    // Esto se elimina cuando se solucionen los errores de F4-F5
    char bufferP4[MAX];
    fgets(bufferP4, MAX, fin);
    strtok(bufferP4, "\n");
	//printf("Feature4: %s\n", bufferP4);
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

        //printf("Nombre: %s\n",pobj->nombre);
        //printf("Cedula: %d\n",pobj->cedula);
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

void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){
    char buffer[MAX];
    char *status = NULL;
    int c=0;
    status = fgets(buffer, MAX, fin);
    if (status!=NULL)
    {
        for (int i = 0; i < MAX; i++)
        {
            buffer[i]-=48;
            if (buffer[i] > 0 && buffer[i]<10)
            {
                c = buffer[i];
            }
        }
        *length = c;
        char *token;
        struct _courseInfo_t arrayObj[c];
        struct _courseInfo_t Obj;
        arrayObj[0] = Obj;
        for (int i = 0; i < c; i++)
        {
            char user[MAX];
            printf("ingresa el curso %d: curso,créditos,nota\n",i+1);
            scanf("%s", user);
            char *token_cs = strtok(user,",");
            strcpy(Obj.name,token_cs);
            char *token_crds = strtok(NULL,",");
            Obj.credits = atoi(token_crds);
            char *token_grd = strtok(NULL,",");
            Obj.grade = atof(token_grd);
            arrayObj[i] = Obj;
        }
        *pobj = arrayObj;
        //printf("Primer Registro de struct: %s, %d, %f\n",arrayObj[0].name,arrayObj[0].credits,arrayObj[0].grade);

    }else{
        printf("Error en la linea del archivo");
    }
}

void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){
    float ponderado = 0;
    int total_crds = 0;
    for(int i=0;i<length;i++){
        float nota = pobj[i].grade;
        int creditos = pobj[i].credits;
        ponderado = ponderado + (nota*creditos);
        total_crds = total_crds + creditos;
    }
    float prom = ponderado/total_crds;
    char user[MAX];  
    printf("deseas almacenar la información (s) o (n):\n");
    scanf("%s", user);
    if(user[0] == 115 || user[0] == 83){
        for(uint8_t i=0;i<length;i++){
            fprintf(fout, "\n");
            fprintf(fout, "%s",pobj[i].name);
            fprintf(fout, ", ");
            fprintf(fout, "%d",pobj[i].credits);
            fprintf(fout, ", ");
            fprintf(fout, "%f",pobj[i].grade);
        }
        fprintf(fout,"\n");
        fprintf(fout,"promedio ponderado: %f", prom);
    }
    else{
        fprintf(fout,"\n");
        fprintf(fout,"%f",prom);
    }
}
// Correcion Problemas Segmentation con uso de memoria dinamica
char *create_array(int size){
    return (char*)malloc(sizeof(int)*size);
}

int *create_arrayInt(int size){
    return (int*)malloc(sizeof(int)*size);
}
// Feature 10 --- Limpiar ---
void destroy_arrays(char *this){
    free(this);
}

void destroy_arraysInt(int *this){
    free(this);
}
