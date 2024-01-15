//#include "common.h"
//
//
////2023/11/8
////242.Valid anagram
////use your brain, don't just think of violent solutions!!!!!
//void validAnagram(){
//    string word_a, word_b;
//    cout << "please enter the first string : ";
//    cin >> word_a;
//    cout << "please enter the second string : ";
//    cin >> word_b;
//    ValidAnagram(word_a, word_b).isValidAnagram();
//}
//
//
////2023/11/8
////349.Intersection Of Two Arrays
////when the range of value is limited, there is no need to use 'set'.
////'set' takes up more space than arrays and is slower
////'set' has to do hash calculations when mapping values to key
//void intersectionOfTwoArrays(){
//    vector<int> nums_a, nums_b, result;
//    string temp1, temp2;
//    cout << "please enter the first array , separated by ',' : ";
//    cin >> temp1;
//    cout << "please enter the second array , separated by ',' : ";
//    cin >> temp2;
//    splitString(temp1, nums_a, ',');
//    splitString(temp2, nums_b, ',');
//    result = IntersectionOfTwoArrays(nums_a, nums_b).intersection();
//    for(auto &it : result){
//        cout << it << " ";
//    }
//}
//
////2023/11/9
////1.Two Sum
//void twoSum(){
//    vector<int> nums_a;
//    string temp1;
//    int target;
//    cout << "please enter the first array , separated by ',' : ";
//    cin >> temp1;
//    cout << "please enter the target : ";
//    cin >> target;
//    splitString(temp1, nums_a, ',');
//    TwoSum(nums_a, target).twoSum();
//}
//
//
//
//
//
//int main() {
//
////    validAnagram();
////    intersectionOfTwoArrays();
////    twoSum();
//
//
//    return 0;
//}


#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

// 哈希表的大小
const int HASH_TABLE_SIZE = 10;

// HashEntry 类表示哈希表中的一个键值对
class HashEntry {
public:
    HashEntry(int key, int value) : key(key), value(value) {}

    // 拷贝构造函数
    HashEntry(const HashEntry& other) : key(other.key), value(other.value) {
        std::cout << "Copy Constructor called." << std::endl;
    }

    // 赋值运算符
    HashEntry& operator=(const HashEntry& other) {
        if (this != &other) {  // 避免自赋值
            key = other.key;
            value = other.value;
            std::cout << "Assignment Operator called." << std::endl;
        }
        return *this;
    }

    int getKey() const {
        return key;
    }

    int getValue() const {
        return value;
    }

private:
    int key;
    int value;
};

// HashTable 类表示哈希表
class HashTable {
public:
    HashTable() : table(HASH_TABLE_SIZE) {};

    // 插入键值对
    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->getKey() == key) {
                // 如果键已存在，则更新值
                table[index].erase(it);
                break;
            }
        }
        table[index].push_back(HashEntry(key, value));
    }

    // 获取键对应的值
    int get(int key) const {
        int index = hashFunction(key);
        for (const auto& entry : table[index]) {
            if (entry.getKey() == key) {
                return entry.getValue();
            }
        }
        return -1; // 如果键不存在返回-1
    }

    // 删除键值对
    void remove(int key) {
        int index = hashFunction(key);
        auto& bucket = table[index];
        // 使用 erase 结合 std::remove_if 删除匹配的元素
        bucket.erase(std::remove_if(bucket.begin(), bucket.end(), [key] (const auto& entry) {
            return entry.getKey() == key;
        }), bucket.end());
    }



private:
    // 哈希函数，简单地取余
    int hashFunction(int key) const {
        return key % HASH_TABLE_SIZE;
    }

    // 使用链表实现每个桶
    std::vector<std::list<HashEntry> > table;
};

int main() {
    // 创建哈希表
    HashTable myHashTable;

    // 插入键值对
    myHashTable.insert(1, 10);
    myHashTable.insert(2, 20);
    myHashTable.insert(11, 30);

    // 获取键对应的值
    std::cout << "Value for key 1: " << myHashTable.get(1) << std::endl;
    std::cout << "Value for key 2: " << myHashTable.get(2) << std::endl;
    std::cout << "Value for key 11: " << myHashTable.get(11) << std::endl;
    std::cout << "Value for key 5: " << myHashTable.get(5) << std::endl; // 不存在的键返回-1

    // 删除键值对
    myHashTable.remove(2);

    // 再次获取键对应的值
    std::cout << "Value for key 2 after removal: " << myHashTable.get(2) << std::endl; // 不存在的键返回-1

    return 0;
}
