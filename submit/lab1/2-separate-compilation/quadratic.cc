#include "fns-compare.hh"
static double
quadratic(double n){
	enum{ C = 1000};
	return C*n*n;
}
static const bool isRegistered = register_fn(FnInfo("quadratic", quadratic));

