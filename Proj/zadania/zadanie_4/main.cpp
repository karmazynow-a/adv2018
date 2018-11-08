/*
Proszę dopisać do kontenera z zadania 1 iteator w wersji normalniej i const
Powinien spełniać on wymogi iteratora dla kontenera zbiór
*/

#include <iostream>
#include "MySet.h"

int main(void){

    MySet<int> s;
    s.insert(4).insert(5).insert(6).insert(1).insert(2);
    MySet<int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it)
        std::cout << *it << " ";
    std::cout<<std::endl;

    --it;
    for (;!(it == s.begin()--); it--)
        std::cout<< *it << " ";
    std::cout<<std::endl;

    MySet<char> s2;
    s2.insert('c').insert('o').insert('n').insert('s').insert('t');
    for (MySet<char>::const_iterator it2 = s2.cbegin(); it2 != s2.cend(); ++it2)
            std::cout << *it2 << " ";
    std::cout<<std::endl;
    
    return 0;
}

/*
1 2 4 5 6 
6 5 4 2 1 
c n o s t
*/