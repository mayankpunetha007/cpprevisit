//
// Created by Mayank Punetha on 2019-09-15.
//

//
// Created by Mayank Punetha on 2019-09-15.
//


#include "Regression.h"
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iostream>

using namespace CFA_level_2::quant;
using namespace boost;

void testLinear(){
    std::cout<<"Started";
    cpp_dec_float_50 data[11] = {1,2,3,4,5,6,6,7,8,9,10};
    Linear l =  Linear(data);
    std::cout<<l.mean();
    std::cout<<l.mode();
    std::cout<<l.median();
}

int main(){
    testLinear();
    return 0;
}



