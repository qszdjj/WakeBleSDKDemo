//
//  DateModel.h
//  JerryWu
//
//  Created by WuJunjie on 16/8/3.
//  Copyright © 2016年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DateModel : NSObject
@property (nonatomic, assign) int year;
@property (nonatomic, assign) int month;
@property (nonatomic, assign) int day;
@property (nonatomic, assign) int hour;
@property (nonatomic, assign) int minute;
@property (nonatomic, assign) int second;

- (instancetype)initWithDate:(NSDate *)date;

@end
