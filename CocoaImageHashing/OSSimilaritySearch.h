//
//  OSSimilaritySearch.h
//  CocoaImageHashing
//
//  Created by Andreas Meingast on 16/10/15.
//  Copyright © 2015 Andreas Meingast. All rights reserved.
//

#import "OSTypes+Internal.h"

@protocol OSSimilaritySearchDelegate <NSObject>

- (void)similaritySearch:(OSSimilaritySearch *)search didChangeProgress:(CGFloat)progress;

@end

@interface OSSimilaritySearch : NSObject

@property (nonatomic, weak, readwrite) id<OSSimilaritySearchDelegate> delegate;

NS_ASSUME_NONNULL_BEGIN

+ (instancetype)sharedInstance;

#pragma mark - Array & Stream Based Similarity Search

- (void)similarImagesWithProvider:(OSImageHashingProviderId)imageHashingProviderId
        withHashDistanceThreshold:(OSHashDistanceType)hashDistanceThreshold
            forImageStreamHandler:(OSTuple<OSImageId *, NSData *> * (^)())imageStreamHandler
                 forResultHandler:(void (^)(OSImageId * __unsafe_unretained leftHandImageId, OSImageId * __unsafe_unretained rightHandImageId))resultHandler;

- (NSArray<OSTuple<OSImageId *, OSImageId *> *> *)similarImagesWithProvider:(OSImageHashingProviderId)imageHashingProviderId
                                                  withHashDistanceThreshold:(OSHashDistanceType)hashDistanceThreshold
                                                      forImageStreamHandler:(OSTuple<OSImageId *, NSData *> * (^)())imageStreamHandler;

- (NSArray<OSTuple<OSImageId *, OSImageId *> *> *)similarImagesWithProvider:(OSImageHashingProviderId)imageHashingProviderId
                                                  withHashDistanceThreshold:(OSHashDistanceType)hashDistanceThreshold
                                                                  forImages:(NSArray<OSTuple<OSImageId *, NSData *> *> *)imageTuples;

#pragma mark - Result Conversion

- (NSDictionary<OSImageId *, NSSet<OSImageId *> *> *)dictionaryFromSimilarImagesResult:(NSArray<OSTuple<OSImageId *, OSImageId *> *> *)similarImageTuples;

NS_ASSUME_NONNULL_END

@end
