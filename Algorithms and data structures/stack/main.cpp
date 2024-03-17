#include <iostream>
#include <stdexcept>

template <typename T>
class Wezel {
public:
    T value;
    Wezel* prev;
    Wezel(T value) : value(value), prev(nullptr) {}
};

template <typename T>
class Stos {
private:
    int capacity;
    int size;
    Wezel<T>* top;

public:
    Stos(int capacity) : capacity(capacity), size(0), top(nullptr) {}
    void Push(T value);
    T Pop();
    bool isFull();
    bool isEmpty();
    int getSize();
    void Clear();
    void Display();
};

template <typename T>
void Stos<T>::Push(T value) {
    if (!isFull()) {
        Wezel<T>* newNode = new Wezel<T>(value);
        newNode->prev = top;
        top = newNode;
        size++;
    } else {
        std::cerr << "Błąd: Stos jest pełny." << std::endl;
    }
}

template <typename T>
T Stos<T>::Pop() {
    if (!isEmpty()) {
        Wezel<T>* poppedNode = top;
        T poppedValue = poppedNode->value;
        top = top->prev;
        delete poppedNode;
        size--;
        return poppedValue;
    } else {
        throw std::runtime_error("Błąd: Stos jest pusty. Nie można usunąć elementu.");
    }
}

template <typename T>
bool Stos<T>::isFull() {
    return size >= capacity;
}

template <typename T>
bool Stos<T>::isEmpty() {
    return size == 0;
}

template <typename T>
int Stos<T>::getSize() {
    return size;
}

template <typename T>
void Stos<T>::Clear() {
    while (!isEmpty()) {
        Pop();
    }
    std::cout << "Wyczyszczono Stos" << std::endl;
}

template <typename T>
void Stos<T>::Display() {
    Wezel<T>* current = top;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

int main() {
    Stos<int> stos(7);

    for (int i = 1; i <= 7; i++) {
        stos.Push(i);
    }

    stos.Display();
    stos.Pop();
    stos.Display();
    stos.Clear();
    stos.Display();

    return 0;
}