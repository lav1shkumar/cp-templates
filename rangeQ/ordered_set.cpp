#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T> 
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


// usage
ordered_set<int> s;
s.insert(x);
cout << s.order_of_key(x) << "\n";     // no of elemets smaller than x
cout << *s.find_by_order(x) << "\n";   // element at index x, if x ia valid(0 - n-1)
