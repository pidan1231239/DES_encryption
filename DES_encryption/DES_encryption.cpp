// DES_encryption.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <bitset>
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include "encyption.h"

using namespace zhang;


int main()
{
	//cout << "功能选择（1加密/2解密）：" ;
	//int option;
	//cin >> option;
	//switch (option)
	//{
	//case 1:
	//{
	//	cout << "加密文件：";
	//	string file;
	//	cin >> file;
	//	cout << "密钥（8个字符）：";
	//	string k;
	//	cin >> k;
	//	key = charToBitset(k.c_str());

	//	// 将文件 file 加密到 file.des 中
	//	ifstream in;
	//	ofstream out;
	//	in.open(file, ios::binary);
	//	out.open(file.append(".des"), ios::binary);
	//	bitset<64> plain;
	//	while (in.read((char*)&plain, sizeof(plain)))
	//	{
	//		bitset<64> cipher = encrypt(plain);
	//		out.write((char*)&cipher, sizeof(cipher));
	//		plain.reset();  // 置0
	//	}
	//	in.close();
	//	out.close();
	//}
	//break;
	//	
	//case 2:
	//{
	//	cout << "解密文件：";
	//	string file;
	//	cin >> file;
	//	cout << "密钥（8个字符）：";
	//	string k;
	//	cin >> k;
	//	key = charToBitset(k.c_str());

	//	// 解密 file.des，并写入 file
	//	ifstream in;
	//	ofstream out;
	//	in.open(file, ios::binary);
	//	out.open(file.substr(0, file.size() - 4), ios::binary);
	//	bitset<64> plain;
	//	while (in.read((char*)&plain, sizeof(plain)))
	//	{
	//		bitset<64> temp = decrypt(plain);
	//		out.write((char*)&temp, sizeof(temp));
	//		plain.reset();  // 置0
	//	}
	//	in.close();
	//	out.close();
	//}
	//	break;
	//default:
	//	cout << "重新选择功能" << endl;
	//	break;
	//}
	//

	//return 0;
	
	string k = "12345678";
	string iv = "12345678";

	CFB<64> cfb(
		new desEncryption(bitset<64>(*((uint64_t*)(k.c_str())))),
		bitset<64>(*((uint64_t*)(iv.c_str())))
	);

	//加密"test.txt"文件到"testen.txt"中
	fstream infile("test.txt", ios::binary | ios::in), 
		outfile("testen.txt", ios::binary | ios::out);

	cfb.encrypt(
		istreambuf_iterator<char>(infile),
		istreambuf_iterator<char>(),
		ostreambuf_iterator<char>(outfile)
	);

	infile.close();
	outfile.close();

	//解密"testen.txt"文件到"testde.txt"中
	infile.open("testen.txt", ios::binary | ios::in);
	outfile.open("testde.txt", ios::binary | ios::out);

	cfb.decrypt(
		istreambuf_iterator<char>(infile),
		istreambuf_iterator<char>(),
		ostreambuf_iterator<char>(outfile)
	);

	infile.close();
	outfile.close();

	return 0;
}

