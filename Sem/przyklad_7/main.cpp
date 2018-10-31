//Cechy iteratora

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>

template <typename T>
void fun_helper (T &it, std::random_access_iterator_tag){
    std::cout<<"random access iterator tag"<<std::endl;
}

template <typename T>
void fun_helper (T &it, std::bidirectional_iterator_tag){
    std::cout<<"bidirectional iterator tag"<<std::endl;
}


template <typename T>
void fun_helper (T &it, std::forward_iterator_tag){
    std::cout<<"forward iterator tag"<<std::endl;
}


template <typename T>
void fun_helper (T &it, std::input_iterator_tag){
    std::cout<<"input iterator tag"<<std::endl;
}


template <typename T>
void fun_helper (T &it, std::output_iterator_tag){
    std::cout<<"output iterator tag"<<std::endl;
}

template <typename T>
void fun (T it){
    fun_helper(it, typename std::iterator_traits<T>::iterator_category());
}

int main(){

    fun(std::vector<int>::iterator());
    fun(std::list<float>::iterator());
    fun(std::forward_list<char>::iterator());
    fun(std::istream_iterator<unsigned>());
    fun(std::ostream_iterator<int>(std::cout));

    return 0;
}
