# Optimum location of point to minimize total distance
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a set of coordinates <strong>points&nbsp;</strong>of the form [p, q]&nbsp;and a line <strong>L</strong>&nbsp;of the form <strong>ax + by + c = 0</strong>. The task is to find a point on a given line for which the sum of distances from a given set of coordinates&nbsp;is minimum.&nbsp;</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
L = {1, -1, -3}
points[] = {{-3, 2}, {-1, 0}, 
&nbsp;           {-1, 2}, {1, 2}, {3, 4}}
<strong>Output: </strong>20.77
<strong>Explanation:</strong> In above figure optimum location of 
point of x - y - 3 = 0 line is (2, -1), whose 
total distance with other points is 20.77, 
which is minimum obtainable total distance.
<img style="height: 200px; width: 233px;" src="https://media.geeksforgeeks.org/img-practice/Optimum-location-of-point-to-minimize-total-distance-1644650073.jpg" alt="">

</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
L = {2, 1, 4}
points[] = {{-1, 2}, {1, 3},{2, 4}}
<strong>Output: </strong>11.20
</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>findOptimumCost()</strong>&nbsp;which takes a line L and coordinates&nbsp;and returns an double up to 2 decimal places&nbsp;as output.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(NlogN)<br><strong>Expected Auxiliary Space:</strong> O(N)</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>5</sup><br>-10<sup>3&nbsp;</sup>&lt;= point[i] &lt;= 10<sup>3</sup></span></p></div>