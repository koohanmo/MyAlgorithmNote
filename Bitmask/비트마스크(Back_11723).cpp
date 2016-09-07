//BAEK 11723
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;
int main() {

	int n; scanf("%d", &n);
	int mask = 0;
	while (n--) {
		char temp[10];
		scanf("%s", &temp); 
		string cmd(temp);
		int x=0;
		if (cmd.compare("all") != 0 && cmd.compare("empty") != 0) scanf("%d", &x);
		x--;
		if (cmd.compare("add")==0) {
			mask |= (1 << x);
		}else if (cmd.compare("remove") == 0) {
 
			mask &= ~(1 << x);
		}
		else if (cmd.compare("check") == 0) {
			if ((mask&(1 << x)) == 0) printf("0\n");
			else printf("1\n");
		}
		else if (cmd.compare("toggle") == 0) {
			mask ^= (1 << x);
		}
		else if (cmd.compare("all") == 0) {
			mask = (1 << 20) - 1;
		}
		else if (cmd.compare("empty") == 0) {
			mask = 0;
		}
	}
	return 0;
}