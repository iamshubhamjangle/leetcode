/*
Words_Within_Two_Edits_of_Dictionary.cpp

Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
Output: ["word","note","wood"]
*/

class Solution {
public:
	vector<string> twoEditWords(vector<string>& queryy, vector<string>& dictry) {
        int count = 0;
        vector<string> ans;

        for(int i=0; i<queryy.size(); i++){
            for(int j=0; j<dictry.size(); j++){
                count = 0;
                for(int k=0; k<dictry[j].size(); k++){
                    if(queryy[i][k] != dictry[j][k])
                        count++;
                }
                if(count <= 2){ 
                    ans.push_back(queryy[i]);
                    break;
                }
            }
        }

        return ans;
    }
};