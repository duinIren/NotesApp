#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <math.h>

int main(){
    DIR *dir;
    struct dirent *dp;

     if ((dir = opendir (".")) == NULL) {
        perror ("Cannot open .");
        exit (1);
    }


    while ((dp = readdir (dir)) != NULL) {
        printf("%s\n", dp->d_name);
    }
    closedir(dir);

    return 0;

}