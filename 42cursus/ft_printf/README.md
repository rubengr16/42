# ft\_printf
## Recode printf in order to learn about variadic arguments
The following project consist of the creation of ft\_printf function.
It is a function which reproduces the original printf found in the
<stdio.h> library.

### Mandatory Part
The prototype of the function must be the following:
```c
int ft_printf(const char *, ...)
```

We are allowed to user *malloc* and *free*, but I decided that they were not
necessary for my code. The same decision was made on the case of *va\_copy*.
On the other hand, I did use the other permitted
functions such as *write*, *va\_start*, *va\_arg*, and *va\_end*.

Firstly, we should get to know all the va\_<macro> functons . The four of 
them are included in *<starg.h>*. The term variadic implies that there will
be some sort of change. Once we find a variadic function, it means that there
will be two parts:

* *Mandatory* arguments: at leas one of them is required. Keep in mind that 
the order is important. So, mandatory arguments *must* be first and later
the optional ones.
* *Optional* arguments.

### Bibliography
[Variadic Functions](https://www.thegeekstuff.com/2017/c-variadic-functions/)
