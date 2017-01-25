#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: ./naive <sampleSet> <target>" << std::endl;
        exit(1);
    }

    // Open file to read from
    std::ifstream input (argv[1], std::ios::in);
    auto target = std::stoull(argv[2]);

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
    auto size = sample.size();
    if (size > 63)
    {
        std::cout << "Naive solver only support less than 64 elements!" << std::endl;
        exit(1);
    }
    auto numOfCombinations = 1ULL<<size;

    std::cout << "Sample size: " << size << std::endl;
    std::cout << "Num of sets: " << numOfCombinations << std::endl;
    std::cout << "Target sums: " << target << std::endl;

    for (auto i = 0ULL; i < numOfCombinations; ++i)
    {
        auto sum = 0ULL;
        for (auto j = 0U; j < size; ++j)
        {
            // If bit j-th is 1 then the element is in
            // this combination, otherwise it is not
            if (i & (1ULL<<j))
            {
                sum += sample[j];
            }
        }

        if (sum == target)
        {
            std::cout << "FOUND!" << std::endl;
            return 1;
        }
    }

    return 0;
}


