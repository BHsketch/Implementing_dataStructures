# Implementing Data structures in c++

## My version of the unordered_map

an unordered map is a template, since the key and value data types are defined at compile time

### Module 1:

#### Figuring out the basic structure of an unordered map:
note:
an unordered map has an average time complexity of O(1)
<ul>
<li> say the map was initialized like this: unordered_map_bh<std::String, int> agemap;</li>
<li>This creates an object of class unordered_map_bh by inserting std::string and int as the template parameters to create the object</li>
<li>agemap["Bob"] = 18</li>
<li>this set of operators (whose functions will be defined by operator overloading) will cause a "pair" object to b created in the unordered_map_bh object.</li>
<li>the operator [] will act as a function with input "Bob". 
    the function:
    <ul>
    <li>It will create a ListNode object called tempnode with the parameter input key, which in turn will create a pair object inside it. The ListNode will have a constructor function that </li>
    <li>input is stored in the key variable of the node pair</li>
    <li>the node pair passes the key through the hash function to get an index hashoutput</li>
    <li>(C[hashoutput]->next)=address of tempnode</li>
    <li>update C[hashoutput] to point to the address of tempnode(the list has now been connected to the linked list whose head is stored at index=hashoutput of the array H</li>
    <li>function returns a reference to the node pair object</li>
    </ul>
</li>
<li>the operator = will act as a function with input '25'.
    the function:
    <li>call the setval function in the pair and pass it the input(25)</li>
</li>

<li></li>
<li></li>
<li></li>
<li></li>
<li></li>
<li>The pair object will call a constructor which will pass the key to a hash function, the output of which returns the "bucket number" hashnum (say) where the key will be stored</li>
<li>that bucket will be a linked list at index hashnum of the array of pairs</li>
<li>The pair object will be appended to the end of that linked list</li>
</ul>

#### Concepts used and problems faced:
<ul>
<li>lvalues and rvalues: when trying to overload the [] and = operators to assign the key and value, I keep getting the "expression should be a modifiable lvalue" error</li>
<li>when inserting elements, there was a need to traverse the whole linked list that started from H[hashoutput]
solution: I created another array C[100] that kept track of the last node added to each linked list in H[100]
<li>I made all variables inside pair as well as listnode private. But I realised that this is not required, since the only way to access the pair, is to access the node, and the only way to access the node is to access the array 
H[] in the unordered_map object(since the only way a listnode will be created will be when an unordered_map obj is created). So if I set the arrays inside the unordered_map private, I no longer need to make the variables in the pair and listnode private. It's overkill and it overcomplicates the program</li>
<li></li>
<li></li>
<li></li>
<li></li>
</ul>