//
//  BCManager.h
//  BugClipper
//
//  Created by Shwet Solanki on 18/11/14.
//  Copyright (c) 2014 BugClipper. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  InvokerType specifies how the bug needs to be reported, either Actively i.e by the Tester or Passively i.e by the End User
 */
typedef NS_ENUM(NSUInteger, InvokerType){
    /**
     *  Adds a invoker on the screen so that the tester can report the bugs easily
     */
    InvokerDeveloperMode,
    /**
     *  Used for Production build, when the developer wants to trigger BugClipper on click of a button from settings or some other event.
     */
    InvokerProductionMode,
};


@interface BCManager : NSObject
/**
 * initiateHandler block will be called whenever the BugClipper library initiates bug handling,
 * In case of Unity Games, it will be very useful to pause the game here.
 */
+(void)setWillInitiateBugReportingBlock:(void(^)(void))initiateHandler;

/**
 *  Executes the finishHandler block when the BugClipper Library is done with bug reporting.
 *  In case of Unity games, it will be very useful to resume the game here.
 *
 *  @param finishHandler
 */

+(void)setDidFinishBugReportingBlock:(void(^)(void))finishHandler;

/**
 *  Invoker type specifes how you want to invoke the bugclipper
 *
 *  @param invokerType - InvokerDeveloperMode (default) : a invoker view will be visible in all the viewcontroller (recommended
 for Tester/Development mode)
 - InvokerProductionMode : you need to add a menu item in your settings and on selection of that menu item you need to invoke showBugClipperMenu.
 */
+(void)setInvokerMode:(InvokerType)invokerType;

/**
 *  Launch the Bugclipper
 *
 *  @param licenseKey unique key provided by BugClipper
 *
 *  @return bool if the launch was successful
 */
+(BOOL)launchWithKey:(NSString *)licenseKey;

/**
 *  Launch the Bugclipper and specify the operation window
 *
 *  @param licenseKey unique key provided by BugClipper
 *  @param window     Specify the window to be used for taking snapshot, video recording, etc
 *
 *  @return bool if the launch was successful
 */
+(BOOL)launchWithKey:(NSString *)licenseKey attachTo:(UIWindow *)window;

/**
 *  Show the BugClipper Menu. Should be used only when InvokeMode is InvokeProductionMode.
 */
+(void)showBugClipperMenu;

/**
 *  Attaches the Bugclipper invoker to the new window, call only when you replace the current window, otherwise not required
 *  @param window
 */
+(void)attachToWindow:(UIWindow *)window;

/**
 *  EmailAdress to identify the user who is reporting the bug.
 *
 *  @param email Email address of the user
 */
+(void)setEmailAddress:(NSString *)email;

/**
 *  UserID to identify the user who is reporting the bug.
 *
 *  @param userID End User
 */
+(void)setUserID:(NSString *)userID;

/**
 *  Additional debug info if the developer want to add to the bug report
 *
 *  @param additionalInfo
 */
+(void)setAdditionalInfo:(NSString *)additionalInfo;

/**
 *  Base URL at which all the API calls will be made, URL address of the server
 *
 *  @param baseURL URL of the server
 */
+(void)setBaseURL:(NSString *)baseURL;

@end
