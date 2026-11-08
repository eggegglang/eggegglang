/*
 * 蛋语言 · 统一软件世界之蛋
 * 文件名：蛋语言.h（蛋语言核心）
 * 创建者：黑蛋
 * 创建日期：20261108
 * 版本：蛋语言 1.0.0 正统版
 */

#pragma once

#include <stdlib.h>
#include <string.h>

/*=====================+ 基本类型 +=====================*/

typedef unsigned char       字节;
typedef unsigned int        字节量;
typedef unsigned int        结果;
typedef unsigned int        行为;
typedef unsigned long long  象号;
typedef unsigned int        引用;

typedef void                扩;   /* 扩展成员，即 O 象的"肉身" */

#define 空                  ((void*)0)
#define 真                  1
#define 假                  0

/* 结果三分：中、成、败。天道不设第二种失败。*/
#define 果中                0u
#define 果成                1u
#define 果败                0xFFFFFFFFu

/*=====================+ 来访者 +=======================*/

typedef struct 来访者
{
    象号 来者;   /* CR，来访的线程 */
    象号 托者;   /* MR，委托它来的那个 */
} 来访者;

/*=====================+ O 象 +=========================*/

typedef struct 对象 对象;

struct 对象
{
    引用  引用数;
    象号  号;
    扩*   扩;

    /* 九大通用接口：打开、输入、输出、进出、交互零~三、关闭。*/
    结果 (*打开)  (对象* 象, const 来访者* 客);
    结果 (*输入)  (对象* 象, 字节* 入, 字节量 量, const 来访者* 客);
    结果 (*输出)  (对象* 象, 字节* 出, 字节量 容量, 字节量* 实出, const 来访者* 客);
    结果 (*进出)  (对象* 象, 字节* 入, 字节量 量, 字节* 出, 字节量 容量, 字节量* 实出, const 来访者* 客);
    结果 (*交互零)(对象* 象, 行为 令, const 来访者* 客);
    结果 (*交互一)(对象* 象, 行为 令, 字节* 出, 字节量 容量, 字节量* 实出, const 来访者* 客);
    结果 (*交互二)(对象* 象, 行为 令, 字节* 入, 字节量 量, const 来访者* 客);
    结果 (*交互三)(对象* 象, 行为 令, 字节* 入, 字节量 量, 字节* 出, 字节量 容量, 字节量* 实出, const 来访者* 客);
    结果 (*关闭)  (对象* 象, const 来访者* 客);
};

/* 九个缺省接口：不妄为，直接答"败"。这叫守中。*/
static inline 结果 空打开(对象* 象, const 来访者* 客)
{ (void)象; (void)客; return 果败; }

static inline 结果 空输入(对象* 象, 字节* 入, 字节量 量, const 来访者* 客)
{ (void)象; (void)入; (void)量; (void)客; return 果败; }

static inline 结果 空输出(对象* 象, 字节* 出, 字节量 容量, 字节量* 实出, const 来访者* 客)
{ (void)象; (void)出; (void)容量; (void)实出; (void)客; return 果败; }

static inline 结果 空进出(对象* 象, 字节* 入, 字节量 量, 字节* 出, 字节量 容量, 字节量* 实出, const 来访者* 客)
{ (void)象; (void)入; (void)量; (void)出; (void)容量; (void)实出; (void)客; return 果败; }

static inline 结果 空交互零(对象* 象, 行为 令, const 来访者* 客)
{ (void)象; (void)令; (void)客; return 果败; }

static inline 结果 空交互一(对象* 象, 行为 令, 字节* 出, 字节量 容量, 字节量* 实出, const 来访者* 客)
{ (void)象; (void)令; (void)出; (void)容量; (void)实出; (void)客; return 果败; }

static inline 结果 空交互二(对象* 象, 行为 令, 字节* 入, 字节量 量, const 来访者* 客)
{ (void)象; (void)令; (void)入; (void)量; (void)客; return 果败; }

static inline 结果 空交互三(对象* 象, 行为 令, 字节* 入, 字节量 量, 字节* 出, 字节量 容量, 字节量* 实出, const 来访者* 客)
{ (void)象; (void)令; (void)入; (void)量; (void)出; (void)容量; (void)实出; (void)客; return 果败; }

static inline 结果 空关闭(对象* 象, const 来访者* 客)
{ (void)象; (void)客; return 果败; }

/*=====================+ 造象 +=========================*/

/* 取 O 象的肉身。类型由 O 范自己定，这就是"扩展成员"。*/
#define 象身(类型)   ((类型*)(象)->扩)

/*
 * 造象：开一块内存，挂九个空接口，再由接生者把真正的接口接上。
 * 接生者负责"打开"和"关闭"，因为生与死只能由 O 范自己说。
 */
static inline 对象* 造象(void (*接生)(对象*), 字节量 扩大小, 象号 号)
{
    对象* 象 = (对象*)calloc(1, sizeof(对象) + 扩大小);

    if (象 == 空)
        return 空;

    象->号 = 号;
    象->扩 = (扩*)(象 + 1);

    象->打开   = 空打开;
    象->输入   = 空输入;
    象->输出   = 空输出;
    象->进出   = 空进出;
    象->交互零 = 空交互零;
    象->交互一 = 空交互一;
    象->交互二 = 空交互二;
    象->交互三 = 空交互三;
    象->关闭   = 空关闭;

    接生(象);
    return 象;
}

static inline 结果 灭象(对象* 象)
{
    if (象 == 空)
        return 果败;

    free(象);
    return 果成;
}

/* 来访者登记：来者、托者，一个都不能少。*/
static inline 来访者 来客(象号 来者, 象号 托者)
{
    来访者 客;
    客.来者 = 来者;
    客.托者 = 托者;
    return 客;
}
