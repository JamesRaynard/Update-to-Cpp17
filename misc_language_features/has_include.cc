#include <iostream>
#include <version>

/*
// Older C++
// Compiler versions which support std::variant
#ifdef _MSC_VER
#  if (_MSC_VER >= 1190)
#    define VARIANT_SUPPORT true
#  else
#    define VARIANT_SUPPORT false
#  endif
#elifdef __GNUC__
#  if (__GNUC__ >= 7)
#    define VARIANT_SUPPORT true
#  else
#    define VARIANT_SUPPORT false
#  endif
#elifdef __clang_major__
#  if (__clang_major__ >= 4)
#    define VARIANT_SUPPORT true
#  else
#    define VARIANT_SUPPORT false
#  endif
#endif
*/
/*
// C++98
// If the compiler fully implements C++17, it supports std::variant
#ifdef __cplusplus
#  if (__cplusplus >= 201703L)
#    define VARIANT_SUPPORT true
#  else
#    define VARIANT_SUPPORT false
#  endif
#endif
*/

// C++17
// If the compiler provides <variant>, it supports std::variant
#ifdef __has_include
#  if __has_include(<variant>)
#    define VARIANT_SUPPORT true
#  else
#    define VARIANT_SUPPORT false
#  endif
#endif

int main()
{
#if VARIANT_SUPPORT
	std::cout << "std::variant is supported by this compiler \n";
#else
	std::cout << "std::variant is not supported by this compiler \n";
#endif
}