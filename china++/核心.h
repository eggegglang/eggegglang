#pragma once

#define 整数 int
#define 返回 return
#define 如果 if
#define 否则 else
#define 又如 else if

#define 计次循环(variant,count) for(int variant = 0; variant < count; variant ++)
#define 计次循环首(variant, count) 计次循环(variant, count) {
#define 计次循环尾 }
#define 判断循环(condition) while(condition)
#define 判断循环首(condition) 判断循环(condition) {
#define 判断循环尾 }
#define 循环判断首 do{
#define 循环判断尾(condition) } while(condition);

#define 主函数 main