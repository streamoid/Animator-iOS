//
//  AnimatorCustomParams.h
//  Animator
//
//  Created by Vengal on 31/01/17.
//  Copyright © 2017 Streamoid. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AnimatorCustomParams : NSObject

@property (nonatomic, assign) BOOL isNotificationEnabled;

@property (nonatomic, strong) NSString *cameraRecentsIcon;
@property (nonatomic, strong) NSString *cameraCaptureIcon;
@property (nonatomic, strong) NSString *cameraFlashOnIcon;
@property (nonatomic, strong) NSString *cameraFlashOffIcon;
@property (nonatomic, strong) NSString *cameraCloseIcon;
@property (nonatomic, strong) NSString *cameraInfoIcon;
@property (nonatomic, strong) NSString *cameraBottomBarHexColor;
@property (nonatomic, strong) NSString *cameraActivityIndicatorViewHexColor;

@property (nonatomic, strong) NSString *topBarHexColor;
@property (nonatomic, strong) NSString *hotspotInnerCircleHexColor;
@property (nonatomic, strong) NSString *hotspotOuterCircleHexColor;
@property (nonatomic, strong) NSString *backArrowIcon;
@property (nonatomic, strong) NSString *closeArrowIcon;
@property (nonatomic, strong) NSString *topArrowIcon;
@property (nonatomic, strong) NSString *irMatchInfoIcon;

@property (nonatomic, strong) NSString *moreInfoIcon;
@property (nonatomic, strong) NSString *videoIcon;
@property (nonatomic, strong) NSString *audioIcon;
@property (nonatomic, strong) NSString *makeCallIcon;
@property (nonatomic, strong) NSString *photoGalleryIcon;
@property (nonatomic, strong) NSString *buyNowIcon;

//Icons for Regular Ads ...
@property (nonatomic, strong) NSString *regularAdMoreInfoIcon;
@property (nonatomic, strong) NSString *regularAdVideoIcon;
@property (nonatomic, strong) NSString *regularAdAudioIcon;
@property (nonatomic, strong) NSString *regularAdMakeCallIcon;
@property (nonatomic, strong) NSString *regularAdPhotoGalleryIcon;
@property (nonatomic, strong) NSString *regularAdBuyNowIcon;

@end
