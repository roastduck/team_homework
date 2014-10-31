Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ns/call  ns/call  name    
 40.00      0.04     0.04                             main
 30.00      0.07     0.03  1445959    20.75    20.75  int* std::lower_bound<int*, int>(int*, int*, int const&)
 20.00      0.09     0.02   668105    29.94    29.94  Calc(int, int, int, int, int)
 10.00      0.10     0.01  1445958     6.92     6.92  Add(int, int, int, int)
  0.00      0.10     0.00  2312267     0.00     0.00  std::iterator_traits<int*>::iterator_category std::__iterator_category<int*>(int* const&)
  0.00      0.10     0.00  1445959     0.00     0.00  std::iterator_traits<int*>::difference_type std::__distance<int*>(int*, int*, std::random_access_iterator_tag)
  0.00      0.10     0.00  1445959     0.00     0.00  std::iterator_traits<int*>::difference_type std::distance<int*>(int*, int*)
  0.00      0.10     0.00   866308     0.00     0.00  void std::advance<int*, int>(int*&, int)
  0.00      0.10     0.00   866308     0.00     0.00  void std::__advance<int*, int>(int*&, int, std::random_access_iterator_tag)
  0.00      0.10     0.00   494567     0.00     0.00  getchar
  0.00      0.10     0.00   146571     0.00     0.00  void std::__iter_swap<true>::iter_swap<int*, int*>(int*, int*)
  0.00      0.10     0.00   146571     0.00     0.00  void std::swap<int>(int&, int&)
  0.00      0.10     0.00   146571     0.00     0.00  void std::iter_swap<int*, int*>(int*, int*)
  0.00      0.10     0.00    50002     0.00     0.00  READ(int&)
  0.00      0.10     0.00    49996     0.00     0.00  void std::__unguarded_linear_insert<int*>(int*)
  0.00      0.10     0.00     5632     0.00     0.00  void std::__move_median_first<int*>(int*, int*, int*)
  0.00      0.10     0.00     5632     0.00     0.00  int* std::__unguarded_partition<int*, int>(int*, int*, int const&)
  0.00      0.10     0.00     5632     0.00     0.00  int* std::__unguarded_partition_pivot<int*>(int*, int*)
  0.00      0.10     0.00       15     0.00     0.00  std::_Iter_base<int*, false>::_S_base(int*)
  0.00      0.10     0.00        9     0.00     0.00  std::_Niter_base<int*>::iterator_type std::__niter_base<int*>(int*)
  0.00      0.10     0.00        6     0.00     0.00  std::_Miter_base<int*>::iterator_type std::__miter_base<int*>(int*)
  0.00      0.10     0.00        3     0.00     0.00  int* std::__copy_move_backward<false, true, std::random_access_iterator_tag>::__copy_move_b<int>(int const*, int const*, int*)
  0.00      0.10     0.00        3     0.00     0.00  int* std::copy_backward<int*, int*>(int*, int*, int*)
  0.00      0.10     0.00        3     0.00     0.00  int* std::__copy_move_backward_a<false, int*, int*>(int*, int*, int*)
  0.00      0.10     0.00        3     0.00     0.00  int* std::__copy_move_backward_a2<false, int*, int*>(int*, int*, int*)
  0.00      0.10     0.00        1     0.00     0.00  void std::__insertion_sort<int*>(int*, int*)
  0.00      0.10     0.00        1     0.00     0.00  void std::__introsort_loop<int*, int>(int*, int*, int)
  0.00      0.10     0.00        1     0.00     0.00  void std::__final_insertion_sort<int*>(int*, int*)
  0.00      0.10     0.00        1     0.00     0.00  void std::__unguarded_insertion_sort<int*>(int*, int*)
  0.00      0.10     0.00        1     0.00     0.00  std::__lg(int)
  0.00      0.10     0.00        1     0.00     0.00  void std::sort<int*>(int*, int*)

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.
 
 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this 
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.

Copyright (C) 2012-2014 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

		     Call graph (explanation follows)


granularity: each sample hit covers 4 byte(s) for 10.00% of 0.10 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.04    0.06                 main [1]
                0.03    0.00 1445959/1445959     int* std::lower_bound<int*, int>(int*, int*, int const&) [2]
                0.02    0.00  668105/668105      Calc(int, int, int, int, int) [3]
                0.01    0.00 1445958/1445958     Add(int, int, int, int) [4]
                0.00    0.00   50002/50002       READ(int&) [15]
                0.00    0.00       1/1           void std::sort<int*>(int*, int*) [32]
-----------------------------------------------
                0.03    0.00 1445959/1445959     main [1]
[2]     30.0    0.03    0.00 1445959         int* std::lower_bound<int*, int>(int*, int*, int const&) [2]
                0.00    0.00 1445959/1445959     std::iterator_traits<int*>::difference_type std::distance<int*>(int*, int*) [8]
                0.00    0.00  866308/866308      void std::advance<int*, int>(int*&, int) [9]
-----------------------------------------------
                0.02    0.00  668105/668105      main [1]
[3]     20.0    0.02    0.00  668105         Calc(int, int, int, int, int) [3]
-----------------------------------------------
                0.01    0.00 1445958/1445958     main [1]
[4]     10.0    0.01    0.00 1445958         Add(int, int, int, int) [4]
-----------------------------------------------
                0.00    0.00  866308/2312267     void std::advance<int*, int>(int*&, int) [9]
                0.00    0.00 1445959/2312267     std::iterator_traits<int*>::difference_type std::distance<int*>(int*, int*) [8]
[6]      0.0    0.00    0.00 2312267         std::iterator_traits<int*>::iterator_category std::__iterator_category<int*>(int* const&) [6]
-----------------------------------------------
                0.00    0.00 1445959/1445959     std::iterator_traits<int*>::difference_type std::distance<int*>(int*, int*) [8]
[7]      0.0    0.00    0.00 1445959         std::iterator_traits<int*>::difference_type std::__distance<int*>(int*, int*, std::random_access_iterator_tag) [7]
-----------------------------------------------
                0.00    0.00 1445959/1445959     int* std::lower_bound<int*, int>(int*, int*, int const&) [2]
[8]      0.0    0.00    0.00 1445959         std::iterator_traits<int*>::difference_type std::distance<int*>(int*, int*) [8]
                0.00    0.00 1445959/2312267     std::iterator_traits<int*>::iterator_category std::__iterator_category<int*>(int* const&) [6]
                0.00    0.00 1445959/1445959     std::iterator_traits<int*>::difference_type std::__distance<int*>(int*, int*, std::random_access_iterator_tag) [7]
-----------------------------------------------
                0.00    0.00  866308/866308      int* std::lower_bound<int*, int>(int*, int*, int const&) [2]
[9]      0.0    0.00    0.00  866308         void std::advance<int*, int>(int*&, int) [9]
                0.00    0.00  866308/2312267     std::iterator_traits<int*>::iterator_category std::__iterator_category<int*>(int* const&) [6]
                0.00    0.00  866308/866308      void std::__advance<int*, int>(int*&, int, std::random_access_iterator_tag) [10]
-----------------------------------------------
                0.00    0.00  866308/866308      void std::advance<int*, int>(int*&, int) [9]
[10]     0.0    0.00    0.00  866308         void std::__advance<int*, int>(int*&, int, std::random_access_iterator_tag) [10]
-----------------------------------------------
                0.00    0.00  494567/494567      READ(int&) [15]
[11]     0.0    0.00    0.00  494567         getchar [11]
-----------------------------------------------
                0.00    0.00  146571/146571      void std::iter_swap<int*, int*>(int*, int*) [14]
[12]     0.0    0.00    0.00  146571         void std::__iter_swap<true>::iter_swap<int*, int*>(int*, int*) [12]
                0.00    0.00  146571/146571      void std::swap<int>(int&, int&) [13]
-----------------------------------------------
                0.00    0.00  146571/146571      void std::__iter_swap<true>::iter_swap<int*, int*>(int*, int*) [12]
[13]     0.0    0.00    0.00  146571         void std::swap<int>(int&, int&) [13]
-----------------------------------------------
                0.00    0.00    4794/146571      void std::__move_median_first<int*>(int*, int*, int*) [17]
                0.00    0.00  141777/146571      int* std::__unguarded_partition<int*, int>(int*, int*, int const&) [18]
[14]     0.0    0.00    0.00  146571         void std::iter_swap<int*, int*>(int*, int*) [14]
                0.00    0.00  146571/146571      void std::__iter_swap<true>::iter_swap<int*, int*>(int*, int*) [12]
-----------------------------------------------
                0.00    0.00   50002/50002       main [1]
[15]     0.0    0.00    0.00   50002         READ(int&) [15]
                0.00    0.00  494567/494567      getchar [11]
-----------------------------------------------
                0.00    0.00      12/49996       void std::__insertion_sort<int*>(int*, int*) [27]
                0.00    0.00   49984/49996       void std::__unguarded_insertion_sort<int*>(int*, int*) [30]
[16]     0.0    0.00    0.00   49996         void std::__unguarded_linear_insert<int*>(int*) [16]
-----------------------------------------------
                0.00    0.00    5632/5632        int* std::__unguarded_partition_pivot<int*>(int*, int*) [19]
[17]     0.0    0.00    0.00    5632         void std::__move_median_first<int*>(int*, int*, int*) [17]
                0.00    0.00    4794/146571      void std::iter_swap<int*, int*>(int*, int*) [14]
-----------------------------------------------
                0.00    0.00    5632/5632        int* std::__unguarded_partition_pivot<int*>(int*, int*) [19]
[18]     0.0    0.00    0.00    5632         int* std::__unguarded_partition<int*, int>(int*, int*, int const&) [18]
                0.00    0.00  141777/146571      void std::iter_swap<int*, int*>(int*, int*) [14]
-----------------------------------------------
                0.00    0.00    5632/5632        void std::__introsort_loop<int*, int>(int*, int*, int) [28]
[19]     0.0    0.00    0.00    5632         int* std::__unguarded_partition_pivot<int*>(int*, int*) [19]
                0.00    0.00    5632/5632        void std::__move_median_first<int*>(int*, int*, int*) [17]
                0.00    0.00    5632/5632        int* std::__unguarded_partition<int*, int>(int*, int*, int const&) [18]
-----------------------------------------------
                0.00    0.00       6/15          std::_Miter_base<int*>::iterator_type std::__miter_base<int*>(int*) [22]
                0.00    0.00       9/15          std::_Niter_base<int*>::iterator_type std::__niter_base<int*>(int*) [21]
[20]     0.0    0.00    0.00      15         std::_Iter_base<int*, false>::_S_base(int*) [20]
-----------------------------------------------
                0.00    0.00       9/9           int* std::__copy_move_backward_a2<false, int*, int*>(int*, int*, int*) [26]
[21]     0.0    0.00    0.00       9         std::_Niter_base<int*>::iterator_type std::__niter_base<int*>(int*) [21]
                0.00    0.00       9/15          std::_Iter_base<int*, false>::_S_base(int*) [20]
-----------------------------------------------
                0.00    0.00       6/6           int* std::copy_backward<int*, int*>(int*, int*, int*) [24]
[22]     0.0    0.00    0.00       6         std::_Miter_base<int*>::iterator_type std::__miter_base<int*>(int*) [22]
                0.00    0.00       6/15          std::_Iter_base<int*, false>::_S_base(int*) [20]
-----------------------------------------------
                0.00    0.00       3/3           int* std::__copy_move_backward_a<false, int*, int*>(int*, int*, int*) [25]
[23]     0.0    0.00    0.00       3         int* std::__copy_move_backward<false, true, std::random_access_iterator_tag>::__copy_move_b<int>(int const*, int const*, int*) [23]
-----------------------------------------------
                0.00    0.00       3/3           void std::__insertion_sort<int*>(int*, int*) [27]
[24]     0.0    0.00    0.00       3         int* std::copy_backward<int*, int*>(int*, int*, int*) [24]
                0.00    0.00       6/6           std::_Miter_base<int*>::iterator_type std::__miter_base<int*>(int*) [22]
                0.00    0.00       3/3           int* std::__copy_move_backward_a2<false, int*, int*>(int*, int*, int*) [26]
-----------------------------------------------
                0.00    0.00       3/3           int* std::__copy_move_backward_a2<false, int*, int*>(int*, int*, int*) [26]
[25]     0.0    0.00    0.00       3         int* std::__copy_move_backward_a<false, int*, int*>(int*, int*, int*) [25]
                0.00    0.00       3/3           int* std::__copy_move_backward<false, true, std::random_access_iterator_tag>::__copy_move_b<int>(int const*, int const*, int*) [23]
-----------------------------------------------
                0.00    0.00       3/3           int* std::copy_backward<int*, int*>(int*, int*, int*) [24]
[26]     0.0    0.00    0.00       3         int* std::__copy_move_backward_a2<false, int*, int*>(int*, int*, int*) [26]
                0.00    0.00       9/9           std::_Niter_base<int*>::iterator_type std::__niter_base<int*>(int*) [21]
                0.00    0.00       3/3           int* std::__copy_move_backward_a<false, int*, int*>(int*, int*, int*) [25]
-----------------------------------------------
                0.00    0.00       1/1           void std::__final_insertion_sort<int*>(int*, int*) [29]
[27]     0.0    0.00    0.00       1         void std::__insertion_sort<int*>(int*, int*) [27]
                0.00    0.00      12/49996       void std::__unguarded_linear_insert<int*>(int*) [16]
                0.00    0.00       3/3           int* std::copy_backward<int*, int*>(int*, int*, int*) [24]
-----------------------------------------------
                                5632             void std::__introsort_loop<int*, int>(int*, int*, int) [28]
                0.00    0.00       1/1           void std::sort<int*>(int*, int*) [32]
[28]     0.0    0.00    0.00       1+5632    void std::__introsort_loop<int*, int>(int*, int*, int) [28]
                0.00    0.00    5632/5632        int* std::__unguarded_partition_pivot<int*>(int*, int*) [19]
                                5632             void std::__introsort_loop<int*, int>(int*, int*, int) [28]
-----------------------------------------------
                0.00    0.00       1/1           void std::sort<int*>(int*, int*) [32]
[29]     0.0    0.00    0.00       1         void std::__final_insertion_sort<int*>(int*, int*) [29]
                0.00    0.00       1/1           void std::__insertion_sort<int*>(int*, int*) [27]
                0.00    0.00       1/1           void std::__unguarded_insertion_sort<int*>(int*, int*) [30]
-----------------------------------------------
                0.00    0.00       1/1           void std::__final_insertion_sort<int*>(int*, int*) [29]
[30]     0.0    0.00    0.00       1         void std::__unguarded_insertion_sort<int*>(int*, int*) [30]
                0.00    0.00   49984/49996       void std::__unguarded_linear_insert<int*>(int*) [16]
-----------------------------------------------
                0.00    0.00       1/1           void std::sort<int*>(int*, int*) [32]
[31]     0.0    0.00    0.00       1         std::__lg(int) [31]
-----------------------------------------------
                0.00    0.00       1/1           main [1]
[32]     0.0    0.00    0.00       1         void std::sort<int*>(int*, int*) [32]
                0.00    0.00       1/1           std::__lg(int) [31]
                0.00    0.00       1/1           void std::__introsort_loop<int*, int>(int*, int*, int) [28]
                0.00    0.00       1/1           void std::__final_insertion_sort<int*>(int*, int*) [29]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index	A unique number given to each element of the table.
		Index numbers are sorted numerically.
		The index number is printed next to every function name so
		it is easier to look up where the function is in the table.

     % time	This is the percentage of the `total' time that was spent
		in this function and its children.  Note that due to
		different viewpoints, functions excluded by options, etc,
		these numbers will NOT add up to 100%.

     self	This is the total amount of time spent in this function.

     children	This is the total amount of time propagated into this
		function by its children.

     called	This is the number of times the function was called.
		If the function called itself recursively, the number
		only includes non-recursive calls, and is followed by
		a `+' and the number of recursive calls.

     name	The name of the current function.  The index number is
		printed after it.  If the function is a member of a
		cycle, the cycle number is printed between the
		function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the function into this parent.

     children	This is the amount of time that was propagated from
		the function's children into this parent.

     called	This is the number of times this parent called the
		function `/' the total number of times the function
		was called.  Recursive calls to the function are not
		included in the number after the `/'.

     name	This is the name of the parent.  The parent's index
		number is printed after it.  If the parent is a
		member of a cycle, the cycle number is printed between
		the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the child into the function.

     children	This is the amount of time that was propagated from the
		child's children to the function.

     called	This is the number of times the function called
		this child `/' the total number of times the child
		was called.  Recursive calls by the child are not
		listed in the number after the `/'.

     name	This is the name of the child.  The child's index
		number is printed after it.  If the child is a
		member of a cycle, the cycle number is printed
		between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.

Copyright (C) 2012-2014 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

Index by function name

   [4] Add(int, int, int, int) [27] void std::__insertion_sort<int*>(int*, int*) [31] std::__lg(int)
   [3] Calc(int, int, int, int, int) [28] void std::__introsort_loop<int*, int>(int*, int*, int) [32] void std::sort<int*>(int*, int*)
  [15] READ(int&)              [6] std::iterator_traits<int*>::iterator_category std::__iterator_category<int*>(int* const&) [13] void std::swap<int>(int&, int&)
  [20] std::_Iter_base<int*, false>::_S_base(int*) [17] void std::__move_median_first<int*>(int*, int*, int*) [9] void std::advance<int*, int>(int*&, int)
  [12] void std::__iter_swap<true>::iter_swap<int*, int*>(int*, int*) [18] int* std::__unguarded_partition<int*, int>(int*, int*, int const&) [8] std::iterator_traits<int*>::difference_type std::distance<int*>(int*, int*)
  [23] int* std::__copy_move_backward<false, true, std::random_access_iterator_tag>::__copy_move_b<int>(int const*, int const*, int*) [25] int* std::__copy_move_backward_a<false, int*, int*>(int*, int*, int*) [10] void std::__advance<int*, int>(int*&, int, std::random_access_iterator_tag)
   [7] std::iterator_traits<int*>::difference_type std::__distance<int*>(int*, int*, std::random_access_iterator_tag) [29] void std::__final_insertion_sort<int*>(int*, int*) [14] void std::iter_swap<int*, int*>(int*, int*)
   [2] int* std::lower_bound<int*, int>(int*, int*, int const&) [26] int* std::__copy_move_backward_a2<false, int*, int*>(int*, int*, int*) [11] getchar
  [22] std::_Miter_base<int*>::iterator_type std::__miter_base<int*>(int*) [16] void std::__unguarded_linear_insert<int*>(int*) [1] main
  [21] std::_Niter_base<int*>::iterator_type std::__niter_base<int*>(int*) [30] void std::__unguarded_insertion_sort<int*>(int*, int*)
  [24] int* std::copy_backward<int*, int*>(int*, int*, int*) [19] int* std::__unguarded_partition_pivot<int*>(int*, int*)
