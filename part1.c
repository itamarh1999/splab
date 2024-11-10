#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * key= "0";
int key_length;
int keytype;

char encode(char c, int keytype, int change) {
    if (key!= "0")
    {
        
        if (isdigit(c)) {
            if (keytype == 1) {
                c = c + change;
                if (c>'9')
                    c = c - 10;
            } else {
                c = c - change;
                if (c<'0')
                    c = c + 10;
            }
        } else if (isupper(c)) {
            if (keytype == 1) {
                c = c + change;
                if (c>'Z')
                    c = c - 26;
            } else {
                c = c - change;
                if (c<'A')
                    c = c + 26;
            }
        } else if (islower(c)) {
            if (keytype == 1) {
                c = c + change;
                if (c>'z')
                    c = c - 26;
            } else {
                c = c - change;
                if (c<'a')
                    c = c + 26;
            }
        }
    }
    return c;
}

int main(int argc, char *argv[]){
    int d_mode =1;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-D") == 0) {
            d_mode = 0;
        } else if (strcmp(argv[i], "+D") == 0) {
            d_mode = 1;
        }
        if (d_mode){
            fprintf(stderr, "Argument %d: %s\n", i, argv[i]);
        }
        if (argv[i][0] == '+' && argv[i][1] == 'E')
        {
            keytype = 1;
            key = argv[i] + 2;
            key_length = strlen(argv[i]) -2;
        }
        if (argv[i][0] == '-' && argv[i][1] == 'E')
        {
            keytype = 0;
            key = argv[i] + 2;
            key_length = strlen(argv[i]) -2;
        }
        
    }
    char c;
    int i = 0;
    while ((c = fgetc(stdin)) != EOF) {
        int shift = key[i % key_length] - '0';
        c = encode(c,keytype,shift);
        i++;
        fputc(c, stdout);      
    }

    return 0;
}
