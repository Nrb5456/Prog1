#include "../std_lib_facilities.h"

using namespace std;

template <typename T, typename C>
void write(const map<T, C>& map)
{
    for(const auto& p : map)
        cout << p.first << " " << p.second << endl;
    cout << endl;
}

//5
void in(map<string, int>& map)
{
    string text;
    int number;
    cin >> text >> number;
    map.insert(pair<string, int>(text, number));
}

int main(){

    map<string,int> msi;
    
    msi["lecture"] = 21;
    msi["something"] = 26;
    msi["some"] = 30;
    msi["thing"] = 33;
    msi["other"] = 25;
    msi["lec"] = 29;
    msi["ture"] = 50;
    msi["last"] = 72;
    
    cout << "1-3.feladat:" << endl;
    write(msi);

    //4
    cout << "4.feladat:" << endl;
    msi.erase(msi.begin(), msi.end());
    write(msi);
    cout << "Erase done!" << endl;
    cout << endl;

    //6
    cout << "5-7.feladat:" << endl;

    for(int i = 0; i < 2; ++i){
        in(msi);
    }

    //7
    cout << endl;
    write(msi);

    //8
    int sum = accumulate(msi.begin(),msi.end(),0,
     [](auto prev_sum, auto &msi_entry){return prev_sum + msi_entry.second;});
    cout << "Sum of int = " << sum << endl;
    cout << endl;

    //9
    map<int, string> mis;

    //10
    for(auto& mapentry: msi)
        mis[mapentry.second] = mapentry.first;

    //11
    cout << "9-11.feladat:" << endl;
    write(mis);
    
    return 0;
}