#include "Instruction.h"
#include <iostream>
#include <string>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

 DEC::DEC()
{

}
DEC::~DEC()
{

}

void DEC::implement()
 {
   SAL::PC=SAL::PC+1;
 }
 
 
LDA::LDA()
{

}
LDA::~LDA()
{

}

void LDA::implement()
 {
   signed int result;
   
   std::map<string,int>::iterator iterate;
   iterate = Inst.find(variable);
   int value = iterate->second;
   
   stringstream stream;
   stream.str(SAL::Memory[value]);
   stream >> result;
   
   SAL::A=result;
   SAL::PC=SAL::PC+1;
 }

LDB::LDB()
{

}
LDB::~LDB()
{

}

void LDB::implement()
 {
   signed int result;
   
   std::map<string,int>::iterator iterate;
   iterate = Inst.find(variable);
   int value = iterate->second;
   
   stringstream stream;
   stream.str(SAL::Memory[value]);
   stream >> result;
   
   SAL::B=result;
   SAL::PC=SAL::PC+1;
 }

LDI::LDI()
{

}
LDI::~LDI()
{

}
void LDI::implement()
{

   SAL::A=variable;
   SAL::PC=SAL::PC+1;

}

ST::ST()
{

}
ST::~ST()
{

}

void ST::implement()
 {
   string result= to_string(SAL::A);
   
   std::map<string,int>::iterator iterate;
   iterate = Inst.find(variable);
   int value = iterate->second;
   
   stringstream stream;
   
   SAL::Memory[value]=result;
   SAL::PC=SAL::PC+1;
 }

XCH::XCH()
{

}
XCH::~XCH()
{

}

void XCH::implement()
 {
   signed int swap;
   swap=SAL::A;
   SAL::A=SAL::B;
   SAL::B=swap;
   SAL::PC=SAL::PC+1;

 }

ADD::ADD()
{

}
ADD::~ADD()
{

}
void ADD::implement()
 {

   SAL::A=SAL::A+SAL::B;
   SAL::PC=SAL::PC+1;
   
   if(SAL::A >=(2147483647) || SAL::A <= (-(2147483648)))
      {          
       SAL::OverFlow=true;
      }
    if(SAL::A==0)
    {
       SAL::ZeroBit=true;
    }
 }
 

 JMP::JMP()
{

}
JMP::~JMP()
{

}

void JMP::implement()
 {

   SAL::PC=variable;

 }

JVS::JVS()
{

}
JVS::~JVS()
{

}

void JVS::implement()
 {
   if(SAL::OverFlow)
   {
       SAL::PC=variable;
   }
   else
   {
       SAL::PC=SAL::PC+1;
   }


 }

JZS::JZS()
{

}
JZS::~JZS()
{

}

void JZS::implement()
 {
   if(SAL::ZeroBit)
   {
       SAL::PC=variable;
   }
   else
   {
       SAL::PC=SAL::PC+1;
   }


 }
