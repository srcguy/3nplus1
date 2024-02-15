#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    int count = 0;

    for (long long i = 1; i <= 10000000; ++i) {
        long long current = i;

        while (current != 1) {
            current = (current % 2 == 0) ? current / 2 : 3 * current + 1;
        }

        ++count;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Total sequences: " << count << std::endl;
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
