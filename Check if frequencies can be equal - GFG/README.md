# Check if frequencies can be equal
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string <strong>s</strong> which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
s = xyyz
<strong>Output:</strong> 1 
<strong>Explanation:</strong> Removing one 'y' will make 
frequency of each letter 1.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
s = xxxxyyzz
<strong>Output:</strong> 0
<strong>Explanation:</strong> Frequency can not be made same 
same by removing just 1 character.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You dont need to read input or print anything. Complete the function<strong> sameFreq() </strong>which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.<br>
<strong>Note:&nbsp;</strong>The driver code print 1 if the value returned is true, otherwise 0.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N) where N is length of str<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= str.length() &lt;= 10<sup>4</sup></span></p>

<p>&nbsp;</p>
</div>