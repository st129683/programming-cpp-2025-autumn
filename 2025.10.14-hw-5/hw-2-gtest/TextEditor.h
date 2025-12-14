#include <stack>
#include <string>
#include <iostream>

class TextEditor {
private:
	std::stack <char> left;
	std::stack <char> right;

	std::string getStringFromStack(std::stack <char> s, bool reverse) {
		std::string res = "";
		while (!s.empty()) {
			res += s.top();
			s.pop();
		}

		if (reverse) {
			for (int i = 0; i < res.length() / 2; ++i) {
				std::swap(res[i], res[res.length() - i]);
			}
		}
		return res;
	}

public:
    TextEditor() {}

    void addText(std::string text) {
        for (char c : text) {
        	left.push(c);
        }
    }

    int deleteText(int k) {
        int deleted = 0;
        while (deleted < k && !left.empty()) {
        	left.pop();
        	++deleted;
        }
        return deleted;
    }

    std::string cursorLeft(int k) {
        while (k-- && !left.empty()) {
        	right.push(left.top());
        	left.pop();
        }
        return getStringFromStack(left, true);
    }

    std::string cursorRight(int k) {
        while (k-- && !right.empty()) {
        	left.push(right.top());
        	right.pop();
        }
        return getStringFromStack(right, false);
    }
};


int main(int argc, char* argv[]) {
	TextEditor te;
	te.addText("andryusha dead insideov");

    std::cout << "left(5): " << te.cursorLeft(5) << std::endl;
    std::cout << "right(1): " << te.cursorRight(1) << std::endl;
    std::cout << "delete(3): " << te.deleteText(3) << std::endl;

	return 0;
}
