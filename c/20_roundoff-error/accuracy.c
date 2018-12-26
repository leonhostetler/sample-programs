/**************************************************************
* accuracy.c -- Test float precision
* 
* Author: Leon Hostetler, Jul 16, 2018
*
**************************************************************/
#include <stdio.h>

/* Main Program */
int main()
{

    /* Two floats to test float precision */
    float float1, float2, result;
    double double1, double2, result2;
    int i;

    float1 = 1.0;
    float2 = 1.0;
    double1 = 1.0;
    double2 = 1.0;
    i = 0;

    /* Test precision of floats when used in calculations */
    while(float1 + float2 != float1) {
        ++i;
        float2 = float2 / 10.0;
    }
    printf("\n%2d digits accuracy in float calculations\n", i);

    /* Test precision of floats when stored in memory */
    i = 0;
    float2 = 1.0;
    while (1) {
        result = float1 + float2;
        if(result == float1)
            break;
        ++i;
        float2 = float2 / 10.0;
    }
    printf("\n%2d digits accuracy in float storage\n", i);

    /* Test precision of doubles when used in calculations */
    i = 0;
    while(double1 + double2 != double1) {
        ++i;
        double2 = double2 / 10.0;
    }
    printf("\n%2d digits accuracy in double calculations\n", i);

    /* Test precision of doubles when stored in memory */
    i = 0;
    double2 = 1.0;
    while (1) {
        result2 = double1 + double2;
        if(result2 == double1)
            break;
        ++i;
        double2 = double2 / 10.0;
    }
    printf("\n%2d digits accuracy in double storage\n", i);

}
