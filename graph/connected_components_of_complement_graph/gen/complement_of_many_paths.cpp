#include <cstdio>
#include "random.h"
#include "../params.h"

using namespace std;

int get_max_n() {
    int ok = N_MIN, ng = N_MAX + 1;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if ((long long)mid * (mid - 1) / 2 <= M_MAX) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main(int, char **argv) {
    long long seed = atoll(argv[1]);
    Random gen(seed);
    int n = get_max_n();
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    gen.shuffle(p.begin(), p.end());
    vector<vector<int>> edge(n, vector<int>(n, 1));
    for (int i = 0; i < n - 1; ++i) {
        if (gen.uniform_bool()) {
            edge[p[i]][p[i + 1]] = edge[p[i + 1]][p[i]] = 0;
        }
    }
    vector<pair<int, int>> output;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (edge[i][j]) {
                if (gen.uniform_bool()) {
                    output.emplace_back(i, j);
                } else {
                    output.emplace_back(j, i);
                }
            }
        }
    }
    gen.shuffle(output.begin(), output.end());
    int m = int(output.size());
    printf("%d %d\n", n, m);
    for (pair<int, int> e : output) {
        printf("%d %d\n", e.first, e.second);
    }
}
