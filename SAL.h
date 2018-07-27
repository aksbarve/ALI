#pragma once

#include <map>
#include <iostream>
using namespace std;

class SAL
{
public:
    SAL();

   ~SAL();
   
   static signed int A;
   static signed int B;
   static int PC;
   static string Memory[256];
   static map<string,int> Inst;
   static bool ZeroBit;
   static bool OverFlow;
   virtual void implement() = 0;
};

