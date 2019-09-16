
#include "Regression.h"
#include <map>

cpp_dec_float_50 CFA_level_2::quant::Linear::mean(){
    int size = sizeof(this->initial);
    cpp_dec_float_50 meanResult = cpp_dec_float_50(0);
    for(int i=0;i< size;i++){
        meanResult = meanResult + (*(initial+0));
    }
    return meanResult/size;
}

/**
CFA_level_2::quant::Linear::Linear(long double* initial) : initial(initial) {
    int size = sizeof(initial);
    cpp_dec_float_50 *first =  (cpp_dec_float_50 *)malloc(sizeof(cpp_dec_float_50)* size);
    for(int i=0;i<size;i++){
        (*(first+i)) =  cpp_dec_float_50(*(initial +i));
    }
    this->initial = first;
}
**/

cpp_dec_float_50 CFA_level_2::quant::Linear::mode() {
    int size = sizeof(this->initial);
    std::map<cpp_dec_float_50, int > numberCount =  std::map<cpp_dec_float_50, int >();
    for(int i=0;i<size;i++) {
        numberCount[*(this->initial+i)]+=1;
    }
    cpp_dec_float_50 mode = -1;
    int max =-1;
    for(std::map<cpp_dec_float_50, int>::iterator it = numberCount.begin();it != numberCount.end(); it++){
        if(it->second > max){
            mode = it->first;
        }
    }
    return mode;
}

cpp_dec_float_50 CFA_level_2::quant::Linear::median() {
    int size = sizeof(this->initial);
    std::sort(this->initial, this->initial+size);
    if(size %2 != 0){
        return (*(this->initial+(size/2))) + (*(this->initial+(size/2)-1));
    }
    return (*(this->initial+(size/2)));
}

CFA_level_2::quant::Linear CFA_level_2::quant::Linear::operator+(Linear to) {
    cpp_dec_float_50* all;
    memccpy(this->initial, all, sizeof(cpp_dec_float_50), sizeof(this->initial));
    int size = sizeof(this->initial);
    for(int i=0;i<size;i++){
        (*(all+i)) = (*(to.initial+i)) + (*(this->initial+i));
    }
    return CFA_level_2::quant::Linear(all);
}

CFA_level_2::quant::Linear CFA_level_2::quant::Linear::operator*(Linear to) {
    cpp_dec_float_50* all;
    memccpy(this->initial, all, sizeof(cpp_dec_float_50), sizeof(this->initial));
    int size = sizeof(this->initial);
    for(int i=0;i<size;i++){
        (*(all+i)) = (*(to.initial+i)) * (*(this->initial+i));
    }
    return CFA_level_2::quant::Linear(all);
}

CFA_level_2::quant::Linear CFA_level_2::quant::Linear::operator-(Linear to) {
    cpp_dec_float_50* all;
    memccpy(this->initial, all, sizeof(cpp_dec_float_50), sizeof(this->initial));
    int size = sizeof(this->initial);
    for(int i=0;i<size;i++){
        (*(all+i)) = (*(to.initial+i)) - (*(this->initial+i));
    }
    return CFA_level_2::quant::Linear(all);
}

CFA_level_2::quant::Linear CFA_level_2::quant::Linear::operator/(Linear to) {
    cpp_dec_float_50* all;
    memccpy(this->initial, all, sizeof(cpp_dec_float_50), sizeof(this->initial));
    int size = sizeof(this->initial);
    for(int i=0;i<size;i++){
        (*(all+i)) = (*(to.initial+i)) / (*(this->initial+i));
    }
    return CFA_level_2::quant::Linear(all);
}