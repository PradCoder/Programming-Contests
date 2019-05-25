#include <bits/stdc++.h>//works on gnu compilers
#include <ext/pb_ds/assoc_container.hpp>//for g++ only data structs
using namespace __gnu_pbds;//makes it easier to use policy 
                           //based data structs
using namespace std;
//Data Structures 
/*
All data structures have there own advantages and disadvantages
so what are the most efficient operations for the chosen
datastructures? 
*/
int main(){
    //remove in/out bottlenecks or reduce them
    ios::sync_with_stdio(0);
    cin.tie(0);

    //dynamic arrays
    vector<int> v;
    v.push_back(3);//[3]
    v.push_back(2);//[3,2]
    v.push_back(5);//[3,2,5]

    cout << v[0] << "\n" <<  v[1] << "\n"<< v[2] << "\n";
    /*
    3
    2
    5
    */

    //the size() function gets the number of elements in the vector
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    //A shorter way to iterate would be as follows
    for(auto x: v){
        cout << x << "\n";
    }

    //back() pop_back() demo
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    cout << v.back() << "\n"; // 2 - back() returns the last element
    v.pop_back();
    cout << v.back() << "\n"; // 5 - pop_back() removed the last element

    /*creating vectors*/
    vector<int> v = {2,4,2,5,1};
    //size 10 , intial value 0
    vector<int> v(10);
    //size 10, initial value 5
    vector<int> v(10,5);
    
    /*
    Note on vectors: the internal implementation of the vector
    uses an array and when the array becomes too small a larger array
    is created and the elements are relocated into that array. But since
    this does not always happen the average time complexity of 
    push_back() is O(1) 
    */

    /*string operations*/
    string a  = "hatti"
    string b = a+a;
    cout << b << "\n";//hattihatti
    b[5] = 'v';
    cout << b << "\n"; //hattivatti
    string c = b.substr(3,4); // substring takes the substring from 3 
                              // and continues for 4 elements
    cout << c << "\n"; //tiva

    //Set Structures
    //A set is a data structure that maintains a collection of elements.
    //The basic operations of sets are insertion, search & removal
    //The structure set is based on a balanced binary tree and its 
    //operations work in O(log n) time The unordered_set structure 
    //uses hashing and works on average at O(1) time
    //set is more organized and has more functions, unordered_set is much
    //faster

    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3) << "\n"; //1
    cout << s.count(4) << "\n"; //0
    s.erase(3); 
    s.insert(4);
    cout << s.count(3) << "\n"; //0
    cout << s.count(4) << "\n"; //1

    set<int> s = {2,5,6,8};
    /*Note: you can't acces a set using [] notation*/
    cout << s.size() << "\n"; //4
    for (auto x : s){
        cout << x << "\n";
    }
    //All the elements in a set structure are distinct
    //the function insert never adds an element to the set if it's 
    //there
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    cout << s.count(5) << "\n";//1

    //C++ also contains the structures multiset and unordered_multiset
    //basically they contain more than one instance of an element
    multiset<int> s;
    s.insert(5);//inset is used to insert to a multiset
    s.insert(5);
    s.insert(5);
    cout << s.count(5) << "\n";//3
    s.erase(5);//to erase all instances of an element
    cout << s.count(5) << "\n";//0
    s.erase(s.find(5));//to erase only one instance of an element
    cout << s.count(5) << "\n";//2

    /*Map Structures*/
    /*A map is generalized array that consists of key-value-pairs
    (Feels like dictionaries in python)*/
    //The Structure map is based on a balanced binary tree and 
    //accessing elements takes O(log n) time 
    //and an unordered_map (just like unordered_set) uses hashing and
    //has the same time complexity

    map<string,int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    cout << m["banana"] << "\n"; //3
    //if a value is requested using a key and the key does not exist
    //the key is added to the map with a default value
    map<string,int> m;
    cout << m["aybabtu"] << "\n"; //0
    //the count() function checks if a key exists in a map
    if (m.count("aybabtu")){
        //key exists
    }
    //the following prints all the keys and values in a map
    for(auto x : m){
        cout << x.first << " " << x.second << "\n";
    }

    /*Iterators and ranges*/
    //An iterator is a variable that points to an element 
    //in a data structure
    //often used iterators are begin and end
    //begin points to the first element in the data-structure
    //end points to the position after the last element 
    /*
    { 3, 4, 6, 8, 12, 13, 14, 17 }
      ^s.begin()                 ^s.end()   
    */
    //ranges in action (ranges are defined by iterators)
    sort(v.begin(),v.end());//sort from beginning to end
    reverse(v.begin(),v.end());//reverse from beginning to end
    random_shuffle(v.begin(),v.end());// shuffle from beginning to end
    /*
    The above functions can also be used on an array
    But the functions are given pointers instead of iterators
    */
    sort(a, a+n);
    reverse(a,a+n);
    random_shuffle(a, a+n);

    /*
    Iterators are used in sets
    The following code create an iterator it that points to 
    the smallest element in a set (since it is accessed by begin()
    and it's in an ordered structure (set in this case)).
    What has happened is that s.begin()'s ability is now given to 
    iterator "it" (Note: iterators are basically pointers)
    */
    set<int>::iterator it = s.begin();
    //The shorter way
    auto it = s.begin();
    /*
    The element to which the iterator points can be accessed using
    the * symbol (dereference operator)
    */
    auto it = s.begin();
    cout << *it << "\n";//prints the first element in s
    //Iterators can be moved using the ++ and -- operators
    //Print all the elements in the set
    for (auto it = s.begin(); it != s.end(); it++){
        cout << *it <<"\n";
    }
    //The following code prints the last element
    auto it = s.end(); it--; //backing up into the correct address
    cout << *it << "\n";
    //find(x) returns an iterator that points to an element with x
    //if x doesn't exist then find(x) will return end
    auto it = s.find(x);
    if (it == s.end()){
        //x is not found
    }
    /*the function lower_bound(x) returns an iterator to the 
    smallest element that is atleast x and upper_bound(x) 
    returns an iterator to the smallest element greater than x*/
    //if x does not exist for both functions the return value is end()
    /*The above functions are not supported in unordered structures*/
    
    /*Example of code that finds the element nearest x*/
    /*
    The code assumes that the set is not empty and goes through
    all possible cases using iterator it.
    */
    auto it = s.lower_bound(x);
    if(it == s.begin()){
        cout << *it << "\n";
    }else if (it == s.end()){
        it--;
        cout << *it << "\n";
    }else {
        int a = *it; it--;
        int b = *it;
        if(x-b < a-x) cout << b << "\n";
        else cout << a << "\n";
    }


    /*Other Structures*/
    //Bitsets -  an array with elements of either 0 or 1
    bitset<10> s;
    s[1] = 1;
    s[3] = 1;
    s[4] = 1;
    s[7] = 1;
    cout << s[4] <<"\n";//1
    cout << s[5] <<"\n";//0
    /*the values of a bitset can be efficiently manipulated using bit 
    operators*/
    //another way to create a bitset:
    bitset<10> s(string("0010011010"));
    cout << s[4] << "\n"; // 1
    cout << s[5] << "\n"; // 0
    //basically count() counts the number of 1's
    bitset<10> s(string("0010011010"));
    cout << s.count() << "\n"; //4
    //bitoperations (in c++ though)
    bitset<10> a(string("0010110110"));
    bitset<10> b(string("1011011000"));
    cout << (a&b) << "\n"; // 0010010000
    cout << (a|b) << "\n"; // 1011111110
    cout << (a^b) << "\n"; // 1001101110

    /*Deque*/
    //basically vector with push_front and pop_front
    deque<int> d;
    d.push_back(5); // [5]
    d.push_back(2); // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back(); // [3,5]
    d.pop_front(); // [5]
    /*The internal implementation of a deque is more complex than 
    a vector, so it's slower than a vector. However both adding
    and removing take O(1) time on average at both ends.*/

    /*Stack*/
    /*It's a data structure that provides two O(1) operations.
    The first is adding the next is removing an element from the top
    You can only access the top element of a stack*/
    //A stack structure
    //gets it's name literally because it functions like a stack
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(5);
    cout << s.top(); // 5
    s.pop();
    cout << s.top(); // 2
    
    /*Queue*/
    /*A queue also provides two O(1) time operations: adding an element
    to the end of the queue and removing from the top of a queue.
    It is only possible to access the first and last element of a queue*/
    //A queue behaves like a literal queue
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(5);
    cout << q.front(); // 3
    q.pop();
    cout << q.front(); // 2

    /*Priority Queue*/
    /*A priority queue maintains a set of elements.*/
    /*Insertion is supported and depending on the the type of queue
    retrieval and removal of either the minimum or maximum element
    Insetions and removal take O(log n) time, and retrival takes O(1)
    time*/
    //Benefits: smaller constant factors
    //A priority queue is implemented using a heap structure that is 
    //much simpler than a balanced binary tree used in an ordered set
    /*Note: a heap is like a tree structure where values either descend
    down or ascend down*/
    /*By default the priority queue structure is in decreasing order,
    and this makes it possible to find and remove the largest element 
    in it*/
    priority_queue<int> q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(2);
    cout << q.top() << "\n"; // 7
    q.pop();
    cout << q.top() << "\n"; // 5
    q.pop();
    q.push(6);
    cout << q.top() << "\n"; // 6
    q.pop();
    /*The code below shows an implementation of a priority queue
    if we want to create a priority queue that supports finding and 
    removing the smallest element*/
    priority_queue<int,vector<int>,greater<int>> q;
    /*Policy-based data structures*/
    /*These data-structures are for the g++ compiler that are not part
    of the standard library. These are policy-based data structures*/
    //After the library includes (and namespaces) are set we can start
    typedef tree<int,null_type,less<int>,rb_tree_tag,
                tree_order_statistics_node_update> indexed_set;
    indexed_set s;
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);
    auto x = s.find_by_order(2);// find_by_order() returns a pointer to 
                                //the element at that position
    cout << *x << "\n"; // 7
    cout << s.order_of_key(7) << "\n"; // 2 since order_of_key() gets 
                                       // the position of a given element
    /*if the element doesn't appear in the set then we get the position
    the element would have in the set*/
    cout << s.order_of_key(6) << "\n"; // 2
    cout << s.order_of_key(8) << "\n"; // 3
    //They both (order_of_key() and find_by_order()) work 
    //in logarithmic time
    
    /***Comparison to sorting***/
    /*It is often possible to solve a problem using either data 
    structures or sorting. But there are differences in the time
    complexities*/
    //Algorithm to calculate intersection of sets 
    // A = {5,2,8.9,4} and B={3,2,9,5}
    //(in different complexities)
    /*A straightforward solution is to go through all pairs in O(n^2)
    time*/
    /*Algorithm 1 - We construct a set of Elements that appear in A
    after this, we iterate through the elements of B and check for
    each elements if it also belongs to A. The time complexity for this
    algorithm is O(nlog(n)) (since n elements and time Complexity of
    find(x) is log(n)) */
    /*Algorithm 2 - It is not necessary to have an ordered set so
    you can use and unordered_set (which have functions than run in 
    O(1)) so the time complexity becomes O(n) for the algorithm*/
    /*Algorithm 3 - If we sort in O(nlog(n)) first and iterate through
    both arrays (both A and B) in O(n) then the complexity is O(nlog(n)) 
    since that's the maximum complexity of a single phase is O(nlog(n))*/
    /*---Analysis---*/
    /*Although 1 and 2 are the same except for different set structure
    2 is 4-5 times faster. 3 is the fastest eventhough it has the same
    time complexity as 1 it is 10 times as fast and 2 times as fast as
    algorithm 2. This is because you only sort once and the rest is done
    in linear time (as the number of elements increase the small
    differences in the other parts of the algorithms run time
    come into play). Besides algorithm 1 maintains a complex 
    balanced tree structure during the whole implementation*/
    return 0;
}
