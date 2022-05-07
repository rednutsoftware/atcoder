#include <bits/stdc++.h>
using namespace std;

#ifdef NO_PROBLEM_MAIN
#define DPRINTF(x) printf x
#else
static inline void nop() { return; }
#define DPRINTF(x) nop()
#endif

#define SOLVER(x) solve_D x
typedef long long ll;

static void s_solve(void)
{
}

void SOLVER((volatile bool *do_loop))
{
    do {
        s_solve();
    } while ((do_loop != NULL) && (*do_loop));
}

#ifndef NO_PROBLEM_MAIN
int main( void )
{
    SOLVER((NULL));
    return 0;
}
#endif
