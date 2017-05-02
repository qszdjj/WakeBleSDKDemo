//
//  MeasureData.h
//  JerryWu
//
//  Created by WuJunjie on 16/8/1.
//  Copyright © 2016年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MeasureData : NSObject
// 0 心率，1 血压，2，血氧，3疲劳
@property (nonatomic, assign) int identifier;
@property (nonatomic, assign) int year;
@property (nonatomic, assign) int month;
@property (nonatomic, assign) int day;
@property (nonatomic, assign) int hour;
@property (nonatomic, assign) int minute;
@property (nonatomic, assign) int maxValue;
@property (nonatomic, assign) int minValue;

@end
