# Fractol
A small program in c language to visualize Mandelbrot and Julia set fractals

---
# Description
Fractol is a small program written in c for visualizing fractals.

There are two set of fractals you can visualize with this program:
* [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set)
* [Julia](https://en.wikipedia.org/wiki/Julia_set)

---
# Installation (UNIX)
You can download these files and compile the program using the `Makefile` provided and `make`.

Go to the directory of the program `fract-ol/` in your shell, and execute:

```shell
> cd ~/path/to/fract-ol
> make
```

# How to execute fract-ol
In the same directory where you compiled the program <<`fract-ol/`>> you should be able to find the excutable `fractol`.

To launch the program use:
```shell
> ./fractol mandelbrot
```
or
```shell
> ./fractol julia -0.7269 -0.1889
```
This is just one example of a Julia set but you can explore other [Julia sets](https://en.wikipedia.org/wiki/Julia_set#Examples).

# Controls

* `UP`,`DOWN`,`LEFT`,`RIGHT`arrow key to move the fractal
* `.` and `,` to change more or less resolution*. Because the color is also linked with the resolution you will see how the colors change. 
* `e` to change the set of colors.


> WARNING:This will increase the amount of iterations to render the fractals so you can go as far as your maching can go

# Disclaimer

This is program has being created as an assignment for 42 Barcelona school, so it has not being optimized for performance.

# Thanks to
This code has being heavily inspired in the [Oceano Tutorial](https://www.youtube.com/@onaecO) : [fractol: render beautiful fractals in C (mandelbrot and julia set)](https://www.youtube.com/watch?v=ANLW1zYbLcs&t=6806s&ab_channel=Oceano)

Also a big thanks to [CODAM College](https://github.com/codam-coding-college) and the [MLX42](https://github.com/codam-coding-college/MLX42/tree/master) library.


