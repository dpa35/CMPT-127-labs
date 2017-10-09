
void reverse(int arr[], unsigned int len){
	int i=0;
	int j=(len-1);
	int temp = 0;
	for(i=0;i<len;i++){
		if (i!=j){
		temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		j--;
		}	
	}
	return;
}
