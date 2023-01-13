#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>

typedef long long u64;

typedef struct pair pair;
struct pair {
    u64 first;
    u64 snd;
};

pair** removNb(u64 n, int* length) {
    u64* res_f = calloc(n, sizeof(u64));
    u64* res_s = calloc(n, sizeof(u64));
    u64 N = (n + n * n) / 2 + 1;
    int l = 0;
    u64 upper_bound = sqrt(N);
    
    for (u64 i = N / (n + 1); i <= upper_bound; ++i) {
        if (N % i == 0) {
            res_f[l] = i - 1; 
            res_s[l++] = (N / i) - 1;
        }
    }

    *length = l*2;

    pair** res_pairs = malloc((*length) * sizeof(pair*));

    for (int i = 0; i < l; ++i) {
        res_pairs[i] = malloc(sizeof(pair));
        *res_pairs[i] = (pair) {
            .first = res_f[i],
            .snd = res_s[i]
        };

        res_pairs[l * 2 - i - 1] = malloc(sizeof(pair));
        *res_pairs[l * 2 - i - 1] = (pair) {
            .first = res_s[i],
            .snd = res_f[i]
        };
    }

    return res_pairs;
}

void test_print(u64 n) {
    int length = 0;
    pair **res = removNb(n, &length);

    for (int i = 0; i < length; ++i) {
        printf("{%lld, %lld} ", res[i]->first, res[i]->snd);
        free(res[i]);
    }

    printf("\r\n");

    free(res);
}

int main(int argc, char* argv) {

    test_print(26);
    test_print(100);
    test_print(37);
    test_print(101);

    return 0;
}