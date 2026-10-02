int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1;
    int length = 0;

    while (s[i] == ' ') {
        i--;
    }

    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}