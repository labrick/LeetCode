#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){ 
        long longestNum = 0, subStrNum = 0;
        string subString;
        for(char a : s){
            int charIndex = subString.find(a);
            if(subString.find(a) != string::npos){
                longestNum = max(longestNum, subStrNum);
                // subString.erase(0, charIndex+1);
                subString.erase(subString.begin(), (string::iterator)&subString[charIndex+1]);
                subStrNum -= (charIndex+1);
            }
            subString += a;
            subStrNum += 1;
        }
        longestNum = max(longestNum, subStrNum);
        return longestNum;
    }
};

int main()
{
    Solution solution = Solution();
    string str = "abcabcbb";

    int longestNum = solution.lengthOfLongestSubstring(str);
    cout << longestNum << endl;
}
