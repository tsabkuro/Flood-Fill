/*
*  File: censorColorPicker.cpp
*  Implements the censor color picker for CPSC 221 PA2.
*
*/

#include "censorColorPicker.h"

#include <math.h> // gives access to sqrt function

/*
*  Useful function for computing the Euclidean distance between two PixelPoints
*/
double PointDistance(PixelPoint a, PixelPoint b) {
  unsigned int diff_x, diff_y;
  if (a.x > b.x)
    diff_x = a.x - b.x;
  else
    diff_x = b.x - a.x;
  if (a.y > b.y)
    diff_y = a.y - b.y;
  else
    diff_y = b.y - a.y;
  return sqrt(diff_x * diff_x + diff_y * diff_y);
}

CensorColorPicker::CensorColorPicker(unsigned int b_width, PixelPoint ctr, unsigned int rad, PNG& inputimage)
{
  // complete your implementation below
  blockwidth = b_width; // width of a mosaic block in pixels.
  center = ctr;         // middle/center point of mosaic area
  radius = rad;         // maximum pixel distance away from center where the mosaic color will be applied
  img = inputimage;     // Original image used in flood fill algorithm

  blockyimg = PNG(img);

  for (unsigned x_start = 0; x_start < blockyimg.width(); x_start += blockwidth) {
    for (unsigned y_start = 0; y_start < blockyimg.height(); y_start += blockwidth) {

      double h_avg = 0;
      double s_avg = 0;
      double l_avg = 0;
      double a_avg = 0;

      if (x_start + blockwidth <= blockyimg.width()) {
        for (unsigned x = x_start; x < x_start + blockwidth; x++) {
          if (y_start + blockwidth <= blockyimg.height()) {
            for (unsigned y = y_start; y < y_start + blockwidth; y++) {
              HSLAPixel *pixel = blockyimg.getPixel(x, y);
              h_avg += pixel->h;
              s_avg += pixel->s;
              l_avg += pixel->l;
              a_avg += pixel->a;
            }
          } else {
            for (unsigned y = y_start; y < blockyimg.height(); y++) {
              HSLAPixel *pixel = blockyimg.getPixel(x, y);
              h_avg += pixel->h;
              s_avg += pixel->s;
              l_avg += pixel->l;
              a_avg += pixel->a;
            }
          }
          
        }
      } else {
        for (unsigned x = x_start; x < blockyimg.width(); x++) {
          if (y_start + blockwidth < blockyimg.height()) {
            for (unsigned y = y_start; y < y_start + blockwidth; y++) {
              HSLAPixel *pixel = blockyimg.getPixel(x, y);
              h_avg += pixel->h;
              s_avg += pixel->s;
              l_avg += pixel->l;
              a_avg += pixel->a;
            }
          } else {
            for (unsigned y = y_start; y < blockyimg.height(); y++) {
              HSLAPixel *pixel = blockyimg.getPixel(x, y);
              h_avg += pixel->h;
              s_avg += pixel->s;
              l_avg += pixel->l;
              a_avg += pixel->a;
            }
          }
          
        }
      }

      h_avg = h_avg / (blockwidth * blockwidth);
      s_avg = s_avg / (blockwidth * blockwidth);
      l_avg = l_avg / (blockwidth * blockwidth);
      a_avg = a_avg / (blockwidth * blockwidth);

      if (x_start + blockwidth < blockyimg.width()) {
        for (unsigned x = x_start; x < x_start + blockwidth; x++) {
          if (y_start + blockwidth < blockyimg.height()) {
            for (unsigned y = y_start; y < y_start + blockwidth; y++) {
              HSLAPixel *pixel = blockyimg.getPixel(x, y);
              pixel->h = h_avg;
              pixel->s = s_avg;
              pixel->l = l_avg;
              pixel->a = a_avg;
            }
          } else {
            for (unsigned y = y_start; y < blockyimg.height(); y++) {
              HSLAPixel *pixel = blockyimg.getPixel(x, y);
              pixel->h = h_avg;
              pixel->s = s_avg;
              pixel->l = l_avg;
              pixel->a = a_avg;
            }
          }
          
        }
      } else {
        for (unsigned x = x_start; x < blockyimg.width(); x++) {
          if (y_start + blockwidth < blockyimg.height()) {
            for (unsigned y = y_start; y < y_start + blockwidth; y++) {
              HSLAPixel *pixel = blockyimg.getPixel(x, y);
              pixel->h = h_avg;
              pixel->s = s_avg;
              pixel->l = l_avg;
              pixel->a = a_avg;
            }
          } else {
            for (unsigned y = y_start; y < blockyimg.height(); y++) {
              HSLAPixel *pixel = blockyimg.getPixel(x, y);
              pixel->h = h_avg;
              pixel->s = s_avg;
              pixel->l = l_avg;
              pixel->a = a_avg;
            }
          }
          
        }
      }
    }
  }
}

HSLAPixel CensorColorPicker::operator()(PixelPoint p)
{
  // complete your implementation below


  if (PointDistance(center, p) <= radius) {
      HSLAPixel *tile_pixel = tile_pixel = blockyimg.getPixel(p.x, p.y);
      p.color = *tile_pixel;
  } else {
      HSLAPixel *tile_pixel = tile_pixel = img.getPixel(p.x, p.y);
      p.color = *tile_pixel;
  }

  return p.color;
}
