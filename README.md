## About

Final project of the programming language I subject at the Federal University of Maranhão. In this work our group(Gabriel Bastos,Gabriel Belo and Joao Felipe) was responsible for developing an algorithm for the knapsack problem, a classic optimization problem, for this problem we used a solution with dynamic programming.

## Problem

The knapsack problem is a classic problem in combinatorial optimization. We are given a set of items, each with a weight and a value, and we need to determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.



## How to Run

1. Clone the project: 
```bash
$  git clone https://github.com/GabrielBeloDev/Final-Work-LP1-UFMA.git ```
2. Navigate to the project directory.
3. Compile the C code.
```bash
$ gcc -o main main.c
```
4. Run the executable.
```bash
$ ./main
```

## Instance Reading Example

The program reads the instance from a file. The instance must be formatted as follows:

1. The first line contains two integers, the number of items `n` and the maximum weight `W`.
2. The next `n` lines each contain two integers, the value and weight of each item.

Example:
```
5 15
12 4
2 2
1 1
1 2
4 10
```

This instance represents a knapsack problem with 5 items and a maximum weight of 15. The items have values and weights as follows: (12, 4), (2, 2), (1, 1), (1, 2), (4, 10).

The instance file should be located in the same directory as the executable and should be named `instance.txt`.

## How to Contribute

If you want to contribute to this project, you can make a pull request. 

1. Fork the repository.
2. Create a new branch for your features.
3. Push your changes to your branch.
4. Submit a pull request from your branch to the master branch in the original repository.

We appreciate any contributions, whether they are small typo fixes or new features.

For more details, check out the GitHub documentation on [contributing to a project](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests).

![Problem Example](https://i.postimg.cc/tCWRSjc6/Captura-de-tela-de-2023-06-21-09-50-18.png)
