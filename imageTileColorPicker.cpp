/*
*  File: imageTileColorPicker.cpp
*  Implements the image tile color picker for CPSC 221 PA2.
*
*/

#include "imageTileColorPicker.h"

ImageTileColorPicker::ImageTileColorPicker(PNG& otherimage) {
  // complete your implementation below
  img_other = otherimage;
}

HSLAPixel ImageTileColorPicker::operator()(PixelPoint p) {
  // complete your implementation below

  HSLAPixel *tile_pixel = img_other.getPixel(p.x % img_other.width(), p.y % img_other.height());
  p.color = *tile_pixel;

  
  return p.color;
}