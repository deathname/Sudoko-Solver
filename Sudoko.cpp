#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
lld sudo[111][111];

lld row(lld r,lld v){
	
	for(lld i=0;i<9;i++){
		if(sudo[r][i]==v){
			return 0;
		}
	}
	return 1;
}

lld col(lld c,lld v){
	
	for(lld i=0;i<9;i++){
		if(sudo[i][c]==v){
			return 0;
		}
	}
	return 1;
}

lld box(lld r,lld c,lld v){
	
	for(lld i=0;i<3;i++){
		for(lld j=0;j<3;j++){
			if(sudo[i+r][j+c]==v){
				return 0;
			}
		}
	}
	return 1;
}


lld check(lld r,lld c,lld v){
	return row(r,v) && col(c,v) && box(r-r%3,c-c%3,v);
}
void print(){
	for(lld i=0;i<9;i++){
		for(lld j=0;j<9;j++){
			cout<<sudo[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}


lld solve(lld x,lld y){
	
	if(x>=9){
		print();
		return 1;
	}
	
	if(sudo[x][y]!=0){
		
		if(y+1<9){
			solve(x,y+1);
		}
		else{
			solve(x+1,0);
		}
	}
	else{
		lld prev=sudo[x][y];
		for(lld i=1;i<=9;i++){
			
			if(check(x,y,i)){
				sudo[x][y]=i;
				lld a;
				if(y+1<9){
					a=solve(x,y+1);
				}
				else{
					a=solve(x+1,0);
				}	
				
				if(a==1){
					return 1;
				}
				sudo[x][y]=0;
			}	
		}
	}
	return 0;
}


int main(){
	
	for(lld i=0;i<9;i++){
		for(lld j=0;j<9;j++){
			cin>>sudo[i][j];	
		}
	}
	solve(0,0);
	
}
