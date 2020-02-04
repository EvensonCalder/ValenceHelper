#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct node {
	string symbol;
	string valence;
	bool if_metal;//true:metal false:nonmetal
	int res_time;
} item[22]; //12 basic ones
int opt,rnd,prize,combo,wrong,start_time,max_combo;
string ans,word[6] {"Good","Great","Amazing","Excellent","Crazy","Unbelievable"};
void start() { //say hello
	system("cls");
	cout<<"Thanks for using ValenceHelper by Evenson";
	Sleep(1000);//wait for 1 second
	return;
}
void init() {
	item[0].if_metal=true;
	item[0].symbol="K";
	item[0].valence="+1";
	item[1].if_metal=true;
	item[1].symbol="Na";
	item[1].valence="+1";
	item[2].if_metal=true;
	item[2].symbol="Ag";
	item[2].valence="+1";
	item[3].if_metal=true;
	item[3].symbol="Ca";
	item[3].valence="+2";
	item[4].if_metal=true;
	item[4].symbol="Mg";
	item[4].valence="+2";
	item[5].if_metal=true;
	item[5].symbol="Ba";
	item[5].valence="+2";
	item[6].if_metal=true;
	item[6].symbol="Zn";
	item[6].valence="+2";
	item[7].if_metal=true;
	item[7].symbol="Al";
	item[7].valence="+3";
	item[8].if_metal=true;
	item[8].symbol="Cu";
	item[8].valence="+1,+2";
	item[9].if_metal=true;
	item[9].symbol="Fe";
	item[9].valence="+2,+3";
	item[10].if_metal=true;
	item[10].symbol="Mn";
	item[10].valence="+2,+4,+6,+7";
	item[11].if_metal=false;
	item[11].symbol="H";
	item[11].valence="+1";
	item[12].if_metal=false;
	item[12].symbol="F";
	item[12].valence="-1";
	item[13].if_metal=false;
	item[13].symbol="O";
	item[13].valence="-2";
	item[14].if_metal=false;
	item[14].symbol="Cl";
	item[14].valence="-1,+5,+7";
	item[15].if_metal=false;
	item[15].symbol="Br";
	item[15].valence="-1,+5,+7";
	item[16].if_metal=false;
	item[16].symbol="I";
	item[16].valence="-1,+5,+7";
	item[17].if_metal=false;
	item[17].symbol="N";
	item[17].valence="-3,+5";
	item[18].if_metal=false;
	item[18].symbol="P";
	item[18].valence="-3,+5";
	item[19].if_metal=false;
	item[19].symbol="S";
	item[19].valence="-2,+4,+6";
	item[20].if_metal=false;
	item[20].symbol="C";
	item[20].valence="-4,+2,+4";
	item[21].if_metal=false;
	item[21].symbol="Si";
	item[21].valence="-4,+4";
	return;
}
void main_function() {
	start_time=time(NULL);
	for (int i=1; i<=opt*22+wrong*2; ++i) {
		srand(time(NULL)+rand());
		system("cls");
		rnd=rand()%22;
		while (item[rnd].res_time==0) {
			rnd=rand()%22;
		}
		cout<<"The valence of "<<item[rnd].symbol<<",a kind of "<<(item[rnd].if_metal?"metal":"nonmetal")<<" element is ";
		cin>>ans;
		if (item[rnd].valence==ans) {
			++combo;
			max_combo=max(max_combo,combo);
			--item[rnd].res_time;
			prize=rand()%6;
			if (combo>=2)
				cout<<"Combo "<<combo<<" ";
			cout<<word[prize]<<endl;
			Sleep(1000);
		} else {
			++item[rnd].res_time;
			++wrong;
			combo=0;
			cout<<"Your answer is wrong!!!\n";
			cout<<"The valence of "<<item[rnd].symbol<<",a kind of "<<(item[rnd].if_metal?"metal":"nonmetal")<<" element is "<<item[rnd].valence<<endl;
			Sleep(3000);
		}
	}
	return;
}
void option() {
	while (opt<1 || opt>3) {
		system("cls");
		cout<<"Option1:easy\n";
		cout<<"Option2:normal\n";
		cout<<"Option3:difficult\n";
		cin>>opt;
	}
	for (int i=0; i<22; ++i)
		item[i].res_time=opt;
	return;
}
void end() {
	system("cls");
	cout<<"You've finish it!!!\n";
	cout<<"Difficulty:"<<(opt==1?"easy":(opt==2?"normal":"difficult"))<<endl;
	cout<<"Wrong answer:"<<wrong<<endl;
	cout<<"Time:"<<time(NULL)-start_time<<"second"<<endl;
	cout<<"Maxcombo:"<<max_combo<<endl;
	cout<<"Score:"<<max(1,(int)(opt*99+max_combo*7-wrong*5-time(NULL)/4+start_time/4))<<endl;
	return;
}
int main() {
	start();
	init();
	option();
	main_function();
	end();
	return 0;
}

