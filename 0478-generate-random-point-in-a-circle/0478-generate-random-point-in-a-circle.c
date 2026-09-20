typedef struct {
    double radius;
    double x_center;
    double y_center;
} Solution;


Solution* solutionCreate(double radius, double x_center, double y_center) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));

    obj->radius = radius;
    obj->x_center = x_center;
    obj->y_center = y_center;

    return obj;
}

double* solutionRandPoint(Solution* obj, int* retSize) {
    double x, y;

    while (1) {
        // Random point in square [-r, r]
        x = ((double)rand() / RAND_MAX) * 2.0 * obj->radius
            - obj->radius;

        y = ((double)rand() / RAND_MAX) * 2.0 * obj->radius
            - obj->radius;

        // Check if point is inside circle
        if (x * x + y * y <= obj->radius * obj->radius) {
            double* result = (double*)malloc(2 * sizeof(double));

            result[0] = x + obj->x_center;
            result[1] = y + obj->y_center;

            *retSize = 2;

            return result;
        }
    }
}

void solutionFree(Solution* obj) {
    free(obj);
}