#include <iostream>
#include "SAL.h"
#include "Instruction.h"
#include<string>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unsigned int rCount = 0, dCount = 0;
string SAL::Memory[256];
signed int SAL::A;
signed int SAL::B;
int SAL::PC;   
map<string,int> SAL::Inst;
bool SAL::OverFlow;
bool SAL::ZeroBit;
string instruction;
string variable;
    
int main()
{
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\tWelcome to SAL Interpreter"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    char selection;  
    
   
 do{
        cout<<endl;
        cout<<"Availabe commands:"<<endl;
        cout<<"i : Input file \t(read from input.txt)"<<endl;
        cout<<"d : Debug Mode \t(Step by step)"<<endl;
        cout<<"r : Run complete code \t(Start to end)"<<endl;
        cout<<"s : Save the program state \t(to output.txt)"<<endl;
        cout<<"q : Quit"<<endl;
        cin>>selection;
        cout<<endl;

    switch(selection)
        {
            
        case 'i':
        {
   
        fstream input("../input.sal");
        if(!input){
            cout<<"No such file. Make sure input file is inside Project 4 Directory"<<endl;
        }
        else{
        SAL::PC = 0;
        SAL::A = 0;
        SAL::B = 0;
        SAL::PC = 0;   
        SAL::OverFlow = false;
        SAL::ZeroBit = false;
        dCount=rCount=0;
        int rem=0;
        cout<<endl;
        while (input)
            {
                if(input.peek() == EOF)
                break;
                string command;
                getline(input,command);
                SAL::Memory[rem]=command;
                cout<<rem<<" "<<SAL::Memory[rem]<<endl;
                rem++;
            }
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Success. Use 'd' to Debug and 'r' to Run."<<endl;
        cout<<"---------------------------------------------------"<<endl;

        
            
            
        }
    }
        break;
        

        case 'd':
        {
    string line = SAL::Memory[SAL::PC];
    instruction = line.substr(0, line.find(" "));
    variable = line.substr(((line.find(" "))+1),line.length());
    SAL *ptr_sal;
    if(instruction=="ADD")
    {
        ADD add;
        ptr_sal=&add;
        ptr_sal->implement();
    }
    else if (instruction=="LDI")
    {
        LDI ldi;
        stringstream stream;
        stream.str(variable);
        stream >> ldi.variable;
        ptr_sal=&ldi;
        ptr_sal->implement();
    }
    else if (instruction=="XCH")
    {
        XCH xch;
        ptr_sal=&xch;
        ptr_sal->implement();
    }
    else if (instruction=="JMP")
    {
        JMP jmp;
        stringstream stream;
        stream.str(variable);
        stream >> jmp.variable;
        ptr_sal=&jmp;
        ptr_sal->implement();
    }
    else if (instruction=="JZS")
    {
        JZS jzs;
        stringstream stream;
        stream.str(variable);
        stream >> jzs.variable;
        ptr_sal=&jzs;
        ptr_sal->implement();

    }
    else if (instruction=="JVS")
    {
        JVS jvs;
        stringstream stream;
        stream.str(variable);
        stream >> jvs.variable;
        ptr_sal=&jvs;
        ptr_sal->implement();

    }
    else if (instruction=="DEC")
    {
        DEC decl;
        SAL::Inst.insert(make_pair(variable,SAL::PC));
        decl.variable=variable;
        ptr_sal=&decl;
        ptr_sal->implement();
    }
    else if (instruction=="ST")
    {
        ST st;
        st.variable=variable;
        ptr_sal=&st;
        ptr_sal->implement();
    }
    else if (instruction=="LDA")
    {
        LDA lda;
        lda.variable=variable;
        ptr_sal=&lda;
        ptr_sal->implement();

    }
    else if (instruction=="LDB")
    {
        LDB ldb;
        ldb.variable=variable;
        ptr_sal=&ldb;
        ptr_sal->implement();
    }
    else if (instruction=="HLT")
    {
        cout<<"HLT Reached. Instructions Over."<<endl;
        cout<<" You can use 'r' to re-run."<<endl;
        break;
    }
    else
    {
    SAL::PC=SAL::PC+1;
    }
    cout<<"\nA Register = "<<SAL::A<<"\t";
    cout<<"B Register = "<<SAL::B<<endl;
    cout<<"PC = "<<SAL::PC<<endl;
    cout<<"Zerobit = "<<SAL::ZeroBit<<"\t";
    cout<<"Overflow = "<<SAL::OverFlow<<endl;
    
    if(dCount==0){
        for(size_t i=0;i<256;i++){
         if(SAL::Memory[i]=="HLT"){
            dCount = i;
            break;
        }    
      }
    }
    for(size_t i=0;i<(dCount+1);i++)
    {
    cout<<i<<" "<<SAL::Memory[i]<<endl;
    }
    }
        break;
        
    case 'r':{
        instruction = " ";
    while(instruction!="HLT")
    {
    string line = SAL::Memory[SAL::PC];
    
    instruction = line.substr(0, line.find(" "));
    variable = line.substr(((line.find(" "))+1),line.length());
    
    SAL *ptr_sal;
    if(instruction=="ADD")
    {
        ADD add;
        ptr_sal=&add;
        ptr_sal->implement();
    }
    else if (instruction=="LDI")
    {
        LDI ldi;
        stringstream stream;
        stream.str(variable);
        stream >> ldi.variable;
        ptr_sal=&ldi;
        ptr_sal->implement();
    }
    else if (instruction=="XCH")
    {
        XCH xch;
        ptr_sal=&xch;
        ptr_sal->implement();
    }
    else if (instruction=="JMP")
    {
        JMP jmp;
        stringstream stream;
        stream.str(variable);
        stream >> jmp.variable;
        ptr_sal=&jmp;
        ptr_sal->implement();
    }
    else if (instruction=="JZS")
    {
        JZS jzs;
        stringstream stream;
        stream.str(variable);
        stream >> jzs.variable;
        ptr_sal=&jzs;
        ptr_sal->implement();

    }
    else if (instruction=="JVS")
    {
        JVS jvs;
        stringstream stream;
        stream.str(variable);
        stream >> jvs.variable;
        ptr_sal=&jvs;
        ptr_sal->implement();
    }
    else if (instruction=="DEC")
    {
        DEC decl;
        SAL::Inst.insert(make_pair(variable, SAL::PC));
        decl.variable=variable;
        ptr_sal=&decl;
        ptr_sal->implement();
    }
    else if (instruction=="ST")
    {
        ST st;
        st.variable=variable;
        ptr_sal=&st;
        ptr_sal->implement();
    }
    else if (instruction=="LDA")
    {
        LDA lda;
        lda.variable=variable;
        ptr_sal=&lda;
        ptr_sal->implement();

    }
    else if (instruction=="LDB")
    {
        LDB ldb;
        ldb.variable=variable;
        ptr_sal=&ldb;
        ptr_sal->implement();
    }
    else if (instruction=="HLT")
    {
        break;
    }
    else
    {
    SAL::PC=SAL::PC+1;
    }    
    }
    cout<<"A Reg = "<<SAL::A<<"\t";
    cout<<"B Reg = "<<SAL::B<<endl;
    cout<<"PC = "<<SAL::PC<<endl;
    cout<<"Zerobit = "<<SAL::ZeroBit<<"\t";
    cout<<"Overflow = "<<SAL::OverFlow<<endl;
    
    if(rCount==0){
        for(size_t i=0;i<256;i++){
         if(SAL::Memory[i]=="HLT"){
            rCount = i;
        }    
      }
    }
    for(size_t i=0;i<(rCount+1);i++)
    {
        cout<<i<<"- "<<SAL::Memory[i]<<endl;
        
    }
    }
        break;
        case 's':{
            
             fstream store;
             store.open("../output.txt",ios::out);
             if(!store){
                cout<<"Error--State not saved"<<endl;
            }else{
             store<<"State Information of program"<<endl;   
             store<<"A = "<<SAL::A<<endl;
             store<<"B = "<<SAL::B<<endl;
             store<<"PC = "<<SAL::PC<<endl;
             store<<"Zero bit = "<<SAL::ZeroBit<<endl;
             store<<"Overflow bit = "<<SAL::OverFlow<<endl<<endl;
             store<<"-----------------\n Memory \n-----------------"<<endl;
             for(size_t i = 0; i < 256; i++)
             {
             store <<i<<" "<<SAL::Memory[i]<< endl;
             }
             store.close();
             cout<<"\nState saved successfully"<<endl;
             cout<<"Check the output.txt file for state information"<<endl;
            
 }
 }
        break;
        case 'q':
        break;
        default: 
        cout<<"\n Command entered is not valid!!"<<endl;
        break;
        }
    }
    while(selection!='q');
    return 0;
}
