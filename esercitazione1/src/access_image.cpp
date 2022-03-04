#include "image.h"


// HW0 #1
// const Image& im: input image
// int x,y: pixel coordinates
// int ch: channel of interest
// returns the 0-based location of the pixel value in the data array
int pixel_address(const Image& im, int x, int y, int ch)
  {
  /*
    Formula ottenuta da https://en.wikipedia.org/wiki/Row-_and_column-major_order#Address_calculation_in_general
    tiene conto pero' del fatto che si accede  all'immagine in formato CHW.
  */
  return im.h * im.w *ch + im.w*y + x;
  }

// HW0 #1
// const Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
// returns the value of the clamped pixel at channel ch
float get_clamped_pixel(const Image& im, int x, int y, int ch)
  {

    /*controlliamo che siamo nei range,in tal caso facciamo clamping,avrei potuto fare la stessa
    operazione con degli if inline ma cosi rimane piu' leggibile*/
    if(x >= im.w) x = im.w - 1;
    else if(x < 0) x = 0;

    if(y >= im.h) y = im.h - 1;
    else if(y < 0) y = 0;

    if(ch >= im.c) ch = im.c -1;
    else if(ch < 0) ch = 0;
   
    return im(x,y,ch);
  }


// HW0 #1
// Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
void set_pixel(Image& im, int x, int y, int c, float value)
  {
  if(x >= im.w || y >= im.h || c >= im.c) return;
  if(x < 0 || y < 0 || c < 0) return;
  im(x,y,c) = value;
  
  }



// HW0 #2
// Copies an image
// Image& to: destination image
// const Image& from: source image
void copy_image(Image& to, const Image& from)
  {
  // allocating data for the new image
  to.data=(float*)calloc(from.w*from.h*from.c,sizeof(float));
  to.c=from.c;
  
  // TODO: populate the remaining fields in 'to' and copy the data
  // You might want to check how 'memcpy' function works
  to.w = from.w;
  to.h = from.h;
  //Alternativamente la struct fornisce il metodo size
  memcpy(to.data,from.data,from.w*from.h*from.c*sizeof(float));
  
  }
