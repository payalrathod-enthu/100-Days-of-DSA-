#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// sort by position descending
int cmp(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed) {
    Car cars[positionSize];

    // Step 1: compute time
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: sort by position descending
    qsort(cars, positionSize, sizeof(Car), cmp);

    int fleets = 0;
    double maxTime = 0;

    // Step 3: traverse
    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > maxTime) {
            fleets++;                 // new fleet
            maxTime = cars[i].time;   // update slowest time
        }
    }

    return fleets;
}

// -------- Driver --------
int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    printf("%d", carFleet(target, position, n, speed));
    return 0;
}
