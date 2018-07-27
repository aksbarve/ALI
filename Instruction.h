#pragma once

#include <string>
#include <iostream>
#include "SAL.h"

using namespace std;


class DEC : public SAL
{
public:
    DEC();
   ~DEC();
   
    string instruction;
    string variable;
    void implement() override;

};

class LDA : public SAL
{
public:
    LDA();
   ~LDA();
   
    string instruction;
    string variable;
    void implement() override;

};

class LDB : public SAL
{
public:
    LDB();
   ~LDB();
   
    string instruction;
    string variable;
    void implement() override;

};

class LDI : public SAL
{
public:
    LDI();
   ~LDI();
   
    string instruction;
    signed int variable;
    void implement() override;
};

class ST : public SAL
{
public:
    ST();
   ~ST();
   
    string instruction;
    string variable;
    void implement() override;

};

class XCH : public SAL
{
public:
    XCH();
   ~XCH();
   
    string instruction;
    void implement() override;

};


class ADD : public SAL
{
public:
    ADD();
   ~ADD();
    
    string instruction;
    void implement() override;

};


class JMP : public SAL
{
public:
    JMP();
   ~JMP();
   
    string instruction;
    int variable;
    void implement() override;

};

class JVS : public SAL
{
public:
    JVS();
   ~JVS();
   
    string instruction;
    int variable;
    void implement() override;

};

class JZS : public SAL
{
public:
    JZS();
   ~JZS();
   
    string instruction;
    int variable;
    void implement() override;

};