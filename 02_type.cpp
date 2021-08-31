#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
	string type_name;
	int cnt_c=0;
	int cnt_i=0;
	int cnt_l=0;
	int cnt_f=0;
	int cnt_d=0;
	
	while(true) {
		cin>>type_name;
		
		if(type_name=="quit") break;
		else if(type_name=="char") {
			cout<<numeric_limits<char>::min()<<" "<<numeric_limits<char>::max()<<endl;
			cnt_c++;
		}
		else if(type_name=="int") {
			cout<<numeric_limits<int>::min()<<" "<<numeric_limits<int>::max()<<endl;
			cnt_i++;
		}
		else if(type_name=="long") {
			cout<<numeric_limits<long>::min()<<" "<<numeric_limits<long>::max()<<endl;
			cnt_l++;
		}
		else if(type_name=="float") {
			cout<<numeric_limits<float>::min()<<" "<<numeric_limits<float>::max()<<endl;
			cnt_f++;
		}
		else if(type_name=="double") {
			cout<<numeric_limits<double>::min()<<" "<<numeric_limits<double>::max()<<endl;
			cnt_d++;
		}
	}
		cout<<"=== A List of # of types ==="<<endl;
		cout<<"int: "<<cnt_i<<endl;
		cout<<"long: "<<cnt_l<<endl;
		cout<<"float: "<<cnt_f<<endl;
		cout<<"double: "<<cnt_d<<endl;
		cout<<"char: "<<cnt_c<<endl;
}