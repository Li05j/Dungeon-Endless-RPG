#ifndef __BASIC_PARAM_H_
#define __BASIC_PARAM_H_

class BasicParam
{
    int m_curr_hp;
    int m_atk;
public:
    BasicParam();
    virtual ~BasicParam();

    void setParams(int, int);
};

#endif