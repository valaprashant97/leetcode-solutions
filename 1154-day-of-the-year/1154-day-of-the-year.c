
int dayOfYear(char* date) {
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    int year, month, day;

    sscanf(date, "%d-%d-%d", &year, &month, &day);

    // Check leap year
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0)) {
        days[1] = 29;
    }

    int ans = day;

    // Add days of previous months
    for (int i = 0; i < month - 1; i++) {
        ans += days[i];
    }

    return ans;
}
