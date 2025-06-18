#include <iostream>
#include <random>

int main() {
    std::mt19937_64 rng(time(0)); // 12345 adalah seed
    std::cout << rng() << std::endl; // menghasilkan angka acak 64-bit
    return 0;
}
