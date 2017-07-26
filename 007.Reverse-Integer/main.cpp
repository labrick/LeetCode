#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        stringstream strstream;
        string str, resultStr = "";
        strstream << x;
        strstream >> str;

        cout << INT_MAX << endl;
        cout << str << endl;
        if(str[0] == '-'){
            resultStr = "-";
            str.erase(0, 1);
        }
        for(int i=(int)(str.length()-1); i>=0; i--) {
            cout << str[i] << " ";
            resultStr += str[i];
            cout << resultStr << endl;
        }

        long result;
        istringstream istr(resultStr);
        istr >> result;
        cout << result << endl;
        if(result < INT_MIN || result > INT_MAX)    result = 0;

        return result;
    }
};

int main()
{
    Solution solution = Solution();
    int num = -2147483648; // 1534236469;

    int result = solution.reverse(num);
    cout <<  result << endl;
}
