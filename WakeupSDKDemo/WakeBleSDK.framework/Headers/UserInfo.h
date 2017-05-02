//
//  UserInfo.h
//  JerryWu
//
//  Created by WuJunjie on 16/7/21.
//  Copyright © 2016年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

// 用户信息
@interface UserInfo : NSObject
// 0 male, 1 female
@property (nonatomic, assign) int sex;
@property (nonatomic, assign) int age;
@property (nonatomic, assign) float height;
@property (nonatomic, assign) float weight;
@property (nonatomic, assign) float stepLength;
// 佩戴方式 0 右手，1 左手
@property (nonatomic, assign) int wearStyle;
// 单位 0 英里，1 km
@property (nonatomic, assign) int distanceUnit;
// 单位 0 磅，1 kg  lb = kg / 2.20462
@property (nonatomic, assign) int weightUnit;
// 单位 0 英尺，1 cm  feet = cm * 30.48
@property (nonatomic, assign) int heightUnit;

// 血压
@property (nonatomic, assign) int bpMax;
@property (nonatomic, assign) int bpMin;
@property (nonatomic, assign) int goal;

@end
