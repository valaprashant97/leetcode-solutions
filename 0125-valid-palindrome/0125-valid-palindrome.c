bool isPalindrome(char* s) {
     int left = 0;
    int right = 0;

    while (s[right] != '\0') {
        right++;
    }

    right--;

    while (left < right) {

        if (!isalnum(s[left])) {
            left++;
        }
        else if (!isalnum(s[right])) {
            right--;
        }
        else {
            // Compare characters
            if (tolower(s[left]) != tolower(s[right])) {
                return 0;
            }

            left++;
            right--;
        }
    }

    return 1;
}