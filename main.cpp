#include "common.h"
#include <sstream>


//2023/11/8
//242.Valid anagram
//动脑子，别只想着暴力解决。。。
void valid_anagram(){
    string word_a, word_b;
    cout << "please enter the first string : ";
    cin >> word_a;
    cout << "please enter the second string : ";
    cin >> word_b;
    ValidAnagram(word_a, word_b).isValidAnagram();
}


//2023/11/8
//349.Intersection Of Two Arrays
//在限制了数值范围的情况下就不需要用set
//set占用空间比数组大，且速度更慢，set把数值映射到key上都要做hash计算的
void intersection_ot_two_arrays(){
    vector<int> nums_a, nums_b, result;
    string temp1, temp2;
    cout << "please enter the first array , separated by ',' : ";
    cin >> temp1;
    cout << "please enter the second array , separated by ',' : ";
    cin >> temp2;
    stringstream nums1(temp1), nums2(temp2);
    string a, b;
    while (getline(nums1, a, ',')){
        nums_a.push_back(stoi(a));
        a.clear();
    }
    while (getline(nums2, b, ',')){
        nums_b.push_back(stoi(b));
        b.clear();
    }
    result = IntersectionOfTwoArrays(nums_a, nums_b).intersection();
    for(auto &it : result){
        cout << it << " ";
    }
}

void two_sum(){
    vector<int> nums_a;
    string temp1;
    int target;
    cout << "please enter the first array , separated by ',' : ";
    cin >> temp1;
    cout << "please enter the target : ";
    cin >> target;
    stringstream nums1(temp1);
    string a;
    while (getline(nums1, a, ',')){
        nums_a.push_back(stoi(a));
        a.clear();
    }
    TwoSum(nums_a, target).twoSum();
}





int main() {

//    valid_anagram();
//    intersection_ot_two_arrays();
    two_sum();

    return 0;
}
