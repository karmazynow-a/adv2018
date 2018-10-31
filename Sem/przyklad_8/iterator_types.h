#pragma once

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
