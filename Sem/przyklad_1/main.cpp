//Kontenery asocjacyjne versus sekwancyjne i uporządkowane versus nieuporządkowane
//Wektor przechowuje zgodnie z kolejnością dodania, zbiory zgodnie z zasadami sortowania

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>

int main(){
    std::vector<std::string> vec;
    std::set<std::string> s;
    std::unordered_set<std::string> us;

    vec.push_back("pierwszy");
    vec.push_back("drugi");
    vec.push_back("trzeci");
    vec.push_back("czwarty");

    s.insert("pierwszy");
    s.insert("drugi");
    s.insert("trzeci");
    s.insert("czwarty");

    us.insert("pierwszy");
    us.insert("drugi");
    us.insert("trzeci");
    us.insert("czwarty");

    std::cout<<std::endl<< "Elementy wektora: "<<std::endl;
    for (auto i : vec)
        std::cout<<i<<std::endl;

    std::cout<<std::endl<< "Elementy zbioru: "<<std::endl;
    for (auto i : s)
        std::cout<<i<<std::endl;

    std::cout<<std::endl<< "Elementy nieuporządkowanego zbioru: "<<std::endl;
    for (auto i : us)
        std::cout<<i<<std::endl;

    return 0;
}