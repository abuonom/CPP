#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main(int argc,char **argv)
{
	std::string filename;
	if(argc != 4)
	{
		std::cout<<"Inserire input in questo formato: <filename> <str1> <str2>"<<std::endl;
		return(1);
	}
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	filename = argv[1];
	std::ifstream file(filename.c_str());
	std::ofstream fileout((filename + ".replace").c_str());
	if(!file.is_open() || !fileout.is_open())
	{
		std::cout<<"Errore nell'apertura del file"<<std::endl;
		return(1);
	}
	std::string line;
	while(std::getline(file,line))
	{
		std::size_t pos = 0;
		while((pos = line.find(str1,pos)) != std::string::npos)
		{
			line.erase(pos,str1.length());
			line.insert(pos,str2);
		}
			fileout << line;
	}
	file.close();
	fileout.close();
}
