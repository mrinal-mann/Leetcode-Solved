#include <stack>
#include <climits> // For INT_MAX

class MinStack {
private:
    std::stack<long long> st; // Stack to store values and encoded minimums
    long long mini;           // Variable to store the current minimum value

public:
    MinStack() {
        mini = INT_MAX; // Initialize mini to the maximum possible value
    }
    
    void push(int val) {
        long long value = (long long)val; // Convert int to long long for calculations
        if (st.empty()) {
            mini = value;
            st.push(value); // Push the first element as-is
        } else {
            if (value < mini) {
                st.push(2 * value - mini); // Encode the current minimum
                mini = value;             // Update the minimum
            } else {
                st.push(value); // Push normally
            }
        }
    }
    
    void pop() {
        if (st.empty()) return; // Do nothing if the stack is empty

        long long topElement = st.top();
        st.pop();

        if (topElement < mini) { 
            mini = 2 * mini - topElement; // Decode the previous minimum
        }
    }
    
    int top() {
        if (st.empty()) return -1; // Return -1 if the stack is empty

        long long topElement = st.top();
        if (topElement < mini) {
            return (int)mini; // If encoded, return the minimum
        }
        return (int)topElement; // Otherwise, return the top element
    }
    
    int getMin() {
        return (int)mini; // Return the current minimum
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
