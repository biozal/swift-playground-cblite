//
//  CBLVectorIndexConfiguration.h
//  CouchbaseLite
//
//  Copyright (c) 2024 Couchbase, Inc. All rights reserved.
//  COUCHBASE CONFIDENTIAL -- part of Couchbase Lite Enterprise Edition
//

#import <CouchbaseLite/CBLIndexConfiguration.h>
#import <CouchbaseLite/CBLVectorEncoding.h>
#import <CouchbaseLite/CBLVectorIndexTypes.h>

NS_ASSUME_NONNULL_BEGIN

/**
 ENTERPRISE EDITION ONLY
 
 Configuration for creating vector indexes.
*/
@interface CBLVectorIndexConfiguration : CBLIndexConfiguration

/** 
 The SQL++ expression returning a vector which is an array of numbers 
*/
@property (nonatomic, readonly) NSString* expression;

/** 
 The number of vector dimensions. */
@property (nonatomic, readonly) unsigned int dimensions;

/** 
 The number of centroids which is the number buckets to partition the vectors in the index. 
*/
@property (nonatomic, readonly) unsigned int centroids;

/** 
 Vector encoding type. The default value is 8-bits Scalar Quantizer. 
*/
@property (nonatomic) CBLVectorEncoding* encoding;

/** 
 Distance Metric type. The default value is euclidean. 
*/
@property (nonatomic) CBLDistanceMetric metric;

/** 
 The minium number of vectors for training the index, an initial process for preparing an index based on the characteristics of the vectors to be indexed. 
 Prior training, the full table scan will be peformed when the vector_match() function is used in the query.

 The default value is 25 times number of centroids.The number must be more than zero and not greater than maxTrainingSize. 
 An invalid argument error will be thrown when creating the index if an invalid value is used.
*/
@property (nonatomic) unsigned int minTrainingSize;

/** The max number of vectors used when trainning the index. The default
    value is 256 times number of centroids. The number must be more than zero
    and not less than minTrainingSize. An invalid argument will be thrown
    when creating the index if an invalid value is used. 
*/

@property (nonatomic) unsigned int maxTrainingSize;

/**
 Initializes the CBLVectorIndexConfiguration object.
 
 @param expression The SQL++ expression returning a vector which is an array of numbers.
 @param dimensions  The number of dimensions of the vectors to be indexed. The vectors that do not have the same dimensions
                   specified in the config will not be indexed. The dimensions must be between 2 and 2048, inclusive
 @param centroids The number of centroids which is the number buckets to partition the vectors in the index. The number of
                  centroids will be based on the expected number of vectors to be indexed; one suggested rule is to use
                  the square root of the number of vectors. The centroids must be between 1 and 64000 inclusively.
 @return The CBLVectorIndexConfiguration object.
 */
- (instancetype)initWithExpression: (NSString*)expression
                        dimensions: (unsigned int)dimensions
                         centroids: (unsigned int)centroids;

@end

NS_ASSUME_NONNULL_END
