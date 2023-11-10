#include "common.h"


//2023/11/8
//242.Valid anagram
//use your brain, don't just think of violent solutions!!!!!
void validAnagram(){
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
//when the range of value is limited, there is no need to use 'set'.
//set占用空间比数组大，且速度更慢，set把数值映射到key上都要做hash计算的
//'set' takes up more space than arrays and is slower
//'set' has to do hash calculations when mapping values to key
void intersectionOfTwoArrays(){
    vector<int> nums_a, nums_b, result;
    string temp1, temp2;
    cout << "please enter the first array , separated by ',' : ";
    cin >> temp1;
    cout << "please enter the second array , separated by ',' : ";
    cin >> temp2;
    splitString(temp1, nums_a, ',');
    splitString(temp2, nums_b, ',');
    result = IntersectionOfTwoArrays(nums_a, nums_b).intersection();
    for(auto &it : result){
        cout << it << " ";
    }
}

//2023/11/9
//1.Two Sum
void twoSum(){
    vector<int> nums_a;
    string temp1;
    int target;
    cout << "please enter the first array , separated by ',' : ";
    cin >> temp1;
    cout << "please enter the target : ";
    cin >> target;
    splitString(temp1, nums_a, ',');
    TwoSum(nums_a, target).twoSum();
}





int main() {

//    validAnagram();
//    intersectionOfTwoArrays();
//    twoSum();


    return 0;
}
