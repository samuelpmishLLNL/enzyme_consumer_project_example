#include <enzyme/enzyme>

double square(double x) { return x * x; }

double foo(double x) {
  double dx = 1.0;
  return __enzyme_autodiff<double>(square, enzyme_dup, x, dx);
}
