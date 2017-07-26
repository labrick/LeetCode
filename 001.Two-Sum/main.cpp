#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    // 遍历法 166ms
    vector<int> twoSum1(vector<int>& nums, int target) {
        for(int i=0; i<(int)nums.size(); i++){
            for(int j=i+1; j<(int)nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    // vector<int> results {i, j};
                    // results.push_back(i);
                    // results.push_back(j);
                    return vector<int> {i, j};
                }
            }
        }
        return vector<int> {0, 0};
    }

    // 查找法find 146ms
    vector<int> twoSum2(vector<int> & nums, int target){
        for(int i=0; i<(int)nums.size(); i++){
            vector<int>::iterator ite = find(nums.begin(), nums.end(), (target-nums[i]));
            int indexTwo;
            if(ite == nums.end())
                continue;
            indexTwo =  ite - nums.begin();
            if(indexTwo != i)
                return vector<int> {i, indexTwo};
        }
        return vector<int> {0, 0};
    }

    // 查找法map map的find那么快 9ms
    vector<int> twoSum3(vector<int> & nums, int target){
        map<int, int> numsMap;
        for(int i=0; i<(int)nums.size(); i++){
            numsMap.insert(pair<int, int>(nums[i], i));
        }
        for(int i=0; i<(int)nums.size(); i++){
            map<int, int>::iterator ite = numsMap.find(target-nums[i]);
            if(ite == numsMap.end())
                continue;
            if(ite->second != i)
                return vector<int> {i, ite->second};
        }
        return vector<int> {0, 0};
    }
    // 查找map改进，基本没变化 9ms
    vector<int> twoSum(vector<int> & nums, int target){
        map<int, int> numsMap;
        for(int i=0; i<(int)nums.size(); i++){
            map<int, int>::iterator ite = numsMap.find(target-nums[i]);
            if(ite != numsMap.end())
                return vector<int> {ite->second, i};
            numsMap.insert(pair<int, int>(nums[i], i));
        }
        return vector<int> {0, 0};
    }
};

int main()
{
    Solution solution = Solution();
    int numsInit[4] = {1, 2, 3, 4};
    vector<int> nums, results;
    int target = 6;

    nums.insert(nums.begin(), &numsInit[0], &numsInit[4]);
    // nums.resize(4);
    // copy(&numsInit[0], &numsInit[4], nums.begin());
    
    // transform 不是不需要resize吗
    // transform(&numsInit[0], &numsInit[4], nums.begin(), 
    //         [](int u){return u;});

    for(int a : nums){
        cout << a << "\t";
    }
    cout << endl;

    results = solution.twoSum(nums, target);
    for(int i=0; i<(int)results.size(); i++){
        cout << results[i] << "\t";
    }
    cout << endl;
}
