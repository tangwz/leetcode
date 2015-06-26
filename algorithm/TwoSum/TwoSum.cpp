#include<vector>
#include<map>
using std::map;
using std::vector;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> nums;
		vector<int> result;
		for (int i = 0; i < numbers.size(); ++i){
			if (nums.find(target - numbers[i])!=nums.end()){
				result.push_back(nums[target-numbers[i]] + 1);
				result.push_back(i + 1);
			}
			else
				nums[numbers[i]] = i;
		}
		return result;
	}
};
