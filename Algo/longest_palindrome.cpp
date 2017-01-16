//============================================================================
// Name        : longest_palindrome.cpp
// Author      : Vedahari
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


/*
 * Method 1: simplest algorithm O(N*N)
 */

bool is_palindrome_odd(string s,int start, int end)
{
	bool result = true;
	int mid = (end-start)/2;
	for (int i=0;i<mid;i++){
		if (s[start+i]!=s[end-i]){
			result = false;
			break;
		}
	}
	return result;
}

bool is_palindrome_even(string s,int start, int end)
{
	bool result = true;
	int mid = (end-start)/2;
	for (int i=0;i<=mid;i++){
		if (s[start+i]!=s[end-i]){
			result = false;
			break;
		}
	}
	return result;
}


bool is_palindrome(string s, int start, int end){
	bool result=false;
	if (end<start){
		return result;
	}
	else if ((end-start)%2==0){
		result = is_palindrome_odd(s,start,end);
	}
	else{
		result = is_palindrome_even(s,start,end);
	}
	return result;
}

void print_string(string s, int start,int end){
	for(int i=start;i<=end;i++){
		cout<<s[i];
	}
	cout<<endl;
}

void find_longest_palindrome(string s){
	int curr_maxi=0;
	int prev_maxi=0;
	int start=0;int end=0;
	for(int i=0;i<s.size();i++){
		for(int j=i;j<s.size();j++){
			if(is_palindrome(s,i,j)){
				curr_maxi=max(prev_maxi,j-i);
				if (curr_maxi!=prev_maxi){
					start=i;
					end = j;
					prev_maxi=curr_maxi;
				}
			}
		}
	}
	cout<<"\n Printing the longest palindrome \n";
	print_string(s,start,end);
}
/*
End of Method 1
*/



int main(){
	find_longest_palindrome("abaxabaxabbbababababbababbabbababababbaaaaaabbaababaaaaaaaa");
	return 0;
}
