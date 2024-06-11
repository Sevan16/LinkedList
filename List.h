#pragma once
#include <iostream>
#include <sstream>
using namespace std;

/**
 * @brief Структура узла списка.
 */
struct Node {
    int data;
    Node* next;

    /**
     * @brief Конструктор узла.
     * @param data Значение для инициализации данных узла.
     */
    Node(int data);
};

/**
 * @brief Класс односвязного списка.
 */
class LinkedList {
private:
    Node* head;

public:
    /**
    * @brief Конструктор по умолчанию.
    */
    LinkedList();

    LinkedList(const LinkedList& other);
    
    LinkedList& operator=(const LinkedList& other);
    
    LinkedList(LinkedList&& other);
    
    LinkedList& operator=(LinkedList&& other);
    
    /**
    * @brief Конструктор со списком инициализации
    * @param list список инициализации
    */
    LinkedList(initializer_list<int> list);
    /**
     * @brief Деструктор списка. Очищает список при удалении объекта.
     */
    ~LinkedList();
    /**
    * @brief Добавляет элемент в начало списка.
    * @param data Значение для добавления.
    */
    void pushFront(int data);

    /**
     * @brief Добавляет элемент в конец списка.
     * @param data Значение для добавления.
     */
    void pushBack(int data);

    /**
     * @brief Удаляет элемент из начала списка.
     */
    void popFront();

    /**
     * @brief Удаляет элемент из конца списка.
     */
    void popBack();

    int size() const;

    void insert(int data, int position);

    void remove(int data);

    /**
     * @brief Очищает список, удаляя все элементы.
     */
    void clear();

    friend ostream& operator<<(ostream& ostream, const LinkedList& list);

    /**
     * @brief Печатает все элементы списка.
     */
    string printList() const;
};
