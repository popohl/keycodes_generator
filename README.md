# keycodes_generator
This project generates a keycodes.h file for my fractol project

It uses the last version of minilibx

The program opens a minilibx window to take in the inputs, then asks you to press the keys in a specific order.

Once you have pressed all the keys, the program ends and outputs a `keycodes.h` file that you can use in your minilibx projects.

There is a good collection of keys already present, but if you want to expand the list, just modify the global variable in `incs/keys.h`
and if needed, increase the MAX_SIZE variable, it represents how big each string is allowed to be.

Finally, if you don't like the defines, all the work is done in the `key_press` function in `srcs/initialization/hooks.c`
*(sorry for the weird file organization, I used my fractol project and removed what was useless)*

The project is not optimized in any way, and there may be leaks, but it's normed (!) and its goal is just to generate a file to use in your project,
feel free to improve it!
