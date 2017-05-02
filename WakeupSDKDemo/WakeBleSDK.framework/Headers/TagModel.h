//
//  TagModel.h
//  JerryWu
//
//  Created by WuJunjie on 2017/3/15.
//  Copyright © 2017年 WuJunjie. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface TagModel : NSObject
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSDictionary *adverDic;
@property (nonatomic, assign) NSInteger rssi;

@end
