#include <iostream>
#include <iomanip>

struct units
{
    const double mm = 0.001, cm = 0.01, m = 1, km = 1000.0;
    units(): mm(0.001), cm(0.01), m(1), km(1000.0) {}
    double string_to_unit(const char* str)
    {
        if ((str[0] == 'm') && (str[1] == 'm')) return mm;
        if (str[0] == 'c') return cm;
        if (str[0] == 'm') return m;
        if (str[0] == 'k') return km;
        return 0;
    }
    double convert(double value, const char* from, const char* to)
    { return value * string_to_unit(from) / string_to_unit(to); }
};

int main()
{
    units converter;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Enter value: "; double value; std::cin >> value;
    std::cout << "From unit (mm/cm/m/km): "; char from[3]; std::cin >> from;
    std::cout << "To unit (mm/cm/m/km): ";   char to[3];   std::cin >> to;
    std::cout << "Result: " << converter.convert(value, from, to) << ' ' << to << std::endl;
    return 0;
}
