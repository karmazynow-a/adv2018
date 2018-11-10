/*
Zadanie polega na napisaniu kontenera, który pozwala na wywołanie metod w funkcji main, czyli:
insert - dodającej element, size - zwracającej rozmiar, empty - zwracającej czy kontener jest pusty, 
clear - usuwający wszystkie elementy, swap - zamieniającej zawartości dwóch zbiorów

Do realizacji nie można użyć żadnego kontenera, ani funkcji new i delete - należy posługiwać się std::allocator, także przy inicjalizacji
Pamięć może być zorganizowana w spobób ciągły lub nie - wedle preferencji
Należy pamiętać o definiowaniu typów składowych i używaniu ich 
*/

#include <iostream>
#include "MySet.h"

int main(void){

    MySet<int> s;
    s.insert(4).insert(5).insert(6).insert(1).insert(2).insert(4);
    std::cout<< "Zbiór 1: ";
    std::cout << s << std::endl;
    std::cout << "Rozmiar: " << s.size() << std::endl<< std::endl;

    MySet<char, std::greater<char>> s2;
    std::cout<< "Zbiór 2: ";
    s2.insert('c').insert('a').insert('z').insert('m');
    std::cout << s2 << std::endl;

    std::cout<< "Czy zbiór 2 jest pusty? " << std::boolalpha << s2.empty()<< std::endl << std::endl;

    MySet<int> s3 = s, s4;
    s4 = s;

    std::cout << "Usuwanie za pomocą earse: "<<std::endl;
    for (int i=1; i<=6; ++i){
        s.earse(i);
        std::cout<<s;
    }

    std::cout<< "Czy zbiór 1 jest pusty? " << std::boolalpha << s.empty() << std::endl << std::endl;

    std::cout<<"Zbiór 3: "<<std::endl;
    std::cout << s3 << std::endl;

    std::cout<<"Zbiór 4: "<<std::endl;
    std::cout << s4 << std::endl;

    s4.clear();
    s4.insert(10).insert(20).insert(30);
    
    std::cout<< "Zamiana zbiorów " << std::endl;
    std::cout<< "Zbiór 3: ";
    std::cout << s3 << std::endl;
    std::cout<< "Zbiór 4: ";
    std::cout << s4 << std::endl;

    s3.swap(s4);

    std::cout<< "Po zamianie: " << std::endl;
    std::cout<< "Zbiór 3: ";
    std::cout << s3 << std::endl;
    std::cout<< "Zbiór 4: ";
    std::cout << s4 << std::endl;

    return 0;
}

/*
Zbiór 1: 1 2 4 5 6 

Rozmiar: 5

Zbiór 2: z m c a 

Czy zbiór 2 jest pusty? false

Usuwanie za pomocą earse: 
2 4 5 6 
4 5 6 
4 5 6 
5 6 
6 

Czy zbiór 1 jest pusty? true

Zbiór 3: 
1 2 4 5 6 

Zbiór 4: 
1 2 4 5 6 

Zamiana zbiorów 
Zbiór 3: 1 2 4 5 6 

Zbiór 4: 10 20 30 

Po zamianie: 
Zbiór 3: 10 20 30 

Zbiór 4: 1 2 4 5 6
*/