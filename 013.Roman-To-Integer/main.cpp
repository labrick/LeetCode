#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s){   // O(n^2)
        const int TABLE_LEN = 25;
        string romanCharTable[TABLE_LEN] = {
        // 1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,    1 
            "m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "MX", "v", "Mv",
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
        };
        int romanTable[TABLE_LEN] = {
            1000000, 900000, 500000, 400000, 100000, 90000, 50000, 40000, 10000, 9000, 5000, 4000,
            1000,    900,    500,    400,    100,    90,    50,    40,    10,    9,    5,    4,    1
        };
        int result = 0;
        for(int i=0; i<TABLE_LEN; i++){
            int romanCharLen = romanCharTable[i].length();
            while(s.substr(0, romanCharLen) == romanCharTable[i]){
                result += romanTable[i];
                cout << result << endl;
                s = s.substr(romanCharLen, s.length()-romanCharLen);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    string romanStr = "MMMCCCXXXIII";

    int romanInt = solution.romanToInt(romanStr);
    cout << romanInt << endl;
}
