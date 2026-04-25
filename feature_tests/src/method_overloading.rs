//! Tests for method overloading with constructors, named constructors, and regular methods.
//!
//! This test addresses the panic that occurred when multiple methods were renamed to Python
//! keywords (like "from") which get escaped to "from_". The code detected these as duplicate
//! entries but failed to handle `NamedConstructor` special methods, only accounting for
//! regular `Constructor` types.

#[diplomat::bridge]
#[diplomat::attr(auto, namespace = "mylib")]
pub mod ffi {
    use diplomat_runtime::DiplomatStr;

    #[diplomat::opaque]
    #[diplomat::cfg(supports = method_overloading)]
    pub struct MethodOverloading;

    impl MethodOverloading {
        #[diplomat::attr(supports = method_overloading, rename = "from")]
        #[diplomat::attr(auto, named_constructor)]
        pub fn from_int32(_v: i32) -> Box<MethodOverloading> {
            Box::new(MethodOverloading)
        }

        #[diplomat::attr(supports = method_overloading, rename = "from")]
        #[diplomat::attr(auto, named_constructor)]
        pub fn from_int64(_v: i64) -> Box<MethodOverloading> {
            Box::new(MethodOverloading)
        }

        #[diplomat::attr(supports = method_overloading, rename = "from")]
        #[diplomat::attr(auto, named_constructor)]
        pub fn from_uint32(_v: u32) -> Box<MethodOverloading> {
            Box::new(MethodOverloading)
        }
    }

    /// Tests that const &self method overloading generates nb::const_ in overload_cast.
    #[diplomat::opaque]
    #[diplomat::cfg(supports = method_overloading)]
    pub struct ConstMethodOverloading(String);

    impl ConstMethodOverloading {
        #[diplomat::attr(auto, named_constructor)]
        pub fn new(v: &DiplomatStr) -> Box<ConstMethodOverloading> {
            Box::new(ConstMethodOverloading(
                String::from_utf8(v.to_owned()).unwrap(),
            ))
        }

        #[diplomat::attr(supports = method_overloading, rename = "contains")]
        pub fn contains_str(&self, s: &DiplomatStr) -> bool {
            let needle = String::from_utf8(s.to_owned()).unwrap();
            self.0.contains(&needle)
        }

        #[diplomat::attr(supports = method_overloading, rename = "contains")]
        pub fn contains_char(&self, c: DiplomatChar) -> bool {
            if let Some(ch) = char::from_u32(c) {
                self.0.contains(ch)
            } else {
                false
            }
        }
    }
}
