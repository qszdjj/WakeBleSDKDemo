//
//  IgnoreAction.h
//  JerryWu
//
//  Created by WuJunjie on 16/7/27.
//  Copyright © 2016年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

// 勿扰模式设置
@interface IgnoreAction : NSObject
@property (nonatomic, assign) BOOL on;
@property (nonatomic, assign) int startHour;
@property (nonatomic, assign) int startMinute;
@property (nonatomic, assign) int endHour;
@property (nonatomic, assign) int endMinute;

@end
