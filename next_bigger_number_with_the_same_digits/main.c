#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 21

long long next_bigger_number(long long n) {
    char* ts = calloc(MAX_LEN, sizeof(char));
    size_t l = 0;
    size_t sec_least_ind = -1;
    
    while (n > 0 && sec_least_ind == -1) {
        int rem = n % 10;
        
        for (int i = 0; i < l; ++i) {
            if (ts[i] - '0' > rem && (ts[i] < ts[sec_least_ind] || sec_least_ind == -1)) {
                sec_least_ind = i;
            }
        }

        ts[l++] = '0' + rem;
        n /= 10;
    }

    if (sec_least_ind == -1) {
        free(ts);
        return -1;
    }

    char mem = ts[l-1];
    ts[l-1] = ts[sec_least_ind];
    ts[sec_least_ind] = mem;

    for (int i = 0; i < l - 1; ++i) {
        for (int j = i + 1; j < l - 1; ++j) {
            if (ts[j] > ts[i]) {
                char swap = ts[i];
                ts[i] = ts[j];
                ts[j] = swap;
            }
        }
    }

    for (int i = 0; i < l; ++i) {
        n = n * 10 + (ts[l - i - 1] - '0');
    }

    free(ts);

    return n;
}

int main(int argc, char* argv[]) {
    int r1 = next_bigger_number(12); // 21);
    int r2 = next_bigger_number(513); // 531);
    int r3 = next_bigger_number(2017); // 2071);
    int r4 = next_bigger_number(414); // 441);
    int r5 = next_bigger_number(144); // 414);
    int r6 = next_bigger_number(10990); // 19009

    return 0;
}