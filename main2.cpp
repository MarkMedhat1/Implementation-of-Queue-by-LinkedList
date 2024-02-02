#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T item) : data(item), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T item) {
        Node<T>* newNode = new Node<T>(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
            // You might want to handle this error differently based on your application
            exit(EXIT_FAILURE);
        }

        T data = front->data;
        Node<T>* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }

        delete temp;
        return data;
    }

    T peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
            // You might want to handle this error differently based on your application
            exit(EXIT_FAILURE);
        }

        return front->data;
    }

    void display() const {
        Node<T>* current = front;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Queue:" << std::endl;
    queue.display();

    std::cout << "Peek: " << queue.peek() << std::endl;

    std::cout << "Dequeue: " << queue.dequeue() << std::endl;
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;

    std::cout << "Queue after dequeues:" << std::endl;
    queue.display();

    return 0;
}
