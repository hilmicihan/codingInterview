/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
link :https://leetcode.com/problems/letter-combinations-of-a-phone-number/

*/


/**
 * @param {string[]} result
 * @param {string} current
 */
 var findStrings =  function(result,current)
 {
     if(result.length>0)
     {
     let front = result[0];
     let targetLength = front.length+1;
     while(front.length<targetLength)
             {
         for(let i of current)
         {
                 let temp = front;
                 temp+=i;
                 result.push(temp);
 
         }
             result.shift();
          front = result[0];
         }
     }
     else
     {
         for(let i of current)
         {
            
             result.push(i);
         }
     }
     
 }
 
 /**
  * @param {string} digits
  * @return {string[]}
  */
 var letterCombinations = function(digits) {
     let result = [];
     let combinations = [
          "",
         "",
         "abc",
         "def",
         "ghi",
         "jkl",
         "mno",
         "pqrs",
         "tuv",
         "wxyz"
     ];
     for(let i=0;i<digits.length;i++)
         {
             findStrings(result,combinations[digits[i]-'0']);
         }
     return result;
     
 };