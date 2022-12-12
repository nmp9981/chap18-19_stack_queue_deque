#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

int n,t;
const int maxi = 100011;
ll hist[maxi];//히스토그램의 높이

//max
inline ll max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
    memset(hist,0,sizeof(hist));
	for (int i = 1; i <= n; i++) cin >> hist[i];
	hist[n+1] = -1;
}
//히스토그램 넓이
void Histogram() {
	ll area = 0;
	stack<ll> s;
	s.push(0);
	
	for (int i = 1; i <= n+1; i++) {
		while (!s.empty() && hist[i] < hist[s.top()]) {//더 작은 높이가 오면 갱신
			int weight;//가로
			int height = s.top();//세로
			s.pop();
			
			if(s.empty()) weight = i;//스택이 비었을 경우
			else weight = i-1-s.top();
			area = max(area, hist[height] * weight);//세로*가로
		}
		s.push(i);
	}
	cout << area<<"\n";
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while(true){
	    cin>>n;
        if(n==0) break;
	    input();//입력
	    Histogram();//히스토그램 넓이
	}
	return 0;
}
