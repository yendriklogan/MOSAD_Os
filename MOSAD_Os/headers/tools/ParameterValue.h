#pragma once

#include <iostream>
#include "data/Interval.h"
#include "Constantes.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB ParameterValue {
public:


private:
    void* value;
    int tipo;

public:
    ParameterValue();
    ParameterValue(void* val);
    ParameterValue(const char val[]);
    ParameterValue(char* val);
    ParameterValue(char val);
    ParameterValue(double val);
    ParameterValue(long long val);
    ParameterValue(float val);
    ParameterValue(long val);
    ParameterValue(int val);
    ParameterValue(Interval val);
    ~ParameterValue();

    ParameterValue operator =(void* val);
    ParameterValue operator =(const char val[]);
    ParameterValue operator =(char* val);
    ParameterValue operator =(char val);    
    ParameterValue operator =(int val);
    ParameterValue operator =(long val);
    ParameterValue operator =(float val);
    ParameterValue operator =(long long val);
    ParameterValue operator =(double val);
    ParameterValue operator =(Interval val);

    void* getValue();
    char* getString();
    char getChar();
    int getInt();
    long getLong();
    float getFloat();
    long long getLongLong();
    double getDouble();
    int getType();
    Interval getInterval();

    //bool operator==(const Parameter& op);

    DECISIONAID_LIB friend ostream& operator<<(ostream& os, const ParameterValue& dt);

};
