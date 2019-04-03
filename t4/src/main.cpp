#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "ZWHosts.h"

int main(int argc, char const *argv[])
{
    int iRet = 0;

    iRet = Hosts_Initialize("/tmp/zwhost/host.conf", "/tmp/zwhost/hosts", "/etc/resolv.conf");
    printf("Hosts_Initialize Ret[%d]\n", iRet);

    while (1)
    {
        sleep(10);
        iRet = Hosts_Update();
        printf("Hosts_Update Ret[%d]\n", iRet);
    }

    iRet = Hosts_Release();
    printf("Hosts_Release Ret[%d]\n", iRet);

    return iRet;
}
