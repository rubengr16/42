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
	struct s_node	*prvs;
}	t_node;

typedef struct s_stack
{
	int		n_elem;
	t_node	*head;
}	t_stack;
```

Although if we observe it in detail, we are able to notice it is not technically
a stack. It has more a **queue** structure as we have a pointer to the first
element -**head**- and later another to the last -**tail**-. This is due to the
computanional benefits it will give us once we implement some of the required
movements. 

In order to move its elements, we will use only 11 allowed movements:

* *sa* : swap a - swaps the first 2 elements at the top of stack **a** -nothing
is done if there is less than 2 elements-.  **TODO**

* *sb* : swap b - same bahaviour as *sa* but in **b**. **TODO**

* *ss* : does *sa* and *sb* at the same time.  **TODO**

* *pa* : push a - takes the first element at the top of **b** and put it at the
top of **a** -nothing is done if **b** is empty-.  **TODO**

* *pb* : push b - same behaviour as *pa*, but takes the first element from **a**
and puts it on **b** if possible.  **TODO**

* *ra* : rotate a - shift up all elements of stack **a** by 1 -the first
element becomes the last one-.

* *rb* : rotate b - same as *ra* but in **b**.

* *rr* : *ra* and *rb* at the same time.

* *rra* : reverse rotate a - shift down all elements of stack **a** by 1 -the
last element becomes the last one-.

* *rrb* : reverse rotate b - same as *rra* but in **b**.

* *rrr* : *rra* and *rrb* at the same time.
