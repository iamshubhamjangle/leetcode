/*
Integer_to_Roman.cpp

https://leetcode.com/problems/integer-to-roman/
*/

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]  = {"","M","MM","MMM"};
        
        // return ths[forthNum] + hrns[thirdNum] + tens[secondNum] + ones[unitNum]
        return ths[(num%10000)/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};


// class Solution {
// public:
//     string intToRoman(int num) {
//         int intCode[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
//         string code[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
//         string s;
//         for(int i=0; i<13; ++i){
//             while(num>=intCode[i]){
//                 s.append(code[i]);
//                 num-=intCode[i];
//             }
//         }
//         return s;
//     }
// };