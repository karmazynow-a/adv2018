//Użycie mapy

#include <iostream>
#include <map>

int main(){
    std::map<std::string, int> m;

    m["pierwszy"] = 10;
    m.insert(std::pair<std::string, int>("drugi", 20));

    for (auto i : m)
        std::cout << i.first << " " << i.second << std::endl;

    std::cout << "Odwołanie się do wartości, której nie ma w mapie przez operator[]: " << m["trzeci"] << std::endl;
    //std::cout << "Odwołanie się do wartości, której nie ma w mapie przez metodę at(): " << m.at("czwarty") << std::endl;
    
    return 0;
}