Maddie Gross, Mary Fillauer, Ava Sangiuliano, Audrey Domitrovic
https://github.com/maddiegross7/Project-2.git

| Mode    | Size      | Elapsed Time  |
|---------|-----------|---------------|
| STL     | 10        | 0.002         | 
| STL     | 100       | 0.001         | 
| STL     | 1000      | 0.003         | 
| STL     | 10000     | 0.015         | 
| STL     | 100000    | 0.472         | 
| STL     | 1000000   | 5.813         | 
| STL     | 10000000  | 59.533        | 
| QSORT   | 10        | 0.002         | 
| QSORT   | 100       | 0.002         | 
| QSORT   | 1000      | 0.003         | 
| QSORT   | 10000     | 0.014         | 
| QSORT   | 100000    | 0.372         | 
| QSORT   | 1000000   | 4.998         | 
| QSORT   | 10000000  | 54.777        | 
| MERGE   | 10        | 0.002         | 
| MERGE   | 100       | 0.002         | 
| MERGE   | 1000      | 0.003         | 
| MERGE   | 10000     | 0.014         | 
| MERGE   | 100000    | 0.470         | 
| MERGE   | 1000000   | 0.385         | 
| MERGE   | 10000000  | 5.185         |
| QUICK   | 10        | 0.007         | 
| QUICK   | 100       | 0.023         | 
| QUICK   | 1000      | 0.004         | 
| QUICK   | 10000     | 0.038         | 
| QUICK   | 100000    | 1.100         | 
| QUICK   | 1000000   | 9.295         | 
| QUICK   | 10000000  | 1:56.16       |


Discussion
STL and Qsort are very similar because they are both just the c++ implementation of the standard algorthms.
They will not be as fast as merge and quick because they are not custom implementation they will take longer
and with an average time complexity of O(n^2).
Merge is pretty quick with an average time complexity of O(n), is does have the potential to be slower than quick 
sort. Quick sort is fast on average with time complexity for O(nLog(n))
We have concluded that while the best case and time complexity that we learned about in class can sometimes be very good but in bad cases it can be just as slow as other methods. 
We really like Merge because it was super fun to implement while also being super quick and was one of the best 
experience with recursion we have seen, with our implentation of quick sory we would not use it.

Team Summary
Mary - All of Merge sort; what a queen
Maddie - sort and oblivious
Ava - qsort and int comparison function
Audrey - quick sort and bool comparers

We all worked at the end to work out the kinks and get the project together

Challenges
We struggled with the comparison function since qsort needed an int to be returned
where all others needed a bool returned, we ended up making different versions of the 
function to return both types where needed
Quick sort was overall a struggle, it took the longest to implement and understand, but we got it done thank the lord


