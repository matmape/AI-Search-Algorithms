#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Node{
	char value;
	vector<Node> children;
public:
	Node(char c){
		value = c;
	}

	void addChild(Node n){
		children.push_back(n);
		return;
	}

	void addChild(char n){
		Node foo(n);
		children.push_back(foo);
	}

	char getValue(){
		return value;
	}

	vector<Node> getChildren(){
		return children;
	}

	bool isLeaf(){
		return children.size()==0;
	}

	bool operator==(Node b){
		return b.value==value;
	}
};


void construct(Node *r)
{
	string foo;
	cout<<"Enter children for "<< r->getValue() <<" (-1 for leaf)"<<endl;
	cin>>foo;

	if(foo == "-1")
		return;
	else{
		for(int i = 0; i < foo.length(); i++)
		{
			Node t(foo[i]);
			construct(&t);

			r->addChild(t);
		}
	}
}


string depthFirstSearch(Node root, Node goal)
{
	std::stack<Node> Q;
	std::vector<Node> children;
	string path = "";
	int depth = 0;
	int limit;
   	std::cout << "Enter the limit for your DLS: " ;
	std::cin >> limit;

	Q.push(root);
	
		while(!Q.empty()) 
	{
		if (depth <= limit){
			Node t = Q.top();
		path += t.getValue();
	//	cout << "The path: ";
	//	cout << path << endl;

		Q.pop();
		
		
  
				if(t == goal){
					return path;
					}
		
					else{
	
						children = t.getChildren();
						std::reverse(children.begin(),children.end());

						for (int i = 0; i < children.size(); ++i){
						Q.push(children[i]);
								
						} 
		depth++; 
		
			}
			
		}
		
		else{
			cout << "Goal node is not found within the depth" << endl;
		}
		
	}

/**
	while(!Q.empty()) // && (path.size())<=limit
	{
		Node t = Q.top();
		path += t.getValue();
		cout << "The path: ";
		cout << path << endl;

		Q.pop();

		if(t == goal){
			
			return path;
		}
		children = t.getChildren();
		std::reverse(children.begin(),children.end());

		for (int i = 0; i < children.size(); ++i){
			Q.push(children[i]);
		} 
	} 
	**/
	return path;
}


int main(int argc, char** args)
{	
	char r;
	cout<<"Enter root node"<<endl;
	cin>>r;

	Node root(r);
	construct(&root);

	cout<<"Enter Node to search for: ";
	cin>>r;

	cout<<endl;


	cout<<"DFS Traversal: "<<depthFirstSearch(root, Node(' '))<<endl;
	cout<<"DFS Search Path: "<<depthFirstSearch(root, Node(r))<<endl;

	return 0;
}
