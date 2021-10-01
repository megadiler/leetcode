// 198 house robber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

typedef std::vector<int> tInt;

class Solution
{
    int calc(tInt& nums, int pos, int parentval, tInt &buffer)
    {
        int sum{ 0 }, sum1{ 0 }, sum0{0};

        if (pos == nums.size()-1)
        {
            if (parentval == 0)
                sum1 = nums.at(pos) * 1;
        }
        else
        {
            if (buffer.at(pos + 1) >= 0)
            {
                sum0 = 0 + buffer.at(pos + 1);
                if (parentval == 0)
                    sum1 = nums.at(pos) * 1 + buffer.at(pos + 1);
            }
            else
            {
                sum0 = 0 + calc(nums, pos + 1, 0, buffer);
                if (parentval == 0)
                    sum1 = nums.at(pos) * 1 + calc(nums, pos + 1, 1, buffer);
            }
        }
        sum = sum1 > sum0 ? sum1 : sum0;
        if (buffer.at(pos) < 0)
            buffer.at(pos) = sum;
        return sum; 
    }
public: 
    int rob(tInt& nums)
    {
        tInt buffer(nums.size(), -1); 
        return calc(nums, 0, 0, buffer);
    }
};

int main()
{
    tInt test1{ 2,7,9,3,1 };
    tInt test2{ 2,10,1,5,15,6,3};

    Solution Sol; 

    int res = Sol.rob(test2);
    std::cout << "res = " << res  << "\n";
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
