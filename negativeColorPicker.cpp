/*
*  File: negativeColorPicker.cpp
*  Implements the negative color picker for CPSC 221 PA2.
*
*/

#include "negativeColorPicker.h"

NegativeColorPicker::NegativeColorPicker(PNG& inputimg)
{
  // complete your implementation below
  img = inputimg;
}

HSLAPixel NegativeColorPicker::operator()(PixelPoint p)
{
  // complete your implementation below
  HSLAPixel *pixel = img.getPixel(p.x, p.y);
  pixel->h = std::fmod((pixel->h + 180),360);
  pixel->l = 1.0 - pixel->l;
  return *pixel;
}
