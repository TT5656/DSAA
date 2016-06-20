#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void print_common(const list<int> &l1, const list<int> &l2) {
	auto it1 = l1.begin(), it2 = l2.begin();
	while(it1 != l1.end() && it2 != l2.end()) {
		if(*it1 > *it2) 
			cout << *it2++ << endl;
		else if(*it1 < *it2)
			cout << *it1++ << endl;
		else {
			cout << *it1 << endl;
			++it1;
			++it2;
		}
	}
	if(it1 == l1.end())
		for_each(it2, l2.end(), [](const int &v){cout << v << endl;});
	else
		for_each(it1, l1.end(), [](const int &v){cout << v << endl;});
}

int main() {
	list<int> l1{1,3,4,5,7,8,10,11,12,13}, l2{2,4,6,7,8,9};

	print_common(l1, l2);

	return 0;
}
