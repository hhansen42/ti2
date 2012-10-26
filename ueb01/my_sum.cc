#include <iostream>
#include <fstream>

#include <dirent.h>
#include <cstdlib>      /* exit(), EXIT_FAILURE and EXIT_SUCCESS */
#include <cstdio>       /* perror() */
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>


using namespace std;
unsigned char isFile = 0x8;

long size(DIR *verz);
DIR *verzeichnis;


int main(int argc, char *argv[]){
    string name;
    cout <<"Schreibe das zu öffnende Verzeichnis:" << endl;
    getline( cin,name);
    if (name.c_str() == "") {
        exit(EXIT_FAILURE);
    }

    if ((verzeichnis=opendir(name.c_str())) == NULL){
        perror("my_sum: open failed");
        exit(EXIT_FAILURE);
    }
    cout << size(verzeichnis) << endl;

    if (closedir(verzeichnis)){	
        perror("my_sum: close failed");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}


long size(DIR *verz) {
    cout << "---------- reading dir " << verz << endl;

    struct dirent *eintrag;
    long sum=0;
    while ((eintrag=readdir(verz)) != NULL) {
        if (eintrag->d_type == isFile) {
            struct stat buf;
            if (lstat(eintrag->d_name,&buf) == 0) {
                sum +=buf.st_size;
                 }
        } else if((strcmp(eintrag->d_name,".") != 0) &&
                  (strcmp(eintrag->d_name,"..") != 0)){
            DIR *tempVerzeichnis;
            if ((tempVerzeichnis = opendir(eintrag->d_name)) == NULL){
                //case error: exit here
                cout << eintrag->d_name << endl;
                perror("my_sum: open failed");
                exit(EXIT_FAILURE);
            }

            //recursive open again
            if (chdir(eintrag->d_name) == 0) {
                sum += size(tempVerzeichnis);
                chdir("..");
            }

            if (closedir(tempVerzeichnis)){
                perror("my_sum: close failed");
                exit(EXIT_FAILURE);
            }

        }
    }
    return sum;

}
