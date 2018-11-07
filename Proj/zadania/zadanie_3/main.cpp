/*
Proszę napisać funckję pomocniczą działającą jak funkcja distance
*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>
#include "MyDistance.h"


int main(void){
    std::vector<int> v = {1, 2, 3, 4};
    std::cout << adv::distance(v.begin(), v.end()) << std::endl;

    std::list<int> l = {1, 2, 3, 4};
    std::cout << adv::distance(l.begin(), l.end()) << std::endl;

    std::forward_list<int> fl = {1, 2, 3, 4};
    std::cout << adv::distance(fl.begin(), fl.end()) << std::endl;    

    return 0;
}
/*
random access iterator tag
4
bidirectional iterator tag
4
forward iterator tag
4
*/
