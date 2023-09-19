#include <stdio.h>
#include <math.h>
float main (){
            float perpendicular, base, hypotenuse, base_square, perpendicular_square, final_hypotenuse;
            scanf("%d",&perpendicular);
            scanf("%d",&base);
            base_square=base*base;
            perpendicular_square=perpendicular*perpendicular;
            hypotenuse=base_square+perpendicular_square;
          final_hypotenuse=sqrt(hypotenuse);
          printf("%f",final_hypotenuse);
          return 1;
}// end main
