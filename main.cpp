#include "kiero.hpp"
#include "kiero_d3d9.hpp"
#include <cstdint>
#include <cstdio>
#include <iostream>

int main(int argc, char** argv)
{
    kiero::D3D9Output d3d9;

    auto error = kiero::locate<kiero::Implementation_D3D9>(nullptr, &d3d9);
    if (error != kiero::Error_Nil) {
        printf("something went wrong: %u", error);
        return 1;
    }

    return 0;
}