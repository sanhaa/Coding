// 9012¹ø: °ýÈ£
#include <iostream>

using namespace std;

int main() {
	int T = 0;
	char c;
	int check = 0; 
	int NF = 0;

	scanf("%d\n", &T);

	while (T--) {
		check = 0;
		NF = 0;
		while (1) {
			scanf("%c", &c);
			if (check < 0) NF = 1;
			if (c == '\n') break;
			else if (c == '(') check++;
			else if (c == ')') check--;
		}
		if (check != 0 || NF) printf("NO\n");
		else printf("YES\n");	 
	}

}
