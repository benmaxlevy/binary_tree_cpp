#include <iostream>
#include <string>

class Node {
	private:
		int val;
		Node* left;
		Node* right;
	public:
		//deconstructor
		~Node() {
			delete this->left;
			delete this->right;
		}
		Node(int val) {
			this->val = val;
			this->right = nullptr;
			this->left = nullptr;
		}
		Node(int val, Node* right) {
			this->val = val;
			this->right = right;
		}
		Node(int val, Node* right, Node* left) {
			this->val = val;
			this->right = right;
			this->left = left;
		}

	
		//set node - side: 0=left, 1=right
		void set_node(bool side, int val) {
			if(side == 0) { //working w/ left node
				if(this->left == nullptr) //if not already y'know
					this->left = new Node(val);
				else
					this->left->val = val;
		
			} else if(side == 1) {
				if(this->right == nullptr)
					this->right = new Node(val);
				else
					this->right->val = val;
			}

		}
		std::string list_tree() {
			std::string res;
			res += "  " + std::to_string(this->val) + "\n";
			
			//left side
			Node* left = this->left;
			Node* right = this->right;
			while(left != nullptr) {
				res += std::to_string(left->val);
				left = left->left;
				//checking for right
				if(right != nullptr)
					res += ", " + std::to_string(right->val) + "\n";
			}
			
			return res;
		}
};
int main() {
	Node* hello = new Node(2);
	hello->set_node(0, 5);
	hello->set_node(1, 3);
	std::cout << hello->list_tree() << std::endl;
}
