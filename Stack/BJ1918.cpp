#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

stack <char> s;
char infix[101];

int main() {
	scanf("%s", infix);

	int infix_len = strlen(infix);
	for (int i = 0; i < infix_len; i++) {
		if (infix[i] == '+' || infix[i] == '-') {
			if (s.empty()) 
				s.push(infix[i]);
			else if (s.size() == 1) {
				if (s.top() != '(') {
					printf("%c", s.top());
					s.pop();
				}
				s.push(infix[i]);
			}
			else if (s.size() > 1) {
				if (s.top() != '(') {
					while (1) {
						if (s.empty())
							break;
						else
							if (s.top() == '(')
								break;
						printf("%c", s.top());
						s.pop();
					}
				}
				s.push(infix[i]);
			}
		}

		else if (infix[i] == '/' || infix[i] == '*') {
			if (s.size() >= 1) {
				if (s.top() == '*' || s.top() == '/') {
					printf("%c", s.top());
					s.pop();
					s.push(infix[i]);
				}
				else 
					s.push(infix[i]);
			}
			else 
				s.push(infix[i]);
		}

		else if (infix[i] == '(' || infix[i] == ')') {
			if (infix[i] == '(') 
				s.push(infix[i]);
			else {
				if (!s.empty()) {
					while (s.top() != '(') {
						printf("%c", s.top());
						s.pop();
					}
					s.pop();
				}
			}
		}
		else
			printf("%c", infix[i]);
	}
	while (1) {
		if (s.empty())
			break;
		else
			if (s.top() == '(')
				break;
		printf("%c", s.top());
		s.pop();
	}
	return 0;
}