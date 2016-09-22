#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <cassert>
#include <array>
#include <stdlib.h>
/* Global string, still-reachable */
int main()
{
    uint8_t temp = 0x88;
    assert(temp >= 0x00 && temp <= 0x7F);
}