#include <iostream>

using namespace std;

//Parent class

class Employee{
    
    private:  
    
    protected:
        int time;
    
    public:
        int ID, projects;
        double salary;
        string name;
        
        //Constructor
       
        Employee(){
            cout<<"Enter all employee details:-"<<endl;
            cout<<"Enter the Employee ID:"<<endl;
            cin>>ID;

            cout<<"Enter the Employee Name:"<<endl;
            cin>>name;

            cout<<"Enter the Employee salary:"<<endl;
            cin>>salary;

            cout<<"Enter the no. of projects done:"<<endl;
            cin>>projects;

            cout<<"Enter the no. of days Employee has worked:"<<endl;
            cin>>time;

        }

       
        //Vrtual Function
       
        virtual void display(){
            cout<<"The name is:"<<name<<endl;
            cout<<"The ID is:"<<ID<<endl;
        }


        //Destuctor
        ~Employee(){}


        //pure virtual function
        
        virtual void appraiseEmployee()=0; 

};


//child class

class Manager: public virtual Employee{
    
    public:
        double appraisalScore;

        
        //Overriding pure virtual function
       
        virtual void appraiseEmployee(){
            appraisalScore=(projects/(time/365));
        }


        //Function to increase salary according to
        //appraisal score
        
        void IncreaseSalary(){
                double half=projects/2;
                double calc=half/3;
                
                if (projects>1){    
                   
                    if ((time/365)<=calc){
                        salary=salary + salary*(appraisalScore/10);
                    }
                   
                    else{
                        salary=salary + salary*(appraisalScore/20);
                    }
                }
                
                else{
                    cout<<"No increase in salary due to lack of progress";
                }

        }
        
        //virtual function overriding
        
        inline virtual void display(){
                
                cout<<"\n \n the ID of Employee is:"<<ID<<endl;
                cout<<"the name of Employee is:"<<name<<endl;
                cout<<"the no. of projects employee has done are:"<<projects<<endl;
                cout<<"the no. of days employee has worked are:"<<time<<endl;
                cout<<"the appraisal score of employee is:"<<appraisalScore<<endl;
                cout<<"the salary of emplyee is:"<<salary<<endl;
        } 

        
        //destructor
        
        ~Manager(){}

};

class Best{
    
    public:
    
    //function to find the best employee
    
    string FindBest(Manager *m){
       
        //initial value
        
        int BestScore=-1;
        int i;
        string performer;
        
            for (i=0;i<2;++i){
                
                if (BestScore<m[i].appraisalScore){
                
                //changing the value of best score according
                
                //to the condition
                
                BestScore=m[i].appraisalScore;
                performer=m[i].name;
                
                }
        
        }
        return performer;
    
    }


};


int main(){
    
    Best B;
    int x;
    cout<<"Enter the number of employees:"<<endl;
    cin>>x;
    

    //Array
    Manager *m=new Manager[x];

    //Exception Handling
    
    try{
        
        if(m->projects<0){
            
            //throwing the error
            
            throw runtime_error("\n ERROR,Number of projects done cannot be negative \n");
        }
        
        else{ 
            m->appraiseEmployee();
            m->IncreaseSalary();

            string bestperformer;
            bestperformer=B.FindBest(m);
            cout<<"The best performer is:"<<bestperformer<<endl;
            m->display();
            delete[] m;        
        
        }
    
    }
    
    catch(runtime_error err){
        cout<<err.what()<<endl;

    
    }

    return 0;


}