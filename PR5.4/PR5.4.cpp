// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 1;
	for (int i = K; i <= N; i++)
		s *= (sin(1. * i)* sin(1. * i)+cos(1./i)*cos(1./i))/i/i;
	return s;
}
double S1(const int K, const int N, const int i)
{
	double x, y;
	x = ((sin(1. * i) * sin(1. * i) + cos(1. / i) * cos(1. / i)) / (i * i));
	
	if (i <= N)
		return x * S1(K, N, i + 1);
	else
		return 1;
	
}
double S2(const int K, const int N, const int i)
{
	if (i < K)
		return 1;
	else
		return ((sin(1. * i) * sin(1. * i) + cos(1. / i) * cos(1. / i)) / (i * i)) * S2(K, N, i - 1);
}
double S3(const int K, const int N, const int i, double t)
{
	t = t * ((sin(1. * i) * sin(1. * i) + cos(1. / i) * cos(1. / i)) / (i * i));
	if (i >= N)
		return t;
	else
		return S3(K, N, i + 1, t);
}
double S4(const int K, const int N, const int i, double t)
{
	t = t * ((sin(1. * i) * sin(1. * i) + cos(1. / i) * cos(1. / i)) / (i * i));
	if (i <= K)
		return t;
	else
		return S4(K, N, i - 1, t);
}

int main()
{
	int K=1, N=15;
	
	cout << "(iter) S0 = " << S0(K, N) << endl;
	cout << "(rec up ++) S1 = " << S1(K, N, K) << endl;
	cout << "(rec up --) S2 = " << S2(K, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(K, N, K, K) << endl;
	cout << "(rec down --) S4 = " << S4(K, N, N, K) << endl;
	return 0;
}
