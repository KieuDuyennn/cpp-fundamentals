#include <stdio.h>
#include <stdlib.h>
#include  <ctype.h> 


int isDelimiter(char c) {
    return (c == ' ' || c == '.' || c == ',' || c == ';' || c == ':' || c == '\'' || c == '?' || c == '!');
}

int main() {
    char *paragraph = NULL; 
    int len = 0;
    char c;

    printf("Nhap van ban: ");
    while ((c = getchar()) != EOF && c != '.') {
       
        paragraph = (char *)realloc(paragraph, (len + 1) * sizeof(char));
        if (paragraph == NULL) {
            printf("Error");
            return 1;
        }
        paragraph[len] = c;
        len++;
    }

 
    paragraph = (char *)realloc(paragraph, (len + 1) * sizeof(char));
    if (paragraph == NULL) {
        printf("error");
        return 1;
    }
    paragraph[len] = '\0';


   int wordCount = 0;
    int i = 0;
    while (paragraph[i] != '\0') {
        
        while (isDelimiter(paragraph[i])) {
            i++;
        }
        if (paragraph[i] != '\0') {
            wordCount++;
        }

    
    for (int i = 0; i < len; i++) {
        if (!isDelimiter(paragraph[i])) {
            
            if (i == 0 || isDelimiter(paragraph[i - 1])) {
                paragraph[i] = toupper(paragraph[i]);
            }
            printf("%c", paragraph[i]);
        } else {
            printf(" "); 
        }
    }


    free(paragraph);

    return 0;
}}

