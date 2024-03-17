
#include <iostream>


double fir(double in, double wsp[], double buf[],int N){
    double output=0;
    buf[0] = in;
    for(int i = 0; i < N; i++){
            output += buf[i] * wsp[i];
    }

    for (int i = N - 1; i > 0; i--) {    // Aktualizacja bufora
        buf[i] = buf[i - 1];
    }
    return output;
}


int main() {

   const int size = 11;
   const int N = 128;

    double h[size] = {-1,2,-0.5,4,5,6,5,4,-0.5,2, -1};
    double memory[size] = {0};

    double in[N]={1};
    double out[N]={0};
    for(int i = 1; i < N; i++){
        in[i]=0;
//        out[i]=0;
    }

    for(int i = 0; i <N;i++){
        out[i]= fir(in[i],h,memory,size);
        std::cout << out[i]<<" " ;
    }
    return 0;
}
