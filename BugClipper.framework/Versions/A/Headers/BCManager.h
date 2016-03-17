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

/**
 *  ShakeGestureEvent specifies how the sdk should behave when a shake gesture is recognized.
 */
typedef NS_ENUM(NSUInteger, ShakeGestureEvent){
    /**
     *  Show an action sheet with the options to report bug via text, screenshot or video.
     */
    ShakeGestureShowAllOptions,
    /**
     *  Takes a screenshot and proceeds to the annotation view.
     */
    ShakeGestureTakeScreenshot
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
 *  Enable / Disable Shake Gesture on Production Mode
 *
 *  @param shakeEnabled
 */
+(void)setShakeGestureEnabled:(BOOL)shakeEnabled;

/**
 *  Specifies the event which should be invoked when then ShakeGesture is invoked
 *
 *  @param event
 */
+(void)setShakeGestureEvent:(ShakeGestureEvent)event;

/**
 *  Show the BugClipper Menu. Should be used only when InvokeMode is InvokeProductionMode.
 */
+(void)showBugClipperMenu;

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
 *  Updates the Status bar
 */
+(void)setNeedsStatusBarAppearanceUpdate;

/**
 *  Set the value to YES if you are on Enterprise plan. Default value is NO
 *
 *  @param isEnterpriseMode
 */
+(void)setEnterpriseMode:(BOOL)isEnterpriseMode;

/**
 *  Base URL at which all the API calls will be made, URL address of the server only if you have your custom bugclipper dashboard configured.
 *
 *  @param baseURL URL of the server
 */
+(void)setBaseURL:(NSString *)baseURL;


@end
