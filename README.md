# Warning Printf Tester

A simple and rigorous tester for the _ft_printf_ project.

The objective of this tester is to compare your _ft_printf_ with the system _printf_ even if it has warnings!

## How to use?

Clone this repository inside your _ft_printf_ project directory.

```shell
git clone https://github.com/rgrmra/warning_printf_tester.git warning_printf_tester
```

Inside the tester directory use the following commands:

**To compile the mandatory test.**
```shell
make m
```

**To compile the mandatory test and execute.**
```shell
make me
```

**To compile the bonus test.**
```shell
make b
```

**To compile the bonus test and execute.**
```shell
make be
```

## Execute specific flags
**After compiling the bonus test, it's possible to execute using only the flags you want.**

It is possible to call with the flags _c_, _s_, _d_, _i_, _u_, _p_, _x_, _X_ and _%_ as following:

```shell
./test c
./test s
./test d
./test i
./test u
./test p
./test x
./test X
./test %
```

It's possible to rerun the test with the flags _m_ and _b_ as follows:

```shell
./test m
./test b
```

## Observation

> This test executes a lot of tests that could result in a warning. If you make a test in your own main and return a warning, you could ignore this configuration.
