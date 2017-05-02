//
//  SleepTimeSet.h
//  JerryWu
//
//  Created by WuJunjie on 2017/2/23.
//  Copyright © 2017年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SleepTimeSet : NSObject
@property (nonatomic, assign) BOOL on;
@property (nonatomic, assign) int startHour;
@property (nonatomic, assign) int startMinute;
@property (nonatomic, assign) int endHour;
@property (nonatomic, assign) int endMinute;

@end
