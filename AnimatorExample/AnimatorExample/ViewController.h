//
//  ViewController.h
//  AnimatorExample
//
//  Created by Vengal on 18/01/17.
//  Copyright © 2017 Streamoid. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Animator/Animator.h>

@interface ViewController : UIViewController

@property (nonatomic, weak) IBOutlet UIButton *langBtn;

- (IBAction)openCameraButtonAction:(id)sender;
- (IBAction)selectLanguageButtonAction:(id)sender;

@end

