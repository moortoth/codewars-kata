#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define OFFSET 13

char *rot13 (char *str_out, const char *str_in) {
    str_out = calloc(strlen(str_in) + 1, sizeof(char));
    str_out[strlen(str_in)] = '\0';
    const char len = 'Z' - 'A' + 1;
    for (int i = 0; i < strlen(str_in); ++i) {
        if ((str_in[i] >= 'A' && str_in[i] <= 'Z') || (str_in[i] >= 'a' && str_in[i] <= 'z')) {
            int let = str_in[i] - (str_in[i] >= 'a' ? 'a' : 'A');
            int off = let - OFFSET;
            off = off < 0 ? off + len : off;
            str_out[i] = str_in[i] >= 'a' ? 'a' + off : 'A' + off;
        }
        else {
            str_out[i] = str_in[i];
        }
    }

    return str_in;
}

int main(int argc, char *argv[]) {
    char *res = rot13(res, "Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.");
    printf("%s", res); // ABCD
}