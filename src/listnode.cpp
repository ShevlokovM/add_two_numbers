//
// Created by 111 on 16.08.2022.
//

#include <iostream>
#include <memory>
#include <string>
#include "../include/listnode.h"


// функция "складывает" два связанных списка
std::shared_ptr<ListNode> addTwoNumbers(ListNode* l1, ListNode* l2)
{
    //возвращаемый указатель, указывает на первый элемент связанного списка
    std::shared_ptr<ListNode> listNode = std::make_shared<ListNode>();

    // временный указатель, нужен чтобы заполнить связанный список
    ListNode * ln = listNode.get();

    // переменная для 1 в уме, если сумма больше 9и
    int remains = 0;

    // складываем элементы входящих связанных списков, и сохраняем сумму в возвращаемый
    // цикл работает, пока есть элементы хотя бы в одном из списков
    // складываются соответствующие элементы списков
    while(true)
    {
        int x, y;

        // если список еще не кончился, вытаскиваем из него val, иначе вытаскиваем ноль
        if(l1) x = l1->val;
        else x = 0;
        if(l2) y = l2->val;
        else y = 0;

        // сумма чисел из входящих списков + то что в уме ( 1 или 0)
        int dig = x + y + remains;

        // если сумма 10 и больше, то записываем в возвращаемый список
        // только первый разряд числа, и 1 в уме
        if(dig > 9)
        {
            ln->val = dig - 10;
            remains = 1;
        }
        else
        {
            ln->val = dig;
            remains = 0;
        }

        // дальше нужно понять, есть дальше ноды во входящих связанных списках, и если да, то
        // создать еще один нод в возвращаемом списке


        // если на этой итерации мы работали с обоими входящими списками
        if(l1 && l2)
        {
            // и если есть продолжение хотя бы одного списка
            if (l1->next || l2->next)
            {
                // создаем новый нод для возвращаемого списка
                ln->next = new ListNode();

                // присваиваем временному указателю его адрес
                ln = ln->next;

                // передвигаем указатели на входящие списки на следующие элементы, если они есть
                // если нет, то nullptr
                if (l1->next)l1 = l1->next;
                else l1 = nullptr;
                if (l2->next) l2 = l2->next;
                else l2 = nullptr;
            }

            // если нет, то выйти из цикла
            else break;
        }
        // аналогичные действия, если остались элементы только в одном из входящих списков
        // этот и следующий else
        else if(l1)
        {
            if (l1->next)
            {
                ln->next = new ListNode();
                ln = ln->next;
                l1 = l1->next;
            }
            else break;
        }
        else if(l2)
        {
            if (l2->next)
            {
                ln->next = new ListNode();
                ln = ln->next;
                l2 = l2->next;
            }
            else break;
        }
        else break;
    }

    return listNode;
}


// функция формирует связанный список из строки
std::shared_ptr<ListNode> createListNode(std::string dig)
{
    //возвращаемый указатель, указывает на первый элемент связанного списка
    std::shared_ptr<ListNode> listNode = std::make_shared<ListNode>();

    // временный указатель, нужен чтобы заполнить связанный список
    ListNode * ln = listNode.get();

    // создаем связанный список в цикле
    for(int i = 0; i < dig.size(); i++)
    {
        // присваиваем значение элементу val структуры ListNode. значение берем из одного символа входящей строки
        ln->val = dig[i] - '0';

        // если обрабатывается не последний символ строки, то нужно создать новый ListNode,
        // и присвоить его адрес указателю next
        if(i != dig.size() - 1)
        {
            ln->next = new ListNode();

            // временный указатель теперь должен указывать на новый, следующий элемент связанноо списка
            ln = ln->next;
        }
        // если обрабатывается последний элемент строки, то дальше не будет элементов в связанном списке,
        // и указателю next нужно присвоить nullptr
        else ln->next = nullptr;
    }

    return listNode;
}

// вывод связанного списка в консоль
void coutListNode(ListNode* l)
{
    std::cout << std::endl;

    while(l)
    {
        std::cout << l->val << "\t";
        l = l->next;
    }

    std::cout << std::endl;
}