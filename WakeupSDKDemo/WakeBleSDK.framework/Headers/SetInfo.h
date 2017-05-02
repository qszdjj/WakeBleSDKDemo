//
//  SetInfo.h
//  JerryWu
//
//  Created by WuJunjie on 16/7/25.
//  Copyright © 2016年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

// 设置
@interface SetInfo : NSObject
@property (nonatomic, assign) int isLight;
@property (nonatomic, assign) int isMeasure;
@property (nonatomic, assign) int isAntilost;

@property (nonatomic, assign) int isCall;
@property (nonatomic, assign) int isMessage;
@property (nonatomic, assign) int isWeChat;
@property (nonatomic, assign) int isQQ;
@property (nonatomic, assign) int isWeibo;
@property (nonatomic, assign) int isFacebook;
@property (nonatomic, assign) int isTwitter;
@property (nonatomic, assign) int isWhat;

//部分手环不支持
@property (nonatomic, assign) int isLine;
@property (nonatomic, assign) int isKakaotalk;

@end
