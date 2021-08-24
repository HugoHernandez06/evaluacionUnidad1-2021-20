#include <stdlib.h>
#include "student.h"
#define MAX 1000

void feature1(FILE *fin, FILE *fout){
    char buffer[MAX];         
    fgets(buffer, MAX, fin); 
    strtok(buffer, "\n");
    printf("La Primera línea fin es: '%s'\n", buffer);
    fputs(buffer,fout);
}
