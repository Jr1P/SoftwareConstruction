#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <iterator>
#include <functional>

int main() {
    std::vector<int> v(10);
    std::fill(v.begin(), v.end(), 1);
    std::iota(v.begin(), v.end(), 0);
    std::reverse(v.begin(), v.end());
    std::sort(v.begin(), v.end());

    //
    std::mt19937 rng;
    std::generate_n(v.begin(), 10, std::ref(rng));
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::vector<int> v_values(v);
    std::sort(v_values.begin(), v_values.end());
    v_values.erase(std::unique(v_values.begin(), v_values.end()), v_values.end());
    for (auto &i: v) {
        i = std::lower_bound(v_values.begin(), v_values.end(), i) - v_values.begin();
    }
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}