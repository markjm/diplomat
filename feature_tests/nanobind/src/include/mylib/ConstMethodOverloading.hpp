#ifndef SOMELIB_mylib_ConstMethodOverloading_HPP
#define SOMELIB_mylib_ConstMethodOverloading_HPP

#include "ConstMethodOverloading.d.hpp"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <functional>
#include <optional>
#include <cstdlib>
#include "../diplomat_runtime.hpp"


namespace somelib::mylib {
namespace capi {
    extern "C" {

    somelib::mylib::capi::ConstMethodOverloading* ConstMethodOverloading_new(somelib::diplomat::capi::DiplomatStringView v);

    bool ConstMethodOverloading_contains_str(const somelib::mylib::capi::ConstMethodOverloading* self, somelib::diplomat::capi::DiplomatStringView s);

    bool ConstMethodOverloading_contains_char(const somelib::mylib::capi::ConstMethodOverloading* self, char32_t c);

    void ConstMethodOverloading_destroy(ConstMethodOverloading* self);

    } // extern "C"
} // namespace capi
} // namespace

inline std::unique_ptr<somelib::mylib::ConstMethodOverloading> somelib::mylib::ConstMethodOverloading::new_(std::string_view v) {
    auto result = somelib::mylib::capi::ConstMethodOverloading_new({v.data(), v.size()});
    return std::unique_ptr<somelib::mylib::ConstMethodOverloading>(somelib::mylib::ConstMethodOverloading::FromFFI(result));
}

inline bool somelib::mylib::ConstMethodOverloading::contains(std::string_view s) const {
    auto result = somelib::mylib::capi::ConstMethodOverloading_contains_str(this->AsFFI(),
        {s.data(), s.size()});
    return result;
}

inline bool somelib::mylib::ConstMethodOverloading::contains(char32_t c) const {
    auto result = somelib::mylib::capi::ConstMethodOverloading_contains_char(this->AsFFI(),
        c);
    return result;
}

inline const somelib::mylib::capi::ConstMethodOverloading* somelib::mylib::ConstMethodOverloading::AsFFI() const {
    return reinterpret_cast<const somelib::mylib::capi::ConstMethodOverloading*>(this);
}

inline somelib::mylib::capi::ConstMethodOverloading* somelib::mylib::ConstMethodOverloading::AsFFI() {
    return reinterpret_cast<somelib::mylib::capi::ConstMethodOverloading*>(this);
}

inline const somelib::mylib::ConstMethodOverloading* somelib::mylib::ConstMethodOverloading::FromFFI(const somelib::mylib::capi::ConstMethodOverloading* ptr) {
    return reinterpret_cast<const somelib::mylib::ConstMethodOverloading*>(ptr);
}

inline somelib::mylib::ConstMethodOverloading* somelib::mylib::ConstMethodOverloading::FromFFI(somelib::mylib::capi::ConstMethodOverloading* ptr) {
    return reinterpret_cast<somelib::mylib::ConstMethodOverloading*>(ptr);
}

inline void somelib::mylib::ConstMethodOverloading::operator delete(void* ptr) {
    somelib::mylib::capi::ConstMethodOverloading_destroy(reinterpret_cast<somelib::mylib::capi::ConstMethodOverloading*>(ptr));
}


#endif // SOMELIB_mylib_ConstMethodOverloading_HPP
