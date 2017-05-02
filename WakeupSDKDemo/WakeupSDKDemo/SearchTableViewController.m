//
//  SearchTableViewController.m
//  WakeupSDKDemo
//
//  Created by WuJunjie on 2017/1/5.
//  Copyright © 2017年 WuJunjie. All rights reserved.
//

#import "SearchTableViewController.h"
#import <WakeBleSDK/WakeBleSDK.h>

@interface SearchTableViewController ()

@end

@implementation SearchTableViewController

- (void)setupBleNotify {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleBleNotify:) name:kTag_Phone_Ble_On object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleBleNotify:) name:kTag_Phone_Ble_Off object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleBleNotify:) name:kTag_Phone_Discover_Device object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleBleNotify:) name:kTag_Device_Connected object:nil];
}

- (void)handleBleNotify:(NSNotification *)notify {
    if ([notify.name isEqualToString:kTag_Phone_Ble_Off]) {
        
    }
    else if ([notify.name isEqualToString:kTag_Phone_Ble_On]) {
        [tagSelf startFindBleDevices];
    }
    else if ([notify.name isEqualToString:kTag_Phone_Discover_Device]) {
        [self.tableView reloadData];
    }
    else if ([notify.name isEqualToString:kTag_Device_Connected]) {
        [self performSegueWithIdentifier:@"detail" sender:nil];
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setupBleNotify];
    [tagSelf setupCentral];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return tagSelf.peripheralArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:@""];
    
    TagModel *model = tagSelf.bleArray[indexPath.row];
    NSString *name = model.adverDic[CBAdvertisementDataLocalNameKey];
    cell.textLabel.text = name;
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%d", (int)model.rssi];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    [tagSelf stopFindBleDevices];
    TagModel *model = tagSelf.bleArray[indexPath.row];
    
    CBPeripheral *peripheral = model.peripheral;
    [tagSelf connectBleDevice:peripheral];
}
- (IBAction)pressSearch:(id)sender {
    [tagSelf stopFindBleDevices];
    [tagSelf.peripheralArray removeAllObjects];
    [tagSelf.bleArray removeAllObjects];
    [tagSelf.connectedPeripheralArray removeAllObjects];
    [self.tableView reloadData];
    
    [tagSelf startFindBleDevices];
}

@end
