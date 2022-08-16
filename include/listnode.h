//
// Created by 111 on 16.08.2022.
//

#ifndef ADD_TWO_NUMBERS_LISTNODE_H
#define ADD_TWO_NUMBERS_LISTNODE_H

#pragma once

#include <iostream>
#include <memory>
#include <string>

struct ListNode
{
    int val;

    // указатель на следующий элемент связанного списка
    ListNode *next;

    // конструкторы
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){}

    // деструктор. достаточно вызвать деструктор первого элемента списка, будут удалены все
    ~ListNode()
    {
        // если в списке есть следующий элемент, вызываем его деструктор
        if(next)
        {
            delete next;
        }
    }

};

// функция "складывает" два связанных списка
std::shared_ptr<ListNode> addTwoNumbers(ListNode* l1, ListNode* l2);

// функция формирует связанный список из строки
std::shared_ptr<ListNode> createListNode(std::string dig);

// вывод связанного списка в консоль
void coutListNode(ListNode* l);


#endif //ADD_TWO_NUMBERS_LISTNODE_H
