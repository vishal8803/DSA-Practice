# Grouping values
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">There are <strong>N</strong> integers given in an array <strong>arr</strong>. You have to determine if it is possible to divide them in&nbsp;at most <strong>K</strong> groups, such that any group does not have a single integer more than twice.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 5, K = 2
arr = {1, 1, 2, 5, 1}
<strong>Output:</strong> 1
<strong>Explaination:</strong> We can divide them in two groups in 
following way (1, 1, 2, 5) and (1).</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 3, K = 1
arr = {1, 1, 1}
<strong>Output:</strong> 0
<strong>Explaination:</strong> There can be only one group and 
three 1's. So it is not possible.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your Task is to complete the function <strong>isPossible()</strong> which takes the value N, K and arr as input parameters and returns 1 if grouping is posible. Otherwise returns 0.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 1000<br>
1 ≤ K ≤ 256<br>
1 ≤ arr[i] ≤ 32</span></p>
</div>