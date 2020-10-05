#include "linkList.h"
#include <fstream>

int main() {

	linkList<int> intList;
	cout << "The size : " << intList.size() << endl;
	intList.printListToScreen();
	for (int i = 1; i <= 10; i++) {
		intList.pushBack(i);
		intList.printListToScreen();
	}
	
	cout << "The size : " << intList.size() << endl;
	ofstream outFile("listData.txt");
	ofstream outBinFile("listDataBin.bin");
	//intList.printListToTextFile(outFile);
	outFile << intList;
	intList.saveToBinFile(outBinFile);
	outBinFile.close();
	outFile.close();
	ifstream inFileTxt("listData.txt");
	inFileTxt >> intList;
	//inFileTxt >> intList;
	//inFileTxt >> intList;
	inFileTxt.close();
	linkList<char> charList;
	for (int i = 0; i < 20; i++)
		charList.pushBack('a' + i);
	charList.printListToScreen();

	//intList.scanFromKeyboard();
	intList.printListToScreen();

	return 0;
}