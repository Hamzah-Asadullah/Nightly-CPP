#include <iostream>
#include <vector>

using n = unsigned short;
constexpr unsigned long long int MAX_B = 65536;

bool is_prime(n x)
{
	if (x < 2) return false;
	for (n i = 2; (i * i) <= x; ++i)
		if ((x % i) == 0) return false;
	return true;
}

unsigned int my_pow(n a, n b)
{
	unsigned int c = 1;
	for (n i = 0; i < b; ++i)
		c *= a;
	return c;
}

n digits(n x)
{
	n d = 0;
	do
	{
		++d;
		x /= 10;
	}
	while (x != 0);
	return d;
}
n sum_digits(const std::vector<n>& nums, n range)
{
	n sum = 0;
	for (n i = 0; i < range; ++i)
		sum += digits(nums[i]);
	return sum;
}

int main()
{ while (true) {
	std::vector<n> nums(MAX_B);
	n a, b, primes = 0; float avg = 0.f;
	
	std::cout << "--- Primes in range min and max ---\n>> Example usage: \n"
			  << "--\n"
			  << ">_ Enter min and max to calc primes for: 0 1024\n"
			  << ">> If you want to see all primes between 0 and MAX_B (defined at line 10), simple do -1 -1\n"
			  << "--" << std::endl;

	std::cout << ">_ Enter min and max to calc primes for: ";
	std::cin >> a >> b; std::cout << ">> Primes found: ";

	if (a > b)
	{
		n c = a;
		a = b;
		b = c;
	}

	{
		unsigned int total = 0;
		for (n i = a; i <= b; ++i)
		{
			if (is_prime(i))
			{
				std::cout << i << " ";
				nums[primes] = i;
				total += i;
				++primes;
			}
		}
		avg = float(total) / float(primes);
	}

	std::cout << "\n\n-- Useless stats ChatGPT's forcing me to calc --";
	std::cout << "\n- Average / Mean: " << avg
			  << "\n- Smallest prime: " << nums[0]
			  << "\n- Largest prime: " << nums[primes - 1]
			  << "\n- Number of all primes: " << primes
			  << "\n- Number of digits of all primes combined: " << sum_digits(nums, primes);

	std::cout << "\nSession reset.\n" << std::endl;
}
	return 0;
}
