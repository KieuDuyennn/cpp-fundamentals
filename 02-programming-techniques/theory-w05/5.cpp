#include <stdio.h>
#include <stdlib.h>

void copy_file(char *source_file, char *destination_file) {
    FILE *source, *destination;
    char ch;

    source = fopen(source_file, "rb");

    if (source == NULL) {
        printf("Không the mo file nguon.\n");
        exit(EXIT_FAILURE);
    }

    destination = fopen(destination_file, "wb");

    if (destination == NULL) {
        fclose(source);
        printf("Không the mo file dich.\n");
        exit(EXIT_FAILURE);
    }

    
    while ((ch = fgetc(source)) != EOF)
        fputc(ch, destination);

    printf("Đa sao chép file thành công.\n");

 
    fclose(source);
    fclose(destination);
}

void join_files(char *file1, char *file2, char *destination) {
    FILE *source1, *source2, *dest;
    char ch;

    
    source1 = fopen(file1, "rb");
    source2 = fopen(file2, "rb");

    if (source1 == NULL || source2 == NULL) {
        printf("FAILED.\n");
        exit(EXIT_FAILURE);
    }

    dest = fopen(destination, "wb");

    if (dest == NULL) {
        fclose(source1);
        fclose(source2);
        printf("Không the mo file dich.\n");
        exit(EXIT_FAILURE);
    }

   
    while ((ch = fgetc(source1)) != EOF)
        fputc(ch, dest);

   
    while ((ch = fgetc(source2)) != EOF)
        fputc(ch, dest);

    printf(" gop file thành công.\n");

    
    fclose(source1);
    fclose(source2);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Cú pháp không dúng. Thu lai.\n");
        return 1;
    }

    if (argv[1][0] == '-') {
      
    } else if (argc == 5) {
        join_files(argv[1], argv[2], argv[4]);
    } else {
        copy_file(argv[1], argv[2]);
    }

    return 0;
}

