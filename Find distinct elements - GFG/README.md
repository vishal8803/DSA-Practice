# Find distinct elements
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a <strong>N</strong> x<strong> N</strong> matrix <strong>M</strong>. Write a program to find count of all the distinct elements common to all rows of the matrix. Print count of such elements.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
N = 4
M = {{2, 1, 4, 3},
     {1, 2, 3, 2},
     {3, 6, 2, 3},
     {5, 2, 5, 3}}
<strong>Output:</strong> 
2
<strong>Explaination:</strong> Only 2 and 3 are common in all rows.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
N = 5
M = {{12, 1, 14, 3, 16},
     {14, 2, 1, 3, 35},
     {14, 1, 14, 3, 11},
     {14, 5, 3, 2, 1},
     {1, 18, 3, 21, 14}}
<strong>Output:</strong> 
3
<strong>Explaination:</strong> 14, 3 and 1 are common in all the rows.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>distinct()</strong> which takes the matrix and n as input parameters and returns the number of distinct elements present in every row.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(N*N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 100<br>
1 ≤ M[i][j] ≤ 1000</span></p>
</div>