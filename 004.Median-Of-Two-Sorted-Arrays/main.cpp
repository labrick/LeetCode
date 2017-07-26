#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 不允许重复
    double findMedianSortedArray1(vector<int> & nums1, vector<int> & nums2){ 
        set<int> numsSet(nums1.begin(), nums1.end());
        numsSet.insert(nums2.begin(), nums2.end());
        for(int a : numsSet)
            cout << a << "\t";
        cout << endl;

        int setNum = numsSet.size();
        // set不能直接+-迭代器是个问题
        set<int>::iterator ite = numsSet.begin();
        if(setNum % 2){
            for(int i=setNum/2; i>0; i--)   ite++;
            return *ite;
        } else {
            for(int i=setNum/2-1; i>0; i--)   ite++;
            // double num1 = *ite;
            // ite++;
            // double num2 = *ite;
            // cout << num1 << ":" << num2 << endl;
            // return (num1 + num2)/2;
            return (((double)*ite++ + (double)*ite))/2;
        }
    }
    // 允许重复
    double findMedianSortedArray(vector<int> & nums1, vector<int> & nums2){ 
        vector<int> nums(nums1);
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        sort(nums.begin(), nums.end());
        for(int a : nums)
            cout << a << "\t";
        cout << endl;

        int setNum = nums.size();
        if(setNum % 2){
            return *(nums.begin()+setNum/2);
        } else {
            // double num1 = *ite;
            // ite++;
            // double num2 = *ite;
            // cout << num1 << ":" << num2 << endl;
            // return (num1 + num2)/2;
            return ((double)*(nums.begin()+setNum/2-1) + (double)*(nums.begin()+setNum/2))/2;
        }
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4}; 

    double medianNum = solution.findMedianSortedArray(nums1, nums2);
    cout <<  medianNum << endl;
}
