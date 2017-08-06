#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits){
        vector<string> results;
        if(digits.size() == 0)  return results;
        const string digitCharTable[] = {"", 
            "",     "abc",  "def", 
            "ghi",  "jkl",  "mno",
            "pqrs", "tuv",  "wxyz"};
        stringstream sstream;
        sstream << digits;
        int digitsInt;
        sstream >> digitsInt;
        int digitTable[8];
        int digitCount = 0;
        while(digitsInt != 0){
            digitTable[digitCount++] = digitsInt % 10;
            digitsInt = digitsInt / 10;
        }
        for(int digitIndex=digitCount-1; digitIndex>=0; digitIndex--){
            if(results.size() == 0){
                for(int i=0; i<(int)digitCharTable[digitTable[digitIndex]].size(); i++){
                    // cout << digitCharTable[digitTable[digitIndex]][i] << endl;
                    string tmp = "";
                    tmp += digitCharTable[digitTable[digitIndex]][i];
                    results.push_back(tmp);
                }
            } else {
                vector<string> tmp;
                for(int i=0; i<(int)digitCharTable[digitTable[digitIndex]].size(); i++){
                    for(int j=0; j<(int)results.size(); j++)
                        tmp.push_back(results[j] + digitCharTable[digitTable[digitIndex]][i]);
                }
                results = tmp;
            }
            for(string a : results)
                cout << a << endl;
        }
        cout << "-------" << endl;
        return results;
    }
};

int main()
{
    Solution solution = Solution();
    string digits = "23";

    vector<string> results = solution.letterCombinations(digits);
    for(string a : results)
        cout << a << endl;
}
