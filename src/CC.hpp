#ifndef Y86_64_CC_HPP
#define Y86_64_CC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

//* Condition Codes Tag
struct Y86CCTag {
    constexpr explicit Y86CCTag(uint8_t value = 0) noexcept(false);

    Y86CCTag& operator|=(const Y86CCTag& other);
    Y86CCTag& operator&=(const Y86CCTag& other);

    friend Y86CCTag operator|(const Y86CCTag& lval, const Y86CCTag& rval);
    friend Y86CCTag operator&(const Y86CCTag& lval, const Y86CCTag& rval);
    friend Y86CCTag operator~(const Y86CCTag& other);

    explicit operator bool() const;

private:
    uint8_t m_value = 0;
};

// clang-format off
template <typename CCTagType = Y86CCTag> constexpr auto ZF = CCTagType{0x1};  // 0 0 1
template <typename CCTagType = Y86CCTag> constexpr auto SF = CCTagType{0x2};  // 0 1 0
template <typename CCTagType = Y86CCTag> constexpr auto OF = CCTagType{0x4};  // 1 0 0
// clang-format on

template <typename CCTagType = Y86CCTag>
struct Y86ConditionCodes {
    using CCTag = CCTagType;
    // clang-format off
    constexpr Y86ConditionCodes(const Y86ConditionCodes&)            = delete;
    constexpr Y86ConditionCodes(Y86ConditionCodes&&)                 = delete;
    constexpr Y86ConditionCodes& operator=(const Y86ConditionCodes&) = delete;
    constexpr Y86ConditionCodes& operator=(Y86ConditionCodes&&)      = delete;
    // clang-format on

    static Y86ConditionCodes& execute()
    {
        static std::unique_ptr<Y86ConditionCodes> cc{new Y86ConditionCodes()};
        return *cc;
    }

    [[nodiscard]] const Y86CCTag& get() const;
    CCTag& get();
    void set(const CCTag& cc_tag);
    void clear(const CCTag& cc_tag = CCTag{0x7});
    void show() const;

protected:
    constexpr Y86ConditionCodes() = default;

private:
    CCTag m_cc;
};

#include "impl/CC.ipp"

#endif  //Y86_64_CC_HPP
