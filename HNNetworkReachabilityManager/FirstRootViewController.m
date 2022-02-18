//
//  FirstRootViewController.m
//  HNNetworkReachabilityManager
//
//  Created by Young on 2022/2/18.
//

#import "FirstRootViewController.h"
#import "HNNetworkReachabilityManager.h"

@interface FirstRootViewController ()

@end

@implementation FirstRootViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)queryStatusButtonDidClick:(UIButton *)sender {
    HNNetworkReachabilityStatus status = HNNetworkReachabilityManager.sharedManager.networkReachabilityStatus;
    switch (status) {
        case HNNetworkReachabilityStatusUnknown:
            NSLog(@"HNNetworkReachabilityStatusUnknown");
            break;
        case HNNetworkReachabilityStatusNotReachable:
            NSLog(@"HNNetworkReachabilityStatusNotReachable");
            break;
        case HNNetworkReachabilityStatusReachableViaWWAN:
            NSLog(@"HNNetworkReachabilityStatusReachableViaWWAN");
            break;
        case HNNetworkReachabilityStatusReachableViaWiFi:
            NSLog(@"HNNetworkReachabilityStatusReachableViaWiFi");
            break;
        default:
            NSLog(@"HNNetworkReachabilityStatusUndefined");
            break;
    }
}

@end
