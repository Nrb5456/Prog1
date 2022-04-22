#include "../std_lib_facilities.h"

using namespace std;

void fill_vec(istream& is, vector<double>& vec_d)
{
	for (double d; is >> d; ) vec_d.push_back(d);
}

int main(){

	vector<double> vd;
    string in {"vec_double.txt"};
    ifstream ist {in};
    fill_vec(ist, vd);

    cout << "1-2.feladat:" << endl;
    for(auto& n : vd)
    	cout << n << endl;

    //3.
    vector<int> vi (vd.size());
    copy(vd.begin(),vd.end(),vi.begin());
    
    //4.
    cout << "3-4.feladat:" << endl;
    for (int i = 0; i <  vd.size(); ++i)
        cout << "(" << vd[i] << "," << vi[i] << ")" << endl;

    //5.	
    double vd_sum = accumulate(vd.begin(),vd.end(),0.0);
    cout << "Sum of vd = " << vd_sum << endl;

    //6.
    double vi_sum = accumulate(vi.begin(),vi.end(),0);
    cout << "vd-vi diff = " << vd_sum-vi_sum << endl;

    //7.
    reverse(vd.begin(),vd.end());
    cout << "Revesre vd :" << endl;
    for(auto& n : vd)
    	cout << n << endl;

    //8. 
    double mean_val = vd_sum / vd.size();
    cout << "Mean value of vd = " << mean_val << endl;

    //9.
    vector<double> vd2;
    copy_if(vd.begin(),vd.end(),back_inserter(vd2),
    	[mean_val](auto& vd_entry){ return vd_entry < mean_val;});

    cout << "9.feladat(vd2): " << endl;
    for(auto& n : vd2)
    	cout << n << endl;

    //10.
    sort(vd.begin(),vd.end());
    cout << "10.feladat(vd sorted): " << endl;
    for(auto& n : vd)
    	cout << n << endl;

	return 0;
}
