#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 5) {
        printf("Usage: MYMERGEFILE -s <source> -d <destination>\n");
        return 1;
    }

    char* sourcePath = argv[2];
    char* destinationPath = argv[4];

    
    char* sourceFileName = strrchr(sourcePath, '/');
    if (sourceFileName == NULL) {
        sourceFileName = sourcePath;
    } else {
        sourceFileName++;
    }

    
    char* dot = strrchr(sourceFileName, '.');
    *dot = '\0';

    
    char destFileName[strlen(destinationPath) + strlen(sourceFileName) + 10];
    sprintf(destFileName, "%s/%s", destinationPath, sourceFileName);
    FILE* destFile = fopen(destFileName, "wb");
    if(!destFile) {
        printf("Error creating destination file.\n");
        return 1;
    }

    
    int partNum = 1;
    while (1) {
        char partFileName[strlen(sourcePath) + 10];
        sprintf(partFileName, "%s.part%02d", sourcePath, partNum);
        FILE* partFile = fopen(partFileName, "rb");
        if (!partFile) {
            break;
        }
        char ch;
        while ((ch = fgetc(partFile)) != EOF) {
            fputc(ch, destFile);
        }
        fclose(partFile);
        partNum++;
    }

    fclose(destFile);

    printf("Merge successful!\n");

    return 0;
}

