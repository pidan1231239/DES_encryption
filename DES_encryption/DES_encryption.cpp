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
	string k, iv;
	string inName,outName;
	CFB<64> cfb(
		new desEncryption
	);

	cout << "功能选择（1加密/2解密）：" ;
	int option;
	cin >> option;
	cout << "输入文件：";
	cin >> inName;
	cout << "输出文件：";
	cin >> outName;
	cout << "密钥（8个字符）：";
	cin >> k;
	cout << "初始向量（8个字符）：";
	cin >> iv;

	cfb.setKey(bitset<64>(*((uint64_t*)(k.c_str()))));
	cfb.setIV(bitset<64>(*((uint64_t*)(iv.c_str()))));

	switch (option)
	{
	case 1:
	{
		// 将文件 file 加密到 file.des 中
		fstream infile(inName, ios::binary | ios::in),
			outfile(outName, ios::binary | ios::out);

		cfb.encrypt(
			istreambuf_iterator<char>(infile),
			istreambuf_iterator<char>(),
			ostreambuf_iterator<char>(outfile)
		);

		infile.close();
		outfile.close();
	}
	break;
		
	case 2:
	{
		// 将文件 file 加密到 file.des 中
		fstream infile(inName, ios::binary | ios::in),
			outfile(outName, ios::binary | ios::out);

		cfb.decrypt(
			istreambuf_iterator<char>(infile),
			istreambuf_iterator<char>(),
			ostreambuf_iterator<char>(outfile)
		);

		infile.close();
		outfile.close();
	}
		break;
	default:
		cout << "重新选择功能" << endl;
		break;
	}
	

	return 0;
}

