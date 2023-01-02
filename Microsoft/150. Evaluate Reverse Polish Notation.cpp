class Solution {
public:
    int evalRPN(vector<string>& tokens){

        stack<int> s;
        int val;
        for(int i=0; i<tokens.size(); i++){

            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                string opt = tokens[i];
                
                    if(opt == "+"){ 
                        int low = s.top();
                        s.pop();
                        int high = s.top();
                        s.pop();
                        s.push(high+low);
                       
                    }
                    else if(opt == "*"){
                        int low = s.top();
                        s.pop();
                        int high = s.top();
                        s.pop();
                        s.push(high*low);
                        
                    }
                    else if(opt == "-"){
                        int low = s.top();
                        s.pop();
                        int high = s.top();
                        s.pop();
                        s.push(high-low);
                       
                    }else if(opt == "/"){
                        int low = s.top();
                        s.pop();
                        int high = s.top();
                        s.pop();
                        s.push(high/low);
                        
                    }
               
            }else{
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
    }
};
