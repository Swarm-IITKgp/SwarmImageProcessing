#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"

using namespace cv;

void readme();

int main( int argc, char** argv )
{
  if( argc != 2 )
  { readme(); return -1; }

  Mat img_1 = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );

  if( !img_1.data )
  { std::cout<< " --(!) Error reading images " << std::endl; return -1; }

  //-- Step 1: Detect the keypoints using SURF Detector
  // this is a threshold.
  int minHessian = 400;

  SurfFeatureDetector detector( minHessian );

  std::vector<KeyPoint> keypoints_1, keypoints_2;

  detector.detect( img_1, keypoints_1 );
 

  //-- Draw keypoints
  Mat img_keypoints_1; Mat img_keypoints_2;

  drawKeypoints( img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
  
  //-- Show detected (drawn) keypoints
  imshow("Keypoints 1", img_keypoints_1 );
 

  waitKey(0);

  return 0;
}

/** @function readme */
void readme()
{ std::cout << " Usage: ./SURF_detector <img1>" << std::endl; }
