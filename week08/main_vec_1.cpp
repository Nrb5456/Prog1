#include "../std_lib_facilities.h"

struct Item { 
	string name; 
	int iid; 
	double value;
};

template<typename C>
void write(C& c)
{
    for (auto p = c.begin();p != c.end(); ++p)
        cout << *p;
    cout << endl;
}

ostream& operator<<(ostream& os, Item& it)
{
    return os << it.name << " " << it.iid << " " << it.value << endl;
}

istream& operator>>(istream& is, Item& it)
{
    string ss;
    int ii;
    double dd;
    is >> ss >> ii >> dd;
    Item final_it {ss,ii,dd};
    it = final_it;
    return is;
}

int main(){

	vector<Item> vi;
	string in {"item.txt"};
    ifstream ist {in};

    for (Item it; ist >> it; ) vi.push_back(it);

    cout << "1.feladat:" << endl;
    write(vi);

	string a,b;

    //2
    cout << "2.feladat:" << endl;
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.name < b.name;});

    write(vi);

    //3
    cout << "3.feladat:" << endl;
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.iid < b.iid;});

    write(vi);

    //4
    cout << "4.feladat:" << endl;
    sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b){return a.value > b.value;});

    write(vi);

    //5
    cout << "5.feladat:" << endl;
    Item horse{"horse shoe",99,12.34};
    Item canon{"Canon S400", 9988,499.95};

    vi.insert(vi.begin(), horse);
    vi.insert(vi.begin(), canon);

    write(vi);

    //6
    cout << "6.feladat:" << endl;
    vi.erase(find_if(vi.begin(),vi.end(),
        [](const Item& a){return a.name == "Szilva";}));
    vi.erase(find_if(vi.begin(),vi.end(),
        [](const Item& a){return a.name == "Barack";}));

    write(vi);

    //7
    cout << "7.feladat:" << endl;
    vi.erase(find_if(vi.begin(),vi.end(),
        [](const Item& a){return a.iid == 1;}));
    vi.erase(find_if(vi.begin(),vi.end(),
        [](const Item& a){return a.iid == 45;}));

    write(vi);

    //8
    //1
    list<Item> li;
    string iname2 {"item.txt"};
    ifstream ist2 {iname2};

    for (Item it; ist2 >> it; ) li.push_back(it);

    cout << "8/1.feladat:" << endl;
    write(li);

    //2
    cout << "8/2.feladat:" << endl;
    string a2,b2;
    li.sort([](const Item& a2, const Item& b2){return a2.name < b2.name;});
    write(li);

    //3
    cout << "8/3.feladat:" << endl;
    li.sort([](const Item& a2, const Item& b2){return a2.iid < b2.iid;});
    write(li);
    
    //4
    cout << "8/4.feladat:" << endl;
    li.sort([](const Item& a2, const Item& b2){return a2.value > b2.value;});
    write(li);

    //5
    cout << "8/5.feladat:" << endl;
    li.insert(li.begin(), horse);
    li.insert(li.begin(), canon);
    write(li);
    
    //6
    cout << "8/6.feladat:" << endl;
    list<Item>::iterator itr = 
    find_if(li.begin(),li.end(),
        [](const Item& a){return a.name == "Szilva";});
    list<Item>::iterator itr2 = 
    find_if(li.begin(),li.end(),
        [](const Item& a){return a.name == "Barack";});
    
    li.erase(itr);
    li.erase(itr2);
    write(li);

    //7
    cout << "8/7.feladat:" << endl;

    itr=find_if(li.begin(),li.end(),
        [](const Item& a){return a.iid == 1;});
    itr2=find_if(li.begin(),li.end(),
        [](const Item& a){return a.iid == 45;});

    li.erase(itr);
    li.erase(itr2);
    write(li);

	return 0;
}