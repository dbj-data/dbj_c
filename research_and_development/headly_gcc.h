#define HEDLEY_C_DECL 
#define HEDLEY_UNAVAILABLE(available_since) __attribute__((__warning__("Not available until " #available_since)))
#define _CRT_INSECURE_DEPRECATE_MEMORY(_Replacement) 
#define __DBL_MIN_EXP__ (-1021)
#define __FLT32X_MAX_EXP__ 1024
#define _MCRTIMP _CRTIMP
#define _CONST_RETURN 
#define HEDLEY_TI_CL7X_VERSION_CHECK(major,minor,patch) (0)
#define __UINT_LEAST16_MAX__ 0xffff
#define _INTPTR_T_DEFINED 
#define __ATOMIC_ACQUIRE 2
#define __FLT128_MAX_10_EXP__ 4932
#define HEDLEY_GCC_HAS_BUILTIN(builtin,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#define __MINGW_GNU_PRINTF(__format,__args) __attribute__((__format__(gnu_printf,__format,__args)))
#define __FLT_MIN__ 1.17549435082228750796873653722224568e-38F
#define __GCC_IEC_559_COMPLEX 2
#define HEDLEY_LIKELY(expr) __builtin_expect (!!(expr), 1 )
#define __UINT_LEAST8_TYPE__ unsigned char
#define __SIZEOF_FLOAT80__ 16
#define _CRT_ERRNO_DEFINED 
#define HEDLEY_IBM_VERSION_CHECK(major,minor,patch) (0)
#define HEDLEY_NO_ESCAPE 
#define HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute) (0)
#define _WIN32 1
#define __INTMAX_C(c) c ## LL
#define __CHAR_BIT__ 8
#define DUMMYUNIONNAME6 
#define __MINGW64_VERSION_RC 0
#define __UINT8_MAX__ 0xff
#define HEDLEY_REINTERPRET_CAST(T,expr) ((T) (expr))
#define _WIN64 1
#define __WINT_MAX__ 0xffff
#define _WCTYPE_T_DEFINED 
#define __FLT32_MIN_EXP__ (-125)
#define __MINGW_IMPORT extern __attribute__ ((__dllimport__))
#define HEDLEY_STRINGIFY_EX(x) #x
#define USE___UUIDOF 0
#define __STDC_SECURE_LIB__ 200411L
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __SIZE_MAX__ 0xffffffffffffffffULL
#define HEDLEY_HAS_FEATURE(feature) (0)
#define HEDLEY_VERSION_DECODE_MINOR(version) (((version) % 1000000) / 1000)
#define DUMMYUNIONNAME1 
#define DUMMYUNIONNAME2 
#define DUMMYUNIONNAME3 
#define DUMMYUNIONNAME4 
#define DUMMYUNIONNAME5 
#define __WCHAR_MAX__ 0xffff
#define DUMMYUNIONNAME7 
#define DUMMYUNIONNAME8 
#define DUMMYUNIONNAME9 
#define HEDLEY_UNREACHABLE_RETURN(value) HEDLEY_UNREACHABLE()
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0(__ret,__func,__type1,__arg1,__type2,__arg2,__dsttype,__dst) 
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __DBL_DENORM_MIN__ ((double)4.94065645841246544176568792868221372e-324L)
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define HEDLEY_PREDICT_FALSE(expr,probability) __builtin_expect_with_probability(!!(expr), 0 , (probability))
#define __MINGW_MSVC2005_DEPREC_STR "This POSIX function is deprecated beginning in Visual C++ 2005, use _CRT_NONSTDC_NO_DEPRECATE to disable deprecation"
#define __GCC_IEC_559 2
#define __FLT32X_DECIMAL_DIG__ 17
#define __nothrow 
#define __FLT_EVAL_METHOD__ 0
#define __FLT64_DECIMAL_DIG__ 17
#define _WINT_T 
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __x86_64 1
#define HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#define HEDLEY_TI_ARMCL_VERSION_CHECK(major,minor,patch) (0)
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 0
#define HEDLEY_GCC_VERSION HEDLEY_GNUC_VERSION
#define __UINT_FAST64_MAX__ 0xffffffffffffffffULL
#define HEDLEY_UNLIKELY(expr) __builtin_expect (!!(expr), 0 )
#define __SIG_ATOMIC_TYPE__ int
#define HEDLEY_HAS_CPP_ATTRIBUTE_NS(ns,attribute) (0)
#define _DLL 
#define __MINGW_ATTRIB_CONST __attribute__ ((__const__))
#define __DBL_MIN_10_EXP__ (-307)
#define __FINITE_MATH_ONLY__ 0
#define _SECURECRT_FILL_BUFFER_PATTERN 0xFD
#define __STDDEF_H__ 
#define __MINGW_USE_UNDERSCORE_PREFIX 0
#define __MINGW_ATTRIB_USED __attribute__ ((__used__))
#define __GNUC_PATCHLEVEL__ 0
#define __FLT32_HAS_DENORM__ 1
#define __MINGW_SEC_WARN_STR "This function or variable may be unsafe, use _CRT_SECURE_NO_WARNINGS to disable deprecation"
#define HEDLEY_VERSION_DECODE_MAJOR(version) ((version) / 1000000)
#define _ADDRESSOF(v) (&(v))
#define __UINT_FAST8_MAX__ 0xff
#define _INC_MINGW_SECAPI 
#define __has_include(STR) __has_include__(STR)
#define _stdcall __attribute__((__stdcall__))
#define __DEC64_MAX_EXP__ 385
#define _WCHAR_T_DEFINED 
#define __INT8_C(c) c
#define _CRT_OBSOLETE(_NewItem) 
#define HEDLEY_REQUIRE_CONSTEXPR(expr) (HEDLEY_IS_CONSTEXPR_(expr) ? (expr) : (-1))
#define __INT_LEAST8_WIDTH__ 8
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffULL
#define __LONG32 long
#define __SHRT_MAX__ 0x7fff
#define __LDBL_MAX__ 1.18973149535723176502126385303097021e+4932L
#define HEDLEY_BEGIN_C_DECLS 
#define __FLT64X_MAX_10_EXP__ 4932
#define __ASSERT_H_ 
#define HEDLEY_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#define __UINT_LEAST8_MAX__ 0xff
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __FLT128_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966F128
#define __UINTMAX_TYPE__ long long unsigned int
#define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (0)
#define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("GCC diagnostic ignored \"-Wunknown-pragmas\"")
#define __mingw_bos_ovr __mingw_ovr
#define __DEC32_EPSILON__ 1E-6DF
#define __FLT_EVAL_METHOD_TS_18661_3__ 0
#define _CRT_ALIGN(x) __attribute__ ((__aligned__ (x)))
#define __MINGW_DEBUGBREAK_IMPL 1
#define __MINGW_ATTRIB_DEPRECATED_MSG(x) __attribute__ ((__deprecated__(x)))
#define __MINGW_MS_SCANF(__format,__args) __attribute__((__format__(ms_scanf, __format,__args)))
#define __UINT32_MAX__ 0xffffffffU
#define __MINGW_ATTRIB_UNUSED __attribute__ ((__unused__))
#define __LDBL_MAX_EXP__ 16384
#define HEDLEY_SENTINEL(position) __attribute__((__sentinel__(position)))
#define __FLT128_MIN_EXP__ (-16381)
#define __WINT_MIN__ 0
#define HEDLEY_COMPCERT_VERSION_CHECK(major,minor,patch) (0)
#define __mingw_ovr static __attribute__ ((__unused__)) __inline__ __cdecl
#define __FLT128_MIN_10_EXP__ (-4931)
#define __INT_LEAST16_WIDTH__ 16
#define MINGW_HAS_SECURE_API 1
#define HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) (0)
#define __SCHAR_MAX__ 0x7f
#define __FLT128_MANT_DIG__ 113
#define __WCHAR_MIN__ 0
#define HEDLEY_FALL_THROUGH __attribute__((__fallthrough__))
#define HEDLEY_GCC_HAS_FEATURE(feature,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#define __INT64_C(c) c ## LL
#define __DBL_DIG__ 15
#define HEDLEY_CLANG_HAS_ATTRIBUTE(attribute) HEDLEY_HAS_ATTRIBUTE(attribute)
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define _crt_va_arg(v,l) __builtin_va_arg(v,l)
#define __FLT64X_MANT_DIG__ 64
#define _TIME_T_DEFINED 
#define HEDLEY_CONCAT(a,b) HEDLEY_CONCAT_EX(a,b)
#define _UINTPTR_T_DEFINED 
#define HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(x) x
#define __SIZEOF_INT__ 4
#define __SIZEOF_POINTER__ 8
#define _INC_CRTDEFS_MACRO 
#define _ANONYMOUS_STRUCT __MINGW_EXTENSION
#define __USER_LABEL_PREFIX__ 
#define __C89_NAMELESSSTRUCTNAME1 
#define __C89_NAMELESSSTRUCTNAME2 
#define __C89_NAMELESSSTRUCTNAME3 
#define __C89_NAMELESSSTRUCTNAME4 
#define __C89_NAMELESSSTRUCTNAME5 
#define __CLANG_MAX_ALIGN_T_DEFINED 
#define HEDLEY_CONCAT3_EX(a,b,c) a ##b ##c
#define _W64 
#define _AGLOBAL 
#define HEDLEY_REQUIRE(expr) 
#define __FLT64X_EPSILON__ 1.08420217248550443400745280086994171e-19F64x
#define __STDC_HOSTED__ 1
#define _RSIZE_T_DEFINED 
#define __WIN32 1
#define HEDLEY_CPP_CAST(T,expr) (expr)
#define __LDBL_HAS_INFINITY__ 1
#define HEDLEY_PUBLIC __declspec(dllexport)
#define HEDLEY_DEPRECATED(since) __attribute__((__deprecated__("Since " #since)))
#define HEDLEY_UNPREDICTABLE(expr) HEDLEY_PREDICT(expr, 1, 0.5)
#define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#define __WIN64 1
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX(__ret_type,__ret_policy,__decl_spec,__name,__sec_name,__dst_attr,__dst_type,__dst) 
#define __FLT32_DIG__ 6
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(__ret,__func,__dsttype,__dst) 
#define _INC_CORECRT 
#define __FLT_EPSILON__ 1.19209289550781250000000000000000000e-7F
#define __SHRT_WIDTH__ 16
#define HEDLEY_PREDICT(expr,value,probability) __builtin_expect_with_probability( (expr), (value), (probability))
#define HEDLEY_REQUIRE_MSG(expr,msg) 
#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
#define __STDC_UTF_16__ 1
#define __MINGW_ATTRIB_MALLOC __attribute__ ((__malloc__))
#define __DEC32_MAX__ 9.999999E96DF
#define HEDLEY_PRIVATE 
#define _crt_va_copy(d,s) __builtin_va_copy(d,s)
#define __FLT64X_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951F64x
#define __MINGW32__ 1
#define _STDDEF_H 
#define __FLT32X_HAS_INFINITY__ 1
#define __INT32_MAX__ 0x7fffffff
#define _CRT_UNUSED(x) (void)x
#define __MINGW_FORTIFY_VA_ARG 0
#define __INT_WIDTH__ 32
#define __SIZEOF_LONG__ 4
#define __C89_NAMELESSSTRUCTNAME 
#define _CRTIMP_NOIA64 _CRTIMP
#define __UINT16_C(c) c
#define __PTRDIFF_WIDTH__ 64
#define __MINGW_CRT_NAME_CONCAT2(sym) ::sym ##_s
#define __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_STR(__MINGW_MSVC2005_DEPREC_STR)
#define __DECIMAL_DIG__ 21
#define __FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64
#define HEDLEY_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
#define __INTMAX_WIDTH__ 64
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY 0
#define __has_include_next(STR) __has_include_next__(STR)
#define __FLT64X_MIN_10_EXP__ (-4931)
#define __LDBL_HAS_QUIET_NAN__ 1
#define _INC__MINGW_H 
#define __FLT64_MANT_DIG__ 53
#define _REENTRANT 1
#define __w64 
#define __GNUC__ 9
#define _cdecl __attribute__((__cdecl__))
#define __MMX__ 1
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX(__ret_type,__ret_policy,__decl_spec,__name,__sec_name,__dst_attr,__dst_type,__dst,__arg1_type,__arg1,__arg2_type,__arg2,__arg3_type,__arg3) 
#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
#define __FLT_HAS_DENORM__ 1
#define __SIZEOF_LONG_DOUBLE__ 16
#define HEDLEY_CLANG_HAS_CPP_ATTRIBUTE(attribute) HEDLEY_HAS_CPP_ATTRIBUTE(attribute)
#define HEDLEY_HAS_WARNING(warning) (0)
#define __BIGGEST_ALIGNMENT__ 16
#define _CRT_DEPRECATE_TEXT(_Text) __declspec(deprecated)
#define __MINGW32_MINOR_VERSION 11
#define HEDLEY_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#define __FLT64_MAX_10_EXP__ 308
#define _threadid (__threadid())
#define DUMMYUNIONNAME 
#define __USE_CRTIMP 1
#define __DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)
#define _thiscall __attribute__((__thiscall__))
#define __INT_FAST32_MAX__ 0x7fffffff
#define __WINNT 1
#define DUMMYSTRUCTNAME1 
#define DUMMYSTRUCTNAME2 
#define DUMMYSTRUCTNAME3 
#define DUMMYSTRUCTNAME4 
#define DUMMYSTRUCTNAME5 
#define __DBL_HAS_INFINITY__ 1
#define _CRT_INSECURE_DEPRECATE_GLOBALS(_Replacement) 
#define _CRTNOALIAS 
#define __WINNT__ 1
#define __HAVE_SPECULATION_SAFE_VALUE 1
#define __MINGW_HAVE_WIDE_C99_SCANF 1
#define __DEC32_MIN_EXP__ (-94)
#define __INTPTR_WIDTH__ 64
#define __MINGW_LSYMBOL(sym) _ ##sym
#define __C89_NAMELESSUNIONNAME1 
#define __C89_NAMELESSUNIONNAME2 
#define __C89_NAMELESSUNIONNAME3 
#define __C89_NAMELESSUNIONNAME4 
#define __C89_NAMELESSUNIONNAME5 
#define __C89_NAMELESSUNIONNAME6 
#define __C89_NAMELESSUNIONNAME7 
#define __C89_NAMELESSUNIONNAME8 
#define MINGW_HAS_DDK_H 1
#define __CRT_INLINE extern inline __attribute__((__gnu_inline__))
#define __FLT32X_HAS_DENORM__ 1
#define __INT_FAST16_TYPE__ short int
#define _SIZE_T_DEFINED 
#define _fastcall __attribute__((__fastcall__))
#define __LDBL_HAS_DENORM__ 1
#define __MINGW_HAS_DXSDK 1
#define __FLT128_HAS_INFINITY__ 1
#define __MINGW_ATTRIB_NO_OPTIMIZE __attribute__((__optimize__ ("0")))
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL
#define __INT_LEAST32_MAX__ 0x7fffffff
#define __DEC32_MIN__ 1E-95DF
#define HEDLEY_GCC_HAS_EXTENSION(extension,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#define HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (HEDLEY_GCC_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#define HEDLEY_VERSION 15
#define __DBL_MAX_EXP__ 1024
#define __WCHAR_WIDTH__ 16
#define __FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32
#define __C89_NAMELESS __MINGW_EXTENSION
#define _M_X64 100
#define __DEC128_EPSILON__ 1E-33DL
#define __SSE2_MATH__ 1
#define __ATOMIC_HLE_RELEASE 131072
#define __WIN32__ 1
#define __PTRDIFF_MAX__ 0x7fffffffffffffffLL
#define __MSABI_LONG(x) x ## l
#define __amd64 1
#define HEDLEY_EMPTY_BASES 
#define HEDLEY_FLAGS_CAST(T,expr) HEDLEY_STATIC_CAST(T, expr)
#define HEDLEY_TI_CL6X_VERSION_CHECK(major,minor,patch) (0)
#define _CRTIMP_ALTERNATIVE _CRTIMP
#define __ATOMIC_HLE_ACQUIRE 65536
#define __FLT32_HAS_QUIET_NAN__ 1
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __SIZEOF_SIZE_T__ 8
#define _CRT_glob _dowildcard
#define HEDLEY_NO_THROW __attribute__((__nothrow__))
#define __FLT64X_MIN_EXP__ (-16381)
#define __SIZEOF_WINT_T__ 2
#define HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (0)
#define __LONG_LONG_WIDTH__ 64
#define _INT128_DEFINED 
#define __CRT_WIDE(_String) L ## _String
#define __FLT32_MAX_EXP__ 128
#define __MINGW64_STRINGIFY(x) __STRINGIFY(x)
#define _TIME64_T_DEFINED 
#define __GXX_ABI_VERSION 1013
#define MINGW_DDK_H 
#define __FLT_MIN_EXP__ (-125)
#define HEDLEY_GCC_HAS_WARNING(warning,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#define _SSIZE_T_DEFINED 
#define HEDLEY_VERSION_DECODE_REVISION(version) ((version) % 1000)
#define __MINGW_ATTRIB_DEPRECATED_SEC_WARN __MINGW_ATTRIB_DEPRECATED_STR(__MINGW_SEC_WARN_STR)
#define __FLT64X_HAS_QUIET_NAN__ 1
#define __INT_FAST64_TYPE__ long long int
#define HEDLEY_CONCAT3(a,b,c) HEDLEY_CONCAT3_EX(a,b,c)
#define _ANSI_STDDEF_H 
#define HEDLEY_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_HAS_ATTRIBUTE(attribute)
#define __FLT64_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F64
#define __DBL_MIN__ ((double)2.22507385850720138309023271733240406e-308L)
#define HEDLEY_END_C_DECLS 
#define HEDLEY_ARRAY_PARAM(name) (name)
#define HEDLEY_HAS_CPP_ATTRIBUTE(attribute) (0)
#define __FLT32X_EPSILON__ 2.22044604925031308084726333618164062e-16F32x
#define __DECIMAL_BID_FORMAT__ 1
#define __FLT64_MIN_EXP__ (-1021)
#define __MINGW64_VERSION_MAJOR 7
#define HEDLEY_ASSUME(expr) HEDLEY_STATIC_CAST(void, ((expr) ? 1 : (HEDLEY_UNREACHABLE(), 1)))
#define __GXX_TYPEINFO_EQUALITY_INLINE 0
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT64X_DECIMAL_DIG__ 21
#define HEDLEY_UNREACHABLE() __builtin_unreachable()
#define __DEC128_MIN__ 1E-6143DL
#define __MINGW_BROKEN_INTERFACE(x) __MINGW_PRAGMA_PARAM(message ("Interface " _CRT_STRINGIZE(x) " has unverified layout."))
#define __REGISTER_PREFIX__ 
#define __UINT16_MAX__ 0xffff
#define __DBL_HAS_DENORM__ 1
#define __cdecl __attribute__((__cdecl__))
#define __FLT32_MIN__ 1.17549435082228750796873653722224568e-38F32
#define __UINT8_TYPE__ unsigned char
#define HEDLEY_IAR_VERSION_CHECK(major,minor,patch) (0)
#define _CRT_ALTERNATIVE_IMPORTED 
#define __NO_INLINE__ 1
#define HEDLEY_DMC_VERSION_CHECK(major,minor,patch) (0)
#define _MRTIMP2 _CRTIMP
#define __FLT_MANT_DIG__ 24
#define __LDBL_DECIMAL_DIG__ 21
#define __mingw_attribute_artificial __attribute__((__artificial__))
#define __VERSION__ "9.2.0"
#define __UINT64_C(c) c ## ULL
#define _PTRDIFF_T_ 
#define HEDLEY_GNUC_HAS_BUILTIN(builtin,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#define HEDLEY_STATIC_CAST(T,expr) ((T) (expr))
#define __int16 short
#define _INC_CRTDEFS 
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(__ret,__func,__dsttype,__dst,__type1,__arg1) 
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(__ret,__func,__dsttype,__dst,__type1,__arg1,__type2,__arg2) 
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(__ret,__func,__dsttype,__dst,__type1,__arg1,__type2,__arg2,__type3,__arg3) 
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(__ret,__func,__dsttype,__dst,__type1,__arg1,__type2,__arg2,__type3,__arg3,__type4,__arg4) 
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define HEDLEY_CLANG_HAS_BUILTIN(builtin) HEDLEY_HAS_BUILTIN(builtin)
#define __int32 int
#define __FLT128_MAX_EXP__ 16384
#define __MINGW_MS_PRINTF(__format,__args) __attribute__((__format__(ms_printf, __format,__args)))
#define __MINGW64_VERSION_BUGFIX 0
#define HEDLEY_PELLES_VERSION_CHECK(major,minor,patch) (0)
#define __FLT32_MANT_DIG__ 24
#define __MINGW_HAVE_ANSI_C99_SCANF 1
#define __int64 long long
#define _CRTIMP __attribute__ ((__dllimport__))
#define _WIN32_WINNT 0x502
#define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __MSVCRT_VERSION__ 0x700
#define _PGLOBAL 
#define __FLT128_HAS_DENORM__ 1
#define __MINGW_INTRIN_INLINE extern __inline__ __attribute__((__always_inline__,__gnu_inline__))
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0(__ret_type,__ret_policy,__decl_spec,__name,__dst_attr,__dst_type,__dst) __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX(__ret_type, __ret_policy, __decl_spec, __func_name, __func_name ##_s, __dst_attr, __dst_type, __dst)
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1(__ret_type,__ret_policy,__decl_spec,__name,__dst_attr,__dst_type,__dst,__arg1_type,__arg1) __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(__ret_type, __ret_policy, __decl_spec, __func_name, __func_name ##_s, __dst_attr, __dst_type, __dst, __arg1_type, __arg1, __arg2_type, __arg2)
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2(__ret_type,__ret_policy,__decl_spec,__name,__dst_attr,__dst_type,__dst,__arg1_type,__arg1,__arg2_type,__arg2) __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(__ret_type, __ret_policy, __decl_spec, __func_name, __func_name ##_s, __dst_attr, __dst_type, __dst, __arg1_type, __arg1, __arg2_type, __arg2)
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4(__ret_type,__ret_policy,__decl_spec,__name,__dst_attr,__dst_type,__dst,__arg1_type,__arg1,__arg2_type,__arg2,__arg3_type,__arg3,__arg4_type,__arg4) __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX(__ret_type, __ret_policy, __decl_spec, __func_name, __func_name ##_s, __dst_attr, __dst_type, __dst, __arg1_type, __arg1, __arg2_type, __arg2, __arg3_type, __arg3, __arg4_type, __arg4)
#define __FLT128_DIG__ 33
#define __SCHAR_WIDTH__ 8
#define __INT32_C(c) c
#define __DEC64_EPSILON__ 1E-15DD
#define __ORDER_PDP_ENDIAN__ 3412
#define __DEC128_MIN_EXP__ (-6142)
#define _CRT_MANAGED_HEAP_DEPRECATE 
#define __FLT32_MAX_10_EXP__ 38
#define HEDLEY_CLANG_HAS_EXTENSION(extension) HEDLEY_HAS_EXTENSION(extension)
#define __INT_FAST32_TYPE__ int
#define __MINGW_ATTRIB_NONNULL(arg) __attribute__ ((__nonnull__ (arg)))
#define __MINGW_IMP_LSYMBOL(sym) __imp_ ##sym
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(__ret,__func,__vfunc,__dsttype,__dst,__type1,__arg1,__type2,__arg2) 
#define __FLT64X_HAS_INFINITY__ 1
#define __INT16_MAX__ 0x7fff
#define __UNUSED_PARAM(x) x __attribute__ ((__unused__))
#define __SIZE_TYPE__ long long unsigned int
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX(__ret_type,__ret_policy,__decl_spec,__name,__sec_name,__dst_attr,__dst_type,__dst,__arg1_type,__arg1) 
#define __UINT64_MAX__ 0xffffffffffffffffULL
#define HEDLEY_HAS_ATTRIBUTE(attribute) __has_attribute(attribute)
#define __FLT64X_DIG__ 18
#define __INT8_TYPE__ signed char
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define _CRTIMP2 _CRTIMP
#define HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#define __ptr32 
#define __FLT_RADIX__ 2
#define __INT_LEAST16_TYPE__ short int
#define __LDBL_EPSILON__ 1.08420217248550443400745280086994171e-19L
#define __UINTMAX_C(c) c ## ULL
#define __SSE_MATH__ 1
#define __ANONYMOUS_DEFINED 
#define HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("GCC diagnostic ignored \"-Wcast-qual\"")
#define __k8 1
#define __ptr64 
#define __SEH__ 1
#define __SIG_ATOMIC_MAX__ 0x7fffffff
#define HEDLEY_PREDICT_TRUE(expr,probability) __builtin_expect_with_probability(!!(expr), 1 , (probability))
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __SIZEOF_PTRDIFF_T__ 8
#define HEDLEY_CONST_CAST(T,expr) (__extension__ ({ HEDLEY_DIAGNOSTIC_PUSH HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL ((T) (expr)); HEDLEY_DIAGNOSTIC_POP }))
#define UNALIGNED __unaligned
#define __FLT32X_MANT_DIG__ 53
#define __restrict_arr __restrict
#define __CRT__NO_INLINE 1
#define HEDLEY_TI_CLPRU_VERSION_CHECK(major,minor,patch) (0)
#define _inline __inline
#define _UNION_NAME(x) 
#define HEDLEY_IS_CONSTEXPR_(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0)), int*)
#define HEDLEY_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_HAS_ATTRIBUTE(attribute)
#define HEDLEY_PGI_VERSION_CHECK(major,minor,patch) (0)
#define __x86_64__ 1
#define __FLT32X_MIN_EXP__ (-1021)
#define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF
#define __MSVCRT__ 1
#define __INT_FAST16_MAX__ 0x7fff
#define HEDLEY_CRAY_VERSION_CHECK(major,minor,patch) (0)
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY_0_3_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3) _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX(__ret_type,__ret_policy,__decl_spec,__name,__sec_name,__dst_attr,__dst_type,__dst,__arg1_type,__arg1,__arg2_type,__arg2,__arg3_type,__arg3,__arg4_type,__arg4) 
#define _TAGLC_ID_DEFINED 
#define __FLT64_DIG__ 15
#define HEDLEY_PURE __attribute__((__pure__))
#define __UINT_FAST32_MAX__ 0xffffffffU
#define HEDLEY_ARM_VERSION_CHECK(major,minor,patch) (0)
#define __UINT_LEAST64_TYPE__ long long unsigned int
#define HEDLEY_MESSAGE(msg) HEDLEY_PRAGMA(message msg)
#define __FLT_HAS_QUIET_NAN__ 1
#define HEDLEY_RESTRICT restrict
#define HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#define __FLT_MAX_10_EXP__ 38
#define HEDLEY_DEPRECATED_FOR(since,replacement) __attribute__((__deprecated__("Since " #since "; use " #replacement)))
#define __LONG_MAX__ 0x7fffffffL
#define __FLT64X_HAS_DENORM__ 1
#define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL
#define HEDLEY_GNUC_HAS_FEATURE(feature,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#define __FLT_HAS_INFINITY__ 1
#define __UINT_FAST16_TYPE__ short unsigned int
#define __DEC64_MAX__ 9.999999999999999E384DD
#define _CRT_TERMINATE_DEFINED 
#define __MINGW_EXTENSION __extension__
#define __INT_FAST32_WIDTH__ 32
#define NULL ((void *)0)
#define __CHAR16_TYPE__ short unsigned int
#define HEDLEY_WARNING(msg) HEDLEY_PRAGMA(GCC warning msg)
#define __PRAGMA_REDEFINE_EXTNAME 1
#define HEDLEY_TI_CL430_VERSION_CHECK(major,minor,patch) (0)
#define HEDLEY_CLANG_HAS_FEATURE(feature) HEDLEY_HAS_FEATURE(feature)
#define _VA_LIST_DEFINED 
#define __SIZE_WIDTH__ 64
#define __MINGW_HAVE_WIDE_C99_PRINTF 1
#define __SEG_FS 1
#define __INT_LEAST16_MAX__ 0x7fff
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY 0
#define __DEC64_MANT_DIG__ 16
#define __INT64_MAX__ 0x7fffffffffffffffLL
#define __UINT_LEAST32_MAX__ 0xffffffffU
#define __SEG_GS 1
#define __FLT32_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F32
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __SIG_ATOMIC_WIDTH__ 32
#define HEDLEY_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
#define HEDLEY_GNUC_HAS_EXTENSION(extension,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#define __INT_LEAST64_TYPE__ long long int
#define __INT16_TYPE__ short int
#define __INT_LEAST8_TYPE__ signed char
#define __STDC_VERSION__ 201710L
#define __DEC32_MAX_EXP__ 97
#define __INT_FAST8_MAX__ 0x7f
#define __FLT128_MAX__ 1.18973149535723176508575932662800702e+4932F128
#define __INTPTR_MAX__ 0x7fffffffffffffffLL
#define _INC_VADEFS 
#define __GXX_MERGED_TYPEINFO_NAMES 0
#define __FLT64_HAS_QUIET_NAN__ 1
#define __stdcall 
#define __MINGW_ASM_CALL(func) __asm__(__MINGW64_STRINGIFY(__MINGW_USYMBOL(func)))
#define __FLT32_MIN_10_EXP__ (-37)
#define __SSE2__ 1
#define _crt_va_end(v) __builtin_va_end(v)
#define __FLT32X_DIG__ 15
#define HEDLEY_ALWAYS_INLINE __attribute__((__always_inline__)) HEDLEY_INLINE
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 0
#define __LDBL_MANT_DIG__ 64
#define __MINGW_GNU_SCANF(__format,__args) __attribute__((__format__(gnu_scanf, __format,__args)))
#define __MINGW64_VERSION_STR __MINGW64_STRINGIFY(__MINGW64_VERSION_MAJOR) "." __MINGW64_STRINGIFY(__MINGW64_VERSION_MINOR) "." __MINGW64_STRINGIFY(__MINGW64_VERSION_BUGFIX)
#define __DBL_HAS_QUIET_NAN__ 1
#define HEDLEY_PRAGMA(value) _Pragma(#value)
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x
#define __GNUC_VA_LIST 
#define _GCC_MAX_ALIGN_T 
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define assert(_Expression) (void) ((!!(_Expression)) || (_assert(#_Expression,__FILE__,__LINE__),0))
#define __k8__ 1
#define __INTPTR_TYPE__ long long int
#define __UINT16_TYPE__ short unsigned int
#define __WCHAR_TYPE__ short unsigned int
#define __SIZEOF_FLOAT__ 4
#define HEDLEY_CONST __attribute__((__const__))
#define _INC_STDDEF 
#define _ARGMAX 100
#define __pic__ 1
#define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#define __MINGW_USYMBOL(sym) sym
#define __UINTPTR_MAX__ 0xffffffffffffffffULL
#define __INT_FAST64_WIDTH__ 64
#define __DEC64_MIN_EXP__ (-382)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(__ret,__func,__dsttype,__src) 
#define __FLT32_DECIMAL_DIG__ 9
#define __uintptr_t_defined 
#define HEDLEY_STATIC_ASSERT(expr,message) _Static_assert(expr, message)
#define __INT_FAST64_MAX__ 0x7fffffffffffffffLL
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __forceinline extern __inline__ __attribute__((__always_inline__,__gnu_inline__))
#define __FLT_DIG__ 6
#define __FLT32_HAS_INFINITY__ 1
#define __FLT64X_MAX_EXP__ 16384
#define __UINT_FAST64_TYPE__ long long unsigned int
#define __INT_MAX__ 0x7fffffff
#define __amd64__ 1
#define MINGW_DDRAW_VERSION 7
#define WIN32 1
#define __CRT_UUID_DECL(type,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) 
#define __code_model_medium__ 1
#define HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE(attribute) HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute)
#define _STRUCT_NAME(x) 
#define __INT64_TYPE__ long long int
#define HEDLEY_RETURNS_NON_NULL __attribute__((__returns_nonnull__))
#define __FLT_MAX_EXP__ 128
#define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(ms_printf, string_idx, first_to_check)))
#define __GNU_EXTENSION __MINGW_EXTENSION
#define WIN64 1
#define __ORDER_BIG_ENDIAN__ 4321
#define __DBL_MANT_DIG__ 53
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(__ret,__func,__type0,__arg0,__dsttype,__dst,__type1,__arg1) 
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(__ret,__func,__type0,__arg0,__dsttype,__dst,__type1,__arg1,__type2,__arg2) 
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(__ret,__func,__type0,__arg0,__dsttype,__dst,__type1,__arg1,__type2,__arg2,__type3,__arg3) 
#define _crt_va_start(v,l) __builtin_va_start(v,l)
#define __SIZEOF_FLOAT128__ 16
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffLL
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __DEC64_MIN__ 1E-383DD
#define __WINT_TYPE__ short unsigned int
#define __UINT_LEAST32_TYPE__ unsigned int
#define __SIZEOF_SHORT__ 2
#define __SSE__ 1
#define __intptr_t_defined 
#define HEDLEY_GNUC_VERSION HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#define __LDBL_MIN_EXP__ (-16381)
#define HEDLEY_STRINGIFY(x) HEDLEY_STRINGIFY_EX(x)
#define _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#define __MINGW_ATTRIB_DEPRECATED_STR(X) 
#define __FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64
#define __MINGW_PRAGMA_PARAM(x) _Pragma (#x)
#define __WINT_WIDTH__ 16
#define MINGW_SDK_INIT 
#define __INT_LEAST8_MAX__ 0x7f
#define HEDLEY_IS_CONSTANT(expr) __builtin_constant_p(expr)
#define __FLT32X_MAX_10_EXP__ 308
#define __MINGW_MSC_PREREQ(major,minor) 0
#define __crt_typefix(ctype) 
#define __MINGW_IMP_SYMBOL(sym) __imp_ ##sym
#define HEDLEY_CONSTEXPR 
#define __SIZEOF_INT128__ 16
#define __LDBL_MAX_10_EXP__ 4932
#define __ATOMIC_RELAXED 0
#define __DBL_EPSILON__ ((double)2.22044604925031308084726333618164062e-16L)
#define __thiscall __attribute__((__thiscall__))
#define __FLT128_MIN__ 3.36210314311209350626267781732175260e-4932F128
#define _CRTRESTRICT 
#define __UINT8_C(c) c
#define __FLT64_MAX_EXP__ 1024
#define HEDLEY_GNUC_VERSION_CHECK(major,minor,patch) (HEDLEY_GNUC_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#define HEDLEY_INLINE inline
#define __INT_LEAST32_TYPE__ int
#define __SIZEOF_WCHAR_T__ 2
#define __UINT64_TYPE__ long long unsigned int
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(__ret,__func,__vfunc,__dsttype,__dst,__type1,__arg1) 
#define __MINGW32_MAJOR_VERSION 3
#define _STDDEF_H_ 
#define _PTRDIFF_T_DEFINED 
#define _ANONYMOUS_UNION __MINGW_EXTENSION
#define __FLT128_HAS_QUIET_NAN__ 1
#define HEDLEY_FLAGS 
#define __INT_FAST8_TYPE__ signed char
#define __fastcall __attribute__((__fastcall__))
#define __MINGW_GNUC_PREREQ(major,minor) (__GNUC__ > (major) || (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
#define __FLT64X_MIN__ 3.36210314311209350626267781732175260e-4932F64x
#define __GNUC_STDC_INLINE__ 1
#define _THREADLOCALEINFO 
#define __FLT64_HAS_DENORM__ 1
#define __FLT32_EPSILON__ 1.19209289550781250000000000000000000e-7F32
#define __STRINGIFY(x) #x
#define __DBL_DECIMAL_DIG__ 17
#define __STDC_UTF_32__ 1
#define __unaligned 
#define __INT_FAST8_WIDTH__ 8
#define __FXSR__ 1
#define __DEC_EVAL_METHOD__ 2
#define __FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x
#define HEDLEY_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
#define HEDLEY_NO_RETURN _Noreturn
#define __CRT_STRINGIZE(_Value) #_Value
#define HEDLEY_INTEL_CL_VERSION_CHECK(major,minor,patch) (0)
#define __MINGW64__ 1
#define _CRT_PACKING 8
#define _TRUNCATE ((size_t)-1)
#define HEDLEY_TI_CL2000_VERSION_CHECK(major,minor,patch) (0)
#define HEDLEY_CONCAT_EX(a,b) a ##b
#define __MINGW_FORTIFY_LEVEL 0
#define __UINT32_C(c) c ## U
#define _CRT_SECURE_CPP_NOTHROW throw()
#define __GOT_SECURE_LIB__ __STDC_SECURE_LIB__
#define __INTMAX_MAX__ 0x7fffffffffffffffLL
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define HEDLEY_NEVER_INLINE __attribute__((__noinline__))
#define WINNT 1
#define __FLT_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT 0
#define MINGW_HAS_DDRAW_H 1
#define __INT8_MAX__ 0x7f
#define __LONG_WIDTH__ 32
#define __PIC__ 1
#define __UINT_FAST32_TYPE__ unsigned int
#define HEDLEY_HAS_BUILTIN(builtin) (0)
#define __MINGW_NOTHROW __attribute__ ((__nothrow__))
#define HEDLEY_NON_NULL(...) __attribute__((__nonnull__(__VA_ARGS__)))
#define __CHAR32_TYPE__ unsigned int
#define __FLT_MAX__ 3.40282346638528859811704183484516925e+38F
#define HEDLEY_TI_VERSION_CHECK(major,minor,patch) (0)
#define __int8 char
#define __INT32_TYPE__ int
#define _CRT_WIDE(_String) __CRT_WIDE(_String)
#define __SIZEOF_DOUBLE__ 8
#define __FLT_MIN_10_EXP__ (-37)
#define HEDLEY_GNUC_HAS_WARNING(warning,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#define __FLT64_MIN__ 2.22507385850720138309023271733240406e-308F64
#define __INT_LEAST32_WIDTH__ 32
#define __MINGW_ATTRIB_PURE __attribute__ ((__pure__))
#define __INTMAX_TYPE__ long long int
#define HEDLEY_NULL ((void*) 0)
#define _MT 
#define _INTEGRAL_MAX_BITS 64
#define __MINGW_ATTRIB_NORETURN __attribute__ ((__noreturn__))
#define __DEC128_MAX_EXP__ 6145
#define _CRTIMP_PURE _CRTIMP
#define __MINGW64_VERSION_STATE "alpha"
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __ATOMIC_CONSUME 1
#define __GNUC_MINOR__ 2
#define HEDLEY_CLANG_HAS_WARNING(warning) HEDLEY_HAS_WARNING(warning)
#define __INT_FAST16_WIDTH__ 16
#define __UINTMAX_MAX__ 0xffffffffffffffffULL
#define __DEC32_MANT_DIG__ 7
#define __FLT32X_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F32x
#define __DECLSPEC_SUPPORTED 
#define __DBL_MAX_10_EXP__ 308
#define __LDBL_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951L
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(__ret_type,__ret_policy,__decl_spec,__name,__sec_name,__dst_attr,__dst_type,__dst,__arg1_type,__arg1,__arg2_type,__arg2) 
#define __INT16_C(c) c
#define __STDC__ 1
#define __CRTDECL __cdecl
#define __MINGW_POISON_NAME(__IFACE) __IFACE ##_layout_has_not_been_verified_and_its_declaration_is_most_likely_incorrect
#define HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION _Pragma("GCC diagnostic ignored \"-Wunused-function\"")
#define static_assert _Static_assert
#define __MINGW_HAVE_ANSI_C99_PRINTF 1
#define __PTRDIFF_TYPE__ long long int
#define errno (*_errno())
#define HEDLEY_WARN_UNUSED_RESULT_MSG(msg) __attribute__((__warn_unused_result__))
#define __MINGW_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#define HEDLEY_MCST_LCC_VERSION_CHECK(major,minor,patch) (0)
#define __mingw_static_ovr __mingw_ovr
#define __ATOMIC_SEQ_CST 5
#define __MINGW_ASM_CRT_CALL(func) __asm__(__STRINGIFY(func))
#define __UINT32_TYPE__ unsigned int
#define __FLT32X_MIN_10_EXP__ (-307)
#define HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) (0)
#define __C89_NAMELESSUNIONNAME 
#define __UINTPTR_TYPE__ long long unsigned int
#define HEDLEY_TINYC_VERSION_CHECK(major,minor,patch) (0)
#define HEDLEY_HAS_EXTENSION(extension) (0)
#define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD
#define __DEC128_MANT_DIG__ 34
#define __LDBL_MIN_10_EXP__ (-4931)
#define __FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128
#define HEDLEY_VERSION_ENCODE(major,minor,revision) (((major) * 1000000) + ((minor) * 1000) + (revision))
#define __SIZEOF_LONG_LONG__ 8
#define DUMMYSTRUCTNAME 
#define __FLT128_DECIMAL_DIG__ 36
#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
#define __FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x
#define __MINGW64_VERSION_MINOR 0
#define __LDBL_DIG__ 18
#define __MINGW_ATTRIB_DEPRECATED __attribute__ ((__deprecated__))
#define __FLT_DECIMAL_DIG__ 9
#define __UINT_FAST16_MAX__ 0xffff
#define _ERRCODE_DEFINED 
#define HEDLEY_IMPORT __declspec(dllimport)
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define HEDLEY_MALLOC __attribute__((__malloc__))
#define __INT_LEAST64_WIDTH__ 64
#define __USE_MINGW_ANSI_STDIO 0
#define __UINT_FAST8_TYPE__ unsigned char
#define __WIN64__ 1
#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3(__ret_type,__ret_policy,__decl_spec,__name,__dst_attr,__dst_type,__dst,__arg1_type,__arg1,__arg2_type,__arg2,__arg3_type,__arg3) __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX(__ret_type, __ret_policy, __decl_spec, __func_name, __func_name ##_s, __dst_attr, __dst_type, __dst, __arg1_type, __arg1, __arg2_type, __arg2, __arg3_type, __arg3)
#define _TIME32_T_DEFINED 
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_RELEASE 3
#define __declspec(x) __attribute__((x))
#define _M_AMD64 100
