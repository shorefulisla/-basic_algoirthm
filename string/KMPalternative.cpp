// In the name of ALLAH
// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define pb push_back
#define endl '\n'
#define mod 1000000007

const double eps = 1e-9;
const int inf = 2000000000;
const int infl = 9000000000000000000;

#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define optimize()              \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

signed main()
{
  optimize();

  int TC;
  cin >> TC;
  while (TC--)
  {
    string a, b;
    cin >> a >> b;

    int j = 0;
    int p = -1;
    int cnt = 0, ck = 0;
    vector<int> v;
    for (int i = 0; i < a.size();)
    {
      if (a[i] == b[j])
      {
        ck = 0;
        p = i;

        while (j < b.size() and i < a.size() and a[i] == b[j])
        {
          i++;
          j++;
          ck++;
        }
        if (ck == b.size())
        {
          v.push_back(p);
          cnt++;
          j = 0;
        }
        else
        {
          j = 0;
        }
      }
      else
      {
        i++;
      }
    }
    if(cnt==0)
    {
       cout<<"Not Found"<<endl;
       cout<<endl;
    }
    else{
       cout<<cnt<<endl;
       for(auto i:v)
       {
         cout<<i+1<<" ";
       }
       cout<<endl;
       cout<<endl;
    }
  }
}