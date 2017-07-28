#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isPalidrome(int x){
        string str;
        stringstream strstream;
        strstream << x;
        strstream >> str;
        int startIndex = 0, endIndex = str.length()-1;
        while(startIndex < endIndex){   // 单字符直接为true
            if(str[startIndex++] != str[endIndex--])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution = Solution();
    int num = 1123211;

    bool isPalidrome = solution.isPalidrome(num);
    cout << isPalidrome << endl;
}
