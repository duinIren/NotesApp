#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <math.h>
#include "functii.h"

void showNotes(void){
    DIR *currentDir;
    struct dirent *dp;

    if((currentDir = opendir("notes"))==NULL){
        perror("Cannot open notes");
        exit(1);
    }
    while((dp =readdir(currentDir))!=NULL){
        size_t len = strlen(dp->d_name);
        if(len > 4 && strcmp(dp->d_name + len -4 ,".txt")==0){
            printf("%s\n",dp->d_name);
        }
    }
    closedir(currentDir);
}

void createNote(char *name ){
    char filename[104];
    snprintf(filename,sizeof(filename),"notes/%s.txt",name);
    FILE *fptr;
    fptr = fopen(filename, "a");
    printf("File %s created or opened for appending.\n", filename);
    if(fptr == NULL){
        fptr = fopen(filename, "w+");
        if(fptr = NULL){
            printf("Eroare fisier \n");
            return;
        }
    }
    fclose(fptr);
}

void read_write(char *name){
    int read;
    char filename[104];
    char buffer[256];
    snprintf(filename,sizeof(filename),"%s.txt",name);
    FILE *fptr;
    fptr = fopen(filename, "r+");
    while(fgets(buffer,sizeof(buffer), fptr)){
        printf("%s", buffer);
    }
    fseek(fptr,0,SEEK_END);
    while(read){
        int alegere;
        fgets(buffer,sizeof(buffer), stdin);
        fprintf(fptr,"%s \n",buffer);
        printf("Doresti sa continui?Apasa ` \n");
        if(scanf("%c",&alegere)=='`'){
            break;
        }
        
    }
   

    fprintf(fptr,"%s \n",buffer);
    fclose(fptr);
    printf("Notita adaugata \n");
}