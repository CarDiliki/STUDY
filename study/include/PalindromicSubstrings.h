//
// Created by uto on 23-11-17.
//

#ifndef STUDY_PALINDROMICSUBSTRINGS_HPP
#define STUDY_PALINDROMICSUBSTRINGS_HPP
#include <string>
#include <vector>
using std::string;
using std::vector;


class PalindromicSubstrings{
public:
    PalindromicSubstrings(string targetString)
    :target_string(targetString)
    {};

    ~PalindromicSubstrings(){};

    int byDynamicProgramming(){
        vector<vector<int>> dp(target_string.size(), vector<int>(target_string.size(), 0));
        int result = 0;

        for(int i = target_string.size() - 1; i >= 0; i--){
            for(int j = i; j < target_string.size(); j++){
                if(target_string[i] == target_string[j]){
                    if(j - i <= 1){
                        dp[i][j] = true;
                        result++;
                    }
                    else if(dp[i + 1][j - 1]){
                        dp[i][j] = true;
                        result++;
                    }
                }
            }
        }
        return result;
    };

    int byDoublePoint(){

    };


private:
    string target_string;
};


#endif //STUDY_PALINDROMICSUBSTRINGS_HPP
