#ifndef Y86_64_PREPROCESSOR_HPP
#define Y86_64_PREPROCESSOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

#include <range/v3/action.hpp>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view.hpp>
#include <range/v3/view/istream.hpp>

using namespace ranges;
using namespace std::placeholders;

std::string string_to_lower(std::string_view s)
{
    return s
         | views::transform(tolower)
         | to<std::string>;
}

std::string remove_inline_comment(std::string_view s)
{
    std::string temp{s};

    const auto comment_pos1 = temp.find_first_of('#');
    if (comment_pos1 != std::string::npos)
        temp.erase(comment_pos1);

    const auto comment_pos2 = temp.find("//");
    if (comment_pos2 != std::string::npos)
        temp.erase(comment_pos2);

    const auto comment_start = temp.find("/*");
    const auto comment_end   = temp.rfind("*/");

    if (comment_start != std::string::npos && comment_end != std::string::npos)
        temp.erase(comment_start, comment_end - comment_start + 2);

    return temp;
}

std::string replace_blanks(std::string_view s)
{
    return s
         | views::transform([](char ch) { return ch == '\t' ? ' ' : ch; })
         | views::transform([](char ch) { return ch == '\f' ? ' ' : ch; })
         | views::transform([](char ch) { return ch == '\v' ? ' ' : ch; })
         | views::transform([](char ch) { return ch == '\r' ? ' ' : ch; })
         | to<std::string>;
}

std::string strip(std::string_view s)
{
    const auto _start = s.find_first_not_of("\n\t\f\v\r ");
    const auto _end   = s.find_last_not_of("\n\t\f\v\r ");
    if (_start != std::string_view::npos && _end != std::string_view::npos)
        return s.substr(_start, _end + 1).data();
    else
        return {};
}

std::vector<std::string> readlines(const std::string& filename)
{
    std::ifstream ifs{filename};

    std::vector<std::string> strings;

    for (std::string str; std::getline(std::cin, str, ';');)
        strings.push_back(str);

    return strings
         | views::transform(string_to_lower)
         | views::transform(remove_inline_comment)
         | views::transform(replace_blanks)
         | views::transform(strip)
         | views::remove_if(&std::string::empty)
         | to_vector;
}

#endif  //Y86_64_PREPROCESSOR_HPP
