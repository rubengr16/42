# push\_swap
## Insert numbers in a stack -**a**- and later sort it with the help of another stack -**b**-

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
a stack. It has more a **queue** structure due to the nature of the data
structure I have created. In this case, it is a **circular double linked list**.
Maybe it is harder to program the movements and basic functions with this
structure, but I think it is a great opportunity to cope with these problems.

Those basic functions to manage the **circular double linked list** are the
following ones:

* *t\_queue \*ft\_queue(void)* : function which reserves memory using malloc 
and initializes its values head and n_elem to NULL and 0 respectively.

* *t\_node \*ft\_newnode(int num)*: receives a new node and establishes its 
value to num and its pointer to NULL.

* *void	ft\_queueadd\_back(t\_queue \*queue, t\_node \*node)* : inserts a node 
received as argument at the back of a queue.

* *void	ft\_queueadd\_back\_num(t\_queue \*queue, int num)* : creates a node 
with the received number as argument and inserts it at the back of a queue.

* *void	ft\_queueadd\_front(t\_queue \*queue, t\_node \*node)* : inserts a 
node received as argument at the front of a queue.

* *void	ft\_queueadd\_front\_num(t\_queue \*queue, int num)* : creates a node 
with the received number as argument and inserts it at the front of a queue.


* *t\_node	\*ft\_queuepop(t\_queue \*queue)* : deletes one node from a queue 
and returns it.

* *void	ft\_queuedelone(t\_queue \*queue)* : deletes the first node of a 
queue.

* *void	ft\_queuedelall(t\_queue \*\*queue)*: deletes a queue.

In order to move its elements, we will use only 11 allowed movements:

* *sa* : swap a - swaps the first 2 elements at the top of stack **a** -nothing
is done if there is less than 2 elements-

* *sb* : swap b - same behaviour as *sa* but in **b**. 

* *ss* : does *sa* and *sb* at the same time.

* *pa* : push a - takes the first element at the top of **b** and put it at the
top of **a** -nothing is done if **b** is empty-.

* *pb* : push b - same behaviour as *pa*, but takes the first element from **a**
if possible and puts it on **b**.

* *ra* : rotate a - shift up all elements of stack **a** by 1 -the first
element becomes the last one-.

* *rb* : rotate b - same as *ra* but in **b**.

* *rr* : *ra* and *rb* at the same time.

* *rra* : reverse rotate a - shift down all elements of stack **a** by 1 -the
last element becomes the last one-.

* *rrb* : reverse rotate b - same as *rra* but in **b**.

* *rrr* : *rra* and *rrb* at the same time.
