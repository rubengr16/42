# ft\_printf
## Recode printf in order to learn about variadic arguments
The following project consists of the creation of ft\_printf function.
It is a function which reproduces the original printf found in the
<stdio.h> library.

**Mark**: [![rgallego's ft\_printf Score](https://badge42.herokuapp.com/api/project/rgallego/ft_printf)](https://github.com/rubengr16)


### Mandatory Part
The prototype of the function must be the following:
```c
int ft_printf(const char *, ...)
```

We are allowed to use *malloc* and *free*, but I decided that they were not
necessary for my code. The same decision I made in the case of *va\_copy*.
On the other hand, I did use the other permitted functions such as *write*,
*va\_start*, *va\_arg*, and *va\_end*.

Firstly, we should get to know all the va\_<macro> functions . The four of 
them are included in *<starg.h>*. The term variadic implies that there will
be some sort of change. Once we find a variadic function, it means that there
will be two parts:

* **Mandatory** arguments: at least one of them is required. Keep in mind that 
the order is important. So, mandatory arguments **must** be first and later
the optional ones.

* **Optional** arguments.

In order to store these **optional** arguments we use the va\_list data
strucure. It will be managed with different functions:

* void	*va\_start*(va\_list ap, argN) : initialices the list of variadic
arguments.

* void	*va\_copy*(va\_list dest, va\_list src) : copies the *src* list
inside *dest*. Useless in this project.

* type	*va\_arg*(va\_list ap, type) : obtains the *N* element of the list
and cast it into the chosen type.

* void	*va\_end*(va\_list ap) : finishes *ap* and cleans up it.

Additionally, we are permitted to use the *libft* but I decided to avoid it.
As I thought I would only need the *ft_putstr_fd* and *ft_putchar_fd* and for
the bonus part the *ft_strchr.c*.

We are asked to manage the next conversions:

* **%c** - char : prints a single character -which I managed in 
[ft\_printf\_chr.c](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_printf_chr.c)-.

* **%s** - string : prints a string of characters
-[ft\_printf\_str.c](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_printf_str.c)-.

* **%p** - pointer : prints a _void \*_ in hexadecimal followed by "0x"
-[ft\_printf\_ptr.c](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_printf_ptr.c)-.

* **%d** and **%i** - decimal : prints a decimal or integer number in base 10
-[ft\_printf\_int.c](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_printf_int.c)-.

* **%u** - unsigned : prints an unsigned decimal number in base 10.
-[ft\_printf\_uns.c](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_printf_uns.c)-.

* **%x** and **%X** - hexadecimal : prints a number in hexadecimal in base 16,
with the first conversion it will we displayed in lowercase and with the other
in uppercase.
-[ft\_printf\_hex.c](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_printf_hex.c) and
[ft\_printf\_hexup.c](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_printf_hexup.c)-

* **%%** - percent : prints a percent sign.

* **%<else>** - other incorrect conversions : prints just the char in the else.
It is undefined behaviour according to the original *printf*.

In order to know which function was needed for each conversion I used different *else if*'s located
in the main file of my project which is
[ft\_printf.c](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_printf.c).

Finally, we need to keep in mind that I used a recursive
-[ft\_putnbr\_base](https://github.com/rubengr16/42/blob/main/42cursus/ft_printf/ft_putnbr_base.c)-
for the conversions which implies a number conversion such as **p**, **d** and
**i**, **u**, **x** and **X**.

### Bonus Part

### Bibliography
* [Variadic Functions](https://www.thegeekstuff.com/2017/c-variadic-functions/)

* [man 3 stdarg](https://man7.org/linux/man-pages/man0/stdarg.h.0p.html)
