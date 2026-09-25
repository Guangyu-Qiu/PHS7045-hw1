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

inline double Binom::dbinom(int k) const{
    return choose(n, k) * std::pow(p, k) * std::pow((1-p), (n-k)); 
}

inline void Binom::print(int k) const{
    std::printf("P(Y=%d ; n=%d, p=%.2f) = %.3f\n",
        k, n, p, dbinom(k));
}

#endif