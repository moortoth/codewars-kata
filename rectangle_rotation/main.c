#include <math.h>

long long rectangle_rotation(int a, int b)
{
    long long main_a, sec_a, main_b, sec_b = 0;
    long long max_a = (double)a / sqrt(2.0);

    if (max_a % 2 == 0) {
        main_a = max_a + 1;
        sec_a = max_a;
    }
    else {
        sec_a = max_a + 1;
        main_a = max_a;
    }

    long long max_b = (double)b / sqrt(2.0);

    if (max_b % 2 == 0) {
        main_b = max_b + 1;
        sec_b = max_b;
    }
    else {
        sec_b = max_b + 1;
        main_b = max_b;
    }

    return main_a * main_b + sec_a * sec_b; // Do your magic!
}

int main(int argc, char* argv[]) {
    long long r0 = rectangle_rotation(6,4); // 23
    long long r1 = rectangle_rotation(30,2); // 65
    long long r2 = rectangle_rotation(8,6); // 49
    long long r3 = rectangle_rotation(16,20); // 333

    return 0;
}