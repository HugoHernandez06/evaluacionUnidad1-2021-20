#include <stdlib.h>
#include "student.h"
#include <string.h>
#define MAX 1000

void feature1(FILE *fin, FILE *fout){
    char buffer[MAX];         
    fgets(buffer, MAX, fin); 
    strtok(buffer, "\n");
    printf("La Primera línea fin es: '%s'\n", buffer);
    fputs(buffer,fout);
}

void feature2(FILE *fin, FILE *fout){
    char buffer[MAX];
    fgets(buffer, MAX, fin);
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
}
