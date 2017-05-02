//
//  DetailTableViewController.m
//  WakeupSDKDemo
//
//  Created by WuJunjie on 2017/1/5.
//  Copyright © 2017年 WuJunjie. All rights reserved.
//

#import "DetailTableViewController.h"
#import <WakeBleSDK/WakeBleSDK.h>

@interface DetailTableViewController ()

@end

@implementation DetailTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupBleNotify];
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)setupBleNotify {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleBleNotify:) name:kReceive_Sleep object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleBleNotify:) name:kReceive_Hour_Data object:nil];
}

- (void)handleBleNotify:(NSNotification *)notify {
    if ([notify.name isEqualToString:kReceive_Sleep]) {
        NSLog(@"%@", notify.object);
    }
    if ([notify.name isEqualToString:kReceive_Hour_Data]) {
        NSLog(@"%@", notify.object);
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//#pragma mark - Table view data source
//
//- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
//    return 1;
//}
//
//- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
//    return 4;
//}
//
//
//- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
//    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:<#@"reuseIdentifier"#> forIndexPath:indexPath];
//    
//    // Configure the cell...
//    
//    return cell;
//}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:true];
    NSLog(@"%s", __func__);
    if (indexPath.row == 0) {
        //用户信息
        UserInfo *userInfo = [[UserInfo alloc] init];
        userInfo.sex = 0;
        userInfo.age = 24;
        userInfo.height = 170;
        userInfo.weight = 60;
        userInfo.stepLength = 70;
        userInfo.wearStyle = 0;
        userInfo.distanceUnit = 1;
        userInfo.weightUnit = 1;
        userInfo.bpMax = 115;
        userInfo.bpMin = 75;
        userInfo.goal = 8000;
        
        [tagSelf sendUserInfo:userInfo];
    }
    else if (indexPath.row == 1) {
        SetInfo *setInfo = [[SetInfo alloc] init];
        setInfo.isLight = 1;
        setInfo.isMeasure = 0;
        setInfo.isCall = 1;
        setInfo.isMessage = 1;
        setInfo.isWeChat = 1;
        setInfo.isQQ = 1;
        setInfo.isWeibo = 0;
        setInfo.isFacebook = 0;
        setInfo.isTwitter = 0;
        setInfo.isWhat = 0;
        
        [tagSelf sendCommand:CommandTypeLight on:setInfo.isLight];
        [tagSelf sendCommand:CommandTypeMeasure on:setInfo.isMeasure];
        
        [tagSelf sendNotify:NotifyTypeCall on:setInfo.isCall];
        [tagSelf sendNotify:NotifyTypeMessage on:setInfo.isMessage];
        [tagSelf sendNotify:NotifyTypeWechat on:setInfo.isWeChat];
        [tagSelf sendNotify:NotifyTypeQQ on:setInfo.isQQ];
        [tagSelf sendNotify:NotifyTypeWeibo on:setInfo.isWeibo];
        [tagSelf sendNotify:NotifyTypeFacebook on:setInfo.isFacebook];
        [tagSelf sendNotify:NotifyTypeFacebookMessage on:setInfo.isFacebook];
        [tagSelf sendNotify:NotifyTypeTwitter on:setInfo.isTwitter];
        [tagSelf sendNotify:NotifyTypeWhatsApp on:setInfo.isWhat];
    }
    else if (indexPath.row == 2) {
        LongSit *longSit = [[LongSit alloc] init];
        longSit.on = NO;
        longSit.startHour = 9;
        longSit.startMinute = 0;
        longSit.endHour = 18;
        longSit.endMinute = 0;
        [tagSelf sendLongSit:longSit];
    }
    else if (indexPath.row == 3) {
        TimeAction *timeAction = [[TimeAction alloc] init];
        timeAction.identifier = 0;
        NSDateComponents *comp = [self getDateComponentsFromDate:[NSDate date]];
        timeAction.hour = (int)comp.hour;
        timeAction.minute = (int)comp.minute;
        timeAction.repeat = 1;
        timeAction.weekday = (int)powf(2, [self getWeekday] - 1);
        timeAction.isOn = 1;
        [tagSelf sendAlert:timeAction];
    }
    
    else if (indexPath.row == 4) {
        [tagSelf sendCommand:CommandTypeMeasureAll on:YES];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(60 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [tagSelf sendCommand:CommandTypeMeasureAll on:NO];
        });
    }
    else if (indexPath.row == 5) {
        [tagSelf sendMeasureId:MeasureTypeHearRate enable:YES];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(30 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [tagSelf sendMeasureId:MeasureTypeHearRate enable:NO];
        });
    }
    else if (indexPath.row == 6) {
        DateModel *model = [[DateModel alloc] init];
        model.year = 2017;
        model.month = 1;
        model.day = 2;
        model.hour = 0;
        model.minute = 0;
        model.second = 0;
        [tagSelf requstSleepWithDateModel:model];
    }
    else if (indexPath.row == 7) {
        DateModel *model = [[DateModel alloc] init];
        model.year = 2017;
        model.month = 1;
        model.day = 1;
        model.hour = 0;
        model.minute = 0;
        model.second = 0;
        [tagSelf requstAllWithDateModel:model];
    }
    else if (indexPath.row == 8) {
        [tagSelf sendCommand:CommandTypeFind on:true];
    }
}

- (int)getWeekday {
    NSDateComponents *components = [self getDateComponentsFromDate:[NSDate date]];
    
    if (components.weekday == 7) {
        return 1;
    }
    
    return (int)components.weekday - 1;
}

- (NSDateComponents *)getDateComponentsFromDate:(NSDate *)date {
    NSDateComponents *components = [[NSCalendar currentCalendar] components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond | NSCalendarUnitWeekday) fromDate:date];
    
    return components;
}

@end
