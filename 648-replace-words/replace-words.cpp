class Solution {
public:
    vector<string> splitSentence(const string& sentence) {
    vector<string> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

string replaceWords(vector<string>& dictionary, const string& sentence) {
    unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
    vector<string> words = splitSentence(sentence);
    
    for (string& word : words) {
        for (int i = 1; i <= word.size(); ++i) {
            if (rootSet.find(word.substr(0, i)) != rootSet.end()) {
                word = word.substr(0, i);
                break;
            }
        }
    }
    
    stringstream result;
    for (int i = 0; i < words.size(); ++i) {
        if (i != 0) result << " ";
        result << words[i];
    }
    
    return result.str();
}
};