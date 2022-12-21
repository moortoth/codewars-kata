long properFractions(long n)
{
    if (n == 1)
        return 0;

    long res = n;
    long f = 1;

    do {
        do {
            if (f * f > n) 
                return res -= res / n;
            f++;
        }
        while (n % f != 0);

        res -= res / f;

        do {
            n /= f;
        }
        while (n % f == 0);
    }
    while(n > f);

    return res;
}

int main (int argc, char **argv) {
    // for (long i = 1; i <= 9999999; ++i) {
    //     long res0 = properFractions(i); // 0
    // }
    long res1 = properFractions(2);// 1
    long res2 = properFractions(5);// 4
    long res3 = properFractions(15);// 8
    long res4 = properFractions(25);// 20
    long res41 = properFractions(60);// 16
    long res5 = properFractions(9999999); // 6637344
    long res6 = properFractions(1532420); // 608256

    return 0;
}