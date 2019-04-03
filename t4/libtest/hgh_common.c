#include <stdio.h>

#include "hgh_common.h"

int common_echo()
{
    printf("[%s:%d]\n", __FUNCTION__, __LINE__);

    return 0;
}
