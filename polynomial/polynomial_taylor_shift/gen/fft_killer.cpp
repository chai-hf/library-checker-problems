#include <cstdio>
#include "../params.h"
#include "random.h"

using namespace std;

int main(int, char *argv[])
{
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);
    auto sub = (seed <= 1) || ((seed - 2) & 1) ? 1000 : 10;
    auto div = (seed <= 1) || ((seed - 2) & 2) ? 1 : 2;

    int n = N_MAX;
    vector<int> a(n);
    const int B = (seed <= 1) || ((seed - 2) & 4) ? 1<<15 : std::sqrt(MOD);
    for (int i = 0; i < n; i++)
    {
        int lw = gen.uniform(B - sub, B - 1);
        int up = gen.uniform(MOD / div / B - sub, MOD / div / B - 1);
        a[i] = up * B + lw;
    }
    int c = gen.uniform(0ll, MOD - 1);

    printf("%d %d\n", n, c);
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
