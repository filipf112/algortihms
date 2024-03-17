#include <stdio.h>

#define size 9
#define N 10

double FIR(double wejscie[], double h[], int pamiec, int rozmiar) {
    double wyjscie = 0;
    for(int i = 0; i <= rozmiar - 1; i++) {
        if(pamiec <= i) {
            wyjscie += wejscie[i - pamiec] * h[i];
        }
    }
    return wyjscie;
}

int main() {


    double h[size] = {0.1, -2, 0.3, 4, 5, 4, 0.3, -2,0.1};

    double in[N] = {1,2,3,4,5,6,7,8,9,10};
    double out[N] = {0};
    for(int i = 1; i < N; i++) {
        in[i] = 0;
    }

    for(int i = 0; i < N; i++) {
        out[i] = FIR(in, h, i, size);
        printf("%f ", out[i]); // Changed %d to %f for double
    }
    return 0;
}
