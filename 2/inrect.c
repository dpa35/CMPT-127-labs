
int InRectangle(float pt[2], float rect[4]){
	float largeY;
	float largeX;
	float smallY;
	float smallX;
	//find boundaries of rectangle
	if (rect[0]> rect[2]){
		largeX = rect[0];
		smallX = rect[2];
	}
	else if(rect[0]<rect[2]){
		largeX = rect[2];
		smallX = rect[0];
	}
	if(rect[1] > rect[3]){
		largeY = rect[1];
		smallY = rect[3];
	}
	else if (rect[1] < rect[3]){
		largeY = rect[3];
		smallY = rect[1];
	}
	//if point outside range, return 0
	if( pt[0]> largeX || pt[0] < smallX || pt[1]>largeY || pt[1] < smallY ){
		return 0;
	
	}
	return 1;
}
