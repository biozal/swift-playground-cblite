//
//  CBLVectorIndexTypes.h
//  CouchbaseLite
//
//  Copyright (c) 2024 Couchbase, Inc. All rights reserved.
//  COUCHBASE CONFIDENTIAL -- part of Couchbase Lite Enterprise Edition
//

NS_ASSUME_NONNULL_BEGIN

/**
 ENTERPRISE EDITION ONLY
 
 Scalar Quantizer encoding type.
*/
typedef NS_ENUM(uint32_t, CBLScalarQuantizerType) {
    kCBLSQ4 = 0, /* 4 bits per dimension */
    kCBLSQ6,     /* 6 bits per dimension */
    kCBLSQ8      /* 8 bits per dimension */
};

/**
 ENTERPRISE EDITION ONLY
 
 Distance metric type
*/
typedef NS_ENUM(uint32_t, CBLDistanceMetric) {
   kCBLDistanceMetricEuclidean = 0, /// Euclidean distance
   kCBLDistanceMetricCosine         /// Cosine distance
};

NS_ASSUME_NONNULL_END
