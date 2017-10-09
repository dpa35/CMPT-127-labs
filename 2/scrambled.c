int scrambled(unsigned int a[], unsigned int b[], unsigned int len){
	int x = 0;
	int y = 0;
	int count1 = 0;
	int count2 = 0;
	int testvalue =0;

	for(x=0; x<len;x++){
		testvalue = a[x];
		for(y=0; y<len; y++){
			if(testvalue==a[y]){
				count1++;
			}
		}
		for(y=0; y<len; y++){
			if(testvalue==b[y]){
				count2++;
			}
		}
		if(count1 != count2){
			return 0;
		}
	return 1;

	}
	
	
			
			
		
}
