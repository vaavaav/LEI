#include <stdio.h>
#include <ctype.h>

int main(){
    int q[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int max = 0;
    char frase[255];
    printf("Sentence:");
    gets(frase);
    printf("\n\n");
    for(int i = 0; frase[i]; i++) {
        if (isalpha(frase[i])) {
            q[toupper(frase[i]) - 'A']++;
            if (max < q[toupper(frase[i]) - 'A'])
                max++;
        }
    }
    for(; max > 0; max--) {
        for (int i = 0; i < 26; i++) {
           if( q[i] >= max)
               printf("*");
           else
               printf(" ");
           printf(" ");
        }
        printf("\n");
    }
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    return 0;
}
