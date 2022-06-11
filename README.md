# PUSH_SWAP

## Introduction
This project proposes to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, it's necessary to choose the most appropriate solution (out of many) based on sorting algorithms.

* [**Mandatory Part**](#mandatory-part) - The goal is to write a program in C called ***push_swap*** which calculates and displays the minimal number of instructions required to sort the integers received as arguments.

* [**Bonus Part**](#bonus-part) - The goal is to write a program called ***checker*** that takes as an argument a list of integers (which will be the stack a). The program will then wait and read instructions on the standard input (*stdin*) and execute then on the stack received as an argument and show if this instructions sorted the stack or not. 

* [**References**](#References) - Useful links to help understanding/solving the project.

* [**FAQ(fm)**](#) - Frequently Asked Question (from myself) - Collection of questions (and answers) I made to other students to help me get through the project and others questions invented to share things I think could be useful/interesting. I'll try to update the list as I eventually got other questions.

## Mandatory Part
You have at your disposal a set of integer values, 2 stacks and a set of instructions to manipulate both stacks. The instructions are the following:

| Instruction | Description |
| --- | --- |
| **sa (swap a)** | Swap the first 2 elements at the top of stack **a**. Do nothing if there is only one or no elements. |
| **sb (swap b)** | Swap the first 2 elements at the top of stack **b**. Do nothing if there is only one or no elements. |
| **ss** | **sa** and **sb** at the same time.|
| **pa (push a)** | Take the first element at the top of **b** and put it at the top of **a**. Do nothing if **b** is empty.|
| **pb (push b)** | Take the first element at the top of **a** and put it at the top of **b**. Do nothing if **a** is empty.|
| **ra (rotate a)** | Shift up all elements of stack **a** by 1, making the first element become the last one. |
| **rb (rotate b)** | Shift up all elements of stack **b** by 1, making the first element become the last one.|
| **rr** | **ra** and **rb** at the same time.|
| **rra (reverse rotate a)**| Shift down all elements of stack **a** by 1, making the last element become the first one.|
| **rrb (reverse rotate b)**| Shift down all elements of stack **b** by 1, making the last element become the first one.|
| **rrr** | **rra** and **rrb** at the same time.|

## Bonus Part

## References
Here's a list of references and useful resources that would help to learn or understand more about the project.



