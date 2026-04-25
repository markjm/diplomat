#ifndef SOMELIB_mylib_ConstMethodOverloading_D_HPP
#define SOMELIB_mylib_ConstMethodOverloading_D_HPP

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <functional>
#include <optional>
#include <cstdlib>
#include "../diplomat_runtime.hpp"
namespace somelib {
namespace mylib {
namespace capi { struct ConstMethodOverloading; }
class ConstMethodOverloading;
} // namespace mylib
} // namespace somelib



namespace somelib::mylib {
namespace capi {
    struct ConstMethodOverloading;
} // namespace capi
} // namespace

namespace somelib::mylib {
/**
 * Tests that const &self method overloading generates nb::const_ in overload_cast.
 */
class ConstMethodOverloading {
public:

  inline static std::unique_ptr<somelib::mylib::ConstMethodOverloading> new_(std::string_view v);

  inline bool contains(std::string_view s) const;

  inline bool contains(char32_t c) const;

    inline const somelib::mylib::capi::ConstMethodOverloading* AsFFI() const;
    inline somelib::mylib::capi::ConstMethodOverloading* AsFFI();
    inline static const somelib::mylib::ConstMethodOverloading* FromFFI(const somelib::mylib::capi::ConstMethodOverloading* ptr);
    inline static somelib::mylib::ConstMethodOverloading* FromFFI(somelib::mylib::capi::ConstMethodOverloading* ptr);
    inline static void operator delete(void* ptr);
private:
    ConstMethodOverloading() = delete;
    ConstMethodOverloading(const somelib::mylib::ConstMethodOverloading&) = delete;
    ConstMethodOverloading(somelib::mylib::ConstMethodOverloading&&) noexcept = delete;
    ConstMethodOverloading operator=(const somelib::mylib::ConstMethodOverloading&) = delete;
    ConstMethodOverloading operator=(somelib::mylib::ConstMethodOverloading&&) noexcept = delete;
    static void operator delete[](void*, size_t) = delete;
};

} // namespace
#endif // SOMELIB_mylib_ConstMethodOverloading_D_HPP
