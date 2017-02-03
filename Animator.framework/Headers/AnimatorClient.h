//
//  AnimatorClient.h
//  Animator
//
//  Created by Vengal on 17/01/17.
//  Copyright © 2017 Streamoid. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AnimatorCustomParams.h"

/**
 * @header
 * @brief AnimatorClient Constants and Notifications
 * @discussion Example to use Constants - Animator constants, these constants used to retieve information from the notification userInfo,for example: [notification.userInfo objectForKey:kAnimatorIsMatchFound]; Detailed information is provided below with each constant.
 * Example to use Notifications - Animator notification name constants, these constants may be used as name values in addObserver method calls,for example: [[NSNotificationCenter defaultCenter] addObserver:self selector:\@selector(irSearchReceieved:) name:kAnimatorClientIRSearch object:nil]; Detailed information is provided below with each notification.
 */

/*!
 * @brief IRSearch -- Dispatched when the API received response or failed to receive response for IR search.
 */
extern NSString * _Nonnull const kAnimatorClientIRSearch;

/*!
 * @brief HotspotClicked -- Dispatched when the user dismissed the hotspot popup view.
 */
extern NSString * _Nonnull const kAnimatorClientHotspotClicked;


/*!
 * @brief kAnimatorIsMatchFound -- Key for to know whether match received on not in IR search which is in kAnimatorClientIRSearch notification's user info.
 * @discussion - Use this constant as below.
 * @code
 * NSNumber *matchFound = (NSNumber *)[notification.userInfo objectForKey:kAnimatorIsMatchFound]
 * @endCode
 */
extern NSString * _Nullable const kAnimatorIsMatchFound;

/*!
 * @brief kAnimatorHotspotIds -- Key for the hotspot ids received in IR Search which is in kAnimatorClientIRSearch notification's user info.
 * @discussion - Use this constant as below.
 * @code
 * NSArray *hotspotIds = (NSArray *)[notification.userInfo objectForKey:kAnimatorHotspotIds]
 * @endCode
 */
extern NSString * _Nullable const kAnimatorHotspotIds;

/*!
 * @brief kAnimatorQueryImageData -- Key for the image queryed to get match IR Search which is in kAnimatorClientIRSearch notification's user info.
 * @discussion - Use this constant as below.
 * @code
 * NSData *imageData = (NSData *)[notification.userInfo objectForKey:kAnimatorQueryImageData]
 * @endCode
 */
extern NSString * _Nullable const kAnimatorQueryImageData;

/*!
 * @brief kAnimatorClickedHotspotId -- Key for the clicked hotspot view's id which is in kAnimatorClientHotspotClicked notification's user info.
 * @discussion - Use this constant as below.
 * @code
 * NSString *hotspotId = (NSString *)[notification.userInfo objectForKey:kAnimatorClickedHotspotId]
 * @endCode
 */
extern NSString * _Nullable const kAnimatorClickedHotspotId;

/*!
 * @brief kAnimatorClickedHotspotOption -- Key for the option selected hotspot view's popup view which is in kAnimatorClientHotspotClicked notification's user info.
 * @discussion - Use this constant as below.
 * @code
 * NSString *hotspotOption = (NSString *)[notification.userInfo objectForKey:kAnimatorClickedHotspotOption]
 * @endCode
 */
extern NSString * _Nullable const kAnimatorClickedHotspotOption;



/*!
 * @brief kAnimatorIsNotificationEnabled -- Key used to enable or disable notifications.
 * If Yes it will enable notifications and user has to listen to them.
 * @discussion - Use this constant as below.
 * @code
 * [dictionary setObject:[NSNumber numberWithBool:YES] forKey:kAnimatorIsNotificationEnabled];
 * @endCode
 */
extern NSString * _Nullable const kAnimatorIsNotificationEnabled;


/*!
 * @typedef AnimatorSDKLanguage -- Language enum to specify which language to use in SDK.
 * @discussion - Set this enum value to pass in setLanguage: method, Use this enum as below.
 * @code
 * [AnimatorClient setLanguage:eAnimatorLanguageSpanish];
 * @endCode
 */

typedef enum : NSInteger
{
    eAnimatorLanguageEnglish,
    eAnimatorLanguageSpanish,
    eAnimatorLanguageRussian,
    eAnimatorLanguageChineseSimplified,
    eAnimatorLanguageChineseTraditional,
    eAnimatorLanguageItalian,
    eAnimatorLanguageGerman
}AnimatorSDKLanguage;



/*!
 * @class AnimatorClient
 * @discussion Main class for SDK to intialize and interact with client.
 */

@interface AnimatorClient : NSObject

/*!
 * @breif This method returms a signleton instance of AnimatorClient. Clients can call all the instance methods available in AnimatorClient class on singleton instance.
 *
 * @discussion To use it, simply call @code [AnimatorClient sharedClient]; @endcode
 *
 * @return shared instace of a AnimatorClient object.
 */
+ (AnimatorClient * _Nullable)sharedClient;

/*!
 * @breif Used to initialize SDK for a client.
 *
 * @discussion To use it, simply call
 * @code
 * [AnimatorClient initializeWithClientName:@"abz" andClientToken:@"2A232-312"];
 * @endcode
 *
 * @param clientName : Name of the client
 * @param clientToken : Token of the client, which is provided by streamoid.
 */
+ (void)initializeWithClientName:(NSString * _Nonnull)clientName andClientToken:(NSString * _Nonnull)clientToken;

/*!
 * @breif Sets the language used in SDK. If not set will use the App default language.
 *
 * @discussion Users of the sdk would call this method before calling  -(void)showCameraScreen method :
 * @code [[AnimatorClient sharedClient] setAnimatorSDKLanguage:AnimatorLanguageSpanish]; @endcode
 *
 */
- (void)setLanguage:(AnimatorSDKLanguage )language;

/*!
 * @breif Shows the camera screen to proceed futher for IR search.
 *
 * @discussion Users of the sdk would call this method on a singleton AnimatorClient instance :
 * @code [[AnimatorClient sharedClient] showCameraScreen]; @endcode
 *
 */
- (void)showCameraScreen;

/*!
 * @breif AnimatorClient's AnimatorCustomParams object, which are used to customise SDK. If user doesn't want to customize, simply pass nil as params object
 *
 * @discussion Users of the sdk would set this object value before calling  -(void)showCameraScreen method :
 * @code [AnimatorClient sharedClient].customParams = customParamObject;  or [[AnimatorClient sharedClient] setCustomParams:customParamObject]; @endcode
 *
 */

@property (nonatomic, strong) AnimatorCustomParams * _Nullable customParams;


@end
