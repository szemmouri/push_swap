# Push_Swap

### Final Score: **125/125**

## Challenge

The goal is to sort a random list of integers using the smallest number of moves. You are given:  
- Two stacks: **a** and **b** (initially empty).  
- A random list of integers passed via command-line arguments.  

### Allowed Moves
Only the following operations are permitted:

- `sa`: Swap the first 2 elements at the top of stack **a**. Does nothing if there are fewer than 2 elements.
- `sb`: Swap the first 2 elements at the top of stack **b**. Does nothing if there are fewer than 2 elements.
- `ss`: Perform both `sa` and `sb` simultaneously.
- `pa`: Push the top element of stack **b** to the top of stack **a**. Does nothing if **b** is empty.
- `pb`: Push the top element of stack **a** to the top of stack **b**. Does nothing if **a** is empty.
- `ra`: Rotate stack **a** (shift all elements up; the first becomes the last).
- `rb`: Rotate stack **b** (shift all elements up; the first becomes the last).
- `rr`: Perform both `ra` and `rb` simultaneously.
- `rra`: Reverse rotate stack **a** (shift all elements down; the last becomes the first).
- `rrb`: Reverse rotate stack **b** (shift all elements down; the last becomes the first).
- `rrr`: Perform both `rra` and `rrb` simultaneously.

At the end of the program:  
- Stack **b** must be empty.  
- Stack **a** must contain all integers in ascending order.  

---

## Project Overview

This project requires creating two programs: **checker** and **push_swap**.

### 1. `checker`
- Reads a random list of integers from the command line.  
- Verifies whether the list is sorted and all operations are valid.  

### 2. `push_swap`
- Calculates the instructions to sort the integers.  
- Outputs the series of moves on the standard output.  

### Usage Together
You can pipe the output of **push_swap** into **checker**, which will validate if the instructions correctly sort the list.

### Mandatory Requirements
- Input parsing must handle errors (e.g., empty input, non-numeric parameters, duplicates).  
- Programs must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf).  
- Only the following standard functions are allowed: `write`, `read`, `malloc`, `free`, `exit`.  
- No memory leaks or crashes (e.g., segmentation faults, bus errors, double frees).  

---

## Approach

The sorting approach depends on the number of integers:  

### Case 1: **3 or Fewer Elements**
1. Identify the largest element and move it to the back (if necessary).  
2. Check if the first two elements are in ascending order; swap if not.  

### Case 2: **4 or 5 Elements**
1. Find the smallest 1-2 elements and push them to stack **b**.  
2. Sort stack **a** using the 3-element method.  
3. Push elements back from **b** to **a**.  

### Case 3: **6 or More Elements**
1. Use an array to assign sorted indices to the elements.  
2. Use a range-based approach to push elements from **a** to **b**:  
   - If the index is within the range, push to **b**.  
   - If the index is smaller, push to **b** and rotate **b**.  
   - Otherwise, rotate **a**.  
3. Once all elements are in **b**, move the largest element to the top of **b** and push it back to **a**.  

---

## Usage

### Running `checker`
```bash
./checker 5 2 3 1 4
./checker "-50 -400 -20 -1 -100"
./checker "-22" "35" "40" "-15" "75"
```

### Running `push_swap`
```bash
./push_swap 5 2 3 1 4
./push_swap "-50 -400 -20 -1 -100"
./push_swap "-22" "35" "40" "-15" "75"
```

### Running `Both Together`
```bash
ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
ARG="Random Numbers"; ./push_swap $ARG | ./checker $ARG
```
### Push Swap Visualizer
![Push_Swap Visualizer](https://github.com/szemmouri/push_swap/blob/master/visualisation.gif)

### Resourses
https://42-cursus.gitbook.io/guide/rank-02/push_swap?utm_source=chatgpt.com 
<br>
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a <br>
https://medium.com/@ayogun/push-swap-c1f5d2d41e97 <br>
https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0 <br>
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e <br>
https://github.com/42YerevanProjects/push_swap <br>
https://github.com/jdecorte-be/42-Push-Swap <br>
https://github.com/ayogun/push_swap/tree/main <br>
https://github.com/julien-ctx/push-swap/tree/main <br>
https://github.com/JamieDawson <br>
https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php <br>
https://github.com/Thuggonaut/42IC_Ring02_Push_swap/tree/main <br>

### Testers
https://github.com/Niimphu/push_swap_visualiser <br>
https://github.com/gemartin99/Push-Swap-Tester <br>
https://github.com/leofu9487/push_swap_tester
