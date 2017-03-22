#include <iostream>
#include <clocale>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, char * argv[]) {
	setlocale(LC_ALL, "RUSSIAN");
    
	if (argc > 1)
	{
		cout << "Your file is:" << argv[1] << endl;
		ifstream file(argv[1], ios::in | ios::binary);
		int size;
		int width = 0;
		int height = 0;
		
			file.seekg(18, ios::beg);
			// Ñ÷èòûâàåì øèðèíó è âûñîòó èçîáðàæåíèÿ (â ïèêñåëÿõ)
			file.read((char*)&width, sizeof(int));

			file.read((char*)&height, sizeof(int));
			
			file.seekg(54, ios::beg);

			ofstream fout("test.txt", ios::binary);
			fout << "width: " << width << endl;
			fout << "height: " << height << endl;
			int test;
			file.seekg(54, ios::beg);
			fout << "picture: " << '\n';
			for (int i = 0; i < (width*height); i++) {
				file.read((char*)&test, sizeof(char));
				fout << setw(2) << hex<<showbase << (short)test<< "  ";
				
				if (!((i+1)  % 12)) fout << endl;
				
			}
			fout.close();

		file.close();
	}
	else
	{
		cout << "Not arguments" << endl;
	}
	system("pause");
}



