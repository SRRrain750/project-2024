#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
srand(time(0));//seed for random num generation

int playerChoice;
int computerChoice;
const int rock=1;
const int paper=2;
const int scissors=3;

 cout<<"wlc to RPS !"<<endl;
 cout<<"enter your choice(1 for rock,2 for paper,3 for scissors):";
cin>>playerChoice;
computerChoice =rand()%3+1;// gen a random  choice for com


cout<<"computer choice:"<<computerChoice<<endl;

if(playerChoice==computerChoice){
 cout<<"its a tie !"<<endl;
}
else if((playerChoice==rock&&computerChoice==scissors)||
       ( playerChoice==paper&&computerChoice==rock)||
       (playerChoice==scissors&&computerChoice==paper)) {


    cout<<"u win!"<<endl;

}else{




cout<<"com win!"<<endl;

}


 return 0;
}












