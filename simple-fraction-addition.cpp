#include <iostream>
using n = long;

n the_great_numbers[4] = { 7, 5, 3, 2 };

struct Fraction
{
    n numerator = 0, denominator = 1;

    Fraction(): numerator(0), denominator(1) {}
    
    void simplify() // I ain't implementing no gcd
    {
        for (n i = 0; i < 4; ++i)
        {
            n num = the_great_numbers[i];
            if (((numerator % num) == 0) && ((denominator % num) == 0))
            {
                numerator /= num;
                denominator /= num;
                break;
            }
        }
    }

    void operator= (const Fraction& other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    Fraction operator+ (const Fraction& other)
    {
        Fraction frac = *this;
        frac.numerator *= other.denominator;
        frac.numerator += other.numerator * frac.denominator;
        frac.denominator *= other.denominator;

        frac.simplify();
        return frac;
    }
};

std::ostream& operator<< (std::ostream& out, const Fraction& frac)
{
    if (frac.numerator < 0) out << '-';
    out << '(' << ((frac.numerator < 0) ? -frac.numerator : frac.numerator) << " / " << frac.denominator << ')';
    return out;
}

Fraction create_fraction(long long a, long long b)
{
    Fraction frac;
    if (b == 0)
    {
        std::cout << "Denominator can't be zero; undefined." << std::endl;
        frac.denominator = 0;
        return frac;
    }
    
    if (b < 0)
    {
        b = -b;
        a = -a;
    }

    frac.numerator = a;
    frac.denominator = b;

    return frac;
}

int main()
{
    Fraction frac[2] = { Fraction(), Fraction() }; long long a, b;

    std::cout << "Input:\nFraction 1: ";
    std::cin >> a >> b;
    frac[0] = create_fraction(a, b);
    if (frac[0].denominator == 0) return 1;

    std::cout << "Fraction 2: ";
    std::cin >> a >> b;
    frac[1] = create_fraction(a, b);
    if (frac[1].denominator == 0) return 2;

    frac[0].simplify();
    frac[1].simplify();

    std::cout << "\nOutput:\n" << frac[0] << " + " << frac[1] << " = " << (frac[0] + frac[1]);
    return 0;
}
