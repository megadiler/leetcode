/*
Given an array of integers numbers that is already sorted in non - decreasing order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers(1 - indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

    The tests are generated such that there is exactly one solution.You may not use the same element twice.



    Example 1:

Input: numbers = [2, 7, 11, 15], target = 9
Output : [1, 2]
Explanation : The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2 :

    Input : numbers = [2, 3, 4], target = 6
    Output : [1, 3]
    Example 3 :

    Input : numbers = [-1, 0], target = -1
    Output : [1, 2]
*/


#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        std::vector<int> res = { 0,0 };
        auto doloop1 = true;
        int sum = 0;
        for (auto iter1 = numbers.begin(); (iter1 != numbers.end()) && doloop1; iter1++)
        {
            if (*iter1 > target)
                continue;
            if (*iter1 + *(numbers.end() - 1) < target)
                continue;
            for (auto iter2 = iter1 + 1; iter2 != numbers.end(); iter2++)
            {
                sum = *iter1 + *iter2;
                if (sum > target)
                    break;


                if (sum == target)
                {
                    res[0] = iter1 - numbers.begin() + 1;
                    res[1] = iter2 - numbers.begin() + 1;
                    doloop1 = false;
                    break;
                }
            }
        }
        return res;
    }
};
int main()
{
    std::vector<int> test{ -5,-4,-2,-1,0,2,4,6 };
    Solution sol; 
    std::vector<int> rs = sol.twoSum(test, 10);
    std::cout << "Hello World!\n";
}

