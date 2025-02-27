#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void listFiles(const char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);
    
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *path;
    
    if (argc > 1) {
        path = argv[1];
    } else {
        path = "."; // Default to current directory
    }
    
    printf("Listing files in directory: %s\n", path);
    listFiles(path);
    
    return 0;
}

