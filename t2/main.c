#include <stdio.h>

#define HGH_DBG(fmt, args...) printf("\033[40;33m HGH_DBG(%s %s %d):\t\033[0m"fmt, __FILE__, __func__, __LINE__, ## args)

int main(int argc, char const *argv[])
{
    HGH_DBG("\n");
    return 0;
}
