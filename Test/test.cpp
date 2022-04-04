#ifdef _MSC_VER
#define _SCL_SECURE_NO_WARNINGS
#endif

#if defined(_MSC_VER) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>
#endif // check memory leaks

#include "algorithm_performance_test.h"
#include "algorithm_test.h"
#include "vector_test.h"
#include "list_test.h"
#include "deque_test.h"
#include "queue_test.h"
#include "stack_test.h"
#include "map_test.h"
#include "set_test.h"
#include "unordered_map_test.h"
#include "unordered_set_test.h"
#include "string_test.h"

int main() {
    using namespace mystl::test;

    // C++为了与C兼容，让IO的时候不发生混乱，将输出流绑定在一起，会多处很多不必要的操作
    // 此操作将绑定接触，提高IO执行效率
    std::cout.sync_with_stdio(false);

    // 运行所有测试案例
    RUN_ALL_TESTS();

    // 测试案例1：函数性能测试
    // algorithm_performance_test是命名空间，在该命名空间中调用algorithm_performance_test()函数
    algorithm_performance_test::algorithm_performance_test();
    vector_test::vector_test();
    list_test::list_test();
    deque_test::deque_test();
    queue_test::queue_test();
    queue_test::priority_test();
    stack_test::stack_test();
    map_test::map_test();
    map_test::multimap_test();
    set_test::set_test();
    set_test::multiset_test();
    unordered_map_test::unordered_map_test();
    unordered_map_test::unordered_multimap_test();
    unordered_set_test::unordered_set_test();
    unordered_set_test::unordered_multiset_test();
    string_test::string_test();

#if defined(_MSC_VER) && defined(_DEBUG)
    _CrtDumpMemoryLeaks();
#endif // check memory leaks

}
