# push\_swap
## Insert numbers in a stack -**a**- and later sort it with the help of another
stack -**b**-

This project needs the creation of a stack. A stack is a type of data
structure which follows  FILO -**F**irst **I**n **L**ast **O**ut- behaviour.
In this structure the numbers received will be inserted in a stack **a**.
Later, with an algorithm chosen by the student and the help of just another
stack **b**.

## Mandatory Part
I decided to use the following data structure to create a stack:

```c
typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		n_elem;
	t_node	*head;
	t_node	*tail;
}	t_stack;
```

In order to move its elements, we will use only 11 allowed movements:

* *sa* : swap a - swaps the first 2 elements at the top of stack **a** -nothing is
done if there is less than 2 elements-.

* *sb* : swap b - same bahaviour as *sa* but in **b**.

* *ss* : does *sa* and *sb* at the same time.
