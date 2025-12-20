#include<iostream>
#include<stack>
#include<string>

void sol(const std::string& text) {
	std::stack<char> st;
	for (int i = 0; i < text.size(); i++) {
		if (std::isalpha(text[i])) std::cout << text[i];
		else {
			if (text[i] == ')') {
				if (st.empty()) continue;
				while (st.top() != '(') {
					std::cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else if (text[i] != '(') {
				if (st.empty()) {
					st.push(text[i]);
					continue;
				}
				if (text[i] == '*' || text[i] == '/') {
					if (st.top() == '+' || st.top() == '-') st.push(text[i]);
					else if (st.top() == '*' || st.top() == '/') {
						std::cout << st.top();
						st.pop();
						st.push(text[i]);
					}
					else st.push(text[i]);
				}
				else {
					while (!st.empty() && st.top() != '(') {
						std::cout << st.top();
						st.pop();
					}
					st.push(text[i]);
				}
			}
			else st.push(text[i]);
		}
	}
	while (!st.empty()) {
		std::cout << st.top();
		st.pop();
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::string text;
	std::cin >> text;
	sol(text);
	return 0;
} 