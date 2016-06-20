#include <iostream>
#include <list>

using namespace std;

void print_common(const list<int> &l1, const list<int> &l2) {
	if(l1.back() < l2.front() || l1.front() > l2.back()) {
		cout << "No common elements" << endl;
		return;
	}
	auto it1 = l1.begin(), it2 = l2.begin();
	while(it1 != l1.end() && it2 != l2.end()) {
		if(*it1 > *it2)
			++it2;
		else if(*it1 < *it2)
			++it1;
		else {
			cout << *it1 << endl;
			++it1;
			++it2;
		}
	}		
}

int main() {
	list<int> l1{1,3,4,5,7,8,10,11,12,13}, l2{2,4,6,7,8,9};

	print_common(l1, l2);

	return 0;
}
