// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* create(const T&);
 public:
    TPQueue();
    ~TPQueue();
    void push(const T&);
    T pop();
};

template <typename T>
TPQueue<T>::TPQueue() : head(nullptr) {}

template <typename T>
TPQueue<T>::~TPQueue() {
    while (head) {
        pop();
    }
}

template <typename T>
typename TPQueue<T>::Node* TPQueue<T>::create(const T& data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

template <typename T>
void TPQueue<T>::push(const T& data) {
    if (head == nullptr) {
        head = create(data);
    } else {
        Node* temp = head;
        Node* item = create(data);
        if (data.prior > head->data.prior) {
            item->next = head;
            head = item;
        } else {
            while (temp->next != nullptr && data.prior <= temp->next->data.prior) {
                temp = temp->next;
            }
            item->next = temp->next;
            temp->next = item;
        }
    }
}

template <typename T>
T TPQueue<T>::pop() {
    if (head == nullptr) {
        throw std::string("Empty!");
    } else {
        Node* temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        return data;
    }
}


#endif  // INCLUDE_TPQUEUE_H_
