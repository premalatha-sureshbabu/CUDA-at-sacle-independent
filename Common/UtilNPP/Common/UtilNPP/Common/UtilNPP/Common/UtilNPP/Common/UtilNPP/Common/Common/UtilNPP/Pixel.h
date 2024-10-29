#ifndef NV_UTIL_PIXEL_H
#define NV_UTIL_PIXEL_H

#include "Exceptions.h"

namespace npp
{
    template <typename D, size_t N>
    struct Pixel
    { };

    template <typename D>
    struct Pixel<D, 1>
    {
        D x;

        const D &
        operator[](size_t iChannel)
        const
        {
            NPP_ASSERT(iChannel < 1);
            return (&x)[iChannel];
        }

        D &
        operator[](size_t iChannel)
        {
            NPP_ASSERT(iChannel < 1);
            return (&x)[iChannel];
        }
    };

    template <typename D>
    struct Pixel<D, 2>
    {
        D x,y;

        const D &
        operator[](size_t iChannel)
        const
        {
            NPP_ASSERT(iChannel < 2);
            return (&x)[iChannel];
        }

        D &
        operator[](size_t iChannel)
        {
            NPP_ASSERT(iChannel < 2);
            return (&x)[iChannel];
        }
    };

    template <typename D>
    struct Pixel<D, 3>
    {
        D x,y,z;

        const D &
        operator[](size_t iChannel)
        const
        {
            NPP_ASSERT(iChannel < 3);
            return (&x)[iChannel];
        }

        D &
        operator[](size_t iChannel)
        {
            NPP_ASSERT(iChannel < 3);
            return (&x)[iChannel];
        }
    };

    template <typename D>
    struct Pixel<D, 4>
    {
        D x, y, z, w;

        const D &
        operator[](size_t iChannel)
        const
        {
            NPP_ASSERT(iChannel < 4);
            return (&x)[iChannel];
        }

        D &
        operator[](size_t iChannel)
        {
            NPP_ASSERT(iChannel < 4);
            return (&x)[iChannel];
        }
    };

} // npp namespace

#endif // NV_UTIL_PIXEL_H
