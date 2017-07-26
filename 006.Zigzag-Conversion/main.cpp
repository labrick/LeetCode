#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strMatrix;
        string result = "";
        int sIndex = 0, columnIndex = 0;

        if(numRows == 1)    return s;
        for(int i=0; i<numRows; i++){
            strMatrix.push_back("");
        }
        while(sIndex < (int)s.length()){
            if((columnIndex % (numRows-1)) == 0){
                for(int i=0; i<numRows; i++){
                    strMatrix[i] += s[sIndex++];
                    if(sIndex >= (int)s.length())
                        break;
                }
            } else
                strMatrix[numRows-1 - (columnIndex % (numRows-1))] += s[sIndex++];
            columnIndex++;

        }
        for(int i=0; i<numRows; i++){
            result += strMatrix[i];
            cout << i << ": " <<strMatrix[i] << endl;
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    string str = "ABCDE";//"PAYPALISHIRING";

    string substring = solution.convert(str, 4);
    cout <<  substring << endl;
}
