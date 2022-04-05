#ifndef MYTINYSTL_ALGORITHM_PERFORMANCE_TEST_H_
#define MYTINYSTL_ALGORITHM_PERFORMANCE_TEST_H_

// 仅仅针对 sort, binary_search 做了性能测试

#include <algorithm>

#include "../MyTinySTL/algorithm.h"
#include "test.h"

// 嵌套命名空间
namespace mystl {
    namespace test {
        namespace algorithm_performance_test {

// 函数性能测试 宏定义
#define FUN_TEST1(mode, fun, count) do {                      \
    std::string fun_name = #fun;                               \
    /* 随机数种子 */                                             \
    srand((int)time(0));                                       \
    char buf[10];                                              \
    clock_t start, end;                                        \
    /* 创建指针arr，指向一个数组，数组大小为传入的count，并给数组的每个元素赋随机值 */  \
    int *arr = new int[count];                                 \
    for(size_t i = 0; i < count; ++i)  *(arr + i) = rand();    \
    start = clock();                                           \
    mode::fun(arr, arr + count);                               \
    end = clock();                                             \
    /* 计算运行时间n，并只保留时间的整数部分 */                       \
    int n = static_cast<int>(static_cast<double>(end - start)  \
        / CLOCKS_PER_SEC * 1000);                              \
    std::snprintf(buf, sizeof(buf), "%d", n);                  \
    std::string t = buf;                                       \
    t += "ms   |";                                             \
    /* setw(14)，如果t的size小于14，则前面用空格补齐到14位 */        \
    std::cout << std::setw(WIDE) << t;                         \
    delete []arr;                                              \
} while(0)

#define FUN_TEST2(mode, fun, count) do {                      \
    std::string fun_name = #fun;                               \
    srand((int)time(0));                                       \
    char buf[10];                                              \
    clock_t start, end;                                        \
    int *arr = new int[count];                                 \
    for(size_t i = 0; i < count; ++i)  *(arr + i) = rand();    \
    start = clock();                                           \
    for(size_t i = 0; i < count; ++i)                          \
        mode::fun(arr, arr + count, rand());                   \
    end = clock();                                             \
    int n = static_cast<int>(static_cast<double>(end - start)  \
        / CLOCKS_PER_SEC * 1000);                              \
    std::snprintf(buf, sizeof(buf), "%d", n);                  \
    std::string t = buf;                                       \
    t += "ms   |";                                             \
    std::cout << std::setw(WIDE) << t;                         \
    delete []arr;                                              \
} while(0)

            void sort_test() {
                std::cout << "[----------------------- function : sort -----------------------]" << std::endl;
                // 数量级
                std::cout << "| orders of magnitude |";
                // LEN1 = 100000, LEN2 = 1000000, LEN3 = 10000000
                TEST_LEN(LEN1, LEN2, LEN3, WIDE);

                // 用std的sort来测试
                std::cout << "|         std         |";
                FUN_TEST1(std, sort, LEN1);
                FUN_TEST1(std, sort, LEN2);
                FUN_TEST1(std, sort, LEN3);

                // 用自己写的stl来测试
                std::cout << std::endl << "|        mystl        |";
                FUN_TEST1(mystl, sort, LEN1);
                FUN_TEST1(mystl, sort, LEN2);
                FUN_TEST1(mystl, sort, LEN3);
                std::cout << std::endl;
            }

            void binary_search_test() {
                std::cout << "[------------------- function : binary_search ------------------]" << std::endl;
                std::cout << "| orders of magnitude |";
                TEST_LEN(LEN1, LEN2, LEN3, WIDE);
                std::cout << "|         std         |";
                FUN_TEST2(std, binary_search, LEN1);
                FUN_TEST2(std, binary_search, LEN2);
                FUN_TEST2(std, binary_search, LEN3);
                std::cout << std::endl << "|        mystl        |";
                FUN_TEST2(mystl, binary_search, LEN1);
                FUN_TEST2(mystl, binary_search, LEN2);
                FUN_TEST2(mystl, binary_search, LEN3);
                std::cout << std::endl;
            }

            // test.cpp中函数性能测试，从这里开始执行
            void algorithm_performance_test() {

// 如果宏已经被定义了，此时PERFORMANCE_TEST_ON这个宏等于1，所以执行下面代码
#if PERFORMANCE_TEST_ON
                std::cout << "[===============================================================]" << std::endl;
                std::cout << "[--------------- Run algorithm performance test ----------------]" << std::endl;
                sort_test();
                binary_search_test();
                std::cout << "[--------------- End algorithm performance test ----------------]" << std::endl;
                std::cout << "[===============================================================]" << std::endl;
#endif // PERFORMANCE_TEST_ON

            }

        } // namespace algorithm_performance_test
    } // namespace test
} // namespace mystl
#endif // !MYTINYSTL_ALGORITHM_PERFORMANCE_TEST_H_