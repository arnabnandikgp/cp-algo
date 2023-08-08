#include "bits/stdc++.h"
using namespace std;

int main()
{
  vector<int> v(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long ans = v[0];
  v[1] -= v[0];
  v[2] -= v[0];
  while ((v[1] > 0 && v[2] > 0) && (v[1] + v[2] >= 3))
  {
    if (v[1] > v[2])
    {         
      v[1] -= 2;
      v[2]--;
      ans++;
    }
    else
    {
      v[2] -= 2;
      v[1]--;
      ans++;+
    }
  }
  cout << ans << endl;
}