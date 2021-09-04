#ifndef DBJ_STRONG_TYPE_INC_
#define DBJ_STRONG_TYPE_INC_
/*
(c) by dbj@dbj.org 

https://dbj.org/c-strong-types-holy-grail/

double AirDensityEasyToMakeAMistake(double hr, double temp, double abs_press);

DBJ_STRONG( Humidity,    double) ;
DBJ_STRONG( Temperature, double) ;
DBJ_STRONG( Pressure,    double) ;
 
// Air Density(kg/m3) from relative humidity(%),
// temperature(°C) and absolute pressure(Pa)
double AirDensity(Humidity hr, Temperature temp, Pressure abs_press)
{
return (1/(287.06*(temp.v+273.15))) *
(abs_press.v - 230.617 * hr.v * exp((17.5043 * temp.v) / (241.2 + temp.v)));
}

*/

#ifdef __cplusplus
#   define DBJ_STRONG(N,T) struct N final { using value_type = T;  T v; }
#else  // C
#   define DBJ_STRONG(N,T) typedef struct { T v; } N
#endif

#endif // DBJ_STRONG_TYPE_INC_