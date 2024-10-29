#ifndef NV_UTIL_NPP_IMAGE_PACKED_H
#define NV_UTIL_NPP_IMAGE_PACKED_H

#include "Image.h"
#include "Pixel.h"

namespace npp
{
    template<typename D, size_t N, class A>
    class ImagePacked: public npp::Image
    {
        public:
            typedef npp::Pixel<D, N>    tPixel;
            typedef D                   tData;
            static const size_t         gnChannels = N;
            typedef npp::Image::Size    tSize;

            ImagePacked(): aPixels_(0)
                , nPitch_(0)
            {
                ;
            }

            ImagePacked(unsigned int nWidth, unsigned int nHeight): Image(nWidth, nHeight)
                , aPixels_(0)
                , nPitch_(0)
            {
                aPixels_ = A::Malloc2D(width(), height(), &nPitch_);
            }

            ImagePacked(unsigned int nWidth, unsigned int nHeight, bool bTight): Image(nWidth, nHeight)
                , aPixels_(0)
                , nPitch_(0)
            {
                aPixels_ = A::Malloc2D(width(), height(), &nPitch_, bTight);
            }

            ImagePacked(const tSize &rSize): Image(rSize)
                , aPixels_(0)
                , nPitch_(0)
            {
                aPixels_ = A::Malloc2D(width(), height(), &nPitch_);
            }

            ImagePacked(const ImagePacked<D, N, A> &rImage): Image(rImage)
                , aPixels_(0)
                , nPitch_(rImage.pitch())
            {
                aPixels_ = A::Malloc2D(width(), height(), &nPitch_);
                A::Copy2D(aPixels_, nPitch_, rImage.pixels(), rImage.pitch(), width(), height());
            }

            virtual
            ~ImagePacked()
            {
                A::Free2D(aPixels_);
            }

            ImagePacked &
            operator= (const ImagePacked<D, N, A> &rImage)
            {
                // in case of self-assignment
                if (&rImage == this)
                {
                    return *this;
                }

                A::Free2D(aPixels_);
                aPixels_ = 0;
                nPitch_ = 0;

                // assign parent class's data fields (width, height)
                Image::operator =(rImage);

                aPixels_ = A::Malloc2D(width(), height(), &nPitch_);
                A::Copy2D(aPixels_, nPitch_, rImage.data(), rImage.pitch(), width(), height());

                return *this;
            }

            unsigned int
            pitch()
            const
            {
                return nPitch_;
            }

            /// Get a pointer to the pixel array.
            ///     The result pointer can be offset to pixel at position (x, y) and
            /// even negative offsets are allowed.
            /// \param nX Horizontal pointer/array offset.
            /// \param nY Vertical pointer/array offset.
            /// \return Pointer to the pixel array (or first pixel in array with coordinates (nX, nY).
            tPixel *
            pixels(int nX = 0, int nY = 0)
            {
                return reinterpret_cast<tPixel *>(reinterpret_cast<unsigned char *>(aPixels_) + nY * pitch() + nX * gnChannels * sizeof(D));
            }

            const
            tPixel *
            pixels(int nX = 0, int nY = 0)
            const
            {
                return reinterpret_cast<const tPixel *>(reinterpret_cast<unsigned char *>(aPixels_) + nY * pitch() + nX * gnChannels * sizeof(D));
            }

            D *
            data(int nX = 0, int nY = 0)
            {
                return reinterpret_cast<D *>(pixels(nX, nY));
            }

            const
            D *
            data(int nX = 0, int nY = 0)
            const
            {
                return reinterpret_cast<const D *>(pixels(nX, nY));
            }

            void
            swap(ImagePacked<D, N, A> &rImage)
            {
                Image::swap(rImage);

                tData *aTemp   = aPixels_;
                aPixels_        = rImage.aPixels_;
                rImage.aPixels_ = aTemp;

                unsigned int nTemp = nPitch_;
                nPitch_            = rImage.nPitch_;
                rImage.nPitch_     = nTemp;
            }

        private:
            D *aPixels_;
            unsigned int nPitch_;
    };

} // npp namespace


#endif // NV_IMAGE_IPP_H
