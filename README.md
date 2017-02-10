# Animator iOS SDK Releases

[![N|Solid](http://www.streamoid.com/images/logo-white.png)](http://www.streamoid.com/)

This repository contains binary distributions of Animator iOS framework.

If you have any questions, comments, or issues related to Animator, Please contact the team by emailing streamoid.support@streamoid.com.

### Animator

Animator iOS SDK provided by Streamoid Technologies, acts as a bridge between offline advertisements and purchasing those products online

Imagine a scenario where you see some product advertisement in a newspaper ad or in a product catalogue, feel like knowing more about that product or buying it online. Animator iOS SDK solves the exact same problem.

If the advertisement is Animator enabled, user can click on the product image using the camera in homescreen, unlock many of animator features like : 
- Watching a video related to that product
- Buy that product online by navigating to the product's webpage
- Call the shop/brand directly in 1 click
- Listen to a promo audio clip
- View more images of the product

### Installation

Animator can be installed directly into your application by importing a framework or via CocoaPods. Quick installation instructions are provided below for reference.

##### CocoaPods Installation:

The recommended path for installation is CocoaPods. CocoaPods provides a simple, versioned dependency management system that automates the tedious and error prone aspects of manually configuring libraries and frameworks. You can add Animator to your project via CocoaPods by doing the following :

```sh
$ sudo gem install cocoapods
$ pod setup
```
Now create a Podfile in the root of your project directory and add the following:
```sh
pod 'Streamoid-Animator'
```
Complete the installation by executing:
```sh
$ pod install
```
These instructions will setup your local CocoaPods environment and import Animator into your project. Once this has completed, test your installation by referring to the Verifying Animator Configuration section below.

##### Framework Installation
Download the appropriate build artifact from this repository and add it to your application:

- Drag and drop the framework onto your project, instructing Xcode to copy items into your destination group's folder.
- Add run script phase to build phase: 
- Go to "Build Phase" section of your target settings.
- Click on the + button in the top left and select New Run Script Phase.
- In the script text input box paste the following snippet:

``` bash ${SRCROOT}/Animator.framework/strip-framework.sh```

Build and run your project to verify installation was successful. Once you have completed a successful build, refer to the Verifying Animator Configuration section below for details on how to test your setup.

### Configuration
- Disable App Transport Security(ATS) to support http : 
- In iOS9 and Xcode 7, Apple requires that all network connections use https. This will block some of the http connections we are making inside framework. So, the following must be added to your info.plist file to support http connections:
```sh 
<key>NSAppTransportSecurity</key>
<dict>
<key>NSAllowsArbitraryLoads</key>
<true/>
</dict>
```
- Enable permission to support camera : 
- In iOS10 and Xcode 8, Apple requires permission to use came and photo library. So, the following must be added to your info.plist filte to use camera and photo library:
```sh 
<key>NSCameraUsageDescription</key>
<value>Uses Camera </value>

```

### Verifying Animator Configuration

Once you have finished installing Animator via CocoaPods or framework, you can test your configuration by importing the headers and connecting a client to the Animator cloud. To do so, edit your view controller   to include the code below (note that you must substitute the client name and client token placeholder text with your actual values, in order to get these values please contact us at streamoid.support@streamoid.com):

```sh
#import <Animator/Animator.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
[AnimatorClient initializeWithClientName:CLIENT_NAME andClientToken:CLIENT_TOKEN];
}
```
Launch your application and verify that the connection is successful. You are now ready to begin exact search.

### Use your preferred language

Animator Framework supports multiple languages. As of now, English, Spanish, Chinese (Simplified), Chinese (Traditional), Italian, German are supported. Many more to come...
It is optional to set the language. If no language is set, we use the default language used by app.
After initializing an animator client in your application, you can specify the language you need to see the framework by using the following method in framework:

```sh
+ (void)setLanguage:(AnimatorSDKLanguage )language;
```
You can change the preferred language any number of times after initializing. On calling `showCameraScreen` method to capture some image using the framwork, it can be seen that all screens in framework will have the language you have set previously.

### Customize the framework

Animator Framework supports customization. As of now user can customise icons and background colours. Many more to come...
It is optional to do customization. If no custom params are set, we use the default icons and colours in SDK.
After initializing an animator client in your application, you can specify the custom params you need to see the framework by using the following in framework:

```sh
AnimatorCustomParams *customParams = [[AnimatorCustomParams alloc] init];
customParams.isNotificationEnabled = YES;
customParams.hotspotInnerCircleHexColor = @"#FF00FF";
customParams.hotspotOuterCircleHexColor = @"#006400";
[[AnimatorClient sharedClient] setCustomParams:customParams];
```
You can set the custom params any number of times after initializing. On calling `showCameraScreen` method to capture some image using the framwork, it can be seen that all icons and background colors in framework will have the custom values.

### Open Animator framework's Camera

```sh
[[AnimatorClient sharedClient] showCameraScreen];

### Contact

You can reach the Streamoid team at any time by emailing streamoid.support@streamoid.com.
