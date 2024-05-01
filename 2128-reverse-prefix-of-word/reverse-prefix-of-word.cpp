class Solution {
public:
    string reversePrefix(string word, char ch) {
        bool found =  false;
        stack<char>s;
        for(int i=0; i<word.size(); i++)
        {
            s.push(word[i]);
            if(word[i]==ch)
            {
                found = true;
                break;
            }
            
        }
        if(!found)return word;
        int se = s.size();
        for(int i=0; i<se; i++)
        {
            word[i]=s.top();
            s.pop();
        }
        return word;
    }
};