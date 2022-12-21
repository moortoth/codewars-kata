int f(int x) {
    return 2 * x + 1;
}

int g(int x) {
    return 3 * x + 1;
}

int s(int n) {
    int r = 1;
    
    for (; n > 1; n /= 2) {
        r = r << 1 + 1;
    }

    return r;
}

int x(int lv, int offset) {
    if (lv == 0) return 1;

    switch(offset % 4)
    {
        case 0:
            return 2 * x(lv - 1, offset ) + 1;
        /* code */
        break;
    }
}

int dblLinear(int n) {
    int sum = s(n);
    int mod = n % sum;
    
    switch (mod)
    {
        case 0: // ff

        break;
    }
}