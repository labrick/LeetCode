#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num){   // O(n^2)
        const int TABLE_LEN = 25;
        string romanCharTable[TABLE_LEN] = {
        // 1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,    1 
            "m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "Mx", "v", "Mv",
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
        };
        int romanTable[TABLE_LEN] = {
            1000000, 900000, 500000, 400000, 100000, 90000, 50000, 40000, 10000, 9000, 5000, 4000,
            1000,    900,    500,    400,    100,    90,    50,    40,    10,    9,    5,    4,    1
        };
        string result;
        for(int i=0; i<TABLE_LEN; i++){
            while(num >= romanTable[i]){
                result += romanCharTable[i];
                cout << result << endl;
                num -= romanTable[i];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    int num = 3333;

    string romanInt = solution.intToRoman(num);
    cout << romanInt << endl;
}
