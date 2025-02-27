#include <stdio.h>
#include <stdlib.h>

void createFile();
void writeFile();
void readFile();
void appendFile();

int main() {
    int choice;
    while (1) {
        printf("\nFile Management System\n");
        printf("1. Create and write to a file\n");
        printf("2. Read from a file\n");
        printf("3. Append to a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                writeFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendFile();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void writeFile() {
    FILE *file;
    char filename[100], content[1000];
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    getchar(); // Consume newline character
    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Enter content to write: ");
    fgets(content, sizeof(content), stdin);
    fprintf(file, "%s", content);
    fclose(file);
    printf("File written successfully!\n");
}

void readFile() {
    FILE *file;
    char filename[100], ch;
    
    printf("Enter the filename to read: ");
    scanf("%s", filename);
    getchar();
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("File content:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void appendFile() {
    FILE *file;
    char filename[100], content[1000];
    
    printf("Enter the filename to append: ");
    scanf("%s", filename);
    getchar();
    
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Enter content to append: ");
    fgets(content, sizeof(content), stdin);
    fprintf(file, "%s", content);
    fclose(file);
    printf("Content appended successfully!\n");
}

