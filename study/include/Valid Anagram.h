//
// Created by 11657 on 2023/11/7.
//

#ifndef STUDY4MYSELF_VALID_ANAGRAM_H
#define STUDY4MYSELF_VALID_ANAGRAM_H
#include <iostream>
#include <string>
using namespace std;

class ValidAnagram{
public:
    ValidAnagram(const string a, const string b)
    :word_a(a)
    ,word_b(b)
    {};

    ~ ValidAnagram(){};

    bool isValidAnagram(){
        int record[26] = {0};
        for(auto &it : word_a){
            record[it - 'a']++;
        }
        for(auto &it : word_b){
            record[it - 'a']--;
        }
        for(auto &it : record){
            if(0 != it){
                return false;
            }
        }
        return true;
    };


private:
    const string word_a;
    const string word_b;
};

#endif //STUDY4MYSELF_VALID_ANAGRAM_H
