/*********************************************
 library of complex number
                         complex.h
**********************************************/

typedef struct {  double re, im;  } complex;  /* type of complex */
extern complex c_conv();
extern complex *c_string();
extern complex c_conj();
extern double c_abs();
extern double c_arg();
extern complex c_add();
extern complex c_sub();
extern complex c_mul();
extern complex c_div();
extern complex c_exp();
extern complex c_log();
extern complex c_pow();
extern complex c_sin();
extern complex c_cos();
extern complex c_tan();
extern complex c_sinh();
extern complex c_cosh();
extern complex c_tanh();
extern complex c_sqrt();
extern complex c_smu();
