# CPP02

## Orthodox Canonical Form  
Classes mus contain:
- Default Constructor: either with empty args or with default values
given to each param:  
``` c++
<Class_name>(void);
// or
<Class_name>(<type> <param_name>=<default_value> [, ...]);
```  

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
