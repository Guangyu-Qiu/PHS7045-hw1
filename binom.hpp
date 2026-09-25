#ifndef BINOM_HPP
#define BINOM_HPP

#include <iostream>
#include <cmath>
#include <cstdio>

class Binom {
private:
  int n;
  double p;
  
public:
  // Binom(int n_, double p_) : n(n_), p(p_) {};
  Binom(int n_, double p_) {
    n = n_;
    p = p_;
  };
  int factorial(int k) const;
  double choose(int a, int b) const;
  double dbinom(int k) const;
  void print(int k) const;
};

inline int Binom::factorial(int k) const {
  if (k == 0) {
    return 1;
  } else {
    return k * factorial(k - 1);
  }
}

inline double Binom::choose(double n, double k) const {
    if (k<0 || n<0 || n < k) return 0;
    return factorial(k)/(factorial(n)*factorial(n-k))
}

#endif