//
//  AppDelegate.m
//  HNNetworkReachabilityManager
//
//  Created by Young on 2022/2/18.
//

#import "AppDelegate.h"
#import "HNNetworkReachabilityManager.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [HNNetworkReachabilityManager.sharedManager startMonitoring];
    return YES;
}


@end
