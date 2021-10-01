

#include <iostream>
#include <vector>

using namespace std; 

class list
{
    int val; 
    list* next;
    void add(list* item)
    {
        list newitem(item->val);
        next = &newitem;
    }

    void add(int newval)
    {
        list* item = new list; 
        item->val = newval;
        this->next = item;
    }

    list* getlast()
    {
        list* ref = this;
        while (ref->next != nullptr)
        {
            ref = ref->next;
        }
        return ref;
    }


    list() : val(0), next(nullptr) 
    {
        cout << "constructor 1" << endl;
    };

    list(int val_)
    {
        list* item = new list;
        item->val = val_;
    }

public:
    //list(std::vector<int>& nums)
    //{
    //    //this->first(nums.at(0));
    //    //list* cur = &first;
    //    for (auto iter = nums.begin()+1; iter != nums.end(); iter++ )
    //    {
    //        list *newitem = new list(*iter);
    //        cur->add(newitem);
    //        cur = newitem;
    //    }


    //}
};

class list2
{
public:
    int val;
    list2* next;
};

class Solution 
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        int N = nums.size();
        int count = 0;
        int count0 = 0;

        list2* pfirst = nullptr;
        list2* plast = pfirst;

        for (int iter : nums)
        {
            list2* node = new list2;
            node->val = iter;
            node->next = nullptr;
            if (iter == 0) count0++;

            if (pfirst == nullptr)
            {
                plast = pfirst = node;
            }
            else
            {
                plast->next = node;
                plast = node;
            }
        }
        if (count0 == N) return;

        list2* iter = pfirst;

        while ((iter->val == 0) && (count < N ))
        {
            plast->next = iter;
            pfirst = iter->next;
            iter = iter->next;
            plast->next->next = nullptr;
            plast = plast->next;
            count++;
        }
        if (count0 == count)
        {
            nums.clear();
            iter = pfirst;
            while (iter != nullptr)
            {
                nums.push_back(iter->val);
                list2* tmp = iter;
                iter = iter->next;
                delete tmp;
            }
            pfirst = plast = nullptr;
            return;
        }

        int ncount = count;
        while ((iter->next != nullptr) && (ncount <= N))
        {
            if (0 == iter->next->val)
            {
                list2* tmp = iter->next;
                if (iter->next->next != nullptr)
                {
                    iter->next = iter->next->next;
                    tmp->next = nullptr;
                    plast->next = tmp;
                    plast = tmp;
                    tmp = nullptr;
                }
                count++; 
            }
            else
                iter = iter->next;
            ncount++;
        }

        nums.clear();
        iter = pfirst;
        while (iter != nullptr)
        {
            nums.push_back(iter->val);
            list2* tmp = iter;
            iter = iter->next;
            delete tmp;
        }
        pfirst = plast = nullptr;
    }


    void print(std::vector<int>& nums)
    {
        for (int iter : nums)
        {
            std::cout << iter << std::endl;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Solution* sol = new Solution;

    std::vector<int> test{ 1,0,3,0,5,6,7,8 };
    std::vector<int> test2{ 0,3,0,5,6,7,8 };
    std::vector<int> test3{ 0 };
    std::vector<int> test4{ 0, 0, 0  };
    std::vector<int> test5{ 1, 0 , 0, 0 };
    std::vector<int> test6{ 0, 0, 0, 10 };
    std::vector<int> test7{ 1, 0, 0, 0, 0, 10 };
    std::vector<int> test8{ 0, 0};
    std::vector<int> test9{ 0, 1 };
    std::vector<int> test10{ 1, 0 };

    std::cout << "==0\n";
    sol->moveZeroes(test);
    sol->print(test);
    std::cout << "==2\n";
    sol->moveZeroes(test2);
    sol->print(test2);
    std::cout << "==3\n";
    sol->moveZeroes(test3);
    sol->print(test3);
    std::cout << "==4\n";
    sol->moveZeroes(test4);
    sol->print(test4);
    std::cout << "==5\n";
    sol->moveZeroes(test5);
    sol->print(test5);
    std::cout << "==6\n";
    sol->moveZeroes(test6);
    sol->print(test6);
    std::cout << "==7\n";
    sol->moveZeroes(test7);
    sol->print(test7);
    std::cout << "==8\n";
    sol->moveZeroes(test8);
    sol->print(test8);
    std::cout << "==9\n";
    sol->moveZeroes(test9);
    sol->print(test9);
    std::cout << "==10\n";
    sol->moveZeroes(test10);
    sol->print(test10);

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
