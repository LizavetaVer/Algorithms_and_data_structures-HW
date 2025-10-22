

#include <iostream>
using namespace std;

/*
ЗАДАЧА:
Реализовать стек
Реализовать очередь
Реализовать дек
...
*/

// -----------------------------СТЕК
class Stack {
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1; // стек пуст
    }
    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Стек переполнен\n";
            return;
        }
        arr[++topIndex] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Стек пуст\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Стек пуст\n";
            return -1; // или можно бросить исключение
        }
        return arr[topIndex];
    }
};
// -----------------------------ОЧЕРЕДЬ

class Queue {
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }
    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == capacity);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Очередь переполнена\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Очередь пуста\n";
            return -1; // или бросать исключение
        }
        return arr[frontIndex];
    }

    int size() {
        return count;
    }
};
// -----------------------------ДЕК
class Deque {
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = capacity - 1;
        count = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void pushFront(int val) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        arr[frontIndex] = val;
        count++;
    }

    void pushBack(int val) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        count++;
    }

    void popFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    void popBack() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        count--;
    }

    int front() const {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1; // Или бросить исключение
        }
        return arr[frontIndex];
    }

    int back() const {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[rearIndex];
    }

    int size() const {
        return count;
    }
};


// -----------------------------ТЕСТ
int main() {
    cout << "СТЕК: " << "\n";
    Stack s(5);
    s.push(10);
    s.push(20);
    cout << "Верхний элемент: " << s.top() << "\n";
    s.pop();
    cout << "Верхний элемент после удаления: " << s.top() << "\n";


    cout << "ОЧЕРЕДЬ: " << "\n";

    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Первый элемент: " << q.front() << "\n";

    q.dequeue();
    cout << "Первый элемент после dequeuing: " << q.front() << "\n";

    cout << "ДЕК: " << "\n";

    Deque d(5);

    d.pushBack(1);
    d.pushBack(2);
    d.pushFront(0);

    cout << "Начало: " << d.front() << "\n"; // 0
    cout << "Конец: " << d.back() << "\n";   // 2

    d.popFront();
    cout << "Начало после popFront: " << d.front() << "\n"; // 1

    d.popBack();
    cout << "Конец после popBack: " << d.back() << "\n";   // 1



    return 0;
}
