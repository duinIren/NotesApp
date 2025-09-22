#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <math.h>
#include "functii.h"

int main(){

    char nume[100];
    int alegere;

    

    printf(" \t \t  \t \t \t  Bun venit la progamul meu de notite foarte basic \n");
    printf("\t \t  \t \t \t Deocamdata include doar crearea de fisiere si adaugarea de notite la finalul fisierului \n");//In viitor doresc sa implementez un text editor custom
    printf("\t \t  \t \t \t Alegeti 1. Creare notita 2. Citire si editare notita existenta 3.Iesire \n");
    
    while(1){
        showNotes();
        if(scanf("%d",&alegere)!=1){
            printf("Alegere invalida");
            return 1;
        }
        getchar();
        switch(alegere){
            case 1:
                char buffer1[100];
                printf("Introdu numele notitei \n");
                fgets(buffer1, sizeof(buffer1),stdin);
                buffer1[strcspn(buffer1, "\n")] = 0;
                createNote(buffer1);
                break;
            case 2: 
                char buffer2[100];
                printf("Introdu numele notitei \n");
                fgets(buffer2, sizeof(buffer2),stdin);
                buffer2[strcspn(buffer2, "\n")] = 0;
                read_write(buffer2);
                break;
            case 3:
                return 0;
                break;
        }
    }
    
    
    return 0;

}