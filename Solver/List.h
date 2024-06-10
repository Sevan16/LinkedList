#pragma once
#include <iostream>
#include <sstream>
using namespace std;

/**
 * @brief ��������� ���� ������.
 */
struct Node {
    int data;
    Node* next;

    /**
     * @brief ����������� ����.
     * @param data �������� ��� ������������� ������ ����.
     */
    Node(int data);
};

/**
 * @brief ����� ������������ ������.
 */
class LinkedList {
private:
    Node* head;

public:
    /**
     * @brief ����������� �� ���������.
     */
    LinkedList();
    /**
    * @brief ����������� �� ������� �������������
    * @param list ������ �������������
    */
    LinkedList(initializer_list<int> list);
    /**
     * @brief ���������� ������. ������� ������ ��� �������� �������.
     */
    ~LinkedList();

    /**
    * @brief ��������� ������� � ������ ������.
    * @param data �������� ��� ����������.
    */
    void pushFront(int data);

    /**
     * @brief ��������� ������� � ����� ������.
     * @param data �������� ��� ����������.
     */
    void pushBack(int data);

    /**
     * @brief ������� ������� �� ������ ������.
     */
    void popFront();

    /**
     * @brief ������� ������� �� ����� ������.
     */
    void popBack();

    /**
     * @brief ������� ������, ������ ��� ��������.
     */
    void clear();

    friend ostream& operator<<(ostream& ostream, const LinkedList& list);

    /**
     * @brief �������� ��� �������� ������.
     */
    string printList() const;
};


