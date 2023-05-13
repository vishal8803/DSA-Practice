# Completing tasks
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">There are total <strong>n</strong> tasks given to a group of 5 students in a class. Three of those five students completed <strong>m</strong> tasks of their choices and left the group. Now the burden of completing remaining tasks is on the two students Tanya and Manya. Suppose the <strong>n</strong>&nbsp;tasks are in an array form <strong>1,2,3,...n</strong>. Tanya and Manya decided to complete their remaining tasks in the following manner :- First of the remaining task is done by Tanya and the next&nbsp;remaining one by Manya . For example if <strong>n&nbsp;</strong>= 10 and <strong>m&nbsp;</strong>= 4 and the completed 4 tasks are {2, 3, 5, 7}&nbsp;then the reamining tasks are {1, 4, 6, 8, 9, 10}&nbsp;so, Tanya completes {1, 6, 9} tasks and Manya completes {4, 8, 10} tasks and thereby completing the <strong>n</strong> tasks given.</span></p>

<p><span style="font-size:18px">Given <strong>n</strong>, <strong>m</strong> and the indexes (1 for first task, 2 for second task and so on..) of completed tasks, find the tasks which Tanya and Manya have to complete.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 15, m = 6
arr[] = {2, 5, 6, 7, 9, 4}
<strong>Output:</strong> 
1 8 11 13 15&nbsp;
3 10 12 14&nbsp;
<strong>Explanation:</strong> The remaining tasks are :
{1, 3, 8, 10, 11, 12, 13, 14, 15}.
So Tanya should take these tasks :
{1, 8, 11, 13, 15}.
And Manya should take these tasks :
{3, 10, 12, 14}.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 4, m = 3
arr[] = {2, 4, 3}
<strong>Output:</strong> 
1

<strong>Explanation:</strong>&nbsp;There are no task for Manya.
</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findTasks()</strong>&nbsp;which takes the array of integers&nbsp;<strong>arr, m</strong>&nbsp;and&nbsp;<strong>n&nbsp;</strong>as parameters and returns a pair of an array&nbsp;of integers denoting the answer.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(n)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(n)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ m&nbsp;≤ n&nbsp;≤ 10<sup>5</sup><br>
1 ≤ arr[i] ≤ n</span></p>
</div>