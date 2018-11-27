//
//  ViewController.m
//  AnimatorExample
//
//  Created by Vengal on 18/01/17.
//  Copyright © 2017 Streamoid. All rights reserved.
//

#import "ViewController.h"
#import <SafariServices/SafariServices.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kAnimatorClientIRSearch object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kAnimatorClientHotspotClicked object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kAnimatorClientHotspotOptionClicked object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(animatorIRSearchResponse:) name:kAnimatorClientIRSearch object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(animatorHotspotClicked:) name:kAnimatorClientHotspotClicked object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(animatorHotspotOptionClicked:) name:kAnimatorClientHotspotOptionClicked object:nil];

    [[AnimatorClient sharedClient] setLanguage:eAnimatorLanguageEnglish];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)openCameraButtonAction:(id)sender {
    [[AnimatorClient sharedClient] showCameraScreen];
}

- (IBAction)selectLanguageButtonAction:(id)sender {
    UIAlertController *actionSheetAC = [UIAlertController alertControllerWithTitle:@"Change Language" message:nil preferredStyle:UIAlertControllerStyleActionSheet];
    [actionSheetAC addAction:[UIAlertAction actionWithTitle:@"English" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [[AnimatorClient sharedClient] setLanguage:eAnimatorLanguageEnglish];
        [self.langBtn setTitle:@"English" forState:UIControlStateNormal];
    }]];
    [actionSheetAC addAction:[UIAlertAction actionWithTitle:@"Spanish" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [[AnimatorClient sharedClient] setLanguage:eAnimatorLanguageSpanish];
        [self.langBtn setTitle:@"Spanish" forState:UIControlStateNormal];
    }]];
    [actionSheetAC addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }]];
    [self presentViewController:actionSheetAC animated:YES completion:nil];
}

- (void)animatorIRSearchResponse:(NSNotification *)notification {
    NSLog(@"match received : %@",[notification.userInfo objectForKey:kAnimatorIsMatchFound]);
}

- (void)animatorHotspotClicked:(NSNotification *)notification {
    NSLog(@"hotspot clicked : %@",notification.userInfo);
}

- (void)animatorHotspotOptionClicked:(NSNotification *)notification {
    NSLog(@"hotspot option clicked : %@",notification.userInfo);
    if([notification.userInfo[kAnimatorClickedHotspotOption] isEqualToString:@"Buy it now"] ||
       [notification.userInfo[kAnimatorClickedHotspotOption] isEqualToString:@"Comprar"] ){
        NSString* urlStr = notification.userInfo[kAnimatorClickedHotspotOptionValue];
        NSURL* the_url = [NSURL URLWithString:urlStr];
        SFSafariViewController *svc = [[SFSafariViewController alloc] initWithURL:the_url];
        [(UINavigationController*)[[UIApplication sharedApplication].keyWindow.rootViewController presentedViewController] pushViewController:svc animated:YES];
    }
}

@end
