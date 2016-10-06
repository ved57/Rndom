
#include <iostream>
#include <fstream>
#include<algorithm>
#include <set>
using namespace std;


/*
 * method1: using recursion
 * Very straight forward implementation
 * This can be used to find the length only.
 * In order to find lcs string then modification is
 * not straightforward
 * */
int lcs(string& s1, string& s2, int len1, int len2)
{
	int res=0;
	//obvious base case
	if (len1<=0||len2<=0)
	{
		return res;
	}
	else
	{
		//case1 :last char in the strings are same
		// so add 1 to length and solve sub problem
		if (s1[len1-1]==s2[len2-1])
		{
			return 1 + lcs(s1,s2,len1-1,len2-1);
		}
		//case2:: last char in the string is not same
		else
		{
			return max (lcs(s1,s2,len1-1,len2),
					lcs(s1,s2,len1,len2-1));
		}
	}
}


/* Method2: Using forward iteration including memoization
 * Take two random strings and follow the following procedure
 * Just form the mem table for the two strings...
 * From the table find the last entry...
 * This table can later be used for printing the string as well
 */
int lcs_iter(string& s1,string& s2, int len1, int len2)
{
	//adding empty line of 0s to simplify stuff
	int m = len1+1;
	int n = len2+1;
	int lcs_table[m][n];

	//we are filling down-right
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (i==0 || j==0)
			{
				lcs_table[i][j]=0;
			}
			else if (s1[i-1]==s2[j-1])
			{
				//left diag + 1
				lcs_table[i][j] = lcs_table[i-1][j-1]+1;
			}
			else
			{
				//max of top and left
				lcs_table[i][j] = max (lcs_table[i-1][j],lcs_table[i][j-1]);
			}
		}
	}
	//return the last element of the matrix as the answer
	return lcs_table[len1][len2];
}


/* Method2: Using forward iteration including memoization
 * Take two random strings and follow the following procedure
 * Just form the mem table for the two strings...
 * From the table find the last entry...
 * This table can later be used for printing the string as well
 */
int lcs_iter_print(string& s1,string& s2, int len1, int len2)
{
	//adding empty line of 0s to simplify stuff
	int m = len1+1;
	int n = len2+1;
	int lcs_table[m][n];

	//we are filling down-right
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (i==0 || j==0)
			{
				lcs_table[i][j]=0;
			}
			else if (s1[i-1]==s2[j-1])
			{
				//left diag + 1
				lcs_table[i][j] = lcs_table[i-1][j-1]+1;
			}
			else
			{
				//max of top and left
				lcs_table[i][j] = max (lcs_table[i-1][j],lcs_table[i][j-1]);
			}
		}
	}

	/*
	 * The trick to print the sub-sequence is that:
	 * From the last element in table travel backwards to form the string.
	 *  and then finally reverse the string.
	 */
	//print lcs_string
	{
		string seq="";
		int i=m-1;
		int j=n-1;
		while (i>0 && j>0)
		{

			if (lcs_table[i][j] == lcs_table[i-1][j])
				i = i-1;
			else if (lcs_table[i][j] == lcs_table[i][j-1])
				j = j-1;
			/*
			 * Very important:
			 * This check should be only at the last.
			 */
			else if (lcs_table[i][j] == lcs_table[i-1][j-1]+1)
			{
				seq.push_back(s2[j-1]);
				i = i-1;
				j= j-1;
			}
		}

		std::reverse(seq.begin(),seq.end());
		cout<<"\n The common sequence is "<<seq<<endl;
	}
	//return the last element of the matrix as the answer
	return lcs_table[len1][len2];
}

/*
 * Before proceeding to the algorithm filter both the strings
 * so that only common strings stay in their position
 */
int lcs_iter_print_optimized(const string& s1,string& s2, int len1, int len2)
{
	string reduced_s1;
	string reduced_s2;
	string common;
	set<char> common_char;
	//initialize the set with longer string.
	string longer_string = (len1>len2)?s1:s2;
	common_char.insert(longer_string.begin(),longer_string.end());

	//insert the smaller string. if already char exists then common.
	string shorter_string = (len1<len2)?s1:s2;
	for (size_t i=0;i<shorter_string.size();i++)
	{
		if (common_char.count(shorter_string[i]))
		{
			common+=shorter_string[i];
		}
	}



	for (int i=0;i<s1.size();i++)
	{
		size_t pos = common.find(s1[i]);
		if (pos!=std::string::npos)
		{
			reduced_s1+=s1[i];
		}
	}

	for (int i=0;i<s2.size();i++)
	{
		size_t pos = common.find(s2[i]);
		if (pos!=std::string::npos)
		{
			reduced_s2+=s2[i];
		}
	}
	cout<<"\n Common string is "<<common<<endl;
	cout<<"\n Reduced string s1 and s2 are "<<reduced_s1<<"  "<<reduced_s2<<endl;
	return 0;

}

int main()
{
	string s1 = "abcdaf";
	string s2 = "acbcf";
	cout<<lcs(s1,s2,s1.size(),s2.size())<<endl;
	cout<<lcs_iter(s1,s2,s1.size(),s2.size())<<endl;
	cout<<lcs_iter_print(s1,s2,s1.size(),s2.size())<<endl;
	cout<<lcs_iter_print_optimized(s1,s2,s1.size(),s2.size())<<endl;
	return 0;
}
