#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.size() == 0)    return "";
        int preStrLen = strs[0].size();
        for(int i=0; i<(int)strs.size()-1; i++){
            int strIndex = 0;
            while(strs[i][strIndex] == strs[i+1][strIndex]){
                strIndex++;
                cout << strIndex << endl;
                if(strIndex >= min((int)strs[i].length(), (int)strs[i+1].length()))
                    break;
            }
            cout << "i: " << i;
            cout << "\tpreStrLen: " << preStrLen << "\tstrIndex: " << strIndex << endl;
            preStrLen = min(preStrLen, strIndex);
        }

        return strs[0].substr(0, preStrLen);
    }
};

int main()
{
    Solution solution = Solution();
    vector<string> str = {"abca", "abc"};

    string longestPrefix = solution.longestCommonPrefix(str);
    cout << longestPrefix << endl;
}
