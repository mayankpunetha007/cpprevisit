//
// Created by Mayank Punetha on 2019-09-15.
//


#ifndef CFA_LEVEL_2_REGRESSION_H
#define CFA_LEVEL_2_REGRESSION_H
#endif //CFA_LEVEL_2_REGRESSION_H

#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace boost::multiprecision;


namespace CFA_level_2 {
    namespace quant {
        class RegConstant {
        public:
            cpp_dec_float_50 intercept;
            cpp_dec_float_50 slope;
            cpp_dec_float_50 error;
        };

        class Linear {
        public:
            cpp_dec_float_50 *initial;

            explicit Linear(cpp_dec_float_50 *initial);

            cpp_dec_float_50 mean();

            cpp_dec_float_50 mode();

            cpp_dec_float_50 median();

            cpp_dec_float_50 variance();

            cpp_dec_float_50 sd();

            Linear operator+(Linear to);

            Linear operator-(Linear to);

            Linear operator*(Linear to);

            Linear operator/(Linear to);
        };

        class Regression {
        public:
            static RegConstant regression(cpp_dec_float_50 *x, cpp_dec_float_50 *y);
        };
    }
}



