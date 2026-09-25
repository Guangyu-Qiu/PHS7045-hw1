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

inline double Binom::choose(int a, int b) const {
    if (a<0 || b<0 || a<b) return 0;
    return static_cast<double>(factorial(a))
    /static_cast<double>(factorial(b)*factorial(a-b));
}

#endif