#include "Node.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
using c_node_t = Node<char>;

vector<c_node_t*> DFS(c_node_t* root, char target)
{
	stack<c_node_t*> node_stack;
	root->visited = true;
	node_stack.push(root);
	while (!node_stack.empty())
	{
		c_node_t* current_node = node_stack.top();
		if (current_node->data == target)
		{
			cout << "Found: " << current_node->data << endl;
			break;
		}
		else
		{
			cout << "Visited: " << current_node->data << endl;
		}

		bool popNode = true;

		for (auto child : current_node->children)
		{
			if (!child->visited)
			{
				popNode = false;
				child->visited = true;
				node_stack.push(child);
				break;
			}
		}

		if (popNode)
		{
			node_stack.pop();
		}
	}

	vector<c_node_t*> path;
	while (!node_stack.empty())
	{
		path.insert(path.begin(), node_stack.top());
		node_stack.pop();

	}

	return path;
}

vector<c_node_t*> BFS(c_node_t* root, char target)
{
	if (root == nullptr) return vector<c_node_t*>();

	queue<c_node_t*> node_queue;
	root->visited = true;

	node_queue.push(root);

	while (!node_queue.empty())
	{
		c_node_t* current = node_queue.front();

		if (current->data == target)
		{
			cout << "found: " << current->data << endl;
			break;
		}
		else
		{
			cout << "visit: " << current->data << endl;
		}

		for (auto child : current->children)
		{
			if (!child->visited)
			{
				child->visited = true;
				child->parent = current;
				node_queue.push(child);
			}
		}

		node_queue.pop();
	}

	vector<c_node_t*> path;
	c_node_t* node = (!node_queue.empty()) ? node_queue.front() : nullptr;
	while (node)
	{
		path.insert(path.begin(), node);
		node = node->parent;
	}

	return path;
}

int main()
{
	c_node_t* nodeA = new c_node_t('A');
	c_node_t* nodeB = new c_node_t('B');
	c_node_t* nodeC = new c_node_t('C');
	c_node_t* nodeD = new c_node_t('D');
	c_node_t* nodeE = new c_node_t('E');
	c_node_t* nodeF = new c_node_t('F');

	nodeA->children.push_back(nodeB);
	nodeA->children.push_back(nodeC);

	nodeB->children.push_back(nodeD);
	nodeB->children.push_back(nodeE);

	nodeC->children.push_back(nodeE);
	nodeC->children.push_back(nodeF);

	/*cout << "DFS\n";
	auto path = DFS(nodeA, 'F');*/

	cout << "BFS\n";
	auto path = BFS(nodeA, 'F');

	cout << "Path: ";
	for (auto node : path)
	{
		cout << node->data << "->";
	}
	cout << endl;

}