# Incomplete Array
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array A containing N integers.Find out how many elements should be added such that all elements between the maximum and minimum of the array is present in the array.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=5
A=[205,173,102,324,957]
<strong>Output:</strong>
851
<strong>Explanation:</strong>
The maximum and minimum of given 
array is 957 and 102 respectively.We need 
to add 854 elements out of which
3 are already present.So answer is 851.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=1
A=[545]
<strong>Output:</strong>
0
<strong>Explanation:</strong>
We don't need to add any element
to the array.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your Task is to complete the function <strong>countElements()</strong> which takes an integer N and an array A of&nbsp;size N&nbsp;and returns the number of elements needed to be added to the array so, that all elements between the minimum and maximum of the array are present.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>O(N)<br>
<strong>Expected Auxillary Space:</strong>O(10<sup>5</sup>)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N,A[i]&lt;=10<sup>5</sup>&nbsp;</span></p>
</div>