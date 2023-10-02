# CPP02

Note: *\<name\> is used to show that name must be substituted by the real value in each real case.*

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

- Copy Assignment Operator:

Documentation: [CPPReference - Copy Assignment](https://en.cppreference.com/w/cpp/language/copy_assignment), [CPPReference - Assignment Operator](https://en.cppreference.com/w/cpp/language/operators#Assignment_operator), [SO - The Rule of Three](https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three), [SO - Copy and Swap Idiom](https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom), [SO - Public Friend Swap Member Function](https://stackoverflow.com/questions/5695548/public-friend-swap-member-function)

- Destructor: function which is called when the end of the lifetime of an object is reached. This is due to reach the end of the scope, delete expresions, etc.  
``` c++
~<Class_name>(void);
```
Documentation: [CPPReference - Destructor](https://en.cppreference.com/w/cpp/language/destructor), [CPPReference - delete](https://en.cppreference.com/w/cpp/language/delete)
