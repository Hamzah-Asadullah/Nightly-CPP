#include <iostream>
#include <iomanip>

#define gt double

template <typename T>
struct mxb
{
    T m = 0, b = 0;
    T y(T x) { return m * x + b; }
};

int main()
{
    std::cout << "Define m, b: ";
    gt m, b; std::cin >> m >> b;

    std::cout << "Define r0, r1 and step-size: ";
    gt r0, r1, ss; std::cin >> r0 >> r1 >> ss;

    mxb<gt> f = { m, b };
    std::cout << "x       |       y\n" << std::fixed << std::setprecision(2);
    for (; r0 < r1; r0 += ss)
        std::cout << std::left << std::setw(8) << r0 << '|' << std::right << std::setw(8) << f.y(r0) << '\n';

    return 0;
}
