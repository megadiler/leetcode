/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/

#include <iostream>
#include <vector>

class Solution
{
    public:
        std::vector<int> twoSum(std::vector<int>& numbers, int target)
        {
            std::vector<int> res = { 0,0 };
            auto doloop1 = true;
            auto sum = 0;
            for (auto iter1 = numbers.begin(); (iter1 != numbers.end()) && doloop1; iter1++)
                for (auto iter2 = iter1 + 1; iter2 != numbers.end(); iter2++)
                {
                    sum = *iter1 + *iter2;
                    if (sum == target)
                    {
                        res[0] = iter1 - numbers.begin();
                        res[1] = iter2 - numbers.begin();
                        doloop1 = false;
                        break;
                    }
                }
            return res;
        }
};

int main()
{
    std::cout << "Hello World!\n";
}


