# datastructure
FUNDAMENTS OF DATASTRUCTURE IN C LANGUAGE


 # ARRAYS

Arrays are contigious memory locations which contain similar data. The memory addresses of arrays are in sequential order.
The code below displays the declaratrion and the insertion of arrays in a specifically C language format.
```
	int a[10]; //Declare the array
	
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]); //Input the elements
	} 
```
# Linklist

linklist's are the proper structured containers. They are not contigious memory locations.They are composed of multiple nodes. Each node is structure which can contain multiple data types. It compulsorily must contain a pointer to structure within the node. The pointer helps point to a node which is similar to the node that contains it.

The code given below depicts the declaration of a node.
```
typedef node-type
{
 int dat;
 struct node-type *next;
 }node;
 ```
 
The above code uses type defination to name a sample node , it provides the node with only two elements, the data element and the pointer to a node which helps point the next element of the link list.

# Stacks

Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).
There are many real-life examples of a stack. Consider an example of plates stacked over one another in the canteen. The plate which is at the top is the first one to be removed, i.e. the plate which has been placed at the bottommost position remains in the stack for the longest period of time. So, it can be simply seen to follow LIFO(Last In First Out)/FILO(First In Last Out) order.




