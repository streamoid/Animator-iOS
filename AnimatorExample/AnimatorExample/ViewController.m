//
//  ViewController.m
//  AnimatorExample
//
//  Created by Vengal on 18/01/17.
//  Copyright © 2017 Streamoid. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kAnimatorClientIRSearch object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kAnimatorClientHotspotClicked object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(animatorIRSearchResponse:) name:kAnimatorClientIRSearch object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(animatorHotspotClicked:) name:kAnimatorClientHotspotClicked object:nil];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)openCameraButtonAction:(id)sender {
    [[AnimatorClient sharedClient] showCameraScreen];
}

- (void)animatorIRSearchResponse:(NSNotification *)notification {
    NSLog(@"match received : %@",[notification.userInfo objectForKey:kAnimatorIsMatchFound]);
}

- (void)animatorHotspotClicked:(NSNotification *)notification {
    NSLog(@"hotspot clicked : %@",notification.userInfo);
}

@end
