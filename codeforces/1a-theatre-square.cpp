#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    unsigned n, m, a;
    cin >> n >> m >> a;
    unsigned long long width = ceil((float)n / a);
    unsigned long long height = ceil((float)m / a);
    cout << width * height;
    return 0;
}