#include <iostream>

template <typename T>
class Wezel {
public:
    T value;
    Wezel* prev;
    Wezel* next;
    Wezel(T value) : value(value), prev(nullptr), next(nullptr) {}

};

template <typename T>
class BuforKolowy {

private:
    int capacity;
    int size;
    Wezel<T>* head;
    Wezel<T>* tail;

public:
    BuforKolowy(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}
    void Push(T value);
    T Pop();
    bool isFull();
    bool isEmpty();
    int getSize();
    void Clear();
    void Display();
};


template <typename T>
void BuforKolowy<T>::Push(T value) {
    Wezel<T>* nowyWezel = new Wezel<T>(value);

    if (size == 0) {
        head = nowyWezel;
        tail = nowyWezel;
        head->next = tail;
        tail->prev = head;
    } else if (size < capacity) {
        nowyWezel->prev = tail;
        nowyWezel->next = head;
        tail->next = nowyWezel;
        tail = nowyWezel;
    } else {
        std::cerr << "Blad: Bufor jest pelny." << std::endl;
        delete nowyWezel;
        return;
    }

    size++;
}


template <typename T>
T BuforKolowy<T>::Pop() {
    if (size > 0) {
        T value = head->value;
        Wezel<T>* temp = head;

        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
            head->prev = tail;
        }

        delete temp;
        size--;
        return value;
    } else {
        std::cerr << "Blad: Bufor jest pusty." << std::endl;
        return T();
    }
}


template <typename T>
bool BuforKolowy<T>::isEmpty(){
    return size == 0;
}


template <typename T>
bool BuforKolowy<T>::isFull(){
    return size == capacity;
}


template <typename T>
int BuforKolowy<T>::getSize(){
    return size;
}

template <typename T>
void BuforKolowy<T>::Clear() {
    while (!isEmpty()) {
        Pop();
    }
    std::cout << "Bufor zostal wyczyszczony." << std::endl;
}

template <typename T>
void BuforKolowy<T>::Display() {
    Wezel<T>* current = head;

    if (isEmpty()) {
        std::cout << "Bufor jest pusty." << std::endl;
    } else {
        std::cout << "Zawartosc bufora:" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

int main() {
    BuforKolowy<int> bufor(7);

    for (int i = 1; i <= 7; i++) {
        bufor.Push(i);
    }
    bufor.Display();
    bufor.Pop();
    bufor.Display();
    bufor.Clear();
    bufor.Display();
    bufor.getSize();
    return 0;
}






