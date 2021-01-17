#include <bits/stdc++.h>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(0)
#define ll long long int
using namespace std;
//#define mod 1000000007
#define pb push_back
const int MAXN = 1000000;
//const int inf = MAX_N + 9;
/*ll comb(ll n, ll r)
{
	if (r == 0)
	{
		return 1;
	}
	ll dp[MAXN][MAXN];
	for (ll i = 0; i < MAXN; i++)
	{
		dp[i][0] = dp[0][i] = 1;
	}
	for (ll i = 1; i < MAXN; i++)
	{
		for (ll j = 1; j < MAXN; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[r][n - r];
}*/
ll modexp(ll x, ll n, ll mod)
{
	ll result = 1;
	x = x % mod;
	while (n > 0)
	{
		if (n % 2 == 1)
			result = (result * x) % mod;
		x = (x * x) % mod;
		n = n / 2;
	}
	return result;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll D, c1, c2;
void extendedEuclid(ll A, ll B)
{
	if (B == 0)
	{
		D = A;
		c1 = 1;
		c2 = 0;
	}
	else
	{
		extendedEuclid(B, A % B);
		ll temp = c1;
		c1 = c2;
		c2 = temp - (A / B) * c2;
	}
}
ll modInverse(ll A, ll M)
{
	extendedEuclid(A, M);
	return (c1 % M + M) % M;
}
bool prime[11];
void sieve()
{
	memset(prime, true, sizeof(prime));
	ll n = 1001;
	for (ll i = 2; i * i <= n; i++)
	{
		if (prime[i] == true)
		{
			for (ll j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}
int mem[1000];
vector<int> ans;
int how_sum(int n, vector<int> v)
{
	if (mem[n] != -1)
		return mem[n];
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	for (int i = 0; i < v.size(); i++)
	{
		int rem = n - v[i];
		int an = how_sum(rem, v);
		mem[rem] = an;
		if (an == 1)
		{
			ans.push_back(v[i]);
			return 1;
		}
	}
	mem[n] = 0;
	return 0;
}
int main()
{
	fast;
	memset(mem, -1, sizeof(mem));
	vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	how_sum(19, v);
	if (ans.size() == 0)
		cout << "NOT POSSIBLE" << endl;
	else
	{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
	}
}
