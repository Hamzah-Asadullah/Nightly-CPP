#include <iostream>
#include <iomanip>

template <typename T>
T input() { T value; std::cin >> value; return value; }
template <typename T>
T input(const char* msg) { std::cout << msg; T value; std::cin >> value; return value; }

int main()
{
    std::cout << std::fixed << std::setprecision(2);
    while (true)
    {
        std::cout
            << "--- Percentage Calculator ---"
            << "\n>> Select a mode: "
            << "\n>> 1. What is X% of Y?"
            << "\n>> 2. What percent is X of Y?"
            << "\n>> 3. X is Y% of what number?"
            << "\n>_ Enter selection (1-3, any other to exit): ";
        char mode = input<char>() - char(48); // or - '0'
        if ((mode < char(1)) || (mode > char(3))) return 0;

        double x = input<double>(">_ Enter X and Y: "), y = input<double>();
        if (((mode == 2) || (mode == 3)) && (y == 0.0))
        {
            std::cout << ">> Invalid input for Y: Can't be 0.0.\n" << std::endl;
            continue; 
        }

        if (mode == 1) // What is X% of Y
            std::cout << ">> " << x * 100.0 << "% of " << y << " is " << x * y << '\n' << std::endl;
        else if (mode == 2) // What percent is X of Y
            std::cout << ">> " << x << " is " << x / y * 100.0 << "% of " << y << '\n' << std::endl;
        else // X is Y% of what number
            std::cout << ">> " << x << " is " << y * 100.0 << "% of " << (1.0 / y) * x << '\n' << std::endl;
    }
    return 0;
}
