#ifndef EXPLORE_SLP_H
#define EXPLORE_SLP_H

#include "../unit/unit.h"
/**
 *  1.  Stm       ->  Stm; Stm        (CompoundStm)
 *  2.  Stm       ->  id := Exp       (AssignStm)
 *  3.  Stm       ->  print(ExpList)  (PrintStm)
 *  4.  Exp       ->  id              (IdExp)
 *  5.  Exp       ->  num             (NumExp)
 *  6.  Exp       ->  Exp Binop Exp   (OpExp)
 *  7.  Exp       ->  (Stm, Exp)      (EseqExp)
 *  8.  ExpList   ->  Exp, ExpList    (PairExpList)
 *  9.  ExpList   ->  Exp             (LastExpList)
 *  10. Binop     ->  +               (Plus)
 *  11. Binop     ->  -               (Minus)
 *  12. Binop     ->  *               (Times)
 *  13. Binop     ->  /               (Div)
 *  a := 5+3; b := (print(a, a-1), 10*a); print(b)
 *                              CompoundStm
 *                            /            \
 *                        AssignStm         CompoundStm
 *                        /     \           /       \
 *                       a      OpExp     AssignStm  PrintStm
 *                             /  |  \     /   \           |
 *                           Num  Plus Num b EseqExp  LastExpList
 *                                           /     \       |
 *                                         PrintStm  OpExp IdExp
 *                                            |        ?   |
 *                                         PairExpList       b
 *                                         /        \
 *                                      IdExp    LastExpList
 *                                         |      /    |    \
 *                                         a     IdExp Minus NumExp
 *  result: 8 7 80
 *  print(a-1, a-1)
 *                      PairExpList
 *                      /
 *                   OpList
 *                   /   |  \
 *                 IdExp -  NumExp
 *                   |        |
 *                   a        1
 */

typedef char                                                    *string;
typedef struct A_stm_                                           *A_stm;
typedef struct A_exp_                                           *A_exp;
typedef struct A_explist_                                       *A_explist;
typedef enum { A_div, A_plus, A_minus, A_times }                A_binop;
struct A_stm_
{
    enum
    {
        A_compoundStm,
        A_assignStm,
        A_printStm
    } kind;
    union
    {
        struct { A_stm stm1, stm2; }        compound;
        struct { string id; A_exp exp; }    assign;
        struct { A_explist exps; }          print;
    } u;
};
A_stm A_CompoundStm(A_stm stm1, A_stm stm2);
A_stm A_AssignStm(string id, A_exp exp);
A_stm A_PrintStm(A_explist exps);
struct A_exp_
{
    enum
    {
        A_idExp, A_numExp, A_opExp, A_eseqExp
    } kind;
    union
    {
        string id;
        int num;
        struct { A_exp left; A_binop oper; A_exp right; }       op;
        struct { A_stm stm; A_exp exp; }                        eseq;
    } u;
};
A_exp A_IdExp(string id);
A_exp A_NumExp(int num);
A_exp A_OpExp(A_exp left, A_binop oper, A_exp right);
A_exp A_EseqExp(A_stm stm, A_exp exp);
struct A_explist_
{
    enum
    {
        A_pairExpList, A_lastExpList
    } kind;
    union {
        struct { A_exp head; A_explist tail; }  pair;
        A_exp                                   last;
    } u;
};
A_explist A_PairExpList(A_exp head, A_explist tail);
A_explist A_LastExpList(A_exp last);
#endif