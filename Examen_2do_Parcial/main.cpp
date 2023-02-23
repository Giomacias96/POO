#include <iostream>
#include "Date.h"
using namespace std;

int main(int argc, char** argv) {
	Date d(04, 04, 2022);
	cout << "Diferencia en días:  " << d.getDifferenceBetweenDates(5, 7, 2020) << endl;
	
	d.printDate( DF_USA );
	d.printDate( DF_ANSI );
	d.printDate( DF_Italian );
	
	
	cout << d.getPartName( DP_Day_of_Week ) << endl;
	cout << d.getPartName( DP_Month ) << endl;
	
	cout << d.getPartNumber( DP_Day_of_Week ) << endl;
	cout << d.getPartNumber( DP_Month ) << endl;
	cout << d.getPartNumber( DP_Year ) << endl;
	
	
	/*cout << "----------------------------------------------------------------" << endl;
	d.add(DP_Month, -24);
	d.printDate( DF_Italian );	
	
	d.add(DP_Day_of_Week, -1);
	d.printDate( DF_Italian );
	
	d.add(DP_Year, 1);
	d.printDate( DF_Italian );*/

  cout<<endl;
  
  cout << "-------------------------SOBRECARGA OPERADORES---------------" << endl<<endl;
  Date b(05,04,2022);
  Date c(04,04,2022);
  //Date c;
  
  cout << b;
  
  cout << b + 5;
  cout << b - 1;
  cout << b - c;
  cout << (b += 6);
  cout << (b -= 1);
  cout << (b == c)<<endl;
  cout << (b > c)<<endl;
  cout << (b >= c)<<endl;
  cout << (b <= c)<<endl;
  cout << (b < c)<<endl;
  cout << (b != c)<<endl;
  
  
  
	return 0;
}