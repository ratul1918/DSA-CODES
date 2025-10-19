#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Question {
    int index;
    int marks;
    int time;
    double marksPerMinute;
};

bool compare(Question a, Question b) {
    return a.marksPerMinute > b.marksPerMinute;
}

int main() {
    int M, T, n;
    cin >> M >> T >> n;
    vector<Question> questions(n);

    for (int i = 0; i < n; i++) {
        cin >> questions[i].marks >> questions[i].time;
        questions[i].index = i + 1;
        questions[i].marksPerMinute = (double)questions[i].marks / questions[i].time;
    }

    sort(questions.begin(), questions.end(), compare);


    double maxMarks = 0;
    int timeLeft = T;
    vector<pair<int, double>> answered;
    vector<double> marksGot(n + 1, 0);

    for (int i = 0; i < n && timeLeft > 0; i++) {
        if (questions[i].time <= timeLeft) {
            maxMarks += questions[i].marks;
            answered.push_back({questions[i].index, 1.0});
            marksGot[questions[i].index] = questions[i].marks;
            timeLeft -= questions[i].time;
        } else {
            double fraction = (double)timeLeft / questions[i].time;
            double partialMarks = questions[i].marks * fraction;
            maxMarks += partialMarks;
            answered.push_back({questions[i].index, fraction});
            marksGot[questions[i].index] = partialMarks;
            timeLeft = 0;
        }
    }

    cout << "Maximum " << (int)maxMarks << " marks answering alone" << endl;
    for (auto x : answered) {
        cout << "ques " << x.first << " " << fixed << setprecision(0) << (x.second * 100) << "% done -- " 
             << fixed << setprecision(0) << marksGot[x.first] << " marks" << endl;
    }

    vector<bool> done(n, false);
    double groupMarks = 0;
    int time1 = T, time2 = T;
    int i = 0, j = 0;

    while ((time1 > 0 || time2 > 0) && (i < n || j < n)) {
        
        while (i < n && done[i]) i++;
        if (i < n && time1 > 0) {
            if (questions[i].time <= time1) {
                groupMarks += questions[i].marks;
                time1 -= questions[i].time;
                done[i] = true;
            } else {
                groupMarks += questions[i].marks * ((double)time1 / questions[i].time);
                done[i] = true;
                time1 = 0;
            }
        }
       
        while (j < n && done[j]) j++;
        if (j < n && time2 > 0) {
            if (questions[j].time <= time2) {
                groupMarks += questions[j].marks;
                time2 -= questions[j].time;
                done[j] = true;
            } else {
                groupMarks += questions[j].marks * ((double)time2 / questions[j].time);
                done[j] = true;
                time2 = 0;
            }
        }
    }

    cout << "Maximum " << (int)groupMarks << " marks answering with a friend" << endl;

    return 0;
}