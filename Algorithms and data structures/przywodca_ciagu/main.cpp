#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <stdlib.h>
#include <iomanip>




int znajdzPrzywodce(const std::vector<int>& wektor)
{
    int kandydat;
    int ile = 0;

    for(int i = 0; i < wektor.size(); i++)
    {
        if(ile == 0)
        {
            ile++;
            kandydat = i;
        }
        else if (wektor[i] == wektor [kandydat])
        {
            ile++;
        }

        else
        {
            ile --;

        }
    }
    return wektor[kandydat];
}

std::vector<int> generuj(int rozmiar, int przywodca)
{
    std::vector<int> vec;
    srand(time(NULL));

    for(int i = 0; i < rozmiar; i++)
    {
        vec.push_back(rand() % rozmiar);
    }
    int j =0;

    while(j < rozmiar/2+1)
    {
        int idx = rand() % rozmiar;
        if(vec[idx] != przywodca)
        {
            vec[idx] = przywodca;
            j++;
        }
    }
    return vec;
}

int algorytmKedane(std::vector<int> &vec)
{
    //auto start = std::chrono::high_resolution_clock::now();
    clock_t start, end;
    double sredniCzas = 0;
    double najgorszyCzas = 0;
    int max_total = vec[0];
    int max_local = vec[0];
    start = clock();

    for(int i = 0; i < vec.size(); i++)
    {
        max_local = fmax(vec[i], max_local + vec[i]);
        max_total = fmax(max_total, max_local);
    }
    end = clock();
    double czas = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas dzialania " << std::setprecision(12) << czas << " sekund." << std::endl;
    std::cout << std::fixed;
    sredniCzas += czas;
    //auto stop = std::chrono::high_resolution_clock::now();
    //auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    //double czasWykonania = static_cast<double>(duration.count());
    //std::cout << "Czas:" << czasWykonania << std::endl;
    return max_total;
}

int znajdzNajmniejszaTablice(std::vector<int> vec, int& start, int& end){
    int n = vec.size();
    int maxSum = vec[0];
    int currSum = vec[0];
    start = 0;
    end = 0;
    int tmp = 0;
    clock_t start, end;
    double sredniCzas = 0;
    double najgorszyCzas = 0;
    start = clock();

    for (int i = 1; i < n; i++){
        if (vec[i] > currSum + vec[i]){
            currSum = vec[i];
            tmp = i;
        }
        else
            currSum += vec[i];

        if (currSum > maxSum){
            maxSum = currSum;
            start = tmp;
            end = i;
        }
    }
    return maxSum;
}



void permutuj(std::vector<int>& slowo, int poz = 0) {
    if (poz == slowo.size()) {
        for(int i = 0; i < slowo.size(); i++)
        {
            std::cout << slowo[i]  << " ";
        }
        std::cout << std::endl;

    } else {
        for (int i = poz; i < slowo.size(); i++)
        {
            std::swap(slowo[i], slowo[poz]);
            permutuj(slowo, poz + 1);
            std::swap(slowo[i], slowo[poz]);
        }
    }
}

void generuj_permutacje(std::vector<int>& elementy) {
    do {
        for (int i = 0; i < elementy.size(); i++) {
            std::cout << elementy[i] << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(elementy.begin(), elementy.end()));
}


int main() {
    std::vector<int> wektor = generuj(100,12);
    for(int i = 0; i < wektor.size(); i++)
    {
        std::cout << wektor[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Zadanie 4 " << std::endl;
    int przywodca = znajdzPrzywodce(wektor);
    std::cout << "Przywodca ciagu jest: " << przywodca << std::endl;


    std::cout << "Zadanie 5 " << std::endl;
    std::vector<int> wektor2 = {4, -10 ,3, 29, -3, 12, -5, 4};
    std::cout << algorytmKedane(wektor2) << std::endl;

    std::cout << "Zadanie 6 " << std::endl;
    std::vector<int> elements = {1,2,3,4,5,6,7,8}; // Możesz zmieniać wartość elementów

    std::sort(elements.begin(), elements.end()); // Sortujemy na początku

    std::cout << "Algorytm 1:" << std::endl;
    std::cout << std::endl;
    //generuj_permutacje(elements);
    std::cout << std::endl;


    std::cout << "Algorytm 2:" << std::endl;
    std::cout << std::endl;
    //permutuj(elements);
    std::cout << std::endl;


    return 0;
}


