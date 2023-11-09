//
// Created by uto on 23-11-9.
//

#ifndef STUDY_TWOSUM_H
#define STUDY_TWOSUM_H
#include <vector>
#include <unordered_map>
#include <iterator>

using std::vector;
using std::unordered_map;

class TwoSum{
public:
    TwoSum(vector<int>& nums, int target)
    :_nums(nums)
    ,_target(target)
    {};

    vector<int> twoSum(){
        unordered_map<int, int> map;
        int value = 0;
        for(auto &it : _nums){
            map.emplace(it, value);
            value++;
        }
        value = 0;
        for(auto &it : _nums){
            auto iter = map.find(_target - it);
            if(iter != map.end() && iter->second != value)
                return vector<int>(iter->second, value);
            value++;
        }
        return { };
    };


private:
    vector<int> _nums;
    int _target;
};

#endif //STUDY_TWOSUM_H
