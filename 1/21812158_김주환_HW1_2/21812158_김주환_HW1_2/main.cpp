/* main.cpp */
/* Description:
*  정수 1 ~ 32 출력 포멧 지정
* Programmed by J. H. Kim
* Last updated : 2021-09-08 */

#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

int main() {
	for (int i = 0; i <= 32; i++) {
		cout << setw(10) << dec << i;
		cout << setw(10) << showbase << oct << i;
		cout << setw(10) << showbase << hex << i;
		cout << setw(10) << bitset<8>(i);
		cout << endl;
	}
}