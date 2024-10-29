#ifndef NV_UTIL_NPP_IMAGES_CPU_H
#define NV_UTIL_NPP_IMAGES_CPU_H

#include "ImagePacked.h"

#include "ImageAllocatorsCPU.h"
#include "Exceptions.h"

#include <npp.h>


namespace npp
{

    template<typename D, unsigned int N, class A>
    class ImageCPU: public npp::ImagePacked<D, N, A>
    {
        public:

            ImageCPU()
            {
                ;
            }

            ImageCPU(unsigned int nWidth, unsigned int nHeight): ImagePacked<D, N, A>(nWidth, nHeight)
            {
                ;
            }

            explicit
            ImageCPU(const npp::Image::Size &rSize): ImagePacked<D, N, A>(rSize)
            {
                ;
            }

            ImageCPU(const ImageCPU<D, N, A> &rImage): Image(rImage)
            {
                ;
            }

            virtual
            ~ImageCPU()
            {
                ;
            }

            ImageCPU &
            operator= (const ImageCPU<D, N, A> &rImage)
            {
                ImagePacked<D, N, A>::operator= (rImage);

                return *this;
            }

            npp::Pixel<D, N> &
            operator()(unsigned int iX, unsigned int iY)
            {
                return *ImagePacked<D, N, A>::pixels(iX, iY);
            }

            npp::Pixel<D, N>
            operator()(unsigned int iX, unsigned int iY)
            const
            {
                return *ImagePacked<D, N, A>::pixels(iX, iY);
            }

    };


    typedef ImageCPU<Npp8u,  1, npp::ImageAllocatorCPU<Npp8u,      1>  >   ImageCPU_8u_C1;
    typedef ImageCPU<Npp8u,  2, npp::ImageAllocatorCPU<Npp8u,      2>  >   ImageCPU_8u_C2;
    typedef ImageCPU<Npp8u,  3, npp::ImageAllocatorCPU<Npp8u,      3>  >   ImageCPU_8u_C3;
    typedef ImageCPU<Npp8u,  4, npp::ImageAllocatorCPU<Npp8u,      4>  >   ImageCPU_8u_C4;

    typedef ImageCPU<Npp16u, 1, npp::ImageAllocatorCPU<Npp16u,     1>  >   ImageCPU_16u_C1;
    typedef ImageCPU<Npp16u, 3, npp::ImageAllocatorCPU<Npp16u,     3>  >   ImageCPU_16u_C3;
    typedef ImageCPU<Npp16u, 4, npp::ImageAllocatorCPU<Npp16u,     4>  >   ImageCPU_16u_C4;

    typedef ImageCPU<Npp16s, 1, npp::ImageAllocatorCPU<Npp16s,     1>  >   ImageCPU_16s_C1;
    typedef ImageCPU<Npp16s, 3, npp::ImageAllocatorCPU<Npp16s,     3>  >   ImageCPU_16s_C3;
    typedef ImageCPU<Npp16s, 4, npp::ImageAllocatorCPU<Npp16s,     4>  >   ImageCPU_16s_C4;

    typedef ImageCPU<Npp32s, 1, npp::ImageAllocatorCPU<Npp32s,     1>  >   ImageCPU_32s_C1;
    typedef ImageCPU<Npp32s, 3, npp::ImageAllocatorCPU<Npp32s,     3>  >   ImageCPU_32s_C3;
    typedef ImageCPU<Npp32s, 4, npp::ImageAllocatorCPU<Npp32s,     4>  >   ImageCPU_32s_C4;

    typedef ImageCPU<Npp32f, 1, npp::ImageAllocatorCPU<Npp32f,     1>  >   ImageCPU_32f_C1;
    typedef ImageCPU<Npp32f, 3, npp::ImageAllocatorCPU<Npp32f,     3>  >   ImageCPU_32f_C3;
    typedef ImageCPU<Npp32f, 4, npp::ImageAllocatorCPU<Npp32f,     4>  >   ImageCPU_32f_C4;

} // npp namespace

#endif // NV_IMAGE_IPP_H
