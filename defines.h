/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:16:53 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:16:55 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_DEFINES_H
#define AVM_DEFINES_H

typedef enum {
    INSTRUCTION,
    OPERAND,
    ERROR,
    END
} eTokenType;

typedef enum
{
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    Types
} eOperandType;

typedef enum
{
    PUSH,
    POP,
    DUMP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    PRINT,
    EXIT,
    CLOSEINPUT,
    COMMENT,
    WORDS
} eKeyword;

#endif //AVM_DEFINES_H
