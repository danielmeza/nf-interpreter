//
// Copyright (c) 2018 The nanoFramework project contributors
// See LICENSE file in the project root for full license information.
//
#include "Core.h"
#include <hal.h>
#include <hal_nf_community.h>

void CLR_RT_Random::Initialize()
{
    trngStart(&TRNGD1, NULL);
}

void CLR_RT_Random::Initialize( int seed )
{
    (void)seed;

    trngStart(&TRNGD1, NULL);
}

uint32_t CLR_RT_Random::Next()
{
    uint32_t rand;
    trngGenerate(&TRNGD1, 32, rand);
    return 
}

double CLR_RT_Random::NextDouble()
{
    double rand;
    // the hardware generator returns a value between 0 - 0xFFFFFFFF
    trngGenerate(&TRNGD1, (double)0xFFFFFFFF, rand);
    return rand;
}

void CLR_RT_Random::NextBytes(unsigned char* buffer, unsigned int count)
{
    unsigned int i;

    for(i = 0; i < count; i++)
    {
        buffer[i] = (unsigned char)trngGenerate(&TRNGD1,1, i);
    }
}
