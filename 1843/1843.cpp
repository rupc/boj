#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

void read_input(istream& pin) {
	pin >> N;
}

// O(N)
long long find_sol_constraintA(int a) {
	long long result = 0;
	if(a<=2) return 0;

	for(int i=a; i>2; --i) {
		if(i%2 == 0) {
			result += (i/2-1);
		} else {
			result += i/2;
		}
	}
	return result;
}


//
int findB(int b) {
	vector<int> divisors;
	int result = 0;
	for(int i=1; i<=(int)sqrt(b); i++) { 
		if(b%i == 0) {
			divisors.push_back(i);
			divisors.push_back(b/i);
		}
	}

	sort(divisors.begin(), divisors.end());
	int sz = divisors.size();
	for(int i=1; i<sz; ++i) {
		for(int j=i-1; divisors[j]>= divisors[i]/2 ; j--) {
			for(int k=0; k<=j; k++) {
				if(divisors[k] + divisors[j] == divisors[i]) {
					result++;
					break;
				}
			}
		}
	}

	return result;
}

long long fb(int b) {

	vector<int> divisors;
	int result = 0;
	for(int i=1; i<=(int)sqrt(b); i++) { 
		if(b%i == 0) {
			divisors.push_back(i);
			divisors.push_back(b/i);
		}
	}

	sort(divisors.begin(), divisors.end());
	int sz = divisors.size();
    for (auto &p : divisors) {
        std::cout << p << " ";
    }
    for(int i=1; i<sz; ++i) {
        for(int j=i-1; divisors[j]>= divisors[i]/2 ; j--) {
            //std::cout << i << " " << j << endl;
            /*for(int k=0; k<=j; k++) {
                if(divisors[k] + divisors[j] == divisors[i]) {
                    result++;
                    break;
                }
            }*/
        }
    }
    return result;
}
int find_sol_constraintC(int c) {
	int result = 0;
	vector<bool> prime(c+1, true);
	for(int p=2; p*p<=c; p++) {
		if(prime[p]) {
			for(int i=p*2; i<=c; i+=p) prime[i] = false;
		}
	}

	for(int p=2; p<=c-2; p++) 
		if(prime[p] && prime[p+2])  result++;
	
	return result;
}



int main() {
	read_input(cin);
    int sa = find_sol_constraintA(N);
    //std::cout << sa << endl;
    int sb = fb(N);
    //std::cout << sb << endl;
    int sc = find_sol_constraintC(N);
    //std::cout << sc << endl;
	return 0;
}
