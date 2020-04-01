template <class Tin, class Tout> void integral_ve(Tin* in, Tout* out, int width, int height)

example：integral_ve<float,float>(in,out,width,height);


Tin：type of input data（int,float,double,…）
Tout：type of output data（int,float,double,…）
in：pointer of input data
out：pointer of output data（ you need to allocate memory. ）
Width：width of image
height：height of image
