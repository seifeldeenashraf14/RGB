

#ifndef RGB_INTERFACE_H_
#define RGB_INTERFACE_H_
#include "TIMER_interface.h"

typedef enum 
 {
 Red,	
 Green,
 Blue,	
 Orange,	
 Pink,
 Cyan,
 Magenta,	
 Yellow	,
 Black	,
 White,	
 Gray,	
 Light_Gray,
 Dark_gray,
 Total_Colors	
}Color_type;


void Switch_Colors (Color_type color_from ,Color_type color_to);
void Color_Choose(Color_type color);



#endif /* RGB_INTERFACE_H_ */