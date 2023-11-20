//roundrobin

#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<vector<int>> processes = {{1, 0, 5}, {2, 1, 6}, {3, 2, 3}, {4, 3, 1}, {5, 4, 5}, {6, 6, 4}};
	int pIndex = 0;
	int totalTime = [&](){
		int sum = 0;
		for(auto i : processes) sum += i[2];
		return sum;
	}();
	int t = 0;
	int TQ = 4;
	queue<vector<int>> readyQ;
	readyQ.push(processes[pIndex++]);
	cout << "Schedule :" << endl;
	while(!readyQ.empty()){
		auto v = readyQ.front();
		cout << v[0] << "\t";
		readyQ.pop();
		if(v[2] <= TQ){
			int pid = v[0];	
			t += v[2];
			for(int i = 0; i < processes.size(); i++){
				if(processes[i][0] == pid){
					processes[i].push_back(t);
					processes[i].push_back(t - v[1]);
					processes[i].push_back(t - v[1] - v[2]);
					break;
				}
			}
		}
		else{
			t += TQ;
			while(pIndex < processes.size() && processes[pIndex][1] <= t){
				readyQ.push(processes[pIndex++]);
			}
			v[2] -= TQ;
			readyQ.push(v);
		}
	}
	cout << "\n\n";
	cout << "PID\t" << "AT\t" << "BT\t" << "TAT\t" << "CT\t" << "WT\t" << endl;
	for(auto i : processes){
		cout << i[0] << "\t" << i[1] << "\t" << i[2] << "\t";
		cout << i[3] << "\t" << i[4] << "\t" << i[5] << endl;
	}
}
