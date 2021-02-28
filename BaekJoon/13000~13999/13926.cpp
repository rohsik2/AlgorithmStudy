#include <cstdio>
#include <cmath>

//  빠른 최대공약수 확장
inline unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    unsigned long long z = __builtin_ctzll(x | y);
    x >>= __builtin_ctzll(x);
    while(y) {
        y >>= __builtin_ctzll(y);
        if(x > y) {
        	unsigned long long t = x;
        	x = y;
        	y = t;
        }
        y -= x;
    }
    return x << z;
}

// 빠른 제곱 확장
inline unsigned long long power(unsigned long long n, unsigned long long d, unsigned long long m) {
	unsigned long long k = 1;
	while(d) {
		if(d & 1) k = ((__int128)k * n) % m;
		n = ((__int128)n * n) % m;
		d >>= 1;
	}
	return k;
}

// 소수 확인 확장 (밀러 라빈, 64비트 이내 자연수에서 항상 정확함)
bool isPrime(unsigned long long n) {
	static const unsigned long long aPrimes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	static const unsigned long long bPrimes[13] = {0, 2047, 1373653, 25326001, 3215031751, 2152302898747, 3474749660383, 341550071728321, 0, 3825123056546413051, 0, 0, 1ull<<63};

	if(n <= 1) return false;
	for(int i = 0; i < 12; i++)
		if(n % aPrimes[i] == 0)
			return n == aPrimes[i];

	unsigned long long m = n - 1, s = __builtin_ctzll(m), d = m >> s;
	for(unsigned long long i = 0; n > bPrimes[i]; i++)
		if(unsigned long long x = power(aPrimes[i], d, n), r = 0; x != 1) {
			for(r = 0; r < s && x != m; r++)
				x = ((__int128)x * x) % n;
			if(r == s)
				return false;
		}
	return true;
}
inline unsigned long long gft(unsigned long long x, unsigned long long n) {
	return ((__int128)x * x - 1) % n;
}
int main() {
	unsigned long long n, r, g = 9223372036854775807;
	scanf("%lld", &n); r = n;

	// 인수분해 (바퀴 인수분해)
	static const int wheel[11]{1,2,2,4,2,4,2,4,6,2,6};
	if(n == 1) return !printf("1\n");
	if(isPrime(n)) return !printf("%llu\n", n - 1);
	for(unsigned long long i = 2, j = 0; i * i <= n / i;) {
		if(n % i == 0) {
			r = r / i * (i - 1);
			do n /= i; while(n % i == 0);
			if(isPrime(n)) goto euler;
			else if(n == 1) goto print;
		}
		i += wheel[j];
		j = j == 10 ? 3 : j + 1;
	}
	
	if(unsigned long long t = sqrtl(n); t * t != n) {
		// 인수분해 (폴라드 로)
		unsigned long long x = 2, y = 2, z = 1, k = 2;
		for(int i = 1; z == 1 || z == n; i++) {
			x = gft(x, n);
			y = gft(gft(y, n), n);
			z = gcd(x > y ? x - y : y - x, n);
			if(z == n) x = y = ++k;
		}
		r = r / z * (z - 1);
		n /= z;
	}
	else n /= t;

	euler: r = r / n * (n - 1);
	print: printf("%llu\n", r);
}