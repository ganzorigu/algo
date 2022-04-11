// 621. Task Scheduler
//     tasks = ['A','A','A','B','B','C'], n = 2

//     1. Find task having max freq and create a imaginary array seperated by
//     cooling period and task

//   task frequency
//     A     3
//     B     2
//     C     1

//     A _ _ A _ _ A   //idle_time = 4.  Remove A from list since its already
//     schedueled

//   task frequency
//     B     2
//     C     1

//     2. Fill idle time with next task having max frequency.

//   A B _ A B _ A         //idle_time = 2. Remove B from list, since its
//   scheduled.

//   task frequency
//     C     1

//     3. Repeat process until task list is not empty.

//   A B C A B _ A         //idle_time = 1. Remove C from list, since its
//   scheduled.

//     4. return idle_time + task.size()

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
	int leastInterval(vector<char> &tasks, int n)
	{

		// Solution from Community
		//         if (not n)
		//         return tasks.size();

		//         int top=0;
		//         std::unordered_map<char,int> um;
		//         std::priority_queue<std::pair<int,char>> pq;

		//         //{{B,2},{A,3},{D,1}}
		//         for(auto ch:tasks)                //1
		//         um[ch]++;

		//         //{{3,A},{2,B},{1,D}}
		//         for (auto [i,j]:um)               //2
		//         pq.push(std::make_pair(j,i));

		//         int idle_time = 0, max_ele = 0;
		//         top = pq.top().first; pq.pop();
		//         max_ele = top;
		//         idle_time = (max_ele - 1)*n;        //3

		//         while (pq.empty() != 1 && idle_time){
		//         top = pq.top().first; pq.pop();
		//         idle_time -=  std::min(max_ele-1, top);   //4
		//         }

		//         idle_time = std::max(0, idle_time);
		//         return idle_time + tasks.size();

		// My Solution
		// used array of size 26;
		// store the number of occurence and sort in descending order
		// first element task with highest number. idleTimes()
		if (n == 0)
		{
			return tasks.size();
		}

		vector<int> auxArr(26, 0);

		for (int i = 0; i < tasks.size(); i++)
		{
			auxArr[(int)(tasks[i] - 'A')]++;
		}

		sort(auxArr.begin(), auxArr.end(), greater<>());

		int numOfTypes = 0;
		while (numOfTypes < 26)
		{
			if (auxArr[numOfTypes] == 0)
			{
				break;
			}
			numOfTypes++;
		}

		int idle_time = (auxArr[0] - 1) * n;
		int max_ele = auxArr[0];
		for (int i = 1; i < numOfTypes; i++)
		{
			idle_time -= min(max_ele - 1, auxArr[i]);
			if (idle_time <= 0)
			{
				break;
			}
		}
		idle_time = std::max(0, idle_time);
		return tasks.size() + idle_time;

		// for (int i=0; i<numOfTypes; i++) {
		//     cout << i << ":" << auxArr[i] << endl;
		// }

		//         int unitTimes = 0;
		//         int numOfTasks = tasks.size();
		//         int idleTimes = 0;
		//         int j=0;
		//         while(numOfTasks>0) {
		//             if (idleTimes>0) {
		//                 // find different tasks
		//                 while(j<numOfTypes && idleTimes>0) {
		//                     if (auxArr[j]>0) {
		//                         cout << "different task:" << j << endl;
		//                         auxArr[j]--;
		//                         unitTimes++;
		//                         numOfTasks--;
		//                         idleTimes--;
		//                     }
		//                     j++;
		//                 }
		//                 if (idleTimes>0) {
		//                     cout << "idle:" << idleTimes << endl;
		//                     // add idle times
		//                     if (numOfTasks) {
		//                         unitTimes+=idleTimes;
		//                     }
		//                     idleTimes = 0;
		//                 }
		//             } else {
		//                 // pick next available task
		//                 for (int i=0; i<numOfTypes; i++) {
		//                     if (auxArr[i]>0) {
		//                         cout << "new task:" << i << endl;
		//                         j=i+1;
		//                         idleTimes = n;
		//                         unitTimes++;
		//                         numOfTasks--;
		//                         auxArr[i]--;
		//                         break;
		//                     }
		//                 }
		//             }

		//         }

		// return unitTimes;
	}
};
