//
//  AnimatorClient.h
//  Animator
//
//  Created by Vengal on 17/01/17.
//  Copyright © 2017 Streamoid. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * @header
 * @brief AnimatorClient Constants and Notifications
 * @discussion
 */

/*!
 * @class AnimatorClient
 * @discussion Main class for SDK to intialize and interact with client.
 */

@interface AnimatorClient : NSObject

/*!
 * @breif This method creates a shared instance object of a AnimatorClient class.
 *
 * @discussion To use it, simply call @code [AnimatorClient sharedClient]; @endcode
 *
 * @return shared instace of a AnimatorClient object.
 */
+ (AnimatorClient * _Nullable)sharedClient;


/*!
 * @breif Shows the camera screen to proceed futher for visual search.
 *
 * @discussion Users of the sdk would call this method on a singleton AnimatorClient instance :
 * @code [[AnimatorClient sharedClient] showCameraScreen]; @endcode
 *
 */
- (void)showCameraScreen;

@end
