#include <iostream>
#include <fstream>
#include <random>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./tool <sampleSize> <limit> <outputFile>" << std::endl;
        exit(1);
    }

    auto sampleSize = std::stoi(argv[1]);
    auto limit = std::stoi(argv[2]);

    if (sampleSize == 0 || limit == 0)
    {
        std::cout << "Invalid arguments!" << std::endl;
        std::cout << "Usage: ./tool <sampleSize> <limit> <outputFile>" << std::endl;
        exit(1);
    }

    // Open file to write to
    std::ofstream output (argv[3], std::ios::out | std::ios::trunc);

    if (!output)
    {
        std::cout << "Unable to open file " << argv[3] << std::endl;
        exit(1);
    }

    // Random device
    std::random_device randDev;
    // Mersenne twister engine
    std::mt19937_64 generator(randDev());
    // Uniform integer distribution
    std::uniform_int_distribution<long> dist(1, limit);

    for(auto i = 0; i < sampleSize; ++i)
    {
        output << dist(generator) << ' ';
    }

    output.close();
    return 0;

}
