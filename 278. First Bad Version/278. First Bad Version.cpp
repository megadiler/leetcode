

# include <stdlib.h>
# include <iostream>



class Solution {
public:
    bool isBadVersion(int n)
    {
        return  0 == rand() % 2;
    }


    int firstBadVersion(int n)
    {
        if (isBadVersion(1))
            return 1;

        if (n == 1)
            return 1;

        int left{ 1 }, right{ n }, pos;
        while (left < right)
        {
            pos = left + (right - left) / 2;
            if (isBadVersion(pos))
                right = pos;
            else
                left = pos + 1;

        }
        return left;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
