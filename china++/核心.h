#pragma once

#define 整数 int
#define 无类型 void
#define 常量 const
#define 静态 static
#define 内联 inline

#define 无符号字符 unsigned char
#define 无符号短整数 unsigned short
#define 无符号整数 unsigned int
#define 无符号长整数 unsigned long long
#define 有符号字符 signed char
#define 有符号短整数 short
#define 有符号整数 int
#define 有符号长整数 long long
#define 字符 char
#define 单精度 float
#define 双精度 double

#define 返回 return
#define 如果 if
#define 否则 else
#define 又如 else if

#define 计次循环(variant,count) for(整数 variant = 0; variant < (整数)(count); variant ++)
#define 计次循环首(variant, count) 计次循环(variant, count) {
#define 计次循环尾 }
#define 判断循环(condition) while(condition)
#define 判断循环首(condition) 判断循环(condition) {
#define 判断循环尾 }
#define 循环判断首 do{
#define 循环判断尾(condition) } while(condition);

#define 主函数 main