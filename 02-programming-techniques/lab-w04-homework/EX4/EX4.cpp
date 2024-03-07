#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 6) {
        printf("Usage: MYSPLITFILE -s <source> -d <destination> -numpart <x> OR -sizepart <y>\n");
        return 1;
    }

    char* sourcePath = argv[2];
    char* destinationPath = argv[4];
    int numParts = atoi(argv[5]);

    FILE* sourceFile = fopen(sourcePath, "rb");
    if (!sourceFile) {
        printf("Error opening source file.\n");
        return 1;
    }

    fseek(sourceFile, 0, SEEK_END);
    long size = ftell(sourceFile);
    rewind(sourceFile);

    
    long partSize;
    if (strcmp(argv[3], "-numpart") == 0) {
        partSize = size / numParts;
    }
    else if (strcmp(argv[3], "-sizepart") == 0) {
        partSize = numParts;
        numParts = (size + partSize - 1) / partSize;  
    }
    else {
        printf("Invalid option.\n");
        return 1;
    }

    char* sourceFileName = strrchr(sourcePath, '/');
    if (sourceFileName == NULL) {
        sourceFileName = sourcePath;
    }
    else {
        sourceFileName++;
    }

    
    char* buffer = (char*)malloc(partSize);
    for (int i = 0; i < numParts; ++i) {
        char destFileName[strlen(destinationPath) + strlen(sourceFileName) + 10];
        sprintf(destFileName, "%s/%s.part%02d", destinationPath, sourceFileName, i + 1);
        FILE* destFile = fopen(destFileName, "wb");
        if (!destFile) {
            printf("Error creating destination file.\n");
            return 1;
        }
        size_t bytesRead = fread(buffer, 1, partSize, sourceFile);
        fwrite(buffer, 1, bytesRead, destFile);
        fclose(destFile);
    }

    free(buffer);
    fclose(sourceFile);

    printf("Split successful!\n");

    return 0;
}
