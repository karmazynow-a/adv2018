//Własny Adaptor

#include <iostream>
#include <vector>
#include <deque>

template<
    class T,
    class Container = std::vector<T>
    > 
class SuperVector{
public:
    void push_back(T newItem) {
        std::cout<<"Dodajemy element: " << newItem << std::endl;
        c.push_back(newItem);
        }

    void pop_back() {
        std::cout<<"Usuwamy ostatni element" << std::endl;
        c.pop_back();
        }

    unsigned int size() {return c.size();}
    bool empty() {return c.empty();}

    friend std::ostream &operator<<(std::ostream & o, SuperVector &v){
        for(int i=0; i<v.size(); ++i)
            o << v.c[i] << " ";
        o << std::endl;
        return o;
    }

private:
    Container c;
};

int main(){
    std::cout << "Kontener oparty o wektor:" <<std::endl;
    SuperVector <int> vec;
    vec.push_back(1);
    vec.push_back(2);

    std::cout<<vec;

    std::cout << "Kontener oparty o kolejke:" <<std::endl;
    SuperVector <int, std::deque<int>> deq;
    deq.push_back(3);
    deq.push_back(4);

    std::cout<<deq;
    
    return 0;
}