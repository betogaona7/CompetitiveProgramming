#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

main(){
	
	map <int, string> r;
	r[1] = "I";
	r[2] = "II";
	r[3] = "III";
	r[4] = "IV";
	r[5] = "V";
	r[6] = "VI";
	r[7] = "VII";
	r[8] = "VIII";
	r[9] = "IX";
	r[10] = "X";
	r[20] = "XX";
	r[30] = "XXX";
	r[40] = "XL";
	r[50] = "L";
	r[60] = "LX";
	r[70] = "LXX";
	r[80] = "LXXX";
	r[90] = "XC";
	r[100] = "C";
	r[200] = "CC";
	r[300] = "CCC";
	r[400] = "CD";
	r[500] = "D";
	r[600] = "DC";
	r[700] = "DCC";
	r[800] = "DCCC";
	r[900] = "CM";
	
	
	int num, c, d;
	scanf("%d", &num);
	
	c = (num/100) * 100;
	num -= c;
	d = (num/10) * 10;
	num -= d;
	
	cout << r[c] << r[d] << r[num] << "\n";
	return 0;
}
