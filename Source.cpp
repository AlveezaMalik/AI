#include<iostream>
using namespace std;
#include<String>
#include <queue>
#include <set>
class Node
{
public:
	int cost;
	int action;
	Node* Parent;
	int state;
};

bool goal_test(Node* node, string goal, string states[], int size1) {

	string* States = new string[size1];
	for (int i = 0; i < size1; i++)
	{
		States[i] = states[i];
	}
	int res;
	for (int i = 0; i < size1; i++)
	{
		if (States[i] == goal)
		{
			res = i;
		}
	}
	for (int i = 0; i < size1; i++)
	{
		if (node->state == res)
		{
			return true;
		}
	}
	return false;

}


Node* Search_Problem() {
	string states[8] = { "(AgentInRoom1, Room1Dusty, Roam2Dusty)","(AgentInRoom1, Room1Dusty, Roam2Clean)","(AgentInRoom1, Room1Clean, Roam2Dusty)","(AgentInRoom1, Room1Clean, Roam2Clean)",
	"(AgentInRoom2, Room1Dusty, Roam2Dusty)","(AgentInRoom2, Room1Dusty, Roam2Clean)","(AgentInRoom2, Room1Clean, Roam2Dusty)","(AgentInRoom2, Room1Clean, Roam2Clean) "
	};
	string Action[3] = { "clear","MoveToRoom1","MoveToRoom2" };
	int transition_matrix[8][3] = { { 2,0,4 },{ 3,1,5 },{ 2,2,6 },{ 3,3,7 },{ 5,0,4 },{ 5,1,5 },{ 7,2,6 },{ 7,3,7 } };

	string Problem[2] = { "(AgentInRoom1, Room1Clean, Roam2Dusty)","(AgentInRoom1, Room1Clean, Roam2Clean)" };
	queue<Node*> Frontier;
	Node* FristNode = new Node();
	bool* isExplored = new bool[8];
	for (int i = 0; i < 8; i++)
	{
		isExplored[i] = 0;
	}
	set<int> Explored;
	for (int i = 0; i < 8; i++)
	{
		if (Problem[0] == states[i]) {
			FristNode->state = i;
			FristNode->action = -1;
			FristNode->Parent = NULL;
			isExplored[i] = 1;
			Frontier.push(FristNode);
		}
	}
	Node* node = new Node;
	Node* child;
	while (true)
	{
		if (!Frontier.empty())
		{
			node = Frontier.front();
			Frontier.pop();
			string goal = Problem[1];
			/*if (true == goal_test(node, goal, states, 8)) {
			cout << "ahtesham1" << endl;
			return node;
			}*/
			for (int i = 0; i < 3; i++)
			{
				if (isExplored[transition_matrix[node->state][i]] == 0) {
					isExplored[transition_matrix[node->state][i]] = 1;
					child = new Node;

					child->Parent = node;
					child->state = transition_matrix[node->state][i];
					child->action = i;
					/*cout << Action[i] << endl;*/
					if (goal_test(child, goal, states, 8) == true) {
						//cout << child->state;
						return child;
					}
					Frontier.push(child);
					//break;
				}
			}

		}
	}
}


int main() {


	string Problem[2] = { "(AgentInRoom1, Room1Dusty, Roam2Dusty)" ,"(AgentInRoom2, Room1Clean, Roam2Clean)" };

	Node* N = new Node;
	N = Search_Problem();
	cout << N->state << endl;
	return 0;

}