#include "diplomat_nanobind_common.hpp"


#include "mylib/ConstMethodOverloading.hpp"

namespace somelib::mylib {
void add_ConstMethodOverloading_binding(nb::module_ mod) {
    PyType_Slot somelib_mylib_ConstMethodOverloading_slots[] = {
        {Py_tp_free, (void *)somelib::mylib::ConstMethodOverloading::operator delete },
        {Py_tp_dealloc, (void *)diplomat_tp_dealloc},
        {0, nullptr}};
    
    nb::class_<somelib::mylib::ConstMethodOverloading> opaque(mod, "ConstMethodOverloading", nb::type_slots(somelib_mylib_ConstMethodOverloading_slots));
    opaque
        .def("contains", nb::overload_cast<std::string_view>(&somelib::mylib::ConstMethodOverloading::contains, nb::const_), "s"_a)
        .def("contains", nb::overload_cast<char32_t>(&somelib::mylib::ConstMethodOverloading::contains, nb::const_), "c"_a)
        .def_static("new", std::move(maybe_op_unwrap(&somelib::mylib::ConstMethodOverloading::new_)), "v"_a);
}

} 