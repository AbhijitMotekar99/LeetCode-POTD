class Solution {
public:
    // Function to parse OR expressions
    bool parse_or(const string& expression, int& index) {
        bool result = false;
        while (expression[index] != ')') {
            index++;  // Skip ',' or move to the next subexpression
            result = result || parse(expression, index);
        }
        return result;
    }
    
    // Function to parse AND expressions
    bool parse_and(const string& expression, int& index) {
        bool result = true;
        while (expression[index] != ')') {
            index++;  // Skip ',' or move to the next subexpression
            result = result && parse(expression, index);
        }
        return result;
    }
    
    // Function to parse NOT expressions
    bool parse_not(const string& expression, int& index) {
        index++;  // Skip '('
        bool result = !parse(expression, index);
        return result;
    }
    
    // Main parse function to handle the expression recursively
    bool parse(const string& expression, int& index) {
        if (expression[index] == 't') {
            return true;
        } 
        else if (expression[index] == 'f') {
            return false;
        } 
        else if (expression[index] == '!') {
            index += 2;  // Skip '!' and '('
            bool result = parse_not(expression, index);
            index++;  // Skip ')'
            return result;
        } 
        else if (expression[index] == '&') {
            index += 2;  // Skip '&' and '('
            bool result = parse_and(expression, index);
            index++;  // Skip ')'
            return result;
        } 
        else if (expression[index] == '|') {
            index += 2;  // Skip '|' and '('
            bool result = parse_or(expression, index);
            index++;  // Skip ')'
            return result;
        }
        return false;
    }
    
    bool parseBoolExpr(string expression) {
        int index = 0;
        return parse(expression, index);
    }
};
