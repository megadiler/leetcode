
//#include <iostream>
//#include <string>
//
//int main()
//{
//    char *z1 = nullptr, *z2 = nullptr; 
//    std::cin >> z1; 
//    std::cin >> z2; 
//    std::cout << z1  << std::endl;
//
//
//}
//

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>


//#if TRUE
//#error C++ compiler required.
//#endif

int main()
{
	//char s[80];
	int t{5};
	//fscanf(stdin, "%s%d", s, &t); 
	//scanf("%s%d", s, &t);

	int test0 = 100; 
	int test1 = test0 << 3;
	int test2 = test0 >> 4;

	int arr[5] = { 10,2,3,4,5 };
	int val1 = arr[0] << 1;
	int val2 = arr[2] >> 1;

	//int* ref = &arr << 2;

	return 100 + t;
}
