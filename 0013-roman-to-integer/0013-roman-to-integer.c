int romanToInt(char* s) {
    int value[256] = {0};

    value['I'] = 1;
    value['V'] = 5;
    value['X'] = 10;
    value['L'] = 50;
    value['C'] = 100;
    value['D'] = 500;
    value['M'] = 1000;

    int ans = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (value[(unsigned char)s[i]] < value[(unsigned char)s[i + 1]]) {
            ans -= value[(unsigned char)s[i]];
        } else {
            ans += value[(unsigned char)s[i]];
        }
    }

    return ans;
}