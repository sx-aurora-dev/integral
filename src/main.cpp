
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "integral_func.hpp"



template <class Tin, class Tout>
void integral_test(Tin* in, Tout* out, Tout* buf, int width, int height, int loop)
{

    timeval start,end;

    gettimeofday(&start, NULL);

    for (int l = 0; l < loop; l++) {
       integral_ve<Tin,Tout>(in,out,buf,width,height);
    }

    gettimeofday(&end, NULL);
    double time =  (end.tv_sec-start.tv_sec)
                + (end.tv_usec-start.tv_usec)/(1000000.0);
    printf("integral: time = %lf ms, %lf GE/s\n",time*1000,width*height/time/1000000000*loop);


}


void test(int loop, int width, int height)
{

    int nmax = width*height;
    float *in = (float *)malloc(nmax*sizeof(float));
    float *out = (float *)malloc(nmax*sizeof(float));
    float *buf = (float *)malloc(nmax*sizeof(float));


    for (size_t n = 0; n < nmax; n++) {
        int ran = n*n;
        in[n] = 1.0/256*((ran*2)%256);
    }

   integral_test(in,out,buf,width,height,loop);


}


int main(int argc, char *argv[])
{

    int loop,width,height;

    if(argc>=2) loop = atoi(argv[1]);
    if(argc>=3) width = atol(argv[2]);
    if(argc>=4) height = atol(argv[3]);



    printf("loop %d, width %d, height %d\n",loop,width,height);


    test(loop,width,height);



    return 0;
}






