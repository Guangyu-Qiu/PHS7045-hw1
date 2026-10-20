#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]


// I couldn't find a way to set seed in cpp, so I will put it in R.
// have to call it in R, so must be a function
IntegerMatrix scale_free(int n = 500, int m = 2) {
    IntegerMatrix g(n,n);
    # set initial nodes
    for (i = 0; i < m, i++){
      for (j = 0; j < m, j++){
        g(i,j) = 1;
      }
    }
    # then set diagonal to be zero.
    for (i = 0; i < n, i++){
      g(i,i) = 0;
    }
    
    //main loop: i from m to n-1
    for (i = m; i < n; i++){
      // to use sample function in cpp, we need x and prob
      IntegerVector x(i - 1);
      IntegerVector prob(i - 1);

      for (int j = 0; j < i - 1; j++) {
        x[j] = j;
        for (int k = 0; k < i; k++) {
          prob[j] += g(k, j);
        }
      }
      IntegerVector ids = sample(x, m, false, prob);
      for (int j = 0; j < m; j++) {
        g(i, ids[j]) = 1;
        g(ids[j], i) = 1;
      }
    }
    return g;
}
