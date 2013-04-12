#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

unsigned long square(int i)
{
  (void)((i < 0) ? (i *=-1): i); // -ive becomes +ive

	static vector<unsigned long> sqV(2);
	sqV[0] = 0;
	sqV[1] = 1;
	int s=0;
	if((unsigned)i < (s = sqV.size())) //ignore this warning as we took care above.
		return sqV[i]; //if already exists then return;

	for(int j = sqV.size(); j <= i ; j++)
		sqV.push_back(sqV[j-1] + (j-1) + (j-1) + 1);

	return sqV[i];
}

const int MAX_INTEGER = 250;

void sqrDriver()
{
	for(int i = 0; i <= MAX_INTEGER; i++)
		cout <<  "Square(" << i << ") = " << square(i) << endl;

	return;
}
