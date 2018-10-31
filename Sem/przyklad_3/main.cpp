//Własny kontener

#include <iostream>
#include <memory>

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

    int size() const { return _size; }

    friend std::ostream &operator<<(std::ostream & o, NewContainer &n){
        for(int i=0; i<n._size; ++i)
            o << n._values[i] << " ";
        o << std::endl;
        return o;
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

    std::cout<< "Elementy: " <<std::endl<<n<<"Rozmiar: "<<n.size()<<std::endl ;

    std::cout<< "--Usunięcie elementu--"<<std::endl ;
    n.earse();
    std::cout<< "Elementy: " <<std::endl<<n<<"Rozmiar: "<<n.size()<<std::endl ;
    
    
    return 0;
}