#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long int gcd_fast(long long int  a, long long int  b){
  if (b==0) return a;
  return gcd_fast(b, a%b);
}

long long int lcm_fast(long long int  a, long long int  b){
    long long int prod = a*b;
    return prod/gcd_fast(a,b);
}

int main() {
  long long int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(max(a,b) , min(a,b)) << std::endl;
  return 0;
}
