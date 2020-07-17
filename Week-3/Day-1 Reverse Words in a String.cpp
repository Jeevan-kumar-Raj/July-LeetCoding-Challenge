Day-1 Reverse Words in a String.cpp

/*
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.


*/


class Solution {
public:
    string reverseWords(string s) {
         stack<string> st = new stack<>();
       string temp = "";
       string ans  = "";
        
       for(int i =0; i <s.length(); i++){
          if(s.charAt(i) == ' '){ 
              if(temp.length() > 0)
               st.push(temp);             
              temp = "";
          }else
             temp = temp + s.charAt(i);
        }
        
        ans = ans + temp;
     
        while(!st.isEmpty()){
            ans = ans + " " + st.pop();
        }
      
        if(ans.length() != 0 && ans.charAt(0) == ' ')
          ans =  ans.substring(1);
        
        return ans;

    }
};






//JAVA Sol


class Solution {
    public String reverseWords(String s) {
       Stack<String> st = new Stack<>();
       String temp = "";
       String ans  = "";
        
       for(int i =0; i <s.length(); i++){
          if(s.charAt(i) == ' '){ 
              if(temp.length() > 0)
               st.push(temp);             
              temp = "";
          }else
             temp = temp + s.charAt(i);
        }
        
        ans = ans + temp;
     
        while(!st.isEmpty()){
            ans = ans + " " + st.pop();
        }
      
        if(ans.length() != 0 && ans.charAt(0) == ' ')
          ans =  ans.substring(1);
        
        return ans;
    }
}