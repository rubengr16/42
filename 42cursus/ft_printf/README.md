# ft\_printf
## Recode printf in order to learn about variadic arguments
The following project consist of the creation of ft\_printf function. 
It is a function which reproduces the original printf found in the 
<stdio.h> library.

```html
<div class="project-status-box" data-status="success">
  <div class="iconf-check-4 mt-4">
  success
  </div>
  <span>111</span>
</div>
```

### Mandatory Part
The prototype of the function must be the following: 
```c 
int ft_printf(const char *, ...)
```

We are allowed to user *malloc* and *free*, but I decided that they were not 
necessary for my code. The same decision was made on the case of *va\_copy*. 
On the other hand, I did use the other permitted
functions such as *write*, *va\_start*, *va\_arg*, and *va\_end*.
