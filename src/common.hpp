#ifndef COMMON_HPP
#define COMMON_HPP

namespace snakeplusplus
{
    void InitializeGenerator(void);
    int GenerateRandomNumber(int generationLimit);

    enum PlayerDirection
    {
        kNone = 0,
        kLeft = 1,
        kUp = 2,
        kDown = 3,
        kRight = 4
    };

}

#endif
