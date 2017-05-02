//
//  HourData.h
//  JerryWu
//
//  Created by WuJunjie on 16/8/1.
//  Copyright © 2016年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HourData : NSObject
@property (nonatomic, assign) int year;
@property (nonatomic, assign) int month;
@property (nonatomic, assign) int day;
@property (nonatomic, assign) int hour;
@property (nonatomic, assign) int minute;

@property (nonatomic, assign) int step;
@property (nonatomic, assign) int cal;

@property (nonatomic, assign) int deep;
@property (nonatomic, assign) int light;
@property (nonatomic, assign) int awakeTimes;

@property (nonatomic, assign) int hrValue;

@property (nonatomic, assign) int bpMax;
@property (nonatomic, assign) int bpMin;

@property (nonatomic, assign) int oxValue;

@end
