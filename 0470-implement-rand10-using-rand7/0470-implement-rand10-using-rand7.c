// The rand7() API is already defined for you.

// int rand7();

// @return a random integer in the range 1 to 7

int rand10() {
    while (1) {
        int a = rand7();
        int b = rand7();

        int num = (a - 1) * 7 + b;

        if (num <= 40) {
            return (num - 1) % 10 + 1;
        }
    }
}