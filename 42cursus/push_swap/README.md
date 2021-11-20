#push\_swap
##Insert numbers in a stack -**a**- and later sort it with the help of another
stack -**b**-

This project needs the creation of a stack. A stack is a type of data
structure which follows  FILO -**F**irst **I**n **L**ast **O**ut- behaviour.
In this structure the numbers received will be inserted in a stack **a**.
Later, with an algorithm chosen by the student and the help of just another
stack **b**.

##Mandatory Part
I decided to use the following data structure to create a stack:

```c
typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prvs;
	int				num;
}	t_node;

typedef struct s_stack
{
	t_node *stack;
}	t_stack;
```
