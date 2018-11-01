//Adaptery iteratora
#include <iostream>
#include <iterator>
#include <list>
#include <deque>
#include <algorithm> //copy
#include <memory>
#include <cstring> //memset

int main(){
    std::cout<<std::endl<< "---Użycie reverse_iterator---"<<std::endl<<std::endl;

    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int>::iterator fi = l.begin();
    for (; fi != l.end(); ++fi)
        std::cout << *fi << " ";
    std::cout<<std::endl;

    std::reverse_iterator<std::list<int>::iterator> ri = l.rbegin();
    for (; ri != l.rend(); ++ri)
        std::cout << *ri << " ";
    std::cout<<std::endl;

    std::cout<<std::endl<< "---Użycie insert_iterator---"<<std::endl<<std::endl;

    std::deque<int> fd;
    std::deque<int> bd;

    std::copy (l.begin(), l.end(), std::front_insert_iterator<std::deque<int>>(fd)); //kolejne elementy beda wstawiane na początku
    std::copy (l.begin(), l.end(), std::back_insert_iterator<std::deque<int>>(bd)); //kolejne elementy beda wstawiane na końcu

    std::cout<<"------Wstawianie na początku---"<<std::endl;
    for (auto i : fd)
        std::cout<< i << " ";
    std::cout<<std::endl;

    std::cout<<"------Wstawianie na końcu---"<<std::endl;
    for (auto i : bd)
        std::cout<< i << " ";
    std::cout<<std::endl;

    std::cout<<std::endl<< "---Użycie move_iterator---"<<std::endl<<std::endl;
    std::list<int> ml(5); //określona wielkość

    std::cout<<"------Zawartość l---"<<std::endl;
    for (auto i : l)
        std::cout<< i << " ";
    std::cout<<std::endl;

    std::copy (std::move_iterator<std::list<int>::iterator>(l.begin()), std::move_iterator<std::list<int>::iterator>(l.end()), ml.begin() );

    l.clear(); //w l znajdują się teraz śmieci, zawartość została przeniesiona do ml, tyle ile sie zmieściło
    
    std::cout<<std::endl;
    std::cout<<"------Zawartość ml---"<<std::endl;
    for (auto i : ml)
        std::cout<< i << " ";
    std::cout<<std::endl;


    return 0;
}
