//
//  HNNetworkReachabilityManager.h
//  HNNetworkReachabilityManager
//
//  Created by Young on 2022/2/18.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, HNNetworkReachabilityStatus) {
    HNNetworkReachabilityStatusUnknown          = -1,
    HNNetworkReachabilityStatusNotReachable     = 0,
    HNNetworkReachabilityStatusReachableViaWWAN = 1,
    HNNetworkReachabilityStatusReachableViaWiFi = 2,
};

/// Posted when network reachability changes.
/// This notification assigns no notification object. The `userInfo` dictionary contains an `NSNumber` object under the `HNNetworkReachabilityNotificationStatusItem` key,
/// representing the `HNNetworkReachabilityStatus` value for the current network reachability.
FOUNDATION_EXPORT NSString * const HNNetworkReachabilityDidChangeNotification;
FOUNDATION_EXPORT NSString * const HNNetworkReachabilityNotificationStatusItem;

/// `HNNetworkReachabilityManager` monitors the reachability of domains, and addresses for both WWAN and WiFi network interfaces.
/// Reachability can be used to determine background information about why a network operation failed, or to trigger a network operation retrying when a connection is established.
/// It should not be used to prevent a user from initiating a network request, as it's possible that an initial request may be required to establish reachability.
/// See Apple's Reachability Sample Code ( https://developer.apple.com/library/ios/samplecode/reachability/ )
/// @warning Instances of `HNNetworkReachabilityManager` must be started with `-startMonitoring` before reachability status can be determined.
@interface HNNetworkReachabilityManager : NSObject

/// The current network reachability status.
@property (nonatomic, readonly, assign) HNNetworkReachabilityStatus networkReachabilityStatus;

/// Whether or not the network is currently reachable.
@property (nonatomic, readonly, assign, getter=isReachable) BOOL reachable;

/// Whether or not the network is currently reachable via WWAN.
@property (nonatomic, readonly, assign, getter=isReachableViaWWAN) BOOL reachableViaWWAN;

/// Whether or not the network is currently reachable via WiFi.
@property (nonatomic, readonly, assign, getter=isReachableViaWiFi) BOOL reachableViaWiFi;

/// Returns the shared network reachability manager.
+ (instancetype)sharedManager;

/// Creates and returns a network reachability manager with the default socket address.
/// @return An initialized network reachability manager, actively monitoring the default socket address.
+ (instancetype)manager;

/// Creates and returns a network reachability manager for the specified domain.
/// @param domain The domain used to evaluate network reachability.
/// @return An initialized network reachability manager, actively monitoring the specified domain.
+ (instancetype)managerForDomain:(NSString *)domain;

/// Creates and returns a network reachability manager for the socket address.
/// @param address The socket address (`sockaddr_in6`) used to evaluate network reachability.
/// @return An initialized network reachability manager, actively monitoring the specified socket address.
+ (instancetype)managerForAddress:(const void *)address;

/// Initializes an instance of a network reachability manager from the specified reachability object.
/// @param reachability The reachability object to monitor.
/// @return An initialized network reachability manager, actively monitoring the specified reachability.
- (instancetype)initWithReachability:(SCNetworkReachabilityRef)reachability NS_DESIGNATED_INITIALIZER;

/// Unavailable initializer
+ (instancetype)new NS_UNAVAILABLE;

/// Unavailable initializer
- (instancetype)init NS_UNAVAILABLE;

/// Starts monitoring for changes in network reachability status.
- (void)startMonitoring;

/// Stops monitoring for changes in network reachability status.
- (void)stopMonitoring;

/// Sets a callback to be executed when the network availability of the `baseURL` host changes.
/// @param block A block object to be executed when the network availability of the `baseURL` host changes.
/// This block has no return value and takes a single argument which represents the various reachability states from the device to the `baseURL`.
- (void)setReachabilityStatusChangeBlock:(nullable void (^)(HNNetworkReachabilityStatus status))block;

@end

NS_ASSUME_NONNULL_END
