#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* sourceFile, * destFile;
    char ch;

    if (argc != 5) {
        printf("Sử dụng: MYCOPYFILE -s path_of_source_file -d path_of_destination\n");
        return 1;
    }

    sourceFile = fopen(argv[2], "rb");
    if (sourceFile == NULL) {
        printf("Không thể mở tệp nguồn %s.\n", argv[2]);
        return 1;
    }


    char* destPath = argv[4];
    char* sourceFileName = strrchr(argv[2], '/');
    if (sourceFileName == NULL) {
        sourceFileName = argv[2];
    }
    else {
        sourceFileName++;
    }
    char destFileName[strlen(destPath) + strlen(sourceFileName) + 2];
    strcpy(destFileName, destPath);
    strcat(destFileName, "/");
    strcat(destFileName, sourceFileName);

    destFile = fopen(destFileName, "wb");
    if (destFile == NULL) {
        printf("Không thể mở tệp đích %s.\n", destFileName);
        return 1;
    }

    
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("Sao chép tệp thành công từ %s đến %s.\n", argv[2], destFileName);

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
