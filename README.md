Be awear, this project is updated by 42 so the original radix sort (with binary bits) is not fast enough to pass anymore. 

Your sorting algorithm has to sort 100 number under 700 operations to pass, and with 500 number it should operate under 5500 moves.

My first try was with binary radix sort which reached 1084 operations for 100 numbers. I couldn't find a way to improve it. So I ended up finiwith ksort, which gives me proximately 554 instructions for 100 number and 5067 for 500 numbers. Of course it varies depends on how the numbers are formed.

Useful tools:
Push Swap Visualizer
https://github.com/o-reo/push_swap_visualizer
