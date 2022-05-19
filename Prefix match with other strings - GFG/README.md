# Prefix match with other strings
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array of strings <strong>arr[]</strong> of size <strong>n</strong> and given s a string <strong>str</strong> and an integer <strong>k</strong>. The task is to find the count of strings in <strong>arr[]</strong> whose prefix of length <strong>k</strong> matches with the <strong>k</strong> length prefix of <strong>str</strong>.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong></span>:
<span style="font-size:18px">n = 6</span>
<span style="font-size:18px">arr[] = {“abba”, “abbb”, “abbc”, “abbd”, 
“abaa”, “abca”}
str = “abbg”
k = 3
<strong>Output:</strong>&nbsp;4&nbsp;
<strong>Explanation</strong>:
“abba”, “abbb”, “abbc” and “abbd” are 
the matching strings.
</span>
</pre>

<p><br>
<strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 3
arr[] = {“geeks”, “geeksforgeeks”, “forgeeks”}
str = “geeks”
k = 2
<strong>Output:&nbsp;</strong>2
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>klengthpref()</strong>&nbsp;which takes the array of strings arr[], its size <strong>n </strong>and an integer <strong>k, </strong>a string<strong> str </strong>as input parameters&nbsp;and returns the </span><span style="font-size:18px">count of strings in <strong>arr[]</strong> whose prefix of length <strong>k</strong> matches with the <strong>k</strong> length prefix of <strong>str</strong>.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n*l) where l is the length of the longest word in arr[].<br>
<strong>Expected Auxiliary Space:</strong> O(n*l) where l is the length of the longest word in arr[].</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= n &lt;= 1000</span><br>
<span style="font-size:18px">1<sup> </sup>&lt;= |arr[i]| , |str| &lt;= 1000</span><br>
<span style="font-size:18px">1 &lt;= k &lt;= 1000<br>
arr[i], str must contain only lowercase english alphabets</span><br>
&nbsp;</p>
 <p></p>
            </div>