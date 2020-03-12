#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

int monOffset[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};


bool isLeap(long long y){
	return ((y%400 == 0) || ( (y%4==0) && (y%100!=0) ));
}

int getOddDay(int month,long long int y){

	int oddDay = 0;
	long long int year = y-1;

	year = year%400; //odd day of 400 years = 0

	oddDay += (year/100)*5; //OD 100 ys = 5
	year=year%100;

	// cout<<month<<'\t'<<year<<'\t'<<oddDay<<endl;

	int leaps = year/4;

	oddDay += (year-leaps)*1 + leaps*2;

	// cout<<month<<'\t'<<year<<'\t'<<oddDay<<endl;

	//calculating for month

	oddDay += monOffset[month -1];
	// cout<<month<<'\t'<<year<<'\t'<<oddDay<<endl;

	if(month >2 && isLeap(y)) oddDay++;
	// cout<<month<<'\t'<<year<<'\t'<<oddDay<<endl;

	return ((oddDay+1)%7);
}

int main(int argc, char const *argv[])
{
	int t;
	std::fstream myfile("./input.txt", std::ios_base::in);

	myfile>> t;
	
	while(t--){
		long long int fromYear,toYear;
		int fromMonth,toMonth;


		myfile>>fromMonth>>fromYear>>toMonth>>toYear;
		
		// cout<<fromMonth<<'\t'<<fromYear<<'\t'<<toMonth<<'\t'<<toYear<<endl;

		// cout<<getOddDay(toMonth,toYear)<<endl;

		//first friday

		if(toMonth<2) toYear--;
		
		long long int answer=0;
		long long int cy = (fromMonth<=2)?(fromYear):(fromYear+1);;
		int cm = fromMonth; 

		int offset = (toYear - cy)/28;
		answer += (offset)*7;

		cy += offset*28;


		int fod =getOddDay(2,cy);
		// cout<<" \t ----fod "<<fod<<endl;

		while (cy<=toYear){

	
			int ffd;
			if(fod==5) ffd=1;
			else if(fod==6) ffd=7;
			else ffd = 1 + (5 - fod);

			int next=(isLeap(cy))?(29):(28);
			int lsd = (fod + next)%7; //1st odd day of next month
			
			//last day of the current month
			if(lsd==0) lsd = 6; 
			else lsd--;
			
			//last sunday of cm
			lsd = next-lsd ; 
			lsd -=7;
			// int lsd = (fod + 21)%7;
			// lsd = 22-lsd;

		// while (cy<=toYear){
			// cout<<"current \t"<<cy<<endl;

			cout<<cy<<"\t fod"<<fod<<endl;

			if(ffd<=lsd && lsd<=ffd+10){
				answer++;
				// cout<<"-------_______CLASHING_________---------"<<"\t year "<<cy<<endl;
				cout<<" |-- fod  "<<fod<<"\t ffd  "<<ffd<<'\t'<<"lsd  "<<lsd<<endl<<endl; 
			}

			if(ffd<0 || lsd<0 || fod<0) break;


            if(isLeap(cy)){
				// ffd = (ffd+2)%7;
				// lsd = (lsd+2)%7;
			 	fod=(fod+2)%7;
			}else{
				// ffd = (ffd+1)%7;
				// lsd = (lsd+1)%7;
			 	fod=(fod+1)%7;
			}

			cy++;
			// //for next month
			// fod += (months[cm-1])%7;

			// if(cm==2 && isLeap(cy)) fod = (fod+1)%7;

			// fod=fod%7;

			// cm++;
			// if(cm>toMonth && cy>=toYear) break;

			// if(cm>12){
			// 	cm=1;
			// 	cy++;
			// }
			
		}

		cout<<answer<<endl;
		
	}

	return 0;
}