/*
189. Rotate Array
*/

/*
* Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/

#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k)
    {
        int N = nums.size();
        int* pint = &nums[0];
        int shift = k % N;
        int* pintnew = new int[N];
        memcpy(pintnew, pint + N - shift, sizeof(int) * shift);
        memcpy(&pintnew[shift], pint, sizeof(int) * (N - shift));
        nums.clear();
        nums.insert(nums.begin(), pintnew, pintnew + N);
        delete[] pintnew;
    }

    void print(std::vector<int>& nums) 
    {
        for (auto& iter : nums)
        {
            std::cout << iter << std::endl; 
        }
    }
};




int main()
{


    std::vector<int> test{ 0,1,2,3,4,5,6,7,8,9 };
    std::vector<int> test1{ 1,2,3};

    Solution Sol; 
    Sol.rotate(test, 13);
    Sol.print(test);

    //Sol.rotate(test1, 2);
    ///Sol.print(test1);

    std::cout << "Hello World!\n";
}

