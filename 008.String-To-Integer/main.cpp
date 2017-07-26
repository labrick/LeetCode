#include <iostream>
#include <string>
#include <climits>
#include <sstream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long result;
        if(str.length() == 0)   return 0;   // 没有这句话，提交竟然不成功
        istringstream istr(str);

        cout << "INT_MIN: " << INT_MIN << endl;
        cout << "INT_MAX: " << INT_MAX << endl;
        istr >> result;
        cout << result << endl;
        if(result < INT_MIN)    result = INT_MIN;
        if(result > INT_MAX)    result = INT_MAX;

        return result;
    }
};

int main()
{
    Solution solution = Solution();
    // string str = "9646324351";    // "1534236469";  // "-2147483648"; 
    string str = "";

    int result = solution.myAtoi(str);
    cout <<  result << endl;
}
