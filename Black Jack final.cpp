/* while project q1 
1.	MEDIUM: Black Jack
Can be simple or complex, complete with "graphics", splitting, doubling down, etc. The cards
used are assumed to consist of an infinite number of decks and any card is equally likely to be dealt at any time. 
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//define type Card
typedef struct{
	int number;
	int shape;
} Card;


//Change card number to readable string
string number(int m){
	switch(m){
		case 1:
			return "A";
		case 2:
			return "2";
		case 3:
			return "3";
		case 4:
			return "4";
		case 5:
			return "5";
		case 6:
			return "6";
		case 7:
			return "7";
		case 8:
			return "8";
		case 9:
			return "9";
		case 10:
			return "10";
		case 11:
			return "J";
		case 12:
			return "Q";
		case 13:
			return "K";
	}
}


//Global
//array of usercard and pccard
Card ucards[21];
Card pccards[21];

//user get card
void userGetCards(int& i,int& ano,int& u_sum,int& u2_sum,int& cot){
	int no;
	//get user cards number
	ucards[i].number = rand()%13+1;
	//get user cards shape
	ucards[i].shape = rand()%4;
	
	//set marks to 10 if number is 11,12,13
	if(ucards[i].number == 11 || ucards[i].number == 12 || ucards[i].number == 13){
		u_sum = 10;
	}
	//let user choose mark for card number 1
	else if(ucards[i].number == 1 && ano == 0)	{
		u2_sum = 11;
		u_sum = 1;
		ano++;
	}
	else if(ucards[i].number == 1 ){
		u2_sum = 1;
		u_sum = 1;
	}
	//else marks = card number
	else{
		u_sum = ucards[i].number;
	}
	
	
	if(!cot == 0){
		cout<<"User--"<<endl<<i+1<<" cards: "<<endl;
		for (int u = 0;u<=i;u++){
			if(ucards[u].number){
				cout<<"|"<<number(ucards[u].number)<<"|"<<endl;
			}
		}
	}
	

}

//pc get cards
void pcGetCards(int& j,int& pcano,int& pc_sum,int& pc2_sum,int& cot){
	int pcyesno;
	//get pc cards number
	pccards[j].number = rand()%13+1;
	//get pc cards shape
	pccards[j].shape = rand()%4;
	
	//set mark be 10 if card number is 11,12,13
	if(pccards[j].number == 11 || pccards[j].number == 12 || pccards[j].number == 13){
		pc_sum = 10;
		pc2_sum = 10;
	}
	//condition for card A be 1 or 11
	else if(pccards[j].number == 1 && pcano == 0)	{
		pc_sum = 1;
		pc2_sum = 11;
		pcano++;
	}
	else if(pccards[j].number == 1 && pcano > 0){
		pc_sum = 1;
		pc2_sum = 1;
	}
	//else set mark = cards number
	else{
		pc_sum = pccards[j].number;
		pc2_sum = pccards[j].number;
	}
	
	
	
	
	//first card no shown
	if(j > 0){
	
		cout<<"PC--"<<endl;
		cout<<"|"<<"*"<<"|"<<endl;
		for (int u = 1;u<=j;u++){
			if(ucards[u].number){
				cout<<"|"<<number(pccards[u].number)<<"|"<<endl;
			}
		}
	}
	
}

int main(){
	//variables of user
	int a = 0,usum = 0,u2sum = 0,money = 100,betmoney = 0,counter = 0,aceno = 0,u_sum = 0,u2_sum = 0;
	char yesno = 'y',play = 'y';
	//variables of pc
	int b = 0,pcsum = 0,pc2sum = 0;
	int pc_aceno = 0,pc_sum = 0,pc2_sum = 0,pcounter = 0;
	char pcyesno = 'y';
	//random base on time
	srand(time(0));
	
	while(play == 'y' && money >= 0){
		//reset variables
		
		counter = 0;
		a = 0;
		usum = 0;
		u2sum = 0;
		u_sum = 0;
		u2_sum = 0;
		aceno = 0;
		yesno = 'y';
		b = 0;
		pcyesno = 'y';
		pcsum = 0;
		pc2sum = 0;
		pc_aceno = 0;
		
		//ask amount of bet of user
		cout<<"How many you want to bet? You have $"<<money<<endl;
		cin>>betmoney;
		while(betmoney>money || betmoney<=0){
			cout<<"You don't have that amount of money. Enter another amount."<<endl;
			cin>>betmoney;
		}
		money -= betmoney;
		cout<<"You bet $"<<betmoney<<endl<<endl;
		
		//game process
		do{
			
			//user round
			if(yesno == 'y' || yesno == 'd'){
				if(yesno == 'd' && betmoney*2<=money){
						money -= betmoney;
						betmoney*=2;
						cout<<"You now have bet $"<<betmoney<<endl;
				}
				else if (yesno =='d' && betmoney*2>money){
					betmoney += money;
					money -= money;
					cout<<"You now have bet $"<<betmoney<<endl;
				}
				//add up card
				userGetCards(a,aceno,u_sum,u2_sum,counter);
				
				if(ucards[a].number == 1){
					u2sum += u2_sum;
				}
				else if(u2sum){
					u2sum += u_sum;
				}
				
				usum += u_sum;
				
				if(!u2sum){
					u2sum += u_sum;
				}
				
				if(counter > 0){
				//	cout<<"counter "<<counter<<endl;
				
				//	cout<<"a / aceno: "<<a<<" "<<aceno<<endl;
					//show 2 sum
					if(u2sum<=21){
						cout<<"Your sum is "<<u2sum<<endl;
					}
					else if(u2sum>usum && u2sum >21){
						cout<<"Your sum now is "<<usum<<endl;
					}
					else if(u2sum == usum && u2sum > 21){
						cout<<"Your sum is "<<u2sum<<endl;
					}
				//	cout<<"usum / u2sum: "<<usum<<" "<<u2sum<<endl;
				}
				a++;				
				counter++;
					
					
				//wining condition
				if(usum>21){
					cout<<endl<<"Bomb!"<<endl;
					cout<<"You lose."<<endl;
					break;
				}
				else if(usum == 21 || u2sum == 21){
					cout<<endl<<"You win!"<<endl;
					money += betmoney*2;
					break;
				}
			}
		
			//pc round
			if(pc_sum<18 || pc2_sum<19){
				//add up cards
				pcGetCards (b,pc_aceno,pc_sum,pc2_sum,pcounter);

				pc2sum += pc2_sum;
				pcsum += pc_sum;


				b++;
				pcounter++;
			
		//	cout<<"pcsum: "<<pcsum<<"  pc2sum: "<<pc2sum<<endl;
			
				//wining condition				
				if(pcsum>21){
					cout<<endl<<"I lose..."<<endl;
					cout<<"You win!"<<endl;
					money += betmoney*2;
					break;
				}
				else if(pcsum == 21 || pc2sum == 21){
					cout<<endl<<"I win!!! You lose."<<endl;
					break;
				}		
			}
			else{
				pcyesno = 'n';
				cout<<"PC are not going to get a card."<<endl;
			}

			//ask user for next card
			if(counter>1){
				cout<<endl<<"Get a card? (y/n) or by doubling down? (d)";
				cin>>yesno;
				while(yesno != 'y' && yesno!= 'n' && yesno != 'd'){
					cout<<"Invalid. Re-enter again.";
					cin>>yesno;
				}
				cout<<"-------------------------------------------------"<<endl;
			}
			//if both stop get a card
			if(pcyesno == 'n' && yesno == 'n'){
			
				//wining condition
				if(usum>pcsum || (u2sum>pcsum && u2sum <= 21) || (usum>pc2sum && usum<=21) ){
					cout<<endl<<"You win!"<<endl;
					money += betmoney*2;
					break;
				}
				else if(usum < pcsum || u2sum < pcsum || (usum < pc2sum && pc2sum <=21) || (u2sum < pc2sum && pc2sum <= 21)){
					cout<<endl<<"You lose."<<endl;
					break;
				}
				else if((usum == pcsum && usum <21 &&pcsum <21) || (u2sum == pcsum && u2sum<21 &&pcsum < 21) ||
						 (usum == pc2sum && usum < 21 &&pc2sum<21) || (u2sum == pc2sum && u2sum <21 && pc2sum <21)){
					cout<<endl<<"draw."<<endl;
					money += betmoney;
					break;
				}
			}
		} while(yesno=='y' || yesno == 'd' || (pcsum<21 && usum<21));
		
		cout<<"The first card of pc is "<<endl;
		cout<<"|"<<number(pccards[0].number)<<"|"<<endl;
		//show pc sum
		if(pc2sum<=21){
			cout<<"PC sum: "<<pc2sum<<endl;
		}
		else if(pc2sum>21 && pcsum<=21){
			cout<<"PC sum: "<<pcsum<<endl;
		}
		else {
			cout<<"PC sum: "<<pcsum<<endl;
		}
		//show final amount of user
		cout<<"You final amount of money is "<<money<<endl;
		//ask for next play
		if(money<=0){
			break;
		}
		cout<<endl<<"Round end"<<endl;
		cout<<"Do you want to continue? (y/n): ";
		cin>>play;
		cout<<endl;
		while (play != 'y' && play != 'n'){
			cout<<"Invalid entry. Re-enter again."<<endl;
			cin>>play;
		}
		cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
	}
	//show amount of gain or lose of money of user
	if(money>=100){
		cout<<"You have won $"<<money-100<<endl;
	}
	else{
		cout<<"You have lose $"<<100-money<<endl;
	}
	
	cout<<"fin"<<endl;
	
	return 0; //end program
	
}
