template <class Tin, class Tout>
void integral_ve(Tin* in, Tout* out, Tout* buf, int width, int height)
{

    const Tin* psrc = in;
    Tout *pdst = out;
    Tout *ptmp = buf;


    for(int y0 = 0; y0 < height; y0+=256) {
        Tout work1[256];
#pragma _NEC vreg(work1)
        int y_end = height-y0<256 ? height-y0:256;
#pragma _NEC shortloop
        for(int y1 = 0; y1 < y_end; y1++) {
            ptmp[0*height+(y0 + y1)] = work1[y1] = psrc[(y0 + y1)*(width)+0];
        }
        for(int x = 1; x < width; x++) {
#pragma _NEC shortloop
            for(int y1 = 0; y1 < y_end; y1++) {
                Tout temp = work1[y1] + psrc[(y0 + y1)*(width)+x];
                ptmp[x*height+(y0 + y1)] = work1[y1] = temp;

            }
        }

    }

    for(int x0 = 0; x0 < width; x0+=256) {
        Tout work2[256];
#pragma _NEC vreg(work2)
        int x_end = width-x0<256 ? width-x0:256;
#pragma _NEC shortloop
        for(int x1 = 0; x1 < x_end; x1++) {
            pdst[0*width+(x0+x1)] = work2[x1] = ptmp[(x0+x1)*height+0];
        }
        for(int y = 1; y < height; y++) {
#pragma _NEC shortloop
            for(int x1 = 0; x1 < x_end; x1++) {
                Tout temp = work2[x1] + ptmp[(x0+x1)*height+y];
                pdst[y*width+(x0+x1)] = work2[x1] = temp;
            }
        }
    }

}

