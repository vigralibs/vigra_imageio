/************************************************************************/
/*                                                                      */
/*               Copyright 2014-2015 by Ullrich Koethe                  */
/*                                                                      */
/*    This file is part of the VIGRA2 computer vision library.          */
/*    The VIGRA2 Website is                                             */
/*        http://ukoethe.github.io/vigra2                               */
/*    Please direct questions, bug reports, and contributions to        */
/*        ullrich.koethe@iwr.uni-heidelberg.de    or                    */
/*        vigra@informatik.uni-hamburg.de                               */
/*                                                                      */
/*    Permission is hereby granted, free of charge, to any person       */
/*    obtaining a copy of this software and associated documentation    */
/*    files (the "Software"), to deal in the Software without           */
/*    restriction, including without limitation the rights to use,      */
/*    copy, modify, merge, publish, distribute, sublicense, and/or      */
/*    sell copies of the Software, and to permit persons to whom the    */
/*    Software is furnished to do so, subject to the following          */
/*    conditions:                                                       */
/*                                                                      */
/*    The above copyright notice and this permission notice shall be    */
/*    included in all copies or substantial portions of the             */
/*    Software.                                                         */
/*                                                                      */
/*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND    */
/*    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES   */
/*    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND          */
/*    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT       */
/*    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,      */
/*    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      */
/*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR     */
/*    OTHER DEALINGS IN THE SOFTWARE.                                   */
/*                                                                      */
/************************************************************************/

#ifndef VIGRA2_IMAGEIO_IMPEX_BMP_HXX
#define VIGRA2_IMAGEIO_IMPEX_BMP_HXX

#include <vigra2/imageio/codec.hxx>

// Windows Bitmap 3.0

namespace vigra {

    struct BmpDecoderImpl;
    struct BmpEncoderImpl;

    struct BmpCodecFactory : public CodecFactory
    {
        CodecDesc getCodecDesc() const;
        VIGRA_UNIQUE_PTR<Decoder> getDecoder() const;
        VIGRA_UNIQUE_PTR<Encoder> getEncoder() const;
    };

    class BmpDecoder : public Decoder
    {
        BmpDecoderImpl * pimpl;

    public:

        BmpDecoder() : pimpl(0) {}

        ~BmpDecoder();
        void init( const std::string & );
        void close();
        void abort();

        std::string getFileType() const;
        std::string getPixelType() const;

        unsigned int getWidth() const;
        unsigned int getHeight() const;
        unsigned int getNumBands() const;
        unsigned int getOffset() const;

        const void * currentScanlineOfBand( unsigned int ) const;
        void nextScanline();
    };

    class BmpEncoder : public Encoder
    {
        BmpEncoderImpl * pimpl;

    public:
        BmpEncoder() : pimpl(0) {}

        ~BmpEncoder();
        void init( const std::string & );
        void close();
        void abort();

        std::string getFileType() const;
        unsigned int getOffset() const;

        void setWidth( unsigned int );
        void setHeight( unsigned int );
        void setNumBands( unsigned int );
        void setCompressionType( const std::string &, int = -1 );
        void setPixelType( const std::string & );
        void finalizeSettings();

        void * currentScanlineOfBand( unsigned int );
        void nextScanline();
    };
}

#endif // VIGRA_IMPEX_BMP_HXX
