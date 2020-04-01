#run
~~~
mkdir build-ve
cd build-ve
nc++ -O4 -I ./../include/ ../src/main.cpp -o integral1
./integral 1 3000 4000
~~~
terminal
~~~
-bash-4.2$ ./integral 1 3000 4000
loop 1, width 3000, height 4000
integral: time = 1.827000 ms, 6.568144 GE/s
~~~


# Function
~~~
template <class Tin, class Tout> void integral_ve(Tin* in, Tout* out, int width, int height)
~~~

# example

~~~
integral_ve<float,float>(in,out,width,height);
~~~

# argument
 - Tin：type of input data（int,float,double,…）
 - Tout：type of output data（int,float,double,…）
 - in：pointer of input data
 - out：pointer of output data（ you need to allocate memory. ）
 - width：width of image
 - height：height of image


![IMAGE](./image.png) 


