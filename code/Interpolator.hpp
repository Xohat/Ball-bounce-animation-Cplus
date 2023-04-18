//
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2015.11+
//

#ifndef SAMPLE_INTERPOLATOR_HEADER
#define SAMPLE_INTERPOLATOR_HEADER

#include "Point.hpp"

namespace example
{

    template< size_t DIMENSION, typename NUMERIC_TYPE = float >
    class Interpolator
    {
    public:

        typedef NUMERIC_TYPE Numeric_Type;
        static  const size_t dimension = DIMENSION;
        typedef example::Point< dimension, Numeric_Type > Point;

    public:

        virtual Point sample (Numeric_Type t) const = 0;

    };

}

#endif
