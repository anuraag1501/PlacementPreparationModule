class minStack
{   
    vector<int> stack, minstack;
    int i, id;
	public:
		minStack() {
            i = id = 0;
            stack.resize(100000);
            minstack.resize(100000);
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num){
			stack[i] = num;
            minstack[id] = (id ? min(minstack[id-1],num) : num);
            i++,id++;
		}
		int pop() {
            if(i==0) return -1;
            i--,id--;
            return stack[i];
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top() {
            if(!i) return -1;
            return stack[i-1];
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin() {
            if(!id) return -1;
            return minstack[id-1];
		}
};