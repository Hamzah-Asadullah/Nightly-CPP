#include <iostream>
#include <cstdlib>

/*
  Solves x in
  ax + b = c
  ax = c - b
  x = (c - b) / a
*/

int main()
{ while (true) {
    std::cout << ">> Enter a, b and c for solving x in `ax + b = c`: ";
    double a, b, c, x = 0.0; std::cin >> a >> b >> c; // I ain't writing for idiots feeling funny with letters

    if ((a == 0.0) && (b == c)) std::cout << ">> Infinite solutions." << std::endl;
    if ((a == 0.0) && (b != c)) std::cout << ">> No solution." << std::endl;
    std::cout << ">> x = " << '(' << c << " - " << b << ") / " << a << " = " << double(c - b) / a << std::endl;
}
    return 0;
}
