class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char, int> nos;

        // creating a freq map for characters in 'secret'
        for(int i=0; i<secret.length(); i++){
            nos[secret[i]]++;
        }

        int bulls = 0, cows = 0; 

        // counting all bulls first
        for(int i=0; i<secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls++;
                nos[secret[i]]--; 
            }
        }

        // now checking for all cows
        for(int i=0; i<secret.length(); i++){
            if(secret[i] != guess[i] and nos[guess[i]] > 0){
                cows++;
                nos[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)
