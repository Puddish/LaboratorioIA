#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>

#include "image.h"

using namespace std;

// HW0 #3
// const Image& im: input image
// return the corresponding grayscale image
Image rgb_to_grayscale(const Image& im)
  {
  assert(im.c == 3); // only accept RGB images
  Image gray(im.w,im.h,1); // create a new grayscale image (note: 1 channel)
  
  // TODO: calculate the pixels of 'gray'
  
  for(int w = 0; w < im.w;w++){
    for(int h =0; h < im.h; h++){
      /*prendo i valore i pixel in corrispondenza di rosso, blue e verde*/
      float pixel_r = 0.299 * im(w,h,0);
      float pixel_g = 0.587 * im(w,h,1);
      float pixel_b = 0.114 * im(w,h,2);
      /*applico la formula per il luma*/
      float gray_pixel = pixel_r + pixel_g + pixel_b;
      gray(w,h,0)= gray_pixel;
    }
  }
  
  
  return gray;
  }



// Example function that changes the color of a grayscale image
Image grayscale_to_rgb(const Image& im, float r, float g, float b)
  {
  assert(im.c == 1);
  Image rgb(im.w,im.h,3);
  
  for(int q2=0;q2<im.h;q2++)for(int q1=0;q1<im.w;q1++)
    {
    rgb(q1,q2,0)=r*im(q1,q2);
    rgb(q1,q2,1)=g*im(q1,q2);
    rgb(q1,q2,2)=b*im(q1,q2);
    }
  
  return rgb;
  }




// HW0 #4
// Image& im: input image to be modified in-place
// int c: which channel to shift
// float v: how much to shift
void shift_image(Image& im, int c, float v)
  {
  assert(c>=0 && c<im.c); // needs to be a valid channel
  
  // TODO: shift all the pixels at the specified channel
  
  for(int w = 0; w < im.w;w++){
    for(int h =0; h < im.h; h++){
      im(w,h,c) += v;
      }
    }
  }
  

// HW0 #8
// Image& im: input image to be modified in-place
// int c: which channel to scale
// float v: how much to scale
void scale_image(Image& im, int c, float v)
  {
  assert(c>=0 && c<im.c); // needs to be a valid channel
  
  // TODO: scale all the pixels at the specified channel
    NOT_IMPLEMENTED();
  }

// HW0 #5
// Image& im: input image to be modified in-place
void clamp_image(Image& im)
  {
  // TODO: clamp all the pixels in all channel to be between 0 and 1
  
    for(int c = 0 ; c < im.c; c++){
      for(int w = 0; w < im.w; w++){
        for(int h =0; h < im.h; h++){
          if(im(w,h,c) >1) im(w,h,c) = 1;
          if(im(w,h,c) <0) im(w,h,c) = 0;
        }
      }
    }
  
  }

// These might be handy
float max(float a, float b, float c)
  {
  return max({a,b,c});
  }

float min(float a, float b, float c)
  {
  return min({a,b,c});
  }


// HW0 #6
// Image& im: input image to be modified in-place
void rgb_to_hsv(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  for(int w = 0 ; w < im.w; w++){
    for(int h = 0; h < im.h; h++){

          float r = im(w,h,0);
          float g = im(w,h,1);
          float b = im(w,h,2);
          float V = max(r,g,b);
          float C = V - min(r,g,b);
          float S = V == 0 ? 0 : C/V;
          float H;
          if(C == 0) H=0;
          else if(V == r) H = (g-b)/C;
          else if(V == g) H = (b-r)/C + 2;
          else if(V == b) H = (r-g)/C + 4;
          H = H < 0 ? (H/6)+1 : H/6;
          /*Notate che H = [0,1) e che dovrà essere circolare quando il valore supera l'1. Per questo si controlla se è negativo e si aggiunge 1 nel caso. */
          while(H<0) H++;
          im(w,h,0) = H;
          im(w,h,1) = S;
          im(w,h,2) = V;
      
    }
  }
  
  }

// HW0 #7
// Image& im: input image to be modified in-place
void hsv_to_rgb(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  for(int w = 0 ; w < im.w; w++){
    for(int h =0 ; h < im.h; h++){
      float H = im(w,h,0);
      float S = im(w,h,1);
      float V = im(w,h,2);

      float C = V * S;
      float X = C * (1- abs(fmod(6*H ,2)-1));
      float m = V - C;
      
      float R,G,B;

      if(H >= 0 && H < (float)1/(float)6){
        R = C;
        G = X;
        B = 0;
      }
      else if(H >= (float)1/(float)6 && H < (float)2/(float)6){
        R = X;
        G = C;
        B = 0;
      }
      else if(H >= (float)2/(float)6 && H < (float)3/(float)6){
        R = 0;
        G = C;
        B = X;
      }
      else if(H >= (float)3/(float)6 && H < (float)4/(float)6){
        R = 0;
        G = X;
        B = C;
      }
      else if(H >= (float)4/(float)6 && H < (float)5/(float)6){
        R = X;
        G = 0;
        B = C;
      }
      else{
        R = C;
        G = 0;
        B = X;
      }
    im(w,h,0) = R + m; 
    im(w,h,1) = G + m;
    im(w,h,2) = B + m;

    }
  }  

  
  }

// HW0 #9
// Image& im: input image to be modified in-place
void rgb_to_lch(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from RGB format to LCH format
  
  
  NOT_IMPLEMENTED();
  
  }

// HW0 #9
// Image& im: input image to be modified in-place
void lch_to_rgb(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from LCH format to RGB format
  
  NOT_IMPLEMENTED();
  
  }



// Implementation of member functions
void Image::clamp(void) { clamp_image(*this); }
void Image::shift(int c, float v) { shift_image(*this,c,v); }
void Image::scale(int c, float v) { scale_image(*this,c,v); }

void Image::HSVtoRGB(void) { hsv_to_rgb(*this); }
void Image::RGBtoHSV(void) { rgb_to_hsv(*this); }
void Image::LCHtoRGB(void) { lch_to_rgb(*this); }
void Image::RGBtoLCH(void) { rgb_to_lch(*this); }
