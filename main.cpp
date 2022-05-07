#include <iostream>
#include <csignal>
#include <sys/resource.h>

using namespace std;

extern void solve_A(volatile bool *do_loop);
extern void solve_B(volatile bool *do_loop);
extern void solve_C(volatile bool *do_loop);
extern void solve_D(volatile bool *do_loop);
extern void solve_E(volatile bool *do_loop);
extern void solve_F(volatile bool *do_loop);

static volatile bool s_do_loop = true;

static void s_on_signal(int s)
{
    printf("caught signal[%d].\n", s);
    s_do_loop = false;
}

int main(int argc, char *argv[])
{
    string problem;
    int problem_c;
    struct rlimit rlim;
    //int ret;

    signal(SIGINT, s_on_signal);
    signal(SIGTERM, s_on_signal);
    signal(SIGSTOP, s_on_signal);

#if 0
    getrlimit( RLIMIT_DATA, &rlim );
    printf( "rlim_cur[%lu] rlim_max[%lu]\n", rlim.rlim_cur, rlim.rlim_max );
    if ( rlim.rlim_max > ( 3UL << 30 ) )
    {
        rlim.rlim_cur = 3UL << 30;
    }
    ret = setrlimit( RLIMIT_DATA, &rlim );
    if ( ret != 0 )
    {
        perror( "setrlimit()" );
    }
#endif
    getrlimit( RLIMIT_AS, &rlim );
    printf( "rlim_cur[%lu] rlim_max[%lu]\n", rlim.rlim_cur, rlim.rlim_max );

    if (argc > 1)
    {
        problem = argv[1];
    }
    else
    {
        cout << "problem?: ";
        cin >> problem;
    }

    problem_c = toupper(problem[0]);

    printf("solving probrem [%c]\n", problem_c);

#define CASE_X(X1, X2) \
    case X1: \
        solve_##X2(&s_do_loop); \
        break

    switch (problem_c)
    {
        CASE_X('A', A);
        CASE_X('B', B);
        CASE_X('C', C);
        CASE_X('D', D);
        CASE_X('E', E);
        CASE_X('F', F);
    }

    printf("done.\n");
    return 0;
}
