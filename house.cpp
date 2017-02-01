//house.cpp
//Diba Mirza
//Program to draw a house using ASCII Art
//Topics: Test driven development, nested loops
//variable scope

#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

//Function declarations
string getBody(int width, int height);
string getRoof(int rheight);
string getHouse(string roof, string body);

string getRoof(int rheight){
    string result="";
    int numSpaces=0;
    int numStars=0;

    for (int row = 0; row<(rheight+1) ;row++){
        string spaces="";
        string stars="";
        numSpaces=rheight-row;    
        numStars=2*row+1;
        for(int i=0;i<numSpaces;i++){
            spaces=spaces+" ";
        }

        for(int i=0;i<numStars;i++){
            stars=stars+"*";
        }

        result=result+spaces+stars+spaces+"\n";
    }

    return result;
}


//test harness

void assertEquals(string expected, string actual, string message=""){
   if(expected == actual){
       cout<<"PASSED "<<message<<endl;
   } else{
       cout<<"FAILED "<<message<<endl<<"expected \n"<<expected<<"\nactual\n"
           <<actual<<endl;
   }
}

//test suite
void runTests(){
   string expectedRoof_0 = "*\n";
   assertEquals(expectedRoof_0, getRoof(0), "getRoof(0)");

   string expectedRoof_1 = 
   " * \n"
   "***\n";

   assertEquals(expectedRoof_1, getRoof(1), "getRoof(1)");

}

int main(int argc, char *argv[]){

    if(argc != 3){
        cerr<<"Usage :"<<argv[0]<<" width height"<<endl;
        exit(1);
    }

    int width(atoi(argv[1]));
    int height(atoi(argv[2]));
    if(width ==-1 && height ==-1){
        cout<<"run tests"<<endl;
        runTests();
        exit(0);
    }

    
    return 0;
}
