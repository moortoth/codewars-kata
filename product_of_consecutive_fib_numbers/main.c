#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <memory.h>

typedef unsigned long long ull;

ull* productFib(ull prod) {
    ull* res = malloc(sizeof(ull) * 3);
    memcpy(res, (ull []){0,0,0}, 3 * sizeof(ull));
    ull prev = 0;
    ull nth = 1;
    int i = 1;
    bool w_rem = false; // if prod devides with F(n) without a reminder

    while (true) {
        ull nth_t = prev + nth;

        if (prod % nth_t == 0) {
            if (prod == nth_t * nth) {
                memcpy(res, (ull []){nth, nth_t, 1}, 3 * sizeof(ull));
                return res;
            }
            w_rem = true;
        }

        if (nth_t * nth > prod) {
            memcpy(res, (ull []){nth, nth_t, 0}, 3 * sizeof(ull));
                return res;
        }

        prev = nth;
        nth = nth_t;
        ++i;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    ull* res = productFib(4895);

    printf("{%d, %d, %d}\r\n", (int)res[0], (int)res[1], (int)res[2]);

    free(res);

    return 0;
}