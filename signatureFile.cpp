#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
	fstream inFile, outFile;
	string filePath;
	char ch;

	if(argc==3){
		inFile.open(argv[1], fstream::in);
		outFile.open(argv[2], fstream::app);
	}
	else{
		cout<<"Enter input file: "<<endl;
		getline(cin, filePath);
		inFile.open(filePath, fstream::in);
		filePath.clear();
		cout<<"Enter output file: "<<endl;
		getline(cin, filePath);
		outFile.open(filePath, fstream::app);
	}

	if( (!inFile) && (!outFile) ){
		cerr<<"Fail to open file: "<<inFile<<endl;
		cerr<<" or "<<outFile<<endl;
		return 1;
	}

	while( !inFile.eof() ){
		inFile.get(ch);
		outFile<<ch;
	}

	outFile<<"--\nSignature Here\n1234567"<<endl;
	cout<<"Signature!!!"<<endl;

	inFile.close();
	outFile.close();
	system("PAUSE");
	return 0;
}