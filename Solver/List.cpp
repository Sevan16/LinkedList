#include "List.h"
#include <iostream>
#include <sstream>
using namespace std;

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::LinkedList(initializer_list<int> list) : LinkedList()
{
    for (auto& data : list)
    {
        this->pushBack(data);
    }
}

LinkedList::~LinkedList() {
    this->clear();
}

int LinkedList::size() const {
    int count = 0;
    Node* current = this->head;

    while (current != nullptr) {
        ++count;
        current = current->next;
    }

    return count;
}

void LinkedList::pushFront(int data) {
    Node* newNode = new Node(data);
    newNode->next = this->head;
    this->head = newNode;
}

void LinkedList::pushBack(int data) {
    Node* newNode = new Node(data);
    if (this->head == nullptr) {
        this->head = newNode;
    }
    else {
        Node* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::popFront() {
    if (this->head == nullptr) {
        throw logic_error("Список пустой!");
    }
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
}

void LinkedList::popBack() {
    if (this->head == nullptr) {
        throw logic_error("Список пустой!");;
    }
    if (this->head->next == nullptr) {
        delete this->head;
        this->head = nullptr;
    }
    else {
        Node* current = this->head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

void LinkedList::clear() {
    while (this->head != nullptr) {
        this->popFront();
    }
}

void LinkedList::insert(int data, int position) {
    if (position < 0 || position > this->size()) {
        throw logic_error("Неверный индекс позиции!");
    }

    Node* newNode = new Node(data);
    if (position == 0) {
        newNode->next = this->head;
        this->head = newNode;
    }
    else {
        Node* current = this->head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void LinkedList::remove(int data) {
    Node* temp = nullptr;
    Node* current = this->head;

    while (current != nullptr) {
        if (current->data == data) {
            if (temp == nullptr) {
                this->head = current->next;
            }
            else {
                temp->next = current->next;
            }
            delete current;
            break;
        }
        temp = current;
        current = current->next;
    }
}

ostream& operator<<(ostream& ostream, const LinkedList& list) {
    auto current = list.head;
    while (current != nullptr) {
        ostream << current->data << " ";
        current = current->next;
    }
    return ostream;
}

string LinkedList::printList() const
{
    ostringstream buffer{};
    buffer << *this;
    return buffer.str();
}