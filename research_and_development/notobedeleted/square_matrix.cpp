#include <assert.h>
#include <iomanip>
#include <iostream>
#include <array>
#include <type_traits>

namespace dbj {

// since we allocate on stack 0xFF is plenty
// we could provide heap allocation variant
// with much larger allowance if anybody
// needs it
constexpr inline static int square_matrix_max_side = 0xF;

// basically just a data holder and operator
template <typename T, size_t SIDE>
struct square_matrix final {
  static_assert(std::is_arithmetic_v<T>,
                "square_matrix element type must be arithmetic type");

  static_assert(SIDE < (square_matrix_max_side + 1),
                "square_matrix max side size is 0xF");

  using type = square_matrix;
  using value_type = T;
  using matrix_ref = T (&)[SIDE][SIDE] ;
  using matrix_ptr = T (*)[SIDE][SIDE] ;

  matrix_ptr get_ptr () noexcept { return (matrix_ptr)&data; };
  matrix_ref get_ref () noexcept { return (matrix_ref)&data; };

  // there should be max matrix size constant
  constexpr inline static int rows = SIDE;
  constexpr inline static int cols = SIDE;

  // can not use this on the const instance
  constexpr float& at(unsigned r, unsigned c) noexcept {
    assert(rows > r);
    assert(cols > c);
    return data[r * rows + c];
  }

  // use this on the const instance
  constexpr float at(unsigned r, unsigned c) const noexcept {
    assert(rows > r);
    assert(cols > c);
    return data[r * rows + c];
  }

   value_type data[rows * cols]{0};
};  // square_matrix
///////////////////////////////////////////////////////////////////////////
// only multiplication is provided as universal matrix operation 
template<typename ETYPE,  size_t m,  size_t n,  size_t p >
inline void multiply( 
const ETYPE (*a)[m][n], 
const ETYPE (*b)[n][p], 
      ETYPE (*c)[m][p])
{
      static_assert(
      std::is_arithmetic_v<ETYPE>,
      "matrix multiplication element type must be arithmetic type");

    static const ETYPE zero{};

    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < p; j++) {
            (*c)[i][j] = zero;
            for (size_t k = 0; k < n; k++) {
                (*c)[i][j] += (*a)[i][k] * (*b)[k][j];
            }
        }
    }
}
// for any T and any SIDE
template <typename T, size_t SIDE>
struct square_matrix_operations final {
};

// there are matrix operations specialized by side size
template <typename T>
struct square_matrix_operations<T, 2> final {
  static_assert(
      std::is_arithmetic_v<T>,
      "square_matrix operations element type must be arithmetic type");

  constexpr inline static int side = 2;

  // note: determinant can be zero
  static constexpr T determinant(const T (&data_)[4]) noexcept {
    T rez_ = data_[0] * data_[3] - data_[1] * data_[2];
    return rez_ = 1 / rez_;
  }

   // simple, fast, universal
   static constexpr bool inversant( T (&out)[4], const T(&in)[4] ) noexcept 
   {
    T det = determinant(in);

    if ( det == T{} ) return false; //return false on zero det

    out[0] = det * (in[3]);
    out[1] = det * -(in[1]);
    out[2] = det * -(in[2]);
    out[3] = det * (in[0]);

    return true;
   }

};  // square_matrix_operations 2x2
} // dbj
//////////////////////////////////////////////////////////////
/// Usage

template <typename SQMX>
void show(SQMX const&, const char* = "");

extern "C" int test_square_matrix(void) 
{
    using namespace dbj;
  using sqm2x2 = square_matrix<float, 2>;
  using sqm2x2ops = square_matrix_operations<float, 2>;
  // aggregate initialization
  // following produces bad determinant
  // sqm2x2 mx = {{-1, 1, -1, 1}};
  sqm2x2 mx = {{1, 2, 3, 4}};
  show(mx, "before inversion");
  sqm2x2 mx_inverted;
  bool ok = sqm2x2ops::inversant(mx_inverted.data, mx.data);
  
  if (ok){
      show(mx_inverted, "after inversion");
  } else {
      show(mx_inverted, "inversion has failed");
  }

   sqm2x2 multiplied;

    multiply( 
    mx.get_ptr(), 
    mx_inverted.get_ptr(), 
    multiplied.get_ptr() 
    ) ;

    show(multiplied, "two of them multiplied");

  return 42;
}

template <typename SQMX>
static void show(SQMX const& mx, const char* prompt) {
  std::cout << "\n" << prompt;
  for (int j = 0; j < SQMX::rows; ++j) {
    std::cout << "\n";
    for (int k = 0; k < SQMX::rows; ++k) {
      std::cout << " [" << std::setw(1) << j << "," << std::setw(1) << k << ":"
                << std::setw(4) << mx.at(j, k) << "]";
    }
  }
  std::cout << "\n";
}