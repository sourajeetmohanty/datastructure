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

# searching in a linklist




