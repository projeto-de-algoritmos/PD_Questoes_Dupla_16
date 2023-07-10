// ABC306 D - Poisonous Full-Course
// https://atcoder.jp/contests/abc306/tasks/abc306_d

#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using ll = long long;

std::pair<ll, ll> solve(std::vector<std::pair<bool, ll>> &meals, std::vector<std::pair<ll, ll>> &memo, int i)
{
    if (memo[i].first != LLONG_MIN) return memo[i];

    std::pair<ll, ll> res;


    if(meals[i-1].first)
    {
        res.first = solve(meals, memo, i-1).first;
        res.second = std::max(
            solve(meals, memo, i-1).first + meals[i-1].second,
            solve(meals, memo, i-1).second
        );
    }

    else
    {
        res.first = std::max(
            std::max(solve(meals, memo, i-1).first + meals[i-1].second, solve(meals, memo, i-1).first),
            solve(meals, memo, i-1).second + meals[i-1].second
        );

        res.second = solve(meals, memo, i-1).second;
    }
    
    memo[i] = res;
    return res;
}

int main()
{
    int n;

    std::cin >> n;
    std::vector<std::pair<bool, ll>> meals(n);
    
    for (int i = 0; i < n; i++)
        std::cin >> meals[i].first >> meals[i].second;

    std::vector<std::pair<ll, ll>> memo(n + 1, std::pair<ll, ll>{LLONG_MIN, LLONG_MIN});
    memo[0].first = 0;
    memo[0].second = 0;

    std::pair<ll, ll> res = solve(meals, memo, meals.size());
    std::cout << std::max(res.first, res.second) << std::endl;

    return 0;
}