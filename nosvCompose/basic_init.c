#include <nosv.h>
#include <stdio.h>

int main(void)
{
    int err = nosv_init();
    printf("Initialized nOS-V with status: %d\nNow looping indefinitely", err);

    while(1);
}