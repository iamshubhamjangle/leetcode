/*
[Contest]_Convert_the_Temperature.cpp

https://leetcode.com/contest/weekly-contest-319/problems/convert-the-temperature/
*/


// Kelvin = Celsius + 273.15
// Fahrenheit = Celsius * 1.80 + 32.00
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = (celsius * 1.80) + 32.00;
        
        return { kelvin, fahrenheit };
    }
};