// #include <ext/pb_ds/detail/standard_policies.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<
    int,                        // Key type: type of elements in the set is int
    null_type,                  // Mapped policy: since it's a set and not a map, we use `null_type`.
    greater_equal<int>,         // Key comparison function: elements are stored in descending order, allowing duplicates.
    rb_tree_tag,                // Tree type: specifies that the underlying data structure is a red-black tree.
    tree_order_statistics_node_update // Node update policy: provides ability to get the k-th largest/smallest element.
> policyBasedSet;


// use less if require in ascending order without duplicates
// check for less
// check for descending without duplicates



order_of_key(x);
find_by_order(x);