#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	string infix(argv[1]);
	stack<char> p_stack;
	map<char, int> signPrio;
	signPrio['+'] = signPrio['-'] = 0;
	signPrio['*'] = signPrio['/'] = 1;
	signPrio['^'] = 2;
	signPrio['{'] = 3;
	for(unsigned int i = 0; i < infix.size(); ++i) {
		auto c = infix[i];
		if('a' <= c && c <= 'z')
			cout << c;
		else if ('(' == c)
			p_stack.push(c);
		else if ('^' == c) {
			while(!p_stack.empty() && '(' != p_stack.top() && '^' != p_stack.top() && signPrio[p_stack.top()] >= signPrio[c]) {
				cout << p_stack.top();
				p_stack.pop();
			}
			p_stack.push(c);
		}
		else if ('+' == c || '-' == c || '*' == c || '/' == c || '^' == c) {
			while(!p_stack.empty() && '(' != p_stack.top() && signPrio[p_stack.top()] >= signPrio[c]) {
				cout << p_stack.top();
				p_stack.pop();
			}
			p_stack.push(c);
		}
		else if (')' == c) {
			while(!p_stack.empty() && p_stack.top() != '(') {
				cout << p_stack.top();
				p_stack.pop();
			}
			if(p_stack.empty()) {
				cout << "No matching parenthesis" << endl;
				break;
			}
			// p_stack.top() == '(', pop the stack but not output
			p_stack.pop();							
		}
	}

	while(!p_stack.empty()) {
		cout << p_stack.top();
		p_stack.pop();
	}
	cout << endl;

	return 0;
}
