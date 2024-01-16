//
// Created by 11657 on 2023/11/8.
//

#ifndef STUDY_INTERSECTIONOFTWOARRAYS_H
#define STUDY_INTERSECTIONOFTWOARRAYS_H
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class IntersectionOfTwoArrays{
public:
    IntersectionOfTwoArrays(vector<int>& nums1, vector<int>& nums2)
    :nums_a(nums1)
    ,nums_b(nums2)
    {};

    ~IntersectionOfTwoArrays(){};

    vector<int> intersection(){
        unordered_set<int> target(nums_a.begin(), nums_a.end());
        unordered_set<int> result;
        for(auto &it : nums_b){
            if(target.find(it) != target.end()){
                result.insert(it);
            }
        }
        return vector<int>(result.begin(), result.end());
    };

private:
    vector<int> nums_a, nums_b;
};


#endif //STUDY_INTERSECTIONOFTWOARRAYS_H
