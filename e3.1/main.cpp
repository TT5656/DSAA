#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <memory>

using namespace std;

int main() {
	list<unsigned int> L{1,2,3,4,5,6,7,8,9}, P{1,3,4,6};
	auto it = L.begin(), Pit = P.begin();
	unsigned int i = 0;
	while(Pit != P.end()) {
		if(i == *Pit) {
			cout << *it << endl;
			++Pit;
		}
		++it;
		++i;
	}
	return 0;
}
