#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string name;
    double value;
    double weight;
    double v_per_w;
    Item(string n, double v, double w){
        name = n;
        value = v;
        weight = w;
        v_per_w = value / weight;
    }
};

bool compare(Item a, Item b) {
    return a.v_per_w > b.v_per_w;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items;
    for(int i=0; i<n; i++){
        string name;
        double value,weight;
        cout <<"Enter name, value and weight for item" <<i+1 <<": "<<endl;
        cin >> name >> value >> weight;
        items.push_back(Item(name, value, weight));
    }

    int k;
    cout <<"Enter the number of theives: ";
    cin >> k;

    vector<double>W(k);
    cout<<"Enter the weights for each thief: "<<endl;
    for(int i=0; i<k; i++){
        cin >> W[i];
    }

    vector<Item> remaining = items;
    sort(remaining.begin(), remaining.end(), compare);

    vector<double> profits(k,0.0);
    vector<vector<pair<string,pair<double,double>>>> taken_items(k);

    for(int t=0; t<k; t++){
        double cap = W[t];
        for(auto &item : remaining){
            if(cap <= 0 || item.weight <= 0) continue;
            double take_w = min(item.weight, cap);
            double take_v = take_w * item.v_per_w;
            taken_items[t].push_back({item.name, {take_w, take_v}});
            profits[t] += take_v;
            item.weight -= take_w;
            item.value -= take_v;
            cap -= take_w;
        }
    }

    int thieves_used = 0;
    for(int i = 0; i < k; i++) {
        if(taken_items[i].empty()) continue;
        thieves_used++;
        for(auto &item_info : taken_items[i]) {
            cout << "Taking " << item_info.first << ": " << item_info.second.first << " kg " << item_info.second.second << " taka" << endl;
        }
        cout << "Thief " << i+1 << " profit: " << profits[i] << " taka" << endl;
    }
    cout << "Total " << thieves_used << " thieves stole from the warehouse." << endl;

    // Show remaining items, if any
    bool items_left = false;
    for(auto &item : remaining) {
        if(item.weight > 0) items_left = true;
    }
    if(items_left) {
        cout << "Still following items are left" << endl;
        for(auto &item : remaining) {
            if(item.weight > 0) {
                cout << item.name << " " << item.weight << " kg " << item.value << " taka" << endl;
            }
        }
    }

    return 0;
}