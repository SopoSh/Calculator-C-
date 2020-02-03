#include <iostream>
#include <limits>

using namespace std;

//prepare calc function prototype
void calculator(double *, double *, char *);

int main()
{
    //avoid memory allocation in loop
    //allocation of memory using new 
    //only these pointers have access to these anonymous variables 
    char *c= new (nothrow) char;
    double *x1 = new (nothrow) double;
    double *x2 = new (nothrow) double;
    
    //if we have space
    
     if (x2 && x2 && c) { 
        cout<<"--------------WELCOME TO CALCULATOR------------------" <<endl;
        cout<<"                START CALCULATING         " <<endl;
    
            do{
            cout<<"     Chose which operation you want to perform\n"<<endl;
            cout<<"+(addition), -(subtraction), *(multiplication), /(division)\n"<< endl;
            cout<<"      Press any other character to quit"<<endl;
          
          //dereference c to get a value 
            cin >> *c;
            
            if (!(*c == '+' || *c == '-' || *c == '*' || *c == '/')) {
                   cout << "END OF CALCULATING";
                   break;
              }
              
            cout<<"Enter operands: " <<endl;
            cin >> *x1;
            cin >> *x2;
        
        //if user does not enter number not to get loop
        //cin.fail() is true if user input is not of declared type and is executed
             while (cin.fail())
            {
            cin.clear(); // clears the error flag on cin
            //cin.sync();
            cin.ignore(numeric_limits<int>::max(), '\n'); // ignore unread characters that remained in the input buffer
            cout << "try entering 2 operands (number characters)"<<endl;
            cin >> *x1;
            cin >> *x2;
            }

        
            if (*x2 == 0 && *c == '/') {
                cout << "division by zero is not allowed, enter another number" << endl;
                cin >> *x2;
            }
            
            calculator(x1, x2, c);

            }while (*c == '+' || *c == '-' || *c == '*' || *c == '/');
            
            }
    else { //no storage pool
        cout << "no memory on Heap" << endl;
    }
    //return memory to the heap
    delete c;
    delete x1;
    delete x2;

    return 0;
}

//simple calculator function with four operators in a switch statement
void calculator (double *x1, double *x2, char *operand){
    switch(*operand){
        case '+':
            cout << *x1+*x2<<endl; break;
        case '-':
            cout << *x1-*x2<<endl; break;
        case '*':
            cout << *x1*(*x2)<<endl; break;
        case '/':
            cout << *x1/(*x2)<<endl; break;
    }
}