#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
	int weight , profit,item_no;

};
bool compare(Item a, Item b) {

    double a_unit_profit = (double)a.profit / a.weight;
    double b_unit_profit = (double)b.profit / b.weight;
    
    return (a.profit/a.weight) > (b.profit/b.weight);
}


int main() {
	int n;
	double W;
	cout << "Enter number of items: ";
	cin >> n;

    vector<Item> items(n);
    cout<<"Enter weights of items: ";
	
    for(int i=0;i<n;i++){
        int w;
        cin >> w;
        items[i].weight = w;
        items[i].item_no = i+1;

    }

    cout<<"Enter profits of items: ";
    for(int i=0;i<n;i++){
        int p;
        cin >> p;
        items[i].profit = p;
        
        
    }
    cout << "Enter maximum weight of knapsack: ";
    int max_cap;
    cin >> max_cap;

    sort(items.begin(),items.end(),compare);

    for(int i=0;i<n;i++){
        cout<<items[i].weight<<" "<<items[i].profit<<endl;
    }

    double max_profit = 0.0;
    for(int i=0;i<n;i++){
        if(items[i].weight<=max_cap){
            max_cap -= items[i].weight;
            max_profit += items[i].profit;
        }
        else{
           max_profit +=max_cap * ((double)items[i].profit/items[i].weight);
           max_cap = 0;
              break;
        }
    }
        
    cout<<"Maximum profit is: "<<max_profit<<endl;
    return 0;
	
}