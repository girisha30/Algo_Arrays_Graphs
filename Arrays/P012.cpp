#include <bits/stdc++.h>
using namespace std;

// Brute Force: check all pairs buy-sell
int profitBrute(const vector<int>& a) {
    int n = a.size();
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            best = max(best, a[j] - a[i]);
        }
    }
    return best;
}

// Optimal: track min price and max profit
int profitOptimal(const vector<int>& a) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : a) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices for " << n << " days: ";
    for (int i=0;i<n;i++) cin >> prices[i];

    cout << "Max Profit (Brute Force): " << profitBrute(prices) << endl;
    cout << "Max Profit (Optimal): " << profitOptimal(prices) << endl;
}
