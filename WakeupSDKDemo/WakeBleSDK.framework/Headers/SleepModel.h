//
//  SleepModel.h
//  JerryWu
//
//  Created by WuJunjie on 2016/11/3.
//  Copyright © 2016年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SleepModel : NSObject
//开始时间, 睡眠时间, 睡眠类型
@property (nonatomic, assign) int year;
@property (nonatomic, assign) int month;
@property (nonatomic, assign) int day;
@property (nonatomic, assign) int hour;
@property (nonatomic, assign) int minute;
@property (nonatomic, assign) int minutes;
// 1 睡眠(包含深睡和浅睡) 2 深睡
@property (nonatomic, assign) int state;

@end
