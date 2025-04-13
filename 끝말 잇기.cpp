#include <iostream>
#define endl '\n'

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <numeric>

#include <queue>

using namespace std;

class WordManager {
    public:
        WordManager() {
            word_mem.resize(26);
        }

        void insert(const string& word) {
            if (word.empty()) return;
            int start = tolower(word.front()) - 'a';
            word_mem[start].push(word);
        }

        string pop(int start) {
            if (word_mem[start].empty()) return "";
    
            string word = word_mem[start].top();
            word_mem[start].pop();
    
            string reversed = word;
            reverse(reversed.begin(), reversed.end());
    
            if (reversed != word)
                reversedQueue.push(reversed);
    
            return word;
        }
    
        void restore() {
            while (!reversedQueue.empty()) {
                string word = reversedQueue.front();
                reversedQueue.pop();
    
                int start = tolower(word.front()) - 'a';
                word_mem[start].push(word);
            }
        }
    
    private:
        vector<priority_queue<string, vector<string>, greater<>>> word_mem;
        queue<string> reversedQueue;
    };