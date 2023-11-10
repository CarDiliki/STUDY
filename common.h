//
// Created by 11657 on 2023/11/7.
//

#ifndef STUDY4MYSELF_COMMON_H
#define STUDY4MYSELF_COMMON_H
#include <sstream>
#include "include/Valid Anagram.h"
#include "include/IntersectionOfTwoArrays.h"
#include "include/TwoSum.h"



//template function are more convenient and can handle various situations
template<typename Input, typename Output, typename Delimiter>
void splitString(const Input& input, Output& output, const Delimiter& delimiter){
    stringstream ss(input);
    string item;
    while(getline(ss, item, delimiter)){
        //istringstream can continuously extract different types from strings
        // converter >> (int)a >> (double)b >> (string)c ...
        istringstream converter(item);
        //template function define the container type value like this
        typename Output::value_type value;
        converter >> value;
        output.push_back(value);
    }
}




#endif //STUDY4MYSELF_COMMON_H
