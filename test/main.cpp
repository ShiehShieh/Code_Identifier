#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;


map<char, int> punctuation;


class node {
public:
	node() {}
	node(char value, node* left, node* right) {
		this->left = left;
		this->right = right;
		this->value = value;
	}
	~node() {}

	node *left = 0;
	node *right = 0;
	char value = '@';
};

string infix_to_inv(string expression) {
	string result;
	vector<char> my_stack;

	for(char c : expression) {
		if ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
			result += c;
		}else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
			if (my_stack.empty())
			{
				my_stack.push_back(c);
			}else if (c == ')')
			{
				while(my_stack.back() != '(') {
					result += my_stack.back();
					my_stack.pop_back();
				}
				my_stack.pop_back();
			}else if (my_stack.back() == '(')
			{
				my_stack.push_back(c);
			}else if (punctuation[my_stack.back()] > punctuation[c])
			{
				while(punctuation[my_stack.back()] >= punctuation[c] && my_stack.back() != '(') {
					result += my_stack.back();
					my_stack.pop_back();
				}
				my_stack.push_back(c);
			}else if (punctuation[my_stack.back()] <= punctuation[c])
			{
				my_stack.push_back(c);
			}
		}
	}

	while(!(my_stack.empty())) {
		result += my_stack.back();
		my_stack.pop_back();
	}

	return result;
}

node build_tree(string changed, vector<node>& my_stack) {
	node new_node;
	for(char c : changed) {
		if ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
			my_stack.push_back(*(new node(c, 0, 0)));
		}else if (c == '+' || c == '-' || c == '*' || c == '/') {
			node *node_right = new node(my_stack.back().value, my_stack.back().left, my_stack.back().right);
			my_stack.pop_back();
			node *node_left = new node(my_stack.back().value, my_stack.back().left, my_stack.back().right);
			my_stack.pop_back();
			new_node = *(new node(c, node_left, node_right));
			my_stack.push_back(new_node);
		}
	}

	return my_stack.back();
}

string poland(node root) {
	string result;

	result += root.value;

	if (root.left != NULL)
	{
		result += poland(*(root.left));
	}

	if (root.right != NULL)
	{
		result += poland(*(root.right));
	}

	return result;
}

int main(int argc, char const *argv[]) {
	string expression;
	string changed;
	vector<node> my_stack;

	punctuation['+'] = 2;
	punctuation['-'] = 2;
	punctuation['*'] = 5;
	punctuation['/'] = 5;
	punctuation['('] = 10;

	cout << "请输入表达式： " << flush;
	cin >> expression;
	cout << endl;

	changed = infix_to_inv(expression);

	node root = build_tree(changed, my_stack);

	cout << "波兰表达式： " << poland(root) << endl;
	cout << endl;

	cout << "中缀表达式： " << expression << endl;
	cout << endl;

	cout << "逆波兰表达式： " << changed << endl;
	cout << endl;

	return 0;
}
