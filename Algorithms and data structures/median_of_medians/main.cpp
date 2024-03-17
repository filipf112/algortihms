#include <chrono> // dołącz bibliotekę do pomiaru czasu
#include <iostream>
// Funkcja pomocnicza do sortowania podtablicy metodą wstawiania
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Funkcja pomocnicza do znajdowania mediany podtablicy
int findMedian(int arr[], int low, int high) {
    insertionSort(arr, low, high); // posortuj podtablicę
    int mid = (low + high) / 2; // znajdź środkowy indeks
    return arr[mid]; // zwróć element środkowy
}

// Funkcja do znajdowania k-tego co do wielkości elementu w tablicy
int magicFives(int arr[], int n, int k) {
    if (k < 1 || k > n) return -1; // sprawdź poprawność k
    if (n <= 5) return findMedian(arr, 0, n - 1); // jeśli tablica ma 5 lub mniej elementów, zwróć medianę

    // Podziel tablicę na podtablice po 5 elementów i znajdź medianę każdej z nich
    int numMedians = (n + 4) / 5; // liczba median
    int medians[numMedians]; // tablica na mediany
    for (int i = 0; i < numMedians; i++) {
        int low = i * 5; // początek podtablicy
        int high = std::min(low + 4, n - 1); // koniec podtablicy
        medians[i] = findMedian(arr, low, high); // medianę podtablicy
    }

    // Znajdź medianę median rekurencyjnie
    int pivot = magicFives(medians, numMedians, (numMedians + 1) / 2);

    // Podziel tablicę względem mediany median
    int left[n], right[n], equal[n]; // tablice na elementy mniejsze, większe i równe medianie median
    int l = 0, r = 0, e = 0; // liczniki elementów w tablicach
    for (int i = 0; i < n; i++) {
        if (arr[i] < pivot) left[l++] = arr[i]; // element mniejszy od mediany median
        else if (arr[i] > pivot) right[r++] = arr[i]; // element większy od mediany median
        else equal[e++] = arr[i]; // element równy medianie median
    }

    // Sprawdź, w której tablicy znajduje się k-ty element
    if (k <= l) return magicFives(left, l, k); // w tablicy elementów mniejszych
    else if (k > l + e) return magicFives(right, r, k - l - e); // w tablicy elementów większych
    else return pivot; // w tablicy elementów równych
}

int main() {
    int arr[] = {6,5,2,32,17,45,8,23,39,12,50,6,28,14,37,3,19,42,5,30,11,49,22,9,41,20,48,2,27,10,34,21,16,40,1,44,29,7,35,18,46,26,15,25,38,13,33,4,24,47,31,36,43, 7, 10, 4, 3, 20, 15,11,23,22,90,8,29,77,66,55,44,123}; // przykładowa tablica
    int n = sizeof(arr) / sizeof(arr[0]); // rozmiar tablicy
    int k = 3; // k-ty element do znalezienia
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); // zacznij mierzyć czas
    int kth = magicFives(arr, n, k); // znajdź k-ty element
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now(); // skończ mierzyć czas
    std::chrono::duration<double, std::milli> time_span = end - start; // oblicz różnicę czasu w milisekundach
    std::cout << "K-ty element to " << kth << std::endl; // wypisz k-ty element
    std::cout << "Czas wykonania algorytmu to " << time_span.count() << " ms" << std::endl; // wypisz czas wykonania
    return 0;
}