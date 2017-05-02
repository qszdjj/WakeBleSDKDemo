//
//  TagManager.h
//  BreezeeBle
//
//  Created by iBreezee_IOS on 16/3/10.
//  Copyright © 2016年 iBreezee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "DateModel.h"
#import "UserInfo.h"
#import "SetInfo.h"
#import "IgnoreAction.h"
#import "LongSit.h"
#import "TimeAction.h"
#import "HourData.h"
#import "MeasureData.h"
#import "TagModel.h"
#import "SleepModel.h"
#import "SleepTimeSet.h"
#import "WKUtils.h"

// return nil
#define kTag_Phone_Ble_On               @"kTag_Phone_Ble_On"
#define kTag_Phone_Ble_Off              @"kTag_Phone_Ble_Off"

//开始搜索前，将peripheralArray，bleArray，connectedPeripheralArray 清空
#define kTag_Phone_Discover_Device      @"kTag_Phone_Discover_Device"


// return CBPeripheral
#define kTag_Device_Connected           @"kTag_Device_Connected"
// return CBPeripheral
#define kTag_Device_Disconnected        @"kTag_Device_Disconnected"
//绑定完成   return nil  绑定完成后发送 设置信息
#define kTag_Device_Bond_Ready @"kTag_Device_Bond_Ready"

//版本信息 return nil
#define kReceive_Version @"kReceive_Version"
//电量    return nil
#define kReceive_Battery @"kReceive_Battery"

//收到单次测量数据 return MeasureData
#define kReceive_HeartRate @"kReceive_HeartRate"
#define kReceive_Oxygen     @"kReceive_oxygen"
#define kReceive_BloodPressure @"kReceive_BloodPressure"

// 收到实时数据 return nil
#define kReceive_HeartRate_Real @"kReceive_HeartRate_Real"
#define kReceive_Oxygen_Real     @"kReceive_Oxygen_Real"
#define kReceive_BloodPressure_Real @"kReceive_BloodPressure_Real"

//临时计步、睡眠、醒来次数、数据 return nil
#define kReceive_Temporary_Data @"kReceive_Temporary_Data"

//整点数据  return HourData
#define kReceive_Hour_Data @"kReceive_Hour_Data"

//一键测量 return @[心率，血压，血氧，疲劳](MeasureData) NSMutableArray
#define kReceive_Measure_All @"kReceive_Measure_All"

//分段睡眠数据 return (SleepModel)
#define kReceive_Sleep @"kReceive_Sleep"
//收到拍照 return nil
#define kReceive_TakePic @"kReceive_TakePic"
//查找手机 return nil
#define kReceive_FindPhone @"kReceive_FindPhone"

#define tagSelf [TagManager sharedTagManager]

//功能类型
typedef NS_ENUM(NSUInteger, CommandType) {
    //查找手环
    CommandTypeFind = 0x71,
    //久坐提醒开关
    CommandTypeSit = 0x75,
    //勿扰模式开关
    CommandTypeIgnore = 0x76,
    //抬手亮屏开关
    CommandTypeLight = 0x77,
    //一键测量开关
    CommandTypeMeasure = 0x78,
    //拍照
    CommandTypeTakePic = 0x79,
    //防丢提醒
    CommandTypeAntiLost = 0x7a,
    //中英文切换
    CommandTypeSwitchLang = 0x7b,
    //时间制度切换 （12小时制和24小时制）
    CommandTypeSwitchTimeFormatter = 0x7c,
    //设置睡眠范围
    CommandTypeSleepTimeSet = 0x7f,
    //获取电量
    CommandTypeBatteryLevel = 0x91,
    //获取版本号
    CommandTypeVersion = 0x92,
    //一键测量
    CommandTypeMeasureAll = 0x32,
    //删除手环数据
    CommandTypeDeleteData = 0x23,
    //恢复出厂设置(不删除数据)
    CommandTypeInit = 0xff,
};

typedef NS_ENUM(NSUInteger, NotifyType) {
    NotifyTypeCall = 1,
    NotifyTypeMessage = 3,
    NotifyTypeWechat = 9,
    NotifyTypeQQ = 7,
    NotifyTypeWeibo = 19,
    NotifyTypeFacebook = 16,
    NotifyTypeFacebookMessage = 17,
    NotifyTypeTwitter = 15,
    NotifyTypeWhatsApp = 10,
    NotifyTypeLine = 14,
    NotifyTypeKakaoTalk = 20,
    
};

typedef NS_ENUM(NSUInteger, MeasureType) {
    MeasureTypeHearRate = 0x09,
    MeasureTypeHearRateReal = 0x0a,
    MeasureTypeOxygen = 0x11,
    MeasureTypeOxygenReal = 0x12,
    MeasureTypeBlood = 0x21,
    MeasureTypeBloodReal = 0x22,
};

@interface TagManager : NSObject
@property (nonatomic, strong) CBCentralManager *centralManager;
@property (nonatomic, strong) CBPeripheral *activePeripheral;

@property (nonatomic, strong) NSMutableArray *peripheralArray;
@property (nonatomic, strong) NSMutableArray *bleArray;
@property (nonatomic, strong) NSMutableArray *connectedPeripheralArray;
// 手机蓝牙开关状态
@property (nonatomic, assign) BOOL on;

@property (nonatomic, assign) float version;
@property (nonatomic, assign) int versionType;
@property (nonatomic, assign) int step;
@property (nonatomic, assign) int cal;
@property (nonatomic, assign) int batteryLevel;
@property (nonatomic, assign) int deepSleep;
@property (nonatomic, assign) int lightSleep;
@property (nonatomic, assign) int wakeupTimes;
@property (nonatomic, assign) int heartRate;
@property (nonatomic, assign) int bpMax;
@property (nonatomic, assign) int bpMin;
@property (nonatomic, assign) int oxyValue;
//mac地址，can be nil
@property (nonatomic, strong) NSString *mac;

//实时临时数据
@property (nonatomic, assign) int heartRateReal;
@property (nonatomic, assign) int bpMaxReal;
@property (nonatomic, assign) int bpMinReal;
@property (nonatomic, assign) int oxyValueReal;


+ (TagManager *)sharedTagManager;


/**
 固件升级会导致delegate发生变化，重新调整delegate指向self
 */
- (void)setupCentral;


/**
 搜索和停止搜索
 */
- (void)startFindBleDevices;
- (void)stopFindBleDevices;


/**
 连接和断开连接

 @param peripheral 外设对象
 */
- (void)connectBleDevice:(CBPeripheral *)peripheral;
- (void)disconnectBleDevice:(CBPeripheral *)peripheral;

/**
 请求手环绑定
 */
- (void)sendBondSystem;

/**
 发送手机时间和用户信息给手环
 */
- (void)sendUserTime:(DateModel *)dateModel;
- (void)sendUserInfo:(UserInfo *)userInfo;


/**
 请求整点数据

 @param dateModel 请求数据的开始节点，蓝牙设备会把这个点后的数据全部发送回手机
 */
- (void)requstAllWithDateModel:(DateModel *)dateModel;


/**
 请求详细的睡眠数据

 @param dateModel 请求数据的开始节点，蓝牙设备会把这天中午12点后的数据全部发送回手机
 如2017-01-01 睡眠返回的是中午12点开始的睡眠数据，要想获取上半天的，请提前日期一天
 */
- (void)requstSleepWithDateModel:(DateModel *)dateModel;


/**
 给手环设置闹钟

 @param timeAction 闹钟对象
 */
- (void)sendAlert:(TimeAction *)timeAction;


/**
 发送命令给设备

 @param type 命令类型
 @param isOn 命令开启或关闭
 */
- (void)sendCommand:(CommandType)type on:(BOOL)isOn;


/**
 设置苹果通知的开启和关闭

 @param notifyid 苹果通知的ID
 @param isOn     开启或关闭蓝牙通知
 */
- (void)sendNotify:(NotifyType)notifyid on:(BOOL)isOn;


/**
 测量 心率，血压，血氧

 @param meaId  测量ID
 @param enable 开始测量和关闭测量
 */
- (void)sendMeasureId:(MeasureType)meaId enable:(BOOL)enable;


/**
 设置 久坐提醒， 和勿扰模式, 睡眠时间设置
 */
- (void)sendLongSit:(LongSit *)longSit;
- (void)sendIgnoreAction:(IgnoreAction *)ignoreAction;
- (void)sendSleepTimeSet:(SleepTimeSet *)longSit;

/**
 @param step 当前计步
 @param hour 当前小时 int
 @return 疲劳值
 */
- (int)fatigueWithStep:(int)step time:(int)hour;

@end
