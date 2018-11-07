//Definiowanie własnego iteratora

#include <iostream>
#include <iterator>

template<typename T>
class my_iterator: public std::iterator<std::random_access_iterator_tag, T>{
public:
    typedef my_iterator<T>  iterator;
    typedef T* pointer;

    my_iterator( pointer ptr = nullptr) : _data(ptr){
        std::cout << "tworzenie iteratora" << std::endl;
    }

    T operator*(){
        return *_data;
    }
    
private:
   pointer _data;
};


int main(){
    int arr[] = {1, 2, 3, 4};

    my_iterator<int> it (arr);
    for (; *it < arr + 4; ++it)
        std::cout << *it << " ";

    
    return 0;
}
