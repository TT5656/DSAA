#include <iostream>
#include <list>
#include <string>

using namespace std;

void Jose(int M, int N) {
	list<int> l;
	for(auto i = 0; i != N; )
		l.push_back(++i);
	auto it = l.begin();
	auto m = M % N;
	auto nLeft = l.size();
	while(nLeft > 1) {
		if(m <= nLeft/2)
			while(m--) { 
				++it;
				if(it == l.end())
					it = l.begin();
			}
		else
			while(m--) {
				if(it == l.begin())
					it = --l.end();
				else
					--it;
			}
		m = M;
		cout << *it << endl;
		it = l.erase(it);
		--nLeft;
		m = M % nLeft;
		if(it == l.end())
			it = l.begin();
	}
	cout << "The winner is " << l.front() << endl;
}

int main(int argc, char *argv[]) {
	int M = stoi(argv[1]), N =stoi(argv[2]);
	Jose(M,N);

	return 0;
}
