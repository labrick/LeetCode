#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalidrome(string str){
        int startIndex = 0, endIndex = str.length()-1;
        while(startIndex < endIndex){   // 单字符直接为true
            if(str[startIndex++] != str[endIndex--])
                return false;
        }
        return true;
    }
    // brute force n^3
    string longestPalindrome(string s){
        int start = 0, end = s.length();
        string longestPalindrome = s.substr(0, 1);
        if(end == 1)    return s;
        while(start != (int)s.length()){
            end = s.find_last_of(s[start], end-1);
            cout << "end: " << end << endl;
            if(end <= start){    // 单字符直接进行判断
                start++;
                end = s.length();
                continue;
            }
            string subStr = s.substr(start, end+1-start);
            if((longestPalindrome.size() < subStr.size()) && isPalidrome(subStr)){
                longestPalindrome = subStr;
            }
        }
        return longestPalindrome;
    }
};

int main()
{
    Solution solution = Solution();
    string str = "ddddddddddddd";// "babadada";   // c, abc, cbbd, babad

    string substring = solution.longestPalindrome(str);
    cout <<  substring << endl;
}
