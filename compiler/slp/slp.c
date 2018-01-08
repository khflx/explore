#include "slp.h"
A_stm
/**
 * 复合
 * @param stm1
 * @param stm2
 * @return
 */
A_CompoundStm(A_stm stm1, A_stm stm2)
{
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_compoundStm;
    s->u.compound.stm1 = stm1;
    s->u.compound.stm2 = stm2;

    return s;
}

A_stm
/**
 * 赋值
 * @param id
 * @param exp
 * @return
 */
A_AssignStm(string id, A_exp exp)
{
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_compoundStm;
    s->u.assign.id  = id;
    s->u.assign.exp = exp;

    return s;
}

A_stm
/**
 * print
 * @param exps
 * @return
 */
A_PrintStm(A_explist exps)
{
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_printStm;
    s->u.print.exps = exps;

    return s;
}

A_exp
/**
 * 标识符 @注: 变量
 * @param id
 * @return
 */
A_IdExp(string id)
{
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_idExp;
    e->u.id = id;

    return e;
}

A_exp
/**
 * 数值
 * @param num
 * @return
 */
A_NumExp(int num)
{
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_numExp;
    e->u.num = num;

    return e;
}

A_exp
/**
 * 双目运算符
 * @param left
 * @param oper
 * @param right
 * @return
 */
A_OpExp(A_exp left, A_binop oper, A_exp right)
{
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_opExp;
    e->u.op.oper  = oper;
    e->u.op.left  = left;
    e->u.op.right = right;

    return e;
}

A_exp
/**
 * 逗号运算符
 * @param stm
 * @param exp
 * @return
 */
A_EseqExp(A_stm stm, A_exp exp)
{
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_eseqExp;
    e->u.eseq.stm = stm;
    e->u.eseq.exp = exp;

    return e;
}

A_explist A_PairExpList(A_exp head, A_explist tail)
{
    A_explist el = checked_malloc(sizeof(*el));
    el->kind = A_pairExpList;
    el->u.pair.head = head;
    el->u.pair.tail = tail;

    return el;
}

A_explist A_LastExpList(A_exp exp)
{
    A_explist el = checked_malloc(sizeof(*el));
    el->kind = A_lastExpList;
    el->u.last = exp;

    return el;
}