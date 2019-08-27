#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	stack <char> s;
	char infix[101] = {}; 
	char postfix[101] = {};
	scanf("%s", infix);

	printf("1");
	int idx = 0; bool open = 0;

	int infix_len = strlen(infix);
	for (int i = 0; i < infix_len; i++) {
		printf("2");
		if (infix[i] == '+' || infix[i] == '-') {
			if (!open) {
				if (s.size() == 1) {
					postfix[idx++] = s.top();
					s.pop();
					s.push(infix[i]);
				}
				else if (s.size() > 1) {
					while (!s.empty()) {
						printf("3");
						postfix[idx++] = s.top();
						s.pop();
					}
				}
				else 
					s.push(infix[i]);
			}
			else
				s.push(infix[i]);
		}
		else if (infix[i] == '/' || infix[i] == '*') {
			if (!open) {
				if (s.size() == 1) {
					if (s.top() == '+' || s.top() == '-') {
						s.push(infix[i]);
					}
					else if (s.top() == '/' || s.top() == '*') {
						postfix[idx++] = s.top();
						s.push(infix[i]);
					}
				}
				else if (s.size() > 1) {
					while (!s.empty()) {
						postfix[idx++] = s.top();
						s.pop();
					}
				}
				else
					s.push(infix[i]);
			}
			else 
				s.push(infix[i]);
			
		}
		else if (infix[i] == '(' || infix[i] == ')') {
			if (infix[i] == '(') {
				open = 1;
				s.push(infix[i]);
			}
			else {
				open = 0;
				while (s.top() != '(') {
					postfix[idx++] = s.top();
					s.pop();
				}
				s.pop();
			}
		}
		else 
			postfix[idx++] = infix[i];
	}
	int postfix_len = strlen(postfix);
	for (int i = 0; i < postfix_len; i++) 
		printf("%c", postfix[i]);
	return 0;
}