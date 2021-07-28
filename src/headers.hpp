#ifndef Y86_64_HEADERS_HPP
#define Y86_64_HEADERS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numbers>
#include <numeric>
#include <ranges>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#ifndef CPP_HPP
#define CPP_HPP

#if defined(__clang__) || defined(__GNUC__)
#define CPP_STANDARD __cplusplus
#elif defined(_MSC_VER)
#define CPP_STANDARD _MSVC_LANG
#endif

#if CPP_STANDARD >= 199711L
#define HAS_CPP_03 1
#endif

#if CPP_STANDARD >= 201103L
#define HAS_CPP_11 1
#endif

#if CPP_STANDARD >= 201402L
#define HAS_CPP_14 1
#endif

#if CPP_STANDARD >= 201703L
#define HAS_CPP_17 1
#endif

#endif

#ifdef DEBUG
#define DP_FINAL
#else
#define DP_FINAL final
#endif

// If the function can be executing return true, otherwise return false
template <typename Func, typename... ArgsType>
bool function_execute_test(Func&& func, ArgsType&&... args)
{
    try {
        std::invoke(std::forward<Func>(func), std::forward<ArgsType>(args)...);
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}

std::size_t operator"" _sz(std::size_t x)
{
    return x;
}

#endif  //Y86_64_HEADERS_HPP