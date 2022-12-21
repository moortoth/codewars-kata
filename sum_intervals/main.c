#include <stdbool.h>
#include <stdlib.h>

struct interval {
    int first;
    int second;
};

int sum_intervals(const struct interval *v, size_t n)
{
    struct interval *res = calloc(n, sizeof(struct interval));
    size_t res_size = 0;

    for (int i = 0; i < n; ++i) {
        bool added = false;
        
        for (int j = 0; j < res_size; ++j) {
            // laying right
            if (v[i].first >= res[j].first)
            {   
            }
            // laying left
            if (v[i].second >= res[j].first)
            {

                res[j].first = v[i].first < res[j].first ? v[i].first : res[j].first;
            }
        }
    }

    return 0;
}