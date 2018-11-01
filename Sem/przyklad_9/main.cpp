//Definiowanie własnego iteratora

#include <iostream>
#include <iterator>
#include <memory>
#include "iterator_types.h"

template <
    typename T, 
    typename Allocator = std::allocator<T> 
    >
class NewContainer{
public:

    typedef Allocator allocator_type;
    typedef typename Allocator::value_type value_type; 
    typedef typename Allocator::reference reference;
    typedef typename Allocator::const_reference const_reference;
    typedef typename Allocator::difference_type difference_type;
    typedef typename Allocator::size_type size_type;

    class iterator{
    public:
        typedef iterator self_type;
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef T difference_type;
        typedef T& reference;
        typedef T* pointer;

        iterator(pointer ptr) : _ptr(ptr) { }

        self_type operator++(){ 
            self_type tmp = *this; 
            ++_ptr; 
            return tmp; 
        }

        self_type operator++(int) { 
            ++_ptr; 
            return *this; 
        }

        bool operator==(const self_type& rhs) { 
            return _ptr == rhs._ptr; 
        }

        bool operator!=(const self_type& rhs) { 
            return _ptr != rhs._ptr; 
        }

        reference operator*() { 
            return *_ptr; 
        }

        reference operator[](const int index) { 
            return *(_ptr + index); 
        }

        iterator operator+(const int index) { 
            return _ptr + index; 
        }

        pointer operator->() { 
            return _ptr; 
        }

    private:
        pointer _ptr;
    };

    NewContainer(int capacity): _size(0){
        _alloc = allocator_type();
        _capacity = capacity;
        _values = _alloc.allocate(_capacity);

    }

    ~NewContainer() {
        _alloc.deallocate(_values, _capacity);
    }

    void insert(T newValue) {
        if (_size < _capacity){
            _values[_size] = newValue;
            ++_size;
        }
    }

    void earse() {
        if (_size > 0){
            --_size;
            _values[_size] = 0;
        }
    }

    int size() const { 
        return _size; 
    }

    friend std::ostream &operator<<(std::ostream & o, NewContainer &n){
        for(int i=0; i<n._size; ++i)
            o << n._values[i] << " ";
        o << std::endl;
        return o;
    }

    iterator begin(){
        return iterator(_values);
    }

    iterator end(){
        return iterator(_values + _size);
    }

private:
    T* _values;
    unsigned int _size;
    unsigned int _capacity;
    Allocator _alloc;
};


int main(){

    NewContainer<int> n (5);
    n.insert(3);
    n.insert(5);
    n.insert(2);
    n.insert(8);
    n.insert(9);
    n.insert(1);

    std::cout<< "Elementy: " <<std::endl<<n<<"Rozmiar: "<<n.size()<<std::endl ;

    std::cout<<std::endl<< "--Usunięcie elementu--"<<std::endl ;
    n.earse();
    std::cout<< "Elementy: " <<std::endl<<n<<"Rozmiar: "<<n.size()<<std::endl ;

    std::cout<<std::endl<< "--Użycie iteratora--"<<std::endl ;

    NewContainer<int>::iterator it = n.begin();

    for (; it != n.end(); ++it)
        *it += 1;

    std::cout<< "Elementy: " <<std::endl<<n<<std::endl ;

    std::cout<<std::endl<< "--Użycie iteratora swobodnego dostępu--"<<std::endl ;

    it = n.begin();
    it = it + 2;

    std::cout << *it <<std::endl;

    std::cout<<std::endl<< "--Rozpoznanie typu iteratora--"<<std::endl ;
    fun(it);
    
    return 0;
}
