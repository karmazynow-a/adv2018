//Prosty iterator

#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec = {3, 1, 4, 1, 5};
    for (std::vector<int>::iterator it=vec.begin(); it<vec.end(); ++it)
        std::cout<<*it<<" ";
    
    return 0;
}