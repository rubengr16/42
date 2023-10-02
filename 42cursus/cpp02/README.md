# CPP02

## Orthodox Canonical Form  
Classes must contain:
- Default Constructor: either with empty args or with default values
given to each param:  
``` c++
<Class_name>(void);
// or
<Class_name>(<type> <param_name>=<default_value> [, ...]);
```  
Documentation: [CPPReference - Default Constructor](https://en.cppreference.com/w/cpp/language/default_constructor)

- Copy Constructor: initialises an object using another object of the same
class. This other object is passed by reference and used to initialise the
values of the new object:  
``` c++
<Class_name>(<Class_name> &<param_name>)
{
	<Class_attribute> = <param_name>.<Class_attr>;
	[...]
}
```
Documentation: [CPPReference - Copy Constructor](https://en.cppreference.com/w/cpp/language/copy_constructor), [GeeksForGeeks - Copy Constructor](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)
