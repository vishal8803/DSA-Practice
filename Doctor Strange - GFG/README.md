# Doctor Strange
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Kamar-taj is a place where "The Ancient One" trains people to protect earth from other dimensions.<br>
The earth is protected by <strong>N</strong>&nbsp;sanctums, destroying any of it will lead to invasion on earth.<br>
The sanctums are connected by <strong>M</strong>&nbsp;bridges.<br>
Now , you being on dormammu's side , want to find the number&nbsp;of sanctum destroying which will disconnect the sanctums.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5, M = 5
arr[] = {{1,2},{1,3},{3,2},{3,4},{5,4}}
<strong>Output :</strong> 2
<strong>Explanation:</strong>
1.Removing 1 will not make graph disconnected
(2--3--4--5).
2.Removing 2 will also not make 
graph disconnected(1--3--4--5).
3.Removing 3 makes graph disconnected 
(1--2 and 4--5).
4.Removing 4 makes graph disconnected 
(1--2--3--1 and 5).
5.Removing 5 also doesn't makes 
graph disconnected(3--1--2--3--4).
6. Therefore,there are two such vertices,
3 and 4,so the answer is 2.

</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> 
N = 2, M = 1 
arr[] = {{1, 2}}<strong>
Output :</strong> 0</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong></span></p>

<p><span style="font-size:18px">This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>doctorStrange()</strong> that takes a number of nodes&nbsp;<strong>(N)</strong>, a number of edges&nbsp;<strong>(M),</strong> a 2-D&nbsp;matrix that contains connection between nodes&nbsp;<strong>(graph)</strong>, and return the number&nbsp;of sanctums when destroyed will disconnect other sanctums of Earth.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N + M).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N + M).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ n ≤ 30000<br>
1 ≤ m ≤ 30000<br>
1 ≤ u, v&nbsp;≤ n</span></p>
</div>