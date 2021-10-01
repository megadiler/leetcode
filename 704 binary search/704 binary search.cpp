// 704binarysearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

namespace Alg
{
    using namespace std;

    class Solution {
    public:
        static int search(vector<int>& nums, int target)
        {
            int size = nums.size();
            int res = -1;

            int left = 0;
            int right = size - 1;
            int pos{ 0 };

            for (;;)
            {
                if (left == right)
                {
                    if (target == nums[left])
                        res = left;
                    break;
                }

                int local_len = right - left;

                if (local_len % 2 > 0)//четное 
                {
                    if (local_len + 1 == 2)
                    {
                        if (target == nums[left])
                            res = left;
                        else
                            if (target == nums[right])
                                res = right;
                        break;
                    }
                    pos = (local_len) / 2 + left;
                    if (target == nums[pos])
                    {
                        res = pos;
                        break;
                    }
                    if (pos + 1 < size)
                        if (target == nums[pos + 1])
                        {
                            res = pos + 1;
                            break;
                        }

                    if (target > nums[pos])
                        left = pos;
                    else
                        right = pos;

                }
                else
                {//нечетное 
                    pos = (local_len) / 2 + left;
                    if (target == nums[pos])
                    {
                        res = pos;
                        break;
                    }
                    else
                    {
                        if (target > nums[pos])
                            left = pos;
                        else
                            right = pos;
                    }
                }
            }
            return res;
        }
    };
}


int main()
{
    std::cout << "Hello World!\n";

    int res;
    std::vector<int> v1{ -1, 0, 3, 5, 9, 12 };
    res = Alg::Solution::search(v1, 2);
    std::cout << "v1{ -1, 0, 3, 5, 9, 12 }  2 " << res << std::endl;

    std::vector<int> v2{ 5 };
    res = Alg::Solution::search(v2, 5);
    std::cout << "[5]  0 " << res << std::endl;

    std::vector<int> v3{ 5, 10 };
    res = Alg::Solution::search(v3, 10);
    std::cout << "[5, 10]  1 " << res << std::endl;

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
