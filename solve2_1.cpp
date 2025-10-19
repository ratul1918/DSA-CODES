#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    string club_id;
    int start;
    int duration;
    int finish;
};

bool compare(Event a, Event b) {
    return a.finish < b.finish;
}

int main() {
    int N;
    cin >> N;
    vector<Event> events(N);

    for (int i = 0; i < N; i++) {
        cin >> events[i].club_id >> events[i].start >> events[i].duration;
        events[i].finish = events[i].start + events[i].duration;
    }
    int X;
    cin >> X;

    sort(events.begin(), events.end(), compare);

    vector<string> chosen;
    int lastFinish = 0; 

    for (int i = 0; i < N; i++) {
        if (events[i].start >= lastFinish) {
            chosen.push_back(events[i].club_id);
            lastFinish = events[i].finish + X;
        }
    }

    cout << "Chosen clubs:" << endl;
    for (auto club : chosen) {
        cout << club << endl;
    }

}