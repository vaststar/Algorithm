#include <iostream>
#include <vector>
#include <algorithm>
#include "include/Sort.hpp"

void main(){
    std::vector<int> test={2,1,8,7,9,10,15,12};
    // Sort::quickSort<int>(test);
    // Sort::mergeSort<int>(test);
    Sort::heapSort<int>(test);
    std::for_each(test.begin(),test.end(),[](int i){
        std::cout<<i<<" ";
    });    
}