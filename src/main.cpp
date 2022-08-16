
/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <iostream>
#include "../include/listnode.h"

// запрос исправления вводных данных, возврат проверяющего цикла к началу
void wrongInput(std::string & str, int & i)
{
    std::cout << "Wrong input, try again: \n";
    str.clear();
    std::cin >> str;
    i = str.size();
}

// функция, гарантирующая правильность ввода
void checkString(std::string & str)
{
    for(int i = str.size() - 1; i >=0; i--)
    {
        // если первый элемент строки равен нулю - запросить изменить ввод
        if(i == 0 && str[0] - '0' == 0)
        {
            wrongInput(str, i);
        }

        // проверка что строка состоит только из цифр
        else if(!std::isdigit(str[i]))
        {
            wrongInput(str, i);
        }
    }
}

int main() {

    std::string first, second;

    // ввод и проверка строк
    std::cout << "Input first number: \n";
    std::cin >> first;
    checkString(first);

    std::cout << "Input second number: \n";
    std::cin >> second;
    checkString(second);

    // создаем связанные списки
    std::shared_ptr<ListNode> l1 = createListNode(first);
    std::shared_ptr<ListNode> l2 = createListNode(second);

    // складываем связанные списки
    std::shared_ptr<ListNode> l3 = addTwoNumbers(l1.get(), l2.get());

    // выводим результирующий списко на печать
    coutListNode(l3.get());

    return 0;
}
