#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> & nums, int target){
        int closestNum = target;
        for(int count=1; ; count++){
            // 注意pow的原型：double pow(double, double);
            closestNum = target + (int)pow(-1, (count-1)) * count/2;
            for(int i=0; i<(int)nums.size(); i++){
                for(int j=i+1; j<(int)nums.size(); j++){
                    cout << "find: " << closestNum << "-" << nums[i] << "-" << nums[j] << "=" << closestNum-nums[i]-nums[j] << endl;;
                    vector<int>::iterator ite = find(nums.begin()+j+1, nums.end(), closestNum-nums[i]-nums[j]);
                    if(ite != nums.end()){
                        cout << nums[i] << "\t" << nums[j]  << "\t" << *ite << endl;
                        return closestNum;
                    }
                }
            }
        }
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> nums = {1, 1, -1, -1, 3};  // {-1, 2, 1, -4};
    int target = -1;

    int result = solution.threeSumClosest(nums, target);
    cout << result << "\t";
}
