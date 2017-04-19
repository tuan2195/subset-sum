#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <chrono>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: ./greedy <sampleSet> <target>" << std::endl;
        exit(1);
    }

    // Open file to read from
    std::ifstream input (argv[1], std::ios::in);
    auto target = std::stoll(argv[2]);

    if (!input)
    {
        std::cout << "Unable to open file " << argv[1] << std::endl;
        exit(1);
    }

    std::vector<long> sample;

    // Copy numbers from file to vector
    std::copy(std::istream_iterator<long>(input),
              std::istream_iterator<long>(),
              std::back_inserter<std::vector<long>>(sample));

    input.close();

    // Seuquential solver using binary representation
    // to generate and represents different combinations
    // Size must be less than 64 otherwise will overflow
    //auto size = sample.size();

    //std::cout << "Sample size: " << size << std::endl;
    //std::cout << "Target sums: " << target << std::endl;

    auto start = std::chrono::steady_clock::now();
    std::sort(sample.begin(), sample.end(), std::greater<long>());

    auto sum = 0LL;
    std::vector<long> result;

    for (const auto &x: sample)
    {
        if (sum < target && x < target - sum)
        {
            sum += x;
            result.push_back(x);
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    //std::cout << "Sorted sample: ";
    //for (const auto &x : sample)
        //std::cout << x << " ";
    //std::cout << std::endl;

    //std::cout << "Result: ";
    //for (const auto &x : result)
        //std::cout << x << " ";
    //std::cout << std::endl;

    //std::cout << "Sum: " << sum << std::endl;
    //std::cout << "Diff: " << target - sum << std::endl;

    //std::cout << "Time taken: " << elapsed.count() << " us" << std::endl;
    std::cout << elapsed.count() << std::endl;

    return 0;
}


