#include <iostream>
#include <fstream>
using namespace std;

int main () {
	ofstream file;
	file.open ("input.txt");
	file << "Maria    Brown      10 Intel      42.75 39.0
Jeffrey  Jackson    20 Boeing     38.0  32.5
Bernard  Smith      30 Douglas    25.0  23.25
Matthew  Davenport  40 Raytheon   63.15 47.5
Kimberly Macias     50 Douglas    45.5  40.0
Amber    Daniels    60 Raytheon   62.25 44.5
Michael  Lee        70 Boeing     32.0  35.5
Patricia Wright     80 Intel      40.0  32.0
Stanley  Johnson    90 HealthTech 48.5  43.25
James    Miller    100 Raytheon   55.5  45.75
Linda    Davis     110 HealthTech 40.0  36.5
Olivia   Walker    120 Intel      61.15 51.5
Thomas   Sanders   130 Raytheon   50.25 38.5
Sophia   Foster    140 Raytheon   44.15 44.0
Ryan     Ward      150 Douglas    68.0  48.25
Karen    Hill      160 Intel      49.5  54.0
";
file.close()

return 0;
}
