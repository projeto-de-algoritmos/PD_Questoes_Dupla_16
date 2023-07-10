// ABC303 D - Shift vs. CapsLock
// https://atcoder.jp/contests/abc303/tasks/abc303_d

#include <iostream>
#include <vector>
#include <utility>

using ll = long long;

std::pair<ll, ll> solve(std::vector<std::pair<ll, ll>> &memo, int i, const std::string &str, int x, int y, int z)
{
    if (memo[i].first != -1) return memo[i];

    std::pair<ll, ll> res;

    if (str[i - 1] == 'a')
    {
        res.first = std::min(
            solve(memo, i - 1, str, x, y, z).first + x,
            solve(memo, i - 1, str, x, y, z).second + z + x
        );
        res.second = std::min(
            solve(memo, i-1, str, x, y, z).first + z+y,
            solve(memo, i-1, str, x, y, z).second + y
        );
    }
    else
    {
        res.first = std::min(
            solve(memo, i-1, str, x, y, z).first + y,
            solve(memo, i-1, str, x, y, z).second + z + y
        );
        res.second = std::min(
            solve(memo, i-1, str, x, y, z).first + z + x,
            solve(memo, i-1, str, x, y, z).second + x
        );
    }
    
    memo[i] = res;
    return res;
}

int main()
{
    std::string str;
    int x, y, z;

    std::cin >> x >> y >> z;
    std::cin >> str;
    
    std::vector<std::pair<ll, ll>> memo(str.size()+1, std::pair<ll, ll>{-1, -1});
    memo[0].first = 0;
    memo[0].second = z;

    std::pair<ll,ll> res = solve(memo, str.size(), str, x, y, z);

    std::cout << std::min(res.first, res.second) << std::endl;

    return 0;
}