#ifndef CAMXHCMATHFUNC_H__
#define CAMXHCMATHFUNC_H__
#define D_MATH_FUNC_NG  (-1)
#define D_MATH_FUNC_OK  (0)
#if defined __GNUC__
__attribute__ ((visibility ("hidden"))) extern void CalcAddressOnLine_slXslY
#else
extern void CalcAddressOnLine_slXslY
#endif
(
    // Input
    signed long *pf_x,
    signed long *pf_y,
    signed long f_xx,
    // Output
    signed long *fp_yy
);
#if defined __GNUC__
__attribute__ ((visibility ("hidden"))) extern signed char CalcAddressOnBrokenLine_slXslY
#else
extern signed char CalcAddressOnBrokenLine_slXslY
#endif
(
    // Input
    signed long *pf_x,
    signed long *pf_y,
    unsigned long f_PointNum,
    signed long f_xx,
    // Output
    signed long *pf_yy
);
#endif