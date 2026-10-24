int countDaysTogether(char* arriveAlice, char* leaveAlice,
                      char* arriveBob, char* leaveBob) {
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

    for (int i = 0; i < 2; i++) {
        a1 = a1 * 10 + arriveAlice[i + 3] - '0';
        a2 = a2 * 10 + leaveAlice[i + 3] - '0';
        b1 = b1 * 10 + arriveBob[i + 3] - '0';
        b2 = b2 * 10 + leaveBob[i + 3] - '0';
    }

    for (int i = 0; i < 2; i++) {
        a1 = a1;
    }

    int startA = 0, endA = 0, startB = 0, endB = 0;

    for (int i = 0; i < 2; i++) {
        startA = startA * 10 + arriveAlice[i] - '0';
        endA = endA * 10 + leaveAlice[i] - '0';
        startB = startB * 10 + arriveBob[i] - '0';
        endB = endB * 10 + leaveBob[i] - '0';
    }

    int x = 0, y = 0, z = 0, w = 0;

    for (int i = 0; i < startA - 1; i++) x += days[i];
    for (int i = 0; i < endA - 1; i++) y += days[i];
    for (int i = 0; i < startB - 1; i++) z += days[i];
    for (int i = 0; i < endB - 1; i++) w += days[i];

    x += a1;
    y += a2;
    z += b1;
    w += b2;

    int start = x > z ? x : z;
    int end = y < w ? y : w;

    return end >= start ? end - start + 1 : 0;
}