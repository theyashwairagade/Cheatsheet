void fastInput(int &number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar()) {
        number = number * 10 + c - 48;
    }
    if (negative) {
        number *= -1;
    }
}

void fastOutput(int number) {
    char buffer[11];
    int i = 0;
    if (number < 0) {
        putchar('-');
        number = -number;
    }
    do {
        buffer[i++] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i) {
        putchar(buffer[--i]);
    }
    putchar('\n');
}

// use this in main
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
fastInput(n);
fastOutput(n);