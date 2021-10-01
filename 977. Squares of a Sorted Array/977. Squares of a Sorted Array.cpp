/*
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

Follow up: 
Squaring each element and sorting the new array is very trivial, 
could you find an O(n) solution using a different approach?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //accepted
    vector<int> sortedSquares(vector<int>& nums) 
    {
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
            *iter *= *iter;
        sort(nums.begin(), nums.end());
        return nums;
    }

    //недоделан
    vector<int> sortedSquares_2(vector<int>& nums)
    {
        vector<int > nums_abs;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            //if (*iter < 0)
        }

        sort(nums.begin(), nums.end());
        return nums;
    }

};

int main()
{
    std::cout << "Hello World!\n";


}

