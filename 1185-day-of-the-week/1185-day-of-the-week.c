char* dayOfTheWeek(int day, int month, int year) {
    char* days[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    int total = day;

    for (int i = 1971; i < year; i++) {
        total += 365;

        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            total++;
    }

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    for (int i = 0; i < month - 1; i++)
        total += daysInMonth[i];

    int result = (total + 4) % 7;

    return days[result];
}