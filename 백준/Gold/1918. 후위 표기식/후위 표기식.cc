#include<iostream>
#include<string>
#include<queue>
void set_queue(const std::string& text, std::queue<char>& qu) {
	for (const char ch : text) {
		qu.push(ch);
	}
}

void clear_the_queue(std::queue<char>& qu) {
	while (!qu.empty()) {
		qu.pop();
	}
}

void move_values_from_qu_to_qu(std::queue<char>& a, std::queue<char>& b) {
	while (!b.empty()) {
		char now = b.front();
		a.push(now);
		b.pop();
	}
}

void postify_times_and_obelus(std::queue<char>& qu) {
	int loop = qu.size();
	bool target_detected = false;
	char target = ' ';
	while (loop--) {
		char now = qu.front();
		qu.pop();
		//if *or / -> if already target_detected -> push the target and save the now in target
		//else -> target_detected. and save the now in target
		if (now == '*' || now == '/') {
			if (target_detected) {
				qu.push(target);
				target = now;
			}
			else {
				target_detected = true;
				target = now;
			}
		}
		//if + or - -> if already * or / in target -> push target and now; else just push
		if (now == '+' || now == '-') {
			if (target_detected) {
				target_detected = false;
				qu.push(target);
			}
			qu.push(now);
		}
		//if alpha -> just push
		if (std::isalpha(now)) qu.push(now);
	}
	//like a*b case. after a b, don' forget to push the target *.
	if (target_detected) qu.push(target);
}
//similiar with times and obelus ver.
//just consider * and / --> alphabet
void postify_plus_and_minus(std::queue<char>& qu) {
	int loop = qu.size();
	bool target_detected = false;
	char target = ' ';
	while (loop--) {
		char now = qu.front();
		qu.pop();
		if (now == '+' || now == '-') {
			if (target_detected) {
				qu.push(target);
				target = now;
			}
			else {
				target_detected = true;
				target = now;
			}
		}
		else
			qu.push(now);
	}
	//if there's any + or -, I must push the target after finishing it.
	//for example, a+b -> a b ? -> a b +. don't forget to pushing the target
	if (target_detected) qu.push(target);
}

//one section --> (...) or no () notation
//but there can be 'x's which are variables for inner sections.
//like this -> a+(b*(c+d)/(e-f)+g) -> a+(b*x/x+g)
//I'm gonna use a vector or queue for "sub_qu"s. if now == x, then replace its elems into x
void make_postfix_notation_in_one_section(std::queue<char>& qu, std::queue<std::queue<char>>& sub_qus) {
	//first, postify * and /
	//second, do + and - --> because of the rule calcuating + and - after * and /
	postify_times_and_obelus(qu);
	postify_plus_and_minus(qu);

	//after postify, let's push some values at x.
	//x's elems should be postfix notation. because it should be done from deeper recursion.
	int loop = qu.size();
	while (loop--) {
		char now = qu.front();
		qu.pop();
		if (now == 'x') {
			std::queue<char> temp = sub_qus.front();

			sub_qus.pop();
			move_values_from_qu_to_qu(qu, temp);
		}
		else qu.push(now);
	}
}
//my solution. convert to postfix notation from deeper notation.
// 4(3(2(1)2)3)4  : 1 will be converted first, then 2, 3, ... --> recursion.
// finished notations will be saved as 'x' ==> a*x+c (x == d*f/g)
// why use x? -> to convert easily. a*x+c  or a*bcd*/*+c.  first one looks like easier. 
// maybe it's called 'substitution'
//get some sub_qu to divide into sections. if a*(b+c*(d+e))) -> a*, b+c*, d+e
//and postify each sections, and combine together.
//to do this, I may have to make sub_qus for using as parameters of make_postfix_notation_in_one_section
void divide_by_sections_and_make_postfix_notation(std::queue<char>& qu) {
	std::queue<std::queue<char>> sub_qus;
	std::queue<char> sub_qu;
	int loop = qu.size();
	bool inner_section = false, there_is_level_2_inner_section = false, there_is_inner_section =false;
	int inner_section_level = 0;
		while (loop--) {
		char now = qu.front();
		qu.pop();
		if (now == '(') {
			//if above level one, we need to save '('
			if (inner_section_level>0) sub_qu.push(now);
			//else don't have to save it.
			there_is_inner_section = true;
			inner_section = true;
			if (++inner_section_level > 1) there_is_level_2_inner_section = true;
		}
		else if (now == ')') {
			//if innersection ends.
			if (--inner_section_level == 0) {
				inner_section = false;
				qu.push('x');
				//if there are several level 1 inner sections -> several x, use sub_qus
				sub_qus.push(sub_qu);
				clear_the_queue(sub_qu);
			}
			//if in a innersection, we gotta save ')'. it may be the end of section level 2, 3 ,...
			else sub_qu.push(now);
		}
		else {
			if (inner_section) sub_qu.push(now);
			else qu.push(now);
		}
	}
	//if there is level 2 inner sections ex) a+(b+(c+d)+(e+f)+g) -> c+d, e+f are level 2 inner sections
	//-> recursion -> until qu got only level 1 sections or no sections. such as a+(b+c)+(d+f)
	if (there_is_level_2_inner_section) {
		int loop = sub_qus.size();
		while (loop--) {
			std::queue<char> elem_qu = sub_qus.front();
			divide_by_sections_and_make_postfix_notation(elem_qu);
			sub_qus.push(elem_qu);
			sub_qus.pop();
		}
	}
	//only level one sections present
	if (there_is_inner_section && !there_is_level_2_inner_section) {
		int loop = sub_qus.size();
		while (loop--) {
			std::queue<char> temp_qu = sub_qus.front();
			sub_qus.pop();
			make_postfix_notation_in_one_section(temp_qu, sub_qus);
			sub_qus.push(temp_qu);
		}	
	}
	make_postfix_notation_in_one_section(qu, sub_qus);
}

void print_queue(std::queue<char>& qu) {
	while (!qu.empty()) {
		std::cout << qu.front();
		qu.pop();
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::string text; std::cin >> text;
	std::queue<char> qu;
	set_queue(text, qu);
	divide_by_sections_and_make_postfix_notation(qu);
	print_queue(qu);
	return 0;
}

//I know this code looks like shxt.
//But "Perfection is despair. but in imperfection does evolution exist."