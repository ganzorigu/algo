/*
 * 682. Baseball game
 *
 * */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
  public:
	//     int calPoints(vector<string>& ops) {
	//         vector<bool> rounds(ops.size(), false);
	//         vector<int> val(ops.size(), 0);
	//         int j=0;
	//         for (int i=0; i<ops.size(); i++) {
	//             // cout << ops[i] << endl;
	//             if (ops[i] == "C") {
	//                 rounds[i] = true;
	//                 j=i;
	//                 while(rounds[j] == true) {
	//                     j--;
	//                 }
	//                 rounds[j] = true;
	//                 val[j] = 0;
	//                 val[i] = 0;
	//             } else if (ops[i] == "D") {
	//                 j=i-1;
	//                 while(rounds[j] == true) {
	//                     j--;
	//                 }
	//                 //cout << "double:" << ops[j] << endl;
	//                 val[i] = val[j]*2;
	//             } else if (ops[i] == "+") {
	//                 j = i - 1;
	//                 while(rounds[j] == true) {
	//                     j--;
	//                 }
	//                 val[i] += val[j];
	//                 j--;
	//                 while(rounds[j] == true) {
	//                     j--;
	//                 }
	//                 val[i] += val[j];
	//             } else {
	//                 val[i] = stoi(ops[i]);
	//             }

	//         }

	//         int sum = 0;
	//         // cout << "result array:" << endl;
	//         for (int i=0; i<val.size(); i++){
	//             sum += val[i];
	//             // cout << val[i] << endl;
	//         }
	//         return sum;
	//     }
	int calPoints(vector<string> &ops)
	{
		stack<int> st;

		for (int i = 0; i < ops.size(); i++)
		{
			if (ops[i] == "C")
			{
				st.pop();
			}
			else if (ops[i] == "D")
			{
				st.push(st.top() * 2);
			}
			else if (ops[i] == "+")
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num2);
				st.push(num1);
				st.push(num1 + num2);
			}
			else
			{
				st.push(stoi(ops[i]));
			}
		}
		int sum = 0;
		while (!st.empty())
		{
			sum += st.top();
			st.pop();
		}
		return sum;
	}
};

int main()
{
}
