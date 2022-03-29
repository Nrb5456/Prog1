#include "../std_lib_facilities.h"

template<typename T> 
struct S { 

	S():val(T()){};
    S(T s):val(s){};

    T& get();

    const T& get() const;

    void set(const T& uj);

    T& operator = (const T&);

    void read_val(T& v);

    private:
        T val;
};

template<typename T> T& S<T>::get() { return val; };

template<typename T> const T& S<T>::get() const { return val; };

template<typename T> void S<T>::set(const T& uj) { val = uj; };

template<typename T> void read_val(T& v) { cin >> v; };

int main(){

	S<int> si {35};
    S<char> sc {'d'};
    S<double> sd {2.6};
    S<string> ss {"alma"};
    vector<int> v {1, 2, 3, 4, 5};
    S<vector<int>> sv {v};

    /*cout << si.val << endl;
    cout << sc.val << endl;
    cout << sd.val << endl;
    cout << ss.val << endl;
    for(int i = 0; i < sv.val.size(); ++i)
        cout << sv.val[i] << endl;*/

    /*cout << si.get() << endl;
    cout << sc.get() << endl;
    cout << sd.get() << endl;
    cout << ss.get() << endl;
    for(int i = 0; i < sv.get().size(); ++i)
        cout << sv.get()[i] << endl;*/

    int si_o;
    char sc_o;
    double sd_o;
    string ss_o;
    cout << "Write an int: ";
    read_val(si_o);
    cout << "Write a char: ";
    read_val(sc_o);
    cout << "Write a double: ";
    read_val(sd_o);
    cout << "Write a string: ";
    read_val(ss_o);

    si.set(si_o);
    cout << si.get() << endl;

    sc.set(sc_o);
    cout << sc.get() << endl;

    sd.set(sd_o);
    cout << sd.get() << endl;

    ss.set(ss_o);
    cout << ss.get() << endl;

	return 0;
}