//
//  TimeAction.h
//  JerryWu
//
//  Created by WuJunjie on 16/7/27.
//  Copyright © 2016年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

// 闹钟设置
@interface TimeAction : NSObject
@property (nonatomic, assign) int identifier;
@property (nonatomic, assign) int hour;
@property (nonatomic, assign) int minute;
@property (nonatomic, assign) int repeat;
@property (nonatomic, assign) int weekday;
@property (nonatomic, assign) int isOn;

@end
