
#define DBJ_FIBO_FACT_IMPLEMENT
#include "dbj_fibo_fact.h"

#include <stdio.h>

#define TEST_BEGIN printf("test:%s(), file: %s, line:%d", __func__, __FILE__, __LINE__)

static int test_fibo_facto(void)
{
    TEST_BEGIN ;
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
        valstat_fibo vs = fibo( fibo_max_n );
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
        valstat_fact vs = fact32(DBJ_FACT32_MAX_N);
        assert(vs.status == 0);
        assert(vs.value == 479001600);
    }
    {
        valstat_fact64 vs = fact64(-1);
        assert(vs.status == EINVAL);
    }
    {
        valstat_fact64 vs = fact64(DBJ_FACT64_MAX_N + 1);
        assert(vs.status == EINVAL);
    }
    {
        valstat_fact64 vs = fact64(DBJ_FACT64_MAX_N);
        assert(vs.status == 0);
        assert(vs.value == 2432902008176640000);
    }
    return 0;
}

int main(void)
{
    test_fibo_facto();
}