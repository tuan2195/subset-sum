#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <chrono>

//bool isSubsetSum(int set[], int n, int sum)
bool isSubsetSum(std::vector<long> set, long long sum)
{
    const int n = (int)set.size();
    bool subset[sum+1][n+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[0][i] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
        subset[i][0] = false;

    // Fill the subset table in botton up manner
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            subset[i][j] = subset[i][j-1];
            if (i >= set[j-1])
                subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
        }
    }

    return subset[sum][n];
}

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

    auto start = std::chrono::steady_clock::now();
    auto found = isSubsetSum(sample, target);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    std::cout << "Sum found = " << (found ? "TRUE" : "FALSE") << " | ";
    std::cout << "Time taken = " << elapsed.count() << std::endl;

    return 0;
}


