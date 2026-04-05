#include <bits/stdc++.h>
using namespace std;

int main() {
   long long n, m, k;
   cin >> n;
   vector<long long> arr1(n);
   for (int i = 0; i < n; i++) cin >> arr1[i];

   cin >> m;
   vector<long long> arr2(m);
   for (int i = 0; i < m; i++) cin >> arr2[i];

   cin >> k;
   sort(arr2.begin(), arr2.end());

   long long left = -2e18, right = 2e18;

   while (left + 1 < right) {
      long long mid = left + (right - left) / 2;
      long long cnt = 0;

      for (int i = 0; i < n; i++) {
         long long target = mid - arr1[i];
         int lo = 0, hi = m;
         while (lo < hi) {
            int mb = lo + (hi - lo) / 2;
            if (arr2[mb] <= target)
               lo = mb + 1;
            else
               hi = mb;
         }
         cnt += lo;
      }

      if (cnt >= k)
         right = mid;
      else
         left = mid;
   }

   cout << right;
   return 0;
}