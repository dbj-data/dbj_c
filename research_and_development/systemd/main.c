
#define DBJ_FIBO_FACT_IMPLEMENT
#include "dbj_fibo_fact.h"

int main(void)
{
    // FIBONACCI
    {
        valstat_fibo vs = fibo( - 1 );
        assert(vs.status == EINVAL);
    }
    {
        valstat_fibo vs = fibo( fibo_table_size );
        assert(vs.status == EINVAL);
    }
    {
        valstat_fibo vs = fibo( fibo_table_size  - 1 );
        assert(vs.status == 0);
        assert(vs.value == 754011380474634642);
    }
// FACTORIEL
    {
        valstat_fact vs = fact32(-1);
        assert(vs.status == EINVAL);
    }
    {
        valstat_fact vs = fact32(DBJ_FACT32_MAX_N + 1);
        assert(vs.status == EINVAL);
    }
    {
        valstat_fact vs = fact32(12);
        assert(vs.status == 0);
        assert(vs.value == 479001600);
    }
    return 0;
}