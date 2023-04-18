//
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2015.10+
//

#ifndef SAMPLE_LINEAR_INTERPOLATOR_HEADER
#define SAMPLE_LINEAR_INTERPOLATOR_HEADER

    #include "Interpolator.hpp"

    namespace example
    {

        template< size_t DIMENSION, typename NUMERIC_TYPE = float >
        class Linear_Interpolator : public Interpolator< DIMENSION, NUMERIC_TYPE >
        {
        private:

            Point origin;
            Point ending;

        public:

            Linear_Interpolator() { }
            Linear_Interpolator(const Point & given_origin, const Point & given_ending) : origin(given_origin), ending(given_ending) { }

        public:

            Point sample (Numeric_Type t) const
            {
                Point result;

                for (size_t index = 0; index < dimension; index++)
                {
                    result[index] = origin[index] * (1 - t) + ending[index] * t;
                }

                return result;
            }

        };

        template< >
        inline Linear_Interpolator< 2, float >::Point Linear_Interpolator< 2, float >::sample (Numeric_Type t) const
        {
            Point result;

            result[0] = origin[0] + (ending[0] - origin[0]) * t;
            result[1] = origin[1] + (ending[1] - origin[1]) * t;

            return result;
        }

    }

#endif
