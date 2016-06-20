#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

// define the struct containing expression string and its expression priority
typedef struct {
	string s;
	int p;
} str_prio_pair;

int main(int argc, char *argv[]) {
	map<char, int> signPrio;
	stack<str_prio_pair> p;
	string postfix(argv[1]);

	signPrio['+'] = signPrio['-'] = 1;
	signPrio['*'] = signPrio['/'] = 2;
	signPrio['^'] = 3;
	
	for(unsigned int i = 0; i != postfix.size(); ++i) {
		auto c = postfix[i];
		// convert the char to string which is pushed to the stack
		string s;
		s.push_back(c);
		// if the charater is an operand, convert it to a string and push it to the
		// stack, and set the priority of the expression to 0
		if(c >= 'a' && c <= 'z') {
			p.push({s, 0});
		}
		// if an operator is encountered
		else {
			// if the postfix expression is appropriate there would at least be
			// two entries in the stack when an operator is encoutered
			// s1 is the right subexpression, s2 is the left subexpression
			auto s1 = p.top();
			p.pop();
			auto s2 = p.top();
			p.pop();
			// if s1 is not a single character operand and its priority is not 
			// determined by ^ and its priority is not higher than c
			if(s1.p > 0 && s1.p != 3 && s1.p <= signPrio[c]) {
				s1.s = "(" + s1.s + ")";
			}
			if(s2.p > 0) {
				// if s2's priority is determined by ^ and the operator is ^
				// because ^ is right associated, parentheses should be added
				if((s2.p == 3 && signPrio[c] ==3 ) ||
				// if the priority of the left subexpression is equal to that 
				// of the operator, no parenthesis is needed
				   (s2.p < signPrio[c])) {
					s2.s = "(" + s2.s + ")";
				}
			}
			string s_tmp = s2.s + s + s1.s;
			// the priority of the new expression is determined by the encountered 
			// operator
			p.push({s_tmp, signPrio[c]});
		}
	}

	if(1 == p.size())
		cout << p.top().s << endl;
	
	p.pop();

	return 0;
}
