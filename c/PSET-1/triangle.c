#include <stdio.h>
#include <math.h>

int main() {

	double v1x;
	double v1y;
	double v2x;
	double v2y;
	double v3x;
	double v3y;

	printf("Please Enter Each Point in the following format: X Y \n");
	
	printf("Point 1: \n");
	scanf("%lf %lf", &v1x, &v1y);
	
	printf("Point 2: \n");
	scanf("%lf %lf", &v2x, &v2y);
	
	printf("Point 3: \n");
	scanf("%lf %lf", &v3x, &v3y);

	double s1 = sqrt(((v2x - v1x) * (v2x - v1x)) + ((v2y - v1y) * (v2y - v1y)));
	double s2 = sqrt(((v3x - v2x) * (v3x - v2x)) + ((v3y - v2y) * (v3y - v2y)));
	double s3 = sqrt(((v3x - v1x) * (v3x - v1x)) + ((v3y - v1y) * (v3y - v1y)));

	printf("Side lengths: %lf %lf %lf \n", s1, s2, s3);


	if (s1 != s2 && s2 != s3 && s1 != s3) {

		printf("Scalene \n");

	}
	else if ( (s1 == s2 && s2 != s3) || (s2 == s3 && s2 != s1) || (s1 == s3 && s3 != s2 ) ) {

		printf("Isosceles \n");

	}
	else if (s1 == s2 == s3) {

		printf("Equilateral \n");

	}
	else if (s1 + s2 <= s3) {

		printf("Not possible \n");

	}
	else {

		printf("Error \n");

	}

	return 0;

}

