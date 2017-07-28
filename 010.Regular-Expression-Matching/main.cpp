#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p){
        int sIndex = 0, pIndex = 0;
        char preChar;
        while(sIndex != (int)s.length() && pIndex != (int)p.length()){
            cout << "sIndex: " << sIndex << "\tpIndex: " << pIndex << endl;
            if(p[pIndex] == '*'){
                if(p[pIndex-1] == '.'){         // *前是.，前一字符为任意字符
                    // 匹配任意多个任意字符
                    if(pIndex+1 == (int)p.length()) {   // .*直接匹配完成
                        return true;
                    } else {
                        do{
                            pIndex++;
                            cout << pIndex << endl;
                            if(pIndex == (int)p.length())     // .*直接匹配完成
                                return true;
                        } while(p[pIndex] == '.' || p[pIndex] == '*');
                    }
                    // .*后面还有字符
                    while(s[sIndex+1] != p[pIndex]){
                        sIndex++;
                        if(sIndex == (int)s.length())   break;
                    }
                    preChar = p[pIndex];
                    continue;
                }else if(p[pIndex-1] != '*'){   // *前是字符
                    preChar = p[pIndex-1];
                }                               // *前是*，preChar不变
                cout << "preChar: " << preChar << endl;
                while(s[sIndex] == preChar){
                    sIndex++;
                    if(sIndex == (int)s.length())   break;
                }
            }else if(p[pIndex] == '.'){
                sIndex++;
            }else{
                if(p[pIndex+1] != '*'){           // 字符后是*交给*处理
                    if(p[pIndex] == s[sIndex]){
                        sIndex++;
                    }else{
                        return false;
                    }
                }
            }
            pIndex++;
        }
        if(sIndex == (int)s.length() && pIndex != (int)p.length()){
            cout << "sIndex: " << sIndex << "\tpIndex: " << pIndex << endl;
            if(p[pIndex-1] == '*' && p[pIndex] == s[s.length()-1]){
                return true;
            }else{
                return false;
            }
            while(pIndex != (int)p.length()){
                if(p[pIndex] != '*' && p[pIndex] != s[s.length()-1])
                    return false;
                pIndex++;
            }
            return true;
        }else if(sIndex != (int)s.length() && pIndex == (int)p.length()){
            return false;
        }else
            return true;
    }
};

int main()
{
    Solution solution = Solution();
    string str = "aaa";
    string regex = "ab*a*c*a";

    bool isMatch = solution.isMatch(str, regex);
    cout << isMatch << endl;
}
