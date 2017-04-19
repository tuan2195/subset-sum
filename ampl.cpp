#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: ./ampl <sampleSet> <target>" << std::endl;
        exit(1);
    }

    // Open file to read from
    std::ifstream input (argv[1], std::ios::in);
    std::ofstream output (std::string(argv[1]) + ".dat", std::ios::out);

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

    output << "param k:=" << target << ";\n";
    output << "param n:=" << sample.size() << ";\n";
    output << "param c:=" << "\n";

    auto i = 0;

    for(const auto &x : sample)
    {
        output << ++i << " " << x << "\n";
    }

    output << ";";

    output.close();
    return 0;
}

