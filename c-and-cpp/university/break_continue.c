#include <stdio.h>
main()
{int n;
  for(n=1; n<50; n++)
	{
		if(n%3 != 0)
		 break;
		//continue;
		printf("%d\n", n);
	}

}