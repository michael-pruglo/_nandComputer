//
// Created by Michael on 06/08/20.
//

#ifndef NANDCOMPUTER_LOGICGATES_HPP
#define NANDCOMPUTER_LOGICGATES_HPP


class LogicGates
{
public:
    static bool _nand(bool a, bool b);

    static bool _not(bool a);
    static bool _and(bool a, bool b);
    static bool _or(bool a, bool b);

    static bool _xor(bool a, bool b);

    static bool _mux(bool a, bool b, bool sel);
    static bool _dmux(bool in, bool sel);
};


#endif //NANDCOMPUTER_LOGICGATES_HPP
