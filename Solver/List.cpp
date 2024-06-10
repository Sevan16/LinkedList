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