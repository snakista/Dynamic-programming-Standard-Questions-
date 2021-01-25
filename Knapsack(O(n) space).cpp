#include <bits/stdc++.h>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(0)
#define ll long long int
using namespace std;
//#define mod 1000000007
#define pb push_back
const int MAX_N = 1000000;
const int inf = MAX_N + 9;
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
bool prime[101];
void sieve()
{
	memset(prime, true, sizeof(prime));
	ll n = 101;
	for (ll i = 2; i * i <= n; i++)
	{
		if (prime[i] == true)
		{
			for (ll j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}
int main()
{
	fast;
	bool pos[13]; // ith position tells whether we can make sum equal to i using weights given or not
	int w[4] = {1, 3, 3, 5};
	memset(pos, false, sizeof(pos));
	pos[0] = true; // if sum required is 0 then 1 way dont select anything ie, it is possible
	for (int k = 0; k < 4; k++)
	{
		for (int x = 12 - w[k]; x >= 0; x--)
		{
			pos[x + w[k]] |= pos[x]; // take k=1 ie, w=3 now update each value from last like if we want to make 12 then if we take weight 3 then problem reduces to m-w[k]=9 now whether 9 is possible to make without including 3 now as now we are left with only wight=1
      //similarly update each position
		}
	}
	for (int i = 0; i <= 12; i++)
		cout << pos[i] << " ";
}
