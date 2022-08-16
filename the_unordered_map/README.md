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
<li>The pair object will call a constructor which will pass the key to a hash function, the output of which returns the "bucket number" hashnum (say) where the key will be stored</li>
<li>that bucket will be a linked list at index hashnum of the array of pairs</li>
<li>The pair object will be appended to the end of that linked list</li>
</ul>

#### Concepts used and problems faced:
<ul>
<li>lvalues and rvalues: when trying to overload the [] and = operators to assign the key and value, I keep getting the "expression should be a modifiable lvalue" error</li>
<li></li>
<li></li>
<li></li>
<li></li>
</ul>