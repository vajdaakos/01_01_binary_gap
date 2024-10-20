#include <stdbool.h>
#include <stdio.h>
#include "unity.h"

static inline int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int solution(int N)
{
    int gap = 0;
    int maxgap = 0;
    bool started = false;
    while (N / 2 != 0 )
    {
        if(N % 2 != 0)
        {
            if(started == false)
            {
                started = true;
            }
            else
            {
                maxgap = max(gap,maxgap);
                gap = 0;
            }
            N -= 1;
        }
        else
        {
            if(started)
            {
                ++gap;
            }
        }
        N /= 2;
    }
    return max(gap,maxgap);
}

void setUp(void) 
{
    printf("Unity Test started.\n");
}

void tearDown(void) 
{
    printf("Unity Test ended.\n");
}
void binary_gap_test(void) {
    TEST_ASSERT_EQUAL_INT( 0,  solution(1));
    TEST_ASSERT_EQUAL_INT( 1,  solution(5));
    TEST_ASSERT_EQUAL_INT( 0,  solution(6));
    TEST_ASSERT_EQUAL_INT( 2,  solution(9));
    TEST_ASSERT_EQUAL_INT( 1,  solution(11));
    TEST_ASSERT_EQUAL_INT( 0,  solution(15));
    TEST_ASSERT_EQUAL_INT( 0,  solution(16));
    TEST_ASSERT_EQUAL_INT( 2,  solution(19));
    TEST_ASSERT_EQUAL_INT( 1,  solution(20));
    TEST_ASSERT_EQUAL_INT( 0,  solution(32));
    TEST_ASSERT_EQUAL_INT( 1,  solution(42));
    TEST_ASSERT_EQUAL_INT( 2,  solution(328));
    TEST_ASSERT_EQUAL_INT( 0,  solution(1024));
    TEST_ASSERT_EQUAL_INT( 5,  solution(1041));
    TEST_ASSERT_EQUAL_INT( 3,  solution(1162));
    TEST_ASSERT_EQUAL_INT( 2,  solution(51712));
    TEST_ASSERT_EQUAL_INT( 9,  solution(66561));
    TEST_ASSERT_EQUAL_INT( 3,  solution(561892));
    TEST_ASSERT_EQUAL_INT( 20, solution(6291457));
    TEST_ASSERT_EQUAL_INT( 4,  solution(74901729));
    TEST_ASSERT_EQUAL_INT( 25, solution(805306373));
    TEST_ASSERT_EQUAL_INT( 29, solution(1073741825));
    TEST_ASSERT_EQUAL_INT( 5,  solution(1376796946));
    TEST_ASSERT_EQUAL_INT( 28, solution(1610612737));
    TEST_ASSERT_EQUAL_INT( 0,  solution(2147483647));
}

int main()
{

    UNITY_BEGIN();
    RUN_TEST(binary_gap_test);
    return UNITY_END();
}
