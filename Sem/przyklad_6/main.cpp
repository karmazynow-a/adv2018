//Funkcje pomocnicze

#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int>::iterator it;
    std::vector<int>::iterator it2 = vec.begin();

    std::cout<<"---Zawartość wektora: " <<std::endl;
    for (it=vec.begin(); it<vec.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<std::endl<<std::endl;

    std::cout<<"---Przesunięcie funkcją advance"<<std::endl;
    it = vec.begin();
    advance(it, 3);
    std::cout<< "o 3: "<<*it << std::endl;

    advance(it, 30);
    std::cout<< "o 30: "<<*it << std::endl;
    std::cout<<std::endl;

    std::cout<<"---Wartość funkcji distance"<<std::endl;
    it = vec.begin();
    advance(it, 4);
    std::cout<< distance(it, it2) << std::endl;
    std::cout<< distance(it2, it) << std::endl;
    advance(it, 100);
    std::cout<< distance(it, it2) << std::endl;
    std::cout<<std::endl;

    std::cout<<"---Zamiana iter_swap"<<std::endl;
    it = vec.begin();
    advance(it, 4);
    std::cout <<"wartości przed zamianą: it="<<*it<<" it2="<<*it2<<std::endl;
    iter_swap(it, it2);
    std::cout <<"wartości po zamianie: it="<<*it<<" it2="<<*it2<<std::endl;
    std::cout<<"wartości w wektorze: "<<std::endl;
    for (auto i : vec)
        std::cout<<i<<" ";
    std::cout<<std::endl<<std::endl;
    iter_swap(it, it2);
    

    std::cout<<"---Funkcje next i prev"<<std::endl;
    it = vec.begin();
    advance(it, 4);
    std::cout <<"wartość it przesuniete o 2 do przodu= "<<*next(it, 2)<<std::endl;
    std::cout <<"wartość it przesuniete o 2 do tyłu= "<<*prev(it, 2)<<std::endl;
    std::cout <<"wartość it="<<*it<<std::endl;
    

    
    return 0;
}