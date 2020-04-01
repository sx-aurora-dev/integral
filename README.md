# Sample code of integral image creation

This repository includes sample code of integral image creation for a gray scale image.
It is implemented to be well vectorized for SX-Aurora TSUBASA Vector Engine.

## Usage

include/intgral_func.hpp provides integral_ve template function.

```
template <class Tin, class Tout>
void integral_ve(Tin* in, Tout* out, Tout* buf, int width, int height)
```

### Arguments

 - Tin：type of input data（int,float,double,…）
 - Tout：type of output data（int,float,double,…）
 - in：pointer of input data
 - out：pointer of output data（ you need to allocate memory. ）
 - buf：pointer of temporary buffer（ you need to allocate memory. temporary buffer and output data are same size.）
 - width：width of image
 - height：height of image

## Example

```
% make
/opt/nec/ve/bin/nc++ -o integral -Iinclude src/main.cpp
nc++: vec( 101): src/main.cpp, line 39: Vectorized loop.
nc++: vec( 103): src/main.cpp, line 17: Unvectorized loop.
nc++: vec( 101): include/integral_func.hpp, line 15: Vectorized loop.
nc++: vec( 101): include/integral_func.hpp, line 20: Vectorized loop.
nc++: vec( 101): include/integral_func.hpp, line 34: Vectorized loop.
nc++: vec( 101): include/integral_func.hpp, line 39: Vectorized loop.
./integral 1 3000 4000
loop 1, width 3000, height 4000
integral: time = 1.816000 ms, 6.607930 GE/s
```

## Data Layout

This program supposes that data layout of an image as below.

![IMAGE](./image.png) 


