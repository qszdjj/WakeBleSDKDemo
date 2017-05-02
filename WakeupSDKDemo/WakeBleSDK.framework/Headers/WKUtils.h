//
//  WKUtils.h
//  WakeBleSDK
//
//  Created by WuJunjie on 2017/5/2.
//  Copyright © 2017年 WuJunjie. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WKUtils : NSObject


/**
 NSCalendar *calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
 calendar.locale = [NSLocale currentLocale];
 calendar.timeZone = [NSTimeZone localTimeZone];
 
 统一转换为公历日历(Unified conversion to Gregorian calendar)

 @return calendar
 */
+ (NSCalendar *)wkCalendar;
+ (NSDateComponents *)getDateComponentsFromDate:(NSDate *)date;

@end
