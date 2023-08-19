// common.cpp
#include <random>
#include "common.hpp"

namespace snakeplusplus
{
    std::default_random_engine generator;
    void InitializeGenerator(void)
    {
        generator.seed(std::random_device{}());
    }

    // Returns a newly generated number
    int GenerateRandomNumber(int generationLimit)
    {
        int generatedNumber;
        std::uniform_int_distribution<> distribution(0, generationLimit - 1);
        generatedNumber = distribution(snakeplusplus::generator);
        return generatedNumber;
    }
}
