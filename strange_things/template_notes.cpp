#include<iostream>

float division (float a, float b)
{
    return a / b;
}

template <class generic>
generic generic_division (generic a, generic b)
{
    return a / b;
}

// 
template <class generic, int m = 10>
generic multiplier (generic number)
{
    return number * m;
}

int main()
{
    std::cout << "division using a traditional function: " << division(4.5, 1.1) << std::endl;
    std::cout << "int division using template function: " <<  generic_division<int>(9, 4) << std::endl;
    std::cout << "float division using the same function: " <<  generic_division<float>(4.2, 1.55) << std::endl;
    
    std::cout << "\n\n";
    // using function overloads
    std::cout << "float division using the overloads: " <<  generic_division(3.8, 2.95) << std::endl;
    std::cout << "int division using the overloads: " <<  generic_division(4, 2) << std::endl;
    
    std::cout << "\n\n";
    // using and changing default templates parameters
    std::cout << "using default parameter: " <<multiplier<int>(10) << std::endl;
    std::cout << "using different parameter: " <<multiplier<int, 11>(5);
    return 0;
}
