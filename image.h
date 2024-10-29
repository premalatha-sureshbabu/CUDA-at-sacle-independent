#ifndef NV_UTIL_NPP_IMAGE_H
#define NV_UTIL_NPP_IMAGE_H

#include <cstddef>

namespace npp
{

    class Image
    {
        public:
            struct Size
            {
                unsigned int nWidth;
                unsigned int nHeight;

                Size() : nWidth(0), nHeight(0)
                { };

                Size(unsigned int nWidthNew, unsigned nHeightNew) : nWidth(nWidthNew), nHeight(nHeightNew)
                { };

                Size(const Size &rSize) : nWidth(rSize.nWidth), nHeight(rSize.nHeight)
                { };

                Size &
                operator= (const Size &rSize)
                {
                    if (&rSize == this)
                    {
                        return *this;
                    }

                    nWidth = rSize.nWidth;
                    nHeight = rSize.nHeight;

                    return *this;
                }

                void
                swap(Size &rSize)
                {
                    unsigned int nTemp;
                    nTemp = nWidth;
                    nWidth = rSize.nWidth;
                    rSize.nWidth = nTemp;

                    nTemp = nHeight;
                    nHeight = rSize.nHeight;
                    rSize.nHeight = nTemp;
                }
            };

            Image()
            { };

            Image(unsigned int nWidth, unsigned int nHeight) : oSize_(nWidth, nHeight)
            { };

            Image(const Image::Size &rSize) : oSize_(rSize)
            { };

            Image(const Image &rImage) : oSize_(rImage.oSize_)
            { };

            virtual
            ~Image()
            { };

            Image &
            operator= (const Image &rImage)
            {
                if (&rImage == this)
                {
                    return *this;
                }

                oSize_  = rImage.oSize_;
                return *this;
            };

            unsigned int
            width()
            const
            {
                return oSize_.nWidth;
            }

            unsigned int
            height()
            const
            {
                return oSize_.nHeight;
            }

            Size
            size()
            const
            {
                return oSize_;
            }

            void
            swap(Image &rImage)
            {
                oSize_.swap(rImage.oSize_);
            }

        private:
            Size oSize_;
    };

    bool
    operator== (const Image::Size &rFirst, const Image::Size &rSecond)
    {
        return rFirst.nWidth == rSecond.nWidth && rFirst.nHeight == rSecond.nHeight;
    }

    bool
    operator!= (const Image::Size &rFirst, const Image::Size &rSecond)
    {
        return rFirst.nWidth != rSecond.nWidth || rFirst.nHeight != rSecond.nHeight;
    }

} // npp namespace


#endif // NV_UTIL_NPP_IMAGE_H
