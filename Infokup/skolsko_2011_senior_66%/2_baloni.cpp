#include<iostream>
#include<utility>
#include<climits>
#include<list>
#define INF LLONG_MAX-1
#define ll long long

using namespace std;

list<pair<ll,pair<ll,ll> > > balloons;

void update_balloons_time(auto curr) {
	auto next = curr;
	next++;
	if(curr==balloons.begin()) curr->second.first = INF;
	if(next!=balloons.end()) {
		if(next->first < curr->first) next->second.first = INF;
		else if (next->first < curr->first*2) next->second.first = 0;
		else next->second.first = next->first-curr->first*2;
		if(curr->first < next->first) curr->second.second = INF;
		else if(curr->first < next->first*2) curr->second.second = 0;
		else curr->second.second = curr->first - next->first * 2;
	}
}

void update_balloons() {
	for(auto x=balloons.begin();x!=balloons.end();x++) update_balloons_time(x);
}

ll next_time() {
	ll nextTime = INF;
	for(auto x=balloons.begin();x!=balloons.end();x++) nextTime = min(nextTime,min(x->second.first,x->second.second));
	return nextTime;
}

void GrowBalloons(ll growTime) {
	for(auto x=balloons.begin();x!=balloons.end();x++) x->first += growTime;
}

void popballoons() {
	while(1337) {
		if(min(balloons.begin()->second.first, balloons.begin()->second.second)==0) {
			balloons.erase(balloons.begin());
			update_balloons_time(balloons.begin());
		}
		for(auto x=balloons.begin();x!=balloons.end();x++) {
			auto next = x;
			next++;
			if (next==balloons.end()) goto end;
			if (min(next->second.first, next->second.second) == 0) {
				balloons.erase(next);
				update_balloons_time(x);
				break;
			}
		}
	}
	end:
		return;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n, x; cin >> n;
	for(int i=0;i<n;i++) {
		cin >> x;
		balloons.push_back(make_pair(x,make_pair(INF,INF)));
	}
	ll cTime = 0;
	update_balloons();
	while(balloons.size()>1) {
		ll diff = next_time();
		cTime += diff;
		GrowBalloons(diff);
		update_balloons();
		popballoons();
	}
	cout << cTime;
	return 0;
}
