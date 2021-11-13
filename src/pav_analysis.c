#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N)
{

    float pdB = 0, ac = 0;
    for (int i = 0; i <= N - 1; i++)
    {
        ac = ac + (x[i] * x[i]);
    }
    pdB = 10 * log10(ac / N);
    return pdB;
}

float compute_am(const float *x, unsigned int N)
{

    float A = 0, ac = 0;
    for (int i = 0; i <= N - 1; i++)
    {
        ac = ac + fabs(x[i]);
    }
    A = ac / N;
    return A;
}

float compute_zcr(const float *x, unsigned int N, float fm)
{

    float ZCR = 0;
    int ac = 0;

    for (int i = 1; i <= N - 1; i++)
    {

        if ((x[i] * x[i - 1]) < 0)
        {
            ac = ac + 1;
        }
    }

    ZCR = fm * (1. / 2) * (1. / (N - 1)) * ac;

    return ZCR;
}