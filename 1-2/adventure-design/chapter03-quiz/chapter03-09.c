#include <stdio.h>

void unitConvert(int km, double mile, double mileConversion) {
    mile = km * mileConversion;
    printf("%3d(km): %.3lf(mile)\n", km, mile);
}

int main() {
    const double mileConversion = 0.6213721;
    int km = 0;
    double mile = 0;

    km = 60;
    unitConvert(km, mile, mileConversion);

    km = 80;
    unitConvert(km, mile, mileConversion);

    km = 100;
    unitConvert(km, mile, mileConversion);

    km = 120;
    unitConvert(km, mile, mileConversion);

    return 0;
}