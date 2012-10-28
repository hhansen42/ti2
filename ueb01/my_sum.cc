#include <iostream>
#include <fstream>

#include <dirent.h>
#include <cstdlib>      /* exit(), EXIT_FAILURE and EXIT_SUCCESS */
#include <cstdio>       /* perror() */
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>


using namespace std;
unsigned char isFile = 0x8;

long size(string directory);
DIR *verzeichnis;


int main(int argc, char *argv[]){
    string name;
    cout <<"Schreibe das zu öffnende Verzeichnis:" << endl;
    getline( cin,name);
    //check for empty input
    if (name.c_str() == "") {
        exit(EXIT_FAILURE);
    }

    cout << size(name.c_str()) << endl;

    exit(EXIT_SUCCESS);
}

//returns summed up size und directory-listing for given directory
long size(string directory) {
    cout << "\n------------- reading dir " << directory << endl;

    struct dirent *eintrag;
    long sum=0;
    DIR *tempVerzeichnis;
    if ((tempVerzeichnis = opendir(directory.c_str())) == NULL){
                    //case error: exit here
                    cout << directory << endl;
                    perror("my_sum: opening subdirectory failed");
                    exit(EXIT_FAILURE);
                }
    //iterating over the DIR entries:
    while ((eintrag=readdir(tempVerzeichnis)) != NULL) {
        struct stat buf;
        if (lstat(eintrag->d_name,&buf) == -1)
        	{
        	cout << "error for " << eintrag->d_name << endl;
        	continue;   //getting the stats
        	}
        if((S_ISDIR(buf.st_mode)) &&
        		(strcmp(eintrag->d_name,".") != 0) &&	//do not include the  current dir
        		(strcmp(eintrag->d_name,"..") != 0)){	// and higher dir
			stringstream fullPath;
			fullPath << directory << "/" << eintrag->d_name;
			sum += size(fullPath.str());

		}else if (!S_ISDIR(buf.st_mode)) {		//check for regular file
			cout << "found reg file" << endl;
		//adding up the size
		sum +=buf.st_size;
        }

    }

    if (closedir(tempVerzeichnis)){
                           perror("my_sum: closing subdirectory failed");
                           exit(EXIT_FAILURE);
                       }
    return sum;

}
