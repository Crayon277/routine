/*************************************************************************
	> File Name: errno.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 30 22:58:31 2015
 ************************************************************************/

#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno ;

int main (){

	   FILE * pf;
	      int errnum;
			 printf("now errno is %d \n",errno);
		     pf = fopen ("unexist.txt", "rb");
			 printf("now errno is %d \n",errno);
			    if (pf == NULL)
					   {

							 errnum = errno;
							   fprintf(stderr, "Value of errno: %d\n", errno);
									         perror("Error printed by perror");
											       fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
												      }
				   else
					      {

							        fclose (pf);
									   }
				      return 0;
}

