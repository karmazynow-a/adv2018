/*
Zadanie polega na napisaniu adaptera działającego jak kolejka (FIFO)
Nie może być ona domyślnym parametrem szablonu
Należy pamiętać o definiowaniu typów składowych i ich używaniu
*/

#include <iostream>
#include "MyQueue.h"

int main(void){
    my_queue<int> q;

    for (int i = 0; i<10; ++i)
        q.push(i*2);

    std::cout << "Kolejka: " << q;

    q.pop();
    std::cout << "Po usunięciu: " << q;

    q.push(5);
    std::cout << "Po dodaniu nowego elementu: " << q;

    std::cout << "Czy jest pusta? " << std::boolalpha  << q.empty() << std::endl;
    std::cout << "Pierwszy element " << q.front() << std::endl;
    std::cout << "Ostatni element " << q.back() << std::endl;

    my_queue<int> q2 = q;

    for (int i = 0; i<5; ++i)
        q2.pop();

    std::cout << "Druga kolejka: " << q2;
    q.swap(q2);
    std::cout << "Po zamianie: " << std::endl << "Pierwsza kolejka: " << q << "Druga kolejka: " << q2;

    my_queue<int> q3, q4;
    for (int i = 0; i<5; ++i)
        q3.push(i);

    for (int i = 0; q4 != q3; ++i)
        q4.push(i);

    std::cout << "Czy q3 i q4 są równe?: " << std::boolalpha  << (q3 == q4 ? true : false )<< std::endl;

    q4.pop();
    std::cout << "Czy q3 jest teraz leksykograficznie większe?: " << std::boolalpha  << (q3 > q4 ? true : false )<< std::endl;
    return 0;
}