Be awear, this project is updated by 42 so the original radix sort (with binary bits) is not fast enough to pass anymore. 

Your sorting algorithm has to sort 100 number under 700 operations to pass, and with 500 number it should operate under 5500 moves.

My first try was with binary radix sort which reached 1084 operations for 100 numbers. Although one student told me he used ternary bit, which is base 3 (using 0, 1, 2), instead of binary, to make it more efficient. I am unfortunately not smart enough to figure it out. But I still left the part of radix sort in my code hoping I can manage it one day.

So I end up with ksort, which gives me proximately 554 instructions for 100 number and 5067 for 500 numbers. Of course it varies depends on how the numbers are formed. 

Useful tools:
Push Swap Visualizer
https://github.com/o-reo/push_swap_visualizer
