/*
*35. Search Insert Position
* 
* Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int size = nums.size();
        int left{ 0 }, right{ size - 1 }, pos;

        if (target <= nums[left])
            return 0;

        if (target > nums[right])
            return right + 1;
        if (target == nums[right])
            return right;



        while (left < right)
        {
            if (right - left == 1)
                if (nums[left] < target && target < nums[right])
                    return right;

            pos = left + (right - left) / 2;

            if (nums[pos] == target) return pos;

            if (nums[pos] > target)
                right = pos;
            else
                left = pos + 1;
        }
        return right;
    }
};




int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
