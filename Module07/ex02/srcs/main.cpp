#include "Array.hpp"
#include <iostream>

int main( void ) {

    std::cout << "\nTEST ARRAY TEMPLATE CLASS " << std::endl;
    Array<double> dbl_arr;
    Array<double> dbl_two(10);
    Array<double> dbl_3(dbl_two);
    std::cout << "dbl_arr: " << dbl_arr.size() << std::endl;
    std::cout << "dbl_two: " << dbl_two.size() << std::endl;
    std::cout << "dbl_3: " << dbl_3.size() << std::endl;
    dbl_arr = dbl_two;
    std::cout << "dbl_arr after copy dbl_two: " << dbl_arr.size() << std::endl;
    {
        std::cout << "\nTEST FLOAT ARRAY" << std::endl;
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
        std::cout << "\nTEST STRING ARRAY" << std::endl;
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
    std::cout << "\nTEST CONST ARRAY" << std::endl;
    const Array<int> const_arr2(5);
    std::cout << const_arr2[0] << std::endl;
    // const_arr2[0] = 1; // will not work
    std::cout << const_arr2[0] << std::endl;

    // std::cout << "\nTEST CONST INT ARRAY" << std::endl;
    // Array<const int> const_arr3(5);
    // std::cout << const_arr3[0] << std::endl;
    // // const_arr3[0] = 1; // will not work
    // std::cout << const_arr3[0] << std::endl;

    std::cout << "\nTEST ASSIGN CONST VALUES TO ARRAY" << std::endl;
    Array<int> test2(3); //none of this is const
    const int one = 1;
    const int two = 2;   
    const int three = 3;
    test2[0] = one;
    test2[1] = two;
    test2[2] = three;
    std::cout << test2[0] << std::endl;
    std::cout << test2[1] << std::endl;
    std::cout << test2[2] << std::endl; 
    test2[0] = 2; //does work
    std::cout << test2[0] << std::endl;


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