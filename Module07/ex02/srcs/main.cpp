#include "Array.hpp"
#include <iostream>

int main( void ) {

    {
        int N = 10;
        Array<float> float_arr(N);
        for (int i = 0; i < N; i++)
        {
            float_arr[i] = i + i - 0.1f;
            std::cout <<  float_arr[i] << ", ";
        }
        std::cout << std::endl;
    }
    {
        int N = 50;
        std::string entry("entry");
        std::string addon("a");
        Array<std::string> string_arr(N);
        for (int i = 0; i < N; i++)
        {
            string_arr[i] = entry.append(addon);
            std::cout <<  string_arr[i]  << ", ";
        }
        std::cout << std::endl;
    }
    Array<double> dbl_arr;
    Array<double> dbl_two(10);
    Array<double> dbl_3(dbl_two);
    std::cout << "dbl_arr: " << dbl_arr.size() << std::endl;
    std::cout << "dbl_two: " << dbl_two.size() << std::endl;
    std::cout << "dbl_3: " << dbl_3.size() << std::endl;
    dbl_arr = dbl_two;
    std::cout << "dbl_arr after copy dbl_two: " << dbl_arr.size() << std::endl;
	return (0);
}

/* Main from the project page */
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }