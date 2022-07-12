
/***** This program simulate NFA that accepts a string over alphabet E = {0,1} ****/
/**** Accept if an input string ends with '01' ****/


#include <iostream>
#include <string.h>


using namespace std;


char curstate[100], nextstate[100];
int state,accept;

// the nfa contain three states
char q0 = '1', q1 = '2', q2 = '3';

// insert the initial state to the current state array


void state0(char), state1(char), state2(char);
void copyToCurrent(), popCurrent();

// define the next states from current
// value of state0 is always sits at index 0,1
void state0(char a){
	if(a == '0'){
		//push to nextstate
		nextstate[0] = q0;
		nextstate[1] = q1;
	}
	else{
		//push to next state
		nextstate[0] = q0;
	}
}

// determine the next state from the current input
void state1(char a){
	if(a == '1'){
		//push to nextstate
		nextstate[2] = q2;
	}
	else{
		//push to next state
			
	}
}

// determine the next state from current input
void state2(char a){
	if(a == '0'){
		//push to nextstate
		nextstate[2] = '0';
	}
	else{
		//push to next state
		nextstate[2] = '0';
	}
}


void copyToCurrent(){
	for(int i = 0; i< 100; i++){
		curstate[i] = nextstate[i];
	}
}

void popCurrent(){
	for(int i = 0; i< 100; i++){
		curstate[i] = '0';
	}
}


int acceptInput(char inputString[]){
	
 
	int len = strlen(inputString);

	for (int i = 0; i < len; i++) {
		// loop through the current state and determine the next state
		for (int j =0; j<100; j++){
			
			//if curstate contain state push its nextstae to nextstate list
			if(curstate[j] == q0){
				state0(inputString[i]);
			}
			
			if(curstate[j] == q1){
				state1(inputString[i]);
			}
			
			if(curstate[j] == q2){
				state2(inputString[i]);
			}
		}
		
		// clear the current array
		popCurrent();
		
		// copy the next states to the current state array
		copyToCurrent();
	}
	
	// output th possible final states array
	cout<<endl<<"Possible Final states : [";
	for (int i = 0; i <3; i++) {
		cout<<curstate[i];
		if(i != 2){
			cout<<",";
		}
	}
	cout<<"]"<<endl<<endl;;
	
	//check if the final state is in the possible final states array
	for (int n = 0; n < 100; n++) {
			if(curstate[n] == q2){
				accept = 1;
			}
	}
}


// MAIN FUNCTION
int main(){
	
	char input[] = "1010110101";
	curstate[0] = q0;
	
	cout<<"This NFA Accepts a String ending with '01'"<<endl;
	cout<<endl<<"List of states"<<endl;
	cout<<"q0 == 1"<<endl<<"q1 == 2"<<endl<<"q2 == 3"<<endl<<"dead state == 0"<<endl;
	
	cout<<endl<<"Input String: "<<input<<endl;
	acceptInput(input);
	
	if(accept == 1){
		cout<<"String Accepted";
	}
	else{
		cout<<"String Rejected";
	}
	return 0;
}









